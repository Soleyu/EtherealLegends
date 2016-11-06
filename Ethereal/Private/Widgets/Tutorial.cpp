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
#include "Gear/EtherealGearMaster.h"
#include "Tutorial.h"

#define LOCTEXT_NAMESPACE "EtherealText"

void UTutorial::FirstContact()
{
	BindActions();  // Bind the player's Input Actions
	ShowConversation_01();  // Start Conversation 01

	TutorialIndex = 0;  // set TutorialIndex
	IsActive = true;  // Set this widget active so that it can receive input

	// Configure Tutorial Text Paragraphs
	Paragraph1 = LOCTEXT("Tutorial_Paragraph1", "Magic, Weapons, and Armor are all items that can be equipped through a process called 'BINDING'.");
	Paragraph2 = LOCTEXT("Tutorial_Paragraph2", "To equip new items, access the Bindings interface at any time during gameplay through the Pause menu.");
	Paragraph3 = LOCTEXT("Tutorial_Paragraph3", "Weapons and Armor have four grades of quality to help determine their power :  Common, Uncommon, Rare, and Epic.");
	Paragraph4 = LOCTEXT("Tutorial_Paragraph4", "Magic has no such distinction.");
	Paragraph5 = LOCTEXT("Tutorial_Paragraph5", "Equip better items to increase in power and gain new abilities!");
	Paragraph6 = LOCTEXT("Tutorial_Paragraph6", "To attack, simply press the 'ACTION' button.");
	Paragraph7 = LOCTEXT("Tutorial_Paragraph7", "Hold down the 'ACTION' button to continuously attack.");
	Paragraph8 = LOCTEXT("Tutorial_Paragraph8", "Lock on to enemies to improve accuracy.");
	Paragraph9 = LOCTEXT("Tutorial_Paragraph9", "Increase your Defense by holding the 'BLOCK' button.");
	Paragraph10 = LOCTEXT("Tutorial_Paragraph10", "There are skeletons in the desert over there.");
	Paragraph11 = LOCTEXT("Tutorial_Paragraph11", "Defeat the largest of them and I will let you through the gate.");
}

void UTutorial::BindActions_Implementation()
{

}

void UTutorial::ShowConversation_01_Implementation()
{

}

void UTutorial::ShowConversation_02_Implementation()
{

}

void UTutorial::ShowConversation_04_Implementation()
{

}

// Gives the tutorial items to the player
void UTutorial::GiveDefaultItems()
{
	// Give the Sword
	FTimerHandle SwordTimer;
	Gatekeeper->GetWorldTimerManager().SetTimer(SwordTimer, this, &UTutorial::GiveSword, 0.2f, false);

	// Give the Shield
	FTimerHandle ShieldTimer;
	Gatekeeper->GetWorldTimerManager().SetTimer(ShieldTimer, this, &UTutorial::GiveShield, 1.0f, false);
}

// Gives the tutorial items to the player
void UTutorial::GiveSword()
{
	Gatekeeper->InteractingPlayer->EtherealPlayerState->AddToInventory(EMasterGearList::GL_IronSword, false, true);
}

// Gives the tutorial items to the player
void UTutorial::GiveShield()
{
	Gatekeeper->InteractingPlayer->EtherealPlayerState->AddToInventory(EMasterGearList::GL_WarAspis, false, true);
}

#undef LOCTEXT_NAMESPACE