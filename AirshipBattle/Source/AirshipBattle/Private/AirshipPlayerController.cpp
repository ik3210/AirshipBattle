// Fill out your copyright notice in the Description page of Project Settings.

#include "AirshipPlayerController.h"
#include "AirshipBattle.h"


//Tick
//Super
//AimTowardsCrosshair



void AAirshipPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledAirship = GetControlledAirship();
	if (!ControlledAirship)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerController Not Possessing An Airship"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController Possessing: %s"), *(ControlledAirship->GetName()));
	}
}

void AAirshipPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

AAirship* AAirshipPlayerController::GetControlledAirship() const 
{
	return Cast<AAirship>(GetPawn());
}

void AAirshipPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledAirship()) { return; }

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *HitLocation.ToString());
		// TODO Tell controlled airship to aim at this point
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool AAirshipPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	//find crosshair position on screen (pixels)
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());
	//deproject screen position of crosshair to world direction
	//linetrace along look direction - see what we hit.
	return true;
}
