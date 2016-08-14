// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#pragma once

#include "Gear/Magic/Magic_Master.h"
#include "CureII.generated.h"

/**
 * 
 */
UCLASS()
class ETHEREAL_API ACureII : public AMagic_Master
{
	GENERATED_BODY()
	
public:

	ACureII(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	/** Casts this spell. */
	UFUNCTION(BlueprintCallable, Category = Controls)
	void Cancel();	
};
