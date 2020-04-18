// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventoryPickup.generated.h"

UCLASS()
class UE4INVENTORY_API AInventoryPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventoryPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


//New Code
public:
	
	UFUNCTION(BlueprintNativeEvent, Category = Inventory)
	bool	OnAddItem(class UInventory* Inventory);
	bool	OnAddItem_Implementation(class UInventory* Inventory); //C++ Default if no BP


	UFUNCTION(BlueprintNativeEvent, Category = Inventory)
	bool	OnRemoveItem(class UInventory* Inventory); //Called in BP
	bool	OnRemoveItem_Implementation(class UInventory* Inventory); //C++ Default if no BP

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = Inventory)
	int32	MaxCount;

};
