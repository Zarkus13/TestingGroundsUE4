// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "BehaviorTree/BTTaskNode.h"
#include "GuardAIController.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDS_API AGuardAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AGuardAIController();

protected:
	UAIPerceptionComponent * AIPerception = nullptr;
	UBlackboardComponent* Blackboard = nullptr;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	FName EnemyKey;

	UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
	UBlackboardData* PatrolData = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Blackboard")
	UBehaviorTree* PatrolingBehaviourTree = nullptr;
	
private:
	void BeginPlay();
		void InitializeAIPerception();
		void InitializePatrolingBehaviour();

	UFUNCTION()
	void OnPerceptionUpdates(AActor* ActorPerceived, FAIStimulus Stimulus);
};
