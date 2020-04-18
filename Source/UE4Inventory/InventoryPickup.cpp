// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryPickup.h"
#include "Inventory.h"

//Custom Log for clarity, add this where you need to use it
DECLARE_LOG_CATEGORY_EXTERN(CaptainsLog, Log, All);


// Sets default values
AInventoryPickup::AInventoryPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MaxCount = 1;
}

// Called when the game starts or when spawned
void AInventoryPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AInventoryPickup::OnAddItem_Implementation(UInventory* Inventory)
{
	if (IsValid(Inventory) && (Inventory->SameItemCount(this) < MaxCount))
	{
		UE_LOG(CaptainsLog, Log, TEXT("Default OnAddItem_Implementation %s OK"), *Inventory->GetName()); //Log Entry
		return true;
	}
	UE_LOG(CaptainsLog, Log, TEXT("Default OnAddItem_Implementation %s Refused"), *Inventory->GetName()); //Log Entry
	return false;
}

bool AInventoryPickup::OnRemoveItem_Implementation(UInventory* Inventory)
{
	if (IsValid(Inventory))
	{
		UE_LOG(CaptainsLog, Log, TEXT("Default OnAddRemove_Implementation %s OK"), *Inventory->GetName()); //Log Entry
	}
	return true;
}

