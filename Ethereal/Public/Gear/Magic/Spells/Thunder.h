// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#pragma once

#include "Gear/Magic/Magic_Master.h"
#include "Thunder.generated.h"

/**
 * 
 */
UCLASS()
class ETHEREAL_API AThunder : public AMagic_Master
{
	GENERATED_BODY()
	
public:

	AThunder(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	/** Casts this spell. */
	UFUNCTION(BlueprintCallable, Category = Controls)
	void Cancel();	
};
