// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventoryPickup.h"

#include "Math/Color.h"


#include "InventoryKeyCard.generated.h"

/**
 * 
 */
UCLASS()
class UE4INVENTORY_API AInventoryKeyCard : public AInventoryPickup
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = KeyCard)
	struct FLinearColor Colour;


};
