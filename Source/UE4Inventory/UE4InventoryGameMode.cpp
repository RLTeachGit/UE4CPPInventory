// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "UE4InventoryGameMode.h"
#include "UE4InventoryHUD.h"
#include "UE4InventoryCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE4InventoryGameMode::AUE4InventoryGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AUE4InventoryHUD::StaticClass();
}
