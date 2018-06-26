// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Classes/AIController.h"
#include "PatrollingComponent.h"



EBTNodeResult::Type NoPatrollingComponentFound(UBehaviorTreeComponent& OwnerComp);
EBTNodeResult::Type PatrolToNextWaypoint(UBehaviorTreeComponent&, UPatrollingComponent*, struct FBlackboardKeySelector, struct FBlackboardKeySelector);

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	auto PatrollingComponent = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrollingComponent>();

	if (!PatrollingComponent)
		return NoPatrollingComponentFound(OwnerComp);
	else
		return PatrolToNextWaypoint(
			OwnerComp,
			PatrollingComponent,
			WaypointIndex,
			NextWaypoint
		);
}

		EBTNodeResult::Type NoPatrollingComponentFound(UBehaviorTreeComponent& OwnerComp) {
			auto Name = OwnerComp.GetAIOwner()->GetName();
			UE_LOG(LogTemp, Error, TEXT("%s does not have a PatrollingComponent"), *Name)

			return EBTNodeResult::Failed;
		}

		EBTNodeResult::Type PatrolToNextWaypoint(UBehaviorTreeComponent& OwnerComp, UPatrollingComponent* PatrollingComponent, struct FBlackboardKeySelector WaypointIndex, struct FBlackboardKeySelector NextWaypoint) {
			auto BlackboardComp = OwnerComp.GetBlackboardComponent();
			auto Index = BlackboardComp->GetValueAsInt(WaypointIndex.SelectedKeyName);

			auto PatrolPoints = PatrollingComponent->GetPatrolPoints();

			if (PatrolPoints.Num() > 0) {
				BlackboardComp->SetValueAsObject(NextWaypoint.SelectedKeyName, PatrolPoints[Index]);
				BlackboardComp->SetValueAsInt(WaypointIndex.SelectedKeyName, (Index + 1) % PatrolPoints.Num());
			}

			return EBTNodeResult::Succeeded;
		}