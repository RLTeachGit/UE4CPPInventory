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
	UE_LOG(CaptainsLog, Log, TEXT("AInventoryPickup")); //Log Entry

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
	return	CanCarry(Inventory);
}

bool AInventoryPickup::CanCarry(UInventory* Inventory)
{
	//You can pick up, if MaxCount<0 any amount else the amount in MaxCount
	return (IsValid(Inventory) && ((MaxCount < 0) || (Inventory->SameItemCount(this) < MaxCount)));
}


bool AInventoryPickup::OnRemoveItem_Implementation(UInventory* Inventory)
{
	return (IsValid(Inventory)); //Allow Removal
}

void AInventoryPickup::Hide(bool Hide)
{

	SetActorHiddenInGame(Hide);

	SetActorEnableCollision(!Hide);

	SetActorTickEnabled(!Hide);
}




