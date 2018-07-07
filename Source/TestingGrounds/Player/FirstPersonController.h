// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FirstPersonController.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AFirstPersonController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.5f;
	
protected:
	void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Fire")
	void OnFire();
	
private:
	class UFiringComponent* FiringComponent = nullptr;

};
