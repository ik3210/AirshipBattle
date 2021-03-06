// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AirshipPlayerController.generated.h" //must be last include

class UAirshipAimingComponent;

/**
 * Player camera controls and crosshair
 */
UCLASS()
class AIRSHIPBATTLE_API AAirshipPlayerController : public APlayerController
{
	GENERATED_BODY()


protected:

		UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UAirshipAimingComponent* AimingComponentReference);

		UFUNCTION()
		void OnPossessedAirshipDeath();

private:
	
	void SetPawn(APawn * InPawn);

	//BEGINPLAY
	virtual void BeginPlay() override;


	//TICK
	virtual void Tick(float DeltaTime) override;

	//Start the airship moving the cannon so a shot would hit where the crosshair intersects the world
	void AimTowardsCrosshair();
	
	//return an out parameter - true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.4;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 10000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
