// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#pragma once

#include "Gear/Magic/Magic_Master.h"
#include "Haste.generated.h"

/**
 * 
 */
UCLASS()
class ETHEREAL_API AHaste : public AMagic_Master
{
	GENERATED_BODY()
	
public:

	AHaste(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	/** Casts this spell. */
	UFUNCTION(BlueprintCallable, Category = Controls)
	void Cancel();	
};
