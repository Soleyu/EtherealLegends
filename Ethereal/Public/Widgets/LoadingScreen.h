// Â© 2014 - 2017 Soverance Studios
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
#include "LoadingScreen.generated.h"

UCLASS()
class ETHEREAL_API ULoadingScreen : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Sets the Hint array
	UFUNCTION(BlueprintCallable, Category = Default)
	void HintConfig();

	// Loading Screen Hint List
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	TArray<FText> HintList;

	// Hint to display on screen during loading
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	FText DisplayHint;
};
