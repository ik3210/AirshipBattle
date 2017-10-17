// Copyright 2017 Richard Passe

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Airship.generated.h" //must be last include - add others before

class UAirshipBarrel; //forward declaration
class UAirshipTurret; //forward declaration
class AProjectile; //forward declaration

UCLASS()
class AIRSHIPBATTLE_API AAirship : public APawn
{
	GENERATED_BODY()

public:
//	void AimAt(FVector HitLocation);

	UFUNCTION(BLueprintCallable, Category = Firing)
	void Fire();


private:
	// Sets default values for this pawn's properties
	AAirship();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;


	//TODO remove once firing is moved to aiming component
//	UPROPERTY(EditDefaultsOnly, Category = Firing)
//		float LaunchSpeed = 10000; 

	UPROPERTY(EditDefaultsOnly, Category = Firing)
		float ReloadTimeInSeconds = 3;

	UAirshipBarrel* Barrel = nullptr; //TODO remove

	double LastFireTime = 0;

};
