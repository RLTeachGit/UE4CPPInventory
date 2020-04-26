// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryKeyCard.h"
#include "Inventory.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

//Custom Log for clarity, add this where you need to use it
DECLARE_LOG_CATEGORY_EXTERN(CaptainsLog, Log, All);



AInventoryKeyCard::AInventoryKeyCard() : AInventoryPickup() //Call parent constructor
{
	DynMatInstance = NULL; //Reset so we can check if its already set up
}

void AInventoryKeyCard::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	UStaticMeshComponent* tMesh = FindComponentByClass< UStaticMeshComponent>();
	if (IsValid(tMesh) && IsValid(BaseMaterial))
	{
		if (DynMatInstance == NULL) //Only do this once
		{
			DynMatInstance = tMesh->CreateDynamicMaterialInstance(0, BaseMaterial); //Make Material Instance & Store
		}
		if (IsValid(DynMatInstance))
		{
			DynMatInstance->SetVectorParameterValue("Base Color", Colour); //Set Colour
			tMesh->SetMaterial(0, DynMatInstance);	//Set Material in mesh
		}
		else
		{
			UE_LOG(CaptainsLog, Error, TEXT("DynMatInstance")); //Log Entry
		}
	}
	else
	{
		UE_LOG(CaptainsLog, Error, TEXT("No Mesh")); //Log Entry
	}
}
