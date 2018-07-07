// Fill out your copyright notice in the Description page of Project Settings.

#include "FiringComponent.h"
#include "Weapon/Gun.h"


// Sets default values for this component's properties
UFiringComponent::UFiringComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UFiringComponent::Fire(FRotator Direction)
{
	UE_LOG(LogTemp, Warning, TEXT("Fire ! Gun : %s"), *Gun->GetName())

	Gun->Fire(Direction);
}

void UFiringComponent::SetGun(AGun * Gun)
{
	this->Gun = Gun;
}
