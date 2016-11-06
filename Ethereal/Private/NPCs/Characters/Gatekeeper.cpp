// © 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "Gear/EtherealGearMaster.h"
#include "Widgets/Tutorial.h"
#include "Gatekeeper.h"

AGatekeeper::AGatekeeper(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> NPCMesh(TEXT("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Ram.SK_CharM_Ram'"));
	static ConstructorHelpers::FObjectFinder<UClass> AnimBP(TEXT("AnimBlueprint'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_Mannequin_Skeleton_AnimBlueprint.SK_Mannequin_Skeleton_AnimBlueprint_C'"));
	static ConstructorHelpers::FClassFinder<UUserWidget> Widget(TEXT("/Game/Blueprints/Widgets/BP_Tutorial"));

	// Set Default Objects
	SM_Mesh = NPCMesh.Object;
	W_InteractWidget = Widget.Class;
	
	// Create objects
	Mesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetAnimInstanceClass(AnimBP.Object);
	Mesh->SkeletalMesh = SM_Mesh;
	Mesh->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));

	CombatBox_Right = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("CombatBox_Right"));
	CombatBox_Right->SetupAttachment(Root);
	CombatBox_Right->SetBoxExtent(FVector(1400, 50, 200));
	CombatBox_Right->SetRelativeLocation(FVector(1640, 1086, 0));
	CombatBox_Right->SetRelativeRotation(FRotator(0, -8, 0));

	CombatBox_Left = ObjectInitializer.CreateDefaultSubobject<UBoxComponent>(this, TEXT("CombatBox_Left"));
	CombatBox_Left->SetupAttachment(Root);
	CombatBox_Left->SetBoxExtent(FVector(1000, 50, 200));
	CombatBox_Left->SetRelativeLocation(FVector(-1172, 47, 0));
	CombatBox_Right->SetRelativeRotation(FRotator(0, 54, 0));

	CombatBox_Right->OnComponentBeginOverlap.AddDynamic(this, &AGatekeeper::EnterCombatTutorialZone);
	CombatBox_Right->OnComponentEndOverlap.AddDynamic(this, &AGatekeeper::ExitCombatTutorialZone);
	CombatBox_Left->OnComponentBeginOverlap.AddDynamic(this, &AGatekeeper::EnterCombatTutorialZone);
	CombatBox_Left->OnComponentEndOverlap.AddDynamic(this, &AGatekeeper::ExitCombatTutorialZone);

	IsUsable = true;
	InteractAnimType = EInteractAnims::IA_Talk;
	DoInteract.AddDynamic(this, &AGatekeeper::Interact);

	DoExplain = false;
	DoHuh = false;
	DoWarning = false;
}

// Called when the game starts or when spawned
void AGatekeeper::BeginPlay()
{
	Super::BeginPlay();
}

// Interact with this NPC
void AGatekeeper::Interact()
{
	IsUsable = false;

	if (!InteractWidget)
	{
		InteractWidget = CreateWidget<UUserWidget>(GetWorld(), W_InteractWidget);  // creates the widget
		Tutorial = Cast<UTutorial>(InteractWidget);

		if (Tutorial)
		{
			Tutorial->AddToViewport();  // add the Tutorial widget to the viewport
			Tutorial->Gatekeeper = this;  // sets the Gatekeeper reference inside the Tutorial widget for later use.
			Tutorial->FirstContact();  // Initiate the tutorial
			DoHuh = true;  // animate
		}		
	}
}

// Disabled the Interact Widget associated with this NPC
void AGatekeeper::DisableInteractWidget()
{
	//InteractWidget->RemoveFromViewport();
	
	IsUsable = true;
}

// Function called when the player enters the InteractBox
void AGatekeeper::EnterCombatTutorialZone(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<AEtherealPlayerMaster>(OtherActor))
	{
		if (!InteractingPlayer->EtherealPlayerState->HasCompletedTutorial)
		{
			if (Tutorial->TutorialIndex == 1)
			{
				Tutorial->ShowConversation_04();  // Show the Combat Tutorial
			}
		}		
	}
}

// Function called when the player can no longer interact with this NPC
void AGatekeeper::ExitCombatTutorialZone(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<AEtherealPlayerMaster>(OtherActor))
	{		

	}
}