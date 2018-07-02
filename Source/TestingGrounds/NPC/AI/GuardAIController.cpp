// Fill out your copyright notice in the Description page of Project Settings.

#include "GuardAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "GameFramework/Actor.h"
#include "BehaviorTree/BlackboardComponent.h"

#define OUT


AGuardAIController::AGuardAIController() {
	
}

void AGuardAIController::BeginPlay()
{
	Super::BeginPlay();

	InitializeAIPerception();
	InitializePatrolingBehaviour();
}

		void AGuardAIController::InitializeAIPerception() 
		{
			AIPerception = FindComponentByClass<UAIPerceptionComponent>();

			if (!AIPerception) {
				UE_LOG(LogTemp, Error, TEXT("No AIPerception !"));
				return;
			}

			AIPerception->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &AGuardAIController::OnPerceptionUpdates);
		}

		void AGuardAIController::InitializePatrolingBehaviour()
		{
			if (!(PatrolData && PatrolingBehaviourTree))
				return;

			UseBlackboard(PatrolData, Blackboard);
			RunBehaviorTree(PatrolingBehaviourTree);
		}


void AGuardAIController::OnPerceptionUpdates(AActor * ActorPerceived, FAIStimulus Stimulus)
{
	//UE_LOG(LogTemp, Warning, TEXT("%s has seen (or not ?) %s : %i"), *GetOwner()->GetName(), *ActorPerceived->GetName(), Stimulus.IsValid())

	if (!ActorPerceived->ActorHasTag("Guard")) {
		if (Stimulus.WasSuccessfullySensed())
			Blackboard->SetValueAsObject(EnemyKey, ActorPerceived);
		else
			Blackboard->ClearValue(EnemyKey);
	}
}
