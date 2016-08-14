// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#include "Ethereal.h"
#include "EtherealPlayerMaster.h"

// Sets default values
AEtherealPlayerMaster::AEtherealPlayerMaster(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

// Called when the game starts or when spawned
void AEtherealPlayerMaster::BeginPlay()
{
	Super::BeginPlay();

	EtherealPlayerState = Cast<AEtherealPlayerState>(PlayerState);
}



