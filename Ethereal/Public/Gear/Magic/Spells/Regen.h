// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#pragma once

#include "Gear/Magic/Magic_Master.h"
#include "Regen.generated.h"

/**
 * 
 */
UCLASS()
class ETHEREAL_API ARegen : public AMagic_Master
{
	GENERATED_BODY()
	
public:

	ARegen(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	/** Casts this spell. */
	UFUNCTION(BlueprintCallable, Category = Controls)
	void Cancel();	
};
