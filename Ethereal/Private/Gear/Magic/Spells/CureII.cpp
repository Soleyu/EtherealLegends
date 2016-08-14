// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#include "Ethereal.h"
#include "CureII.h"

// Sets default values
ACureII::ACureII(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/Blueprints/Gear/Magic/SpellEffects/Audio/Spell_CureII_Cue.Spell_CureII_Cue'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> CastParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/P_CureII.P_CureII'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> ChargeParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Spells/SpellEffects/Particles/ChargeFX/ChargeParticle.ChargeParticle'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/cure2.cure2'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/cure2-small.cure2-small'"));

	// Set Default Values
	Name = EMasterGearList::GL_Cure2;
	Type = EMasterGearTypes::GT_White;
	Description = "Heals a significant portion of Max HP.";
	MPCost = 150;
	ATK = 0;
	DEF = 0;
	SPD = 0;
	HP = -150;
	MP = 45;
	Duration = 4;
	CastTime = 35;
	CritMultiplier = 75;
	HasteMultiplier = 0;
	DefenseMultiplier = 0;
	TargetType = EMagic_TargetTypes::TT_Player;
	AnimType = EMagic_AnimTypes::AT_Standard;

	// Set Default Objects
	S_CastAudio = AudioObject.Object;
	P_CastFX = CastParticleObject.Object;
	P_ChargeFX = ChargeParticleObject.Object;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	// Attachment
	CastAudio->SetupAttachment(GetRootComponent());
	CastAudio->Sound = S_CastAudio;
	CastAudio->bAutoActivate = false;
	CastFX->SetupAttachment(GetRootComponent());
	CastFX->Template = P_CastFX;
	CastFX->bAutoActivate = false;
	ChargeFX->SetupAttachment(GetRootComponent());
	ChargeFX->Template = P_ChargeFX;
	ChargeFX->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ACureII::BeginPlay()
{
	Super::BeginPlay();

	// Bind the Use function to the event dispatcher for Item Use
	QuitCharging.AddDynamic(this, &ACureII::Cancel);
}

void ACureII::Cancel()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Cure II casting was cancelled.");
}


