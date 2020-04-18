// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UE4InventoryHUD.generated.h"

UCLASS()
class AUE4InventoryHUD : public AHUD
{
	GENERATED_BODY()

public:
	AUE4InventoryHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

