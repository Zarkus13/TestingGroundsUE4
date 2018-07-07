// Fill out your copyright notice in the Description page of Project Settings.

#include "FirstPersonController.h"
#include "GameFramework/Pawn.h"
#include "Player/FiringComponent.h"

#define OUT

void AFirstPersonController::BeginPlay() {
	Super::BeginPlay();

	FiringComponent = GetPawn()->FindComponentByClass<UFiringComponent>();
}

void AFirstPersonController::OnFire() {
	if (!FiringComponent) {
		UE_LOG(LogTemp, Error, TEXT("NO FIRING COMPONENT"))
		return;
	}

	int32 ViewportWidth, ViewportHeight;
	GetViewportSize(ViewportWidth, ViewportHeight);

	FVector2D CrosshairScreenLocation =
		FVector2D(
			ViewportWidth * CrosshairXLocation,
			ViewportHeight * CrosshairYLocation
		);

	FVector WorldLocation, Direction;

	DeprojectScreenPositionToWorld(
		CrosshairScreenLocation.X,
		CrosshairScreenLocation.Y,
		OUT WorldLocation,
		OUT Direction
	);

	FiringComponent->Fire(Direction.Rotation());
}

