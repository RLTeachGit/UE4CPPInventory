// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inventory.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE4INVENTORY_API UInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventory();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



//New code
public:

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool	AddItem(class AInventoryPickup* InventoryPickup);

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool	RemoveItem(class AInventoryPickup* InventoryPickup);

	UPROPERTY(BlueprintReadOnly)
	TArray<class AInventoryPickup*> ItemArray;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Inventory)
	int32	SameItemCount(class AInventoryPickup* InventoryPickup);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Inventory)
	int32	Count(); //How many items



};
