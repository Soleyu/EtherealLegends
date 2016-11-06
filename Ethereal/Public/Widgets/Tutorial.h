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

#pragma once

#include "Blueprint/UserWidget.h"
#include "NPCs/Characters/Gatekeeper.h"
#include "Tutorial.generated.h"

UCLASS()
class ETHEREAL_API UTutorial : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Gatekeeper Reference
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	AGatekeeper* Gatekeeper;

	// Initiates the tutorial, giving the player default items. Called when you first interact with the Gatekeeper NPC
	UFUNCTION(BlueprintCallable, Category = Default)
	void FirstContact();

	// Bind the Action Inputs of the PlayerController to functions in this widget
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Widgets)
	void BindActions();

	// Tutorial Index
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	int32 TutorialIndex;

	// Whether this widget is usable or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	bool IsActive;

	///////////////////////////
	// TUTORIAL SECTION 1
	// 
	// Section 1 contains a small conversation with Prodigy, the Gatekeeper, where he'll give you basic weapons.

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Widgets)
	void ShowConversation_01();

	// Gives the Tutorial items to the player
	UFUNCTION(BlueprintCallable, Category = Tutorial)
	void GiveDefaultItems();

	// Gives the player the Iron Sword
	UFUNCTION(BlueprintCallable, Category = Tutorial)
	void GiveSword();

	// Gives the player the War Aspis
	UFUNCTION(BlueprintCallable, Category = Tutorial)
	void GiveShield();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Widgets)
	void ShowConversation_02();

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph1;

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph2;

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph3;

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph4;

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph5;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Widgets)
	void ShowConversation_04();

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph6;

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph7;

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph8;

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph9;

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph10;

	// Informational tutorial text
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText Paragraph11;
};
