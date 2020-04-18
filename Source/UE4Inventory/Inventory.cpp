// Fill out your copyright notice in the Description page of Project Settings.

#include "Inventory.h"
#include "Engine/World.h"
#include "InventoryPickup.h"

//Custom Log for clarity, add this where you need to use it
DECLARE_LOG_CATEGORY_EXTERN(CaptainsLog, Log, All);

// Sets default values for this component's properties
UInventory::UInventory()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventory::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInventory::AddItem(AInventoryPickup* InventoryPickup)
{
	if (InventoryPickup->OnAddItem(this)) 
	{
		int32 tIndex = ItemArray.Add(InventoryPickup); //Add to Inventory, no Duplicates
		UE_LOG(CaptainsLog, Log, TEXT("AddItem %s %d OK"), *InventoryPickup->GetName(),tIndex); //Log Entry
		return true;
	}
	UE_LOG(CaptainsLog, Log, TEXT("AddItem %s Refused"), *InventoryPickup->GetName()); //Log Entry
	return false;
}

bool UInventory::RemoveItem(AInventoryPickup* InventoryPickup)
{
	if (InventoryPickup->OnRemoveItem(this))
	{
		ItemArray.Remove(InventoryPickup); //Remove from Inventory
		UE_LOG(CaptainsLog, Log, TEXT("RemoveItem %s OK"), *InventoryPickup->GetName()); //Log Entry
		return true;
	}
	UE_LOG(CaptainsLog, Log, TEXT("RemoveItem %s Refused"), *InventoryPickup->GetName()); //Log Entry
	return false;
}

int32 UInventory::SameItemCount(AInventoryPickup* InventoryPickup)
{
	int32 tCount = 0;
	for (auto& tItemIterator : ItemArray)
	{
		if (tItemIterator == InventoryPickup)	tCount++; //Count same items
	}
	return tCount;
}

int32 UInventory::Count()
{
	return ItemArray.Num();
}

