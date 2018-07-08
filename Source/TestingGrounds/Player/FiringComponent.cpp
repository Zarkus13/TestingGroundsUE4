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


void UFiringComponent::Fire(FVector LocationToShoot)
{
	Gun->Fire(LocationToShoot);
}

void UFiringComponent::SetGun(AGun * Gun)
{
	this->Gun = Gun;
}
