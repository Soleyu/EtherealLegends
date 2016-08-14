// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#pragma once

#include "Characters/EtherealCharacterMaster.h"
#include "EtherealPlayerState.h"
#include "EtherealPlayerMaster.generated.h"

/**
 * 
 */
UCLASS()
class ETHEREAL_API AEtherealPlayerMaster : public AEtherealCharacterMaster
{
	GENERATED_BODY()

public:
	
	AEtherealPlayerMaster(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	/** Casts this spell. */
	//UFUNCTION(BlueprintCallable, Category = Controls)
	//void Cast();	

	/** Same as CritMultiplier, but specifically for affecting the player's SPD stat. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Defaults)
	AEtherealPlayerState* EtherealPlayerState;
};
