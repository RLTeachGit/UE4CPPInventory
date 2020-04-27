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
	AInventoryKeyCard(); //Run Base class constructor


	//Hard to find in Docs, but this runs on construction like the BP ConstructionScript
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	struct FLinearColor Colour;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	struct FLinearColor Colour1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	class	UMaterial* BaseMaterial;

	UPROPERTY()
	UMaterialInstanceDynamic* DynMatInstance;


};
