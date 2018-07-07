// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FiringComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTINGGROUNDS_API UFiringComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFiringComponent();

	void Fire(FRotator Direction);

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void SetGun(class AGun* Gun);

protected:
	class AGun* Gun = nullptr;

};
