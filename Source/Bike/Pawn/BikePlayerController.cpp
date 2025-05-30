// Fill out your copyright notice in the Description page of Project Settings.


#include "BikePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "BikePawn.h"
#include "Bike/HUD/BicycleHUD.h"



void ABikePlayerController::BeginPlay()
{
	Super::BeginPlay();

	BikeHUD = Cast<ABicycleHUD>(GetHUD());
}

void ABikePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}

void ABikePlayerController::Tick(float Delta)
{
	Super::Tick(Delta);

	if (IsValid(VehiclePawn) )
	{
		//VehicleUI->UpdateSpeed(VehiclePawn->GetChaosVehicleMovement()->GetForwardSpeed());
		//VehicleUI->UpdateGear(VehiclePawn->GetChaosVehicleMovement()->GetCurrentGear());
	}

	if (BikeHUD)
	{
		BikeHUD->Speed = VehiclePawn->GetVelocity().Length();
	}


}

void ABikePlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// get a pointer to the controlled pawn
	VehiclePawn = CastChecked<APawn>(InPawn);
}

void ABikePlayerController::StartScene() {
	DisableInput(this);
	FTimerHandle countdownTimerHandle;
	GetWorldTimerManager().SetTimer(countdownTimerHandle, this, &ABikePlayerController::ShowGameWidget, 5.0f, false);
}

void ABikePlayerController::ShowGameWidget() {
	if (BikeHUD)
	{
		BikeHUD->ShowTimeWidget();
	}
}