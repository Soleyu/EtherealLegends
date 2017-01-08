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

#include "Characters/Enemy/EtherealEnemyMaster.h"
#include "Characters/Enemy/Standard/UndeadWarrior.h"
#include "Characters/Enemy/Boss/SkeletonKing.h"
#include "Characters/Enemy/Standard/SoulEater.h"
#include "Characters/Enemy/Standard/DemonStatue.h"
#include "Characters/Enemy/Standard/Watcher.h"
#include "Characters/Enemy/Boss/DeathCap.h"
#include "Characters/Enemy/Standard/Goblin.h"
#include "Characters/Enemy/Standard/Gruntling.h"
#include "Characters/Enemy/Standard/DragonWorm.h"
#include "Characters/Enemy/Boss/RedDragon.h"
#include "Characters/Enemy/Boss/LavaKnight.h"
#include "Characters/Enemy/Standard/FrostGiant.h"
#include "Characters/Enemy/Standard/Spider.h"
#include "Characters/Enemy/Standard/GiantSpider.h"
#include "Characters/Enemy/Boss/FrostCaptain.h"
#include "Characters/Enemy/Standard/Flytrap.h"
#include "Characters/Enemy/Standard/Mugbear.h"
#include "Characters/Enemy/Standard/EarthTroll.h"
#include "Characters/Enemy/Boss/GaiaTortoise.h"
#include "Characters/Enemy/Boss/GaiaTitan.h"
#include "Characters/Enemy/Standard/PowerDrone.h"
#include "Characters/Enemy/Standard/Golem.h"
#include "Characters/Enemy/Boss/Samaritan.h"
#include "Characters/Enemy/Standard/Nightshade.h"
#include "Characters/Enemy/Boss/Zhan.h"
#include "Characters/Enemy/Boss/Eternal.h"

#include "EtherealEnemyManager.h"


// Sets default values
AEtherealEnemyManager::AEtherealEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AEtherealEnemyManager::BeginPlay()
{
	Super::BeginPlay();

	// This usually wouldn't be necessary, since we collect this reference when the player enters the NPC's collider.
	// However, we require the reference to draw debug lines for the map, and the player may access the map before having interacting with this actor
	for (TActorIterator<AEtherealPlayerMaster> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		Player = *ActorItr; // get the instance of the Player
	}
}

void AEtherealEnemyManager::SpawnAllNodes()
{
	// iterate through the world for all Enemy Nodes
	for (TActorIterator<AEnemyNode> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AEnemyNode* Node = *ActorItr; // get the instance of the node

		SpawnNode(Node); // Spawn the enemy related to this node instance
	}
}

// This function is called during the loading screen to destroy all enemies leftover from the previous Realm
void AEtherealEnemyManager::DestroyAllEnemies()
{
	// iterate through the world for all Enemy Nodes
	for (TActorIterator<AEtherealEnemyMaster> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AEtherealEnemyMaster* Enemy = *ActorItr; // get the instance of the enemy

		Enemy->DestroyEnemy();  //  Destroy it
	}
}

void AEtherealEnemyManager::SpawnNode(AEnemyNode* Node)
{
	AEtherealEnemyMaster* Enemy = nullptr;

	FTransform transform = Node->GetActorTransform();
	int level = Node->EnemyLevel;

	// TO DO : Spawn AI from class based on name, set it's level based on Node, and then call SetDefaultStats() on the enemy
	switch (Node->EnemyName)
	{
		case EEnemyNames::EN_None:
			
			break;

		// ARCADIA

		case EEnemyNames::EN_UndeadWarrior:
			Enemy = GetWorld()->SpawnActor<AUndeadWarrior>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_SkeletonKing:
			Enemy = GetWorld()->SpawnActor<ASkeletonKing>(Node->GetActorLocation(), Node->GetActorRotation());
			break;

		// SHIITAKE TEMPLE

		case EEnemyNames::EN_SoulEater:
			Enemy = GetWorld()->SpawnActor<ASoulEater>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_DemonStatue:
			Enemy = GetWorld()->SpawnActor<ADemonStatue>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_Watcher:
			Enemy = GetWorld()->SpawnActor<AWatcher>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_DeathCap:
			Enemy = GetWorld()->SpawnActor<ADeathCap>(Node->GetActorLocation(), Node->GetActorRotation());
			break;

		// VULCAN SHRINE

		case EEnemyNames::EN_Gruntling:
			Enemy = GetWorld()->SpawnActor<AGruntling>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_Goblin:
			Enemy = GetWorld()->SpawnActor<AGoblin>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_DragonWorm:
			Enemy = GetWorld()->SpawnActor<ADragonWorm>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_RedDragon:
			Enemy = GetWorld()->SpawnActor<ARedDragon>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_LavaKnight:
			Enemy = GetWorld()->SpawnActor<ALavaKnight>(Node->GetActorLocation(), Node->GetActorRotation());
			break;

		// BOREAL CORE

		case EEnemyNames::EN_Spider:
			Enemy = GetWorld()->SpawnActor<ASpider>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_GiantSpider:
			Enemy = GetWorld()->SpawnActor<AGiantSpider>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_FrostGiant:
			Enemy = GetWorld()->SpawnActor<AFrostGiant>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_FrostCaptain:
			Enemy = GetWorld()->SpawnActor<AFrostCaptain>(Node->GetActorLocation(), Node->GetActorRotation());
			break;

		// YGGDRASIL

		case EEnemyNames::EN_Flytrap:
			Enemy = GetWorld()->SpawnActor<AFlytrap>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_Mugbear:
			Enemy = GetWorld()->SpawnActor<AMugbear>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_EarthTroll:
			Enemy = GetWorld()->SpawnActor<AEarthTroll>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_GaiaTortoise:
			Enemy = GetWorld()->SpawnActor<AGaiaTortoise>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_GaiaTitan:
			Enemy = GetWorld()->SpawnActor<AGaiaTitan>(Node->GetActorLocation(), Node->GetActorRotation());
			break;

		// EMPYREAN GARDENS

		case EEnemyNames::EN_Golem:
			Enemy = GetWorld()->SpawnActor<AGolem>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_PowerDrone:
			Enemy = GetWorld()->SpawnActor<APowerDrone>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_Nightshade:
			Enemy = GetWorld()->SpawnActor<ANightshade>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_Samaritan:
			Enemy = GetWorld()->SpawnActor<ASamaritan>(Node->GetActorLocation(), Node->GetActorRotation());
			break;

		// CELESTIAL NEXUS
		case EEnemyNames::EN_Eternal:
			Enemy = GetWorld()->SpawnActor<AEternal>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
		case EEnemyNames::EN_Zhan:
			Enemy = GetWorld()->SpawnActor<AZhan>(Node->GetActorLocation(), Node->GetActorRotation());
			break;
	}

	if (Enemy)
	{
		Enemy->SpawnDefaultController();  // Spawns the Enemy's A.I. Controller
		Enemy->Level = Node->EnemyLevel; // Sets the Enemy's Level
		Enemy->SetBaseStats(); // Sets the Enemy's base stats.
		Enemy->Target = Player;  // Sets the Player as this enemy's target. this is a single player game, so we can do dumb shit like this
	}
}
