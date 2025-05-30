// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BikePawn.generated.h"

UCLASS()
class BIKE_API ABikePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABikePawn();

	/** Spring Arm for the front camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* FrontSpringArm;

	/** Front Camera component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FrontCamera;

	/** Spring Arm for the back camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* BackSpringArm;

	/** Back Camera component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* BackCamera;

	/**  The human skeletal mesh associated with this Vehicle */
	UPROPERTY(Category = Human, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* HumanMesh;

	/**  The bicycle skeletal mesh associated with this Vehicle */
	UPROPERTY(Category = Human, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* MainBicycleMesh;

	UPROPERTY(Category = Human, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* BicycleMesh;

	UPROPERTY(Category = Human, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UChaosWheeledVehicleMovementComponent* ChaosVehicleMovement;

	UPROPERTY(Category = Human, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterSelect")
	class USkeletalMesh* Option1;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterSelect")
	class USkeletalMesh* Option2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterSelect")
	class USkeletalMesh* Option3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterSelect")
	class USkeletalMesh* Option4;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterSelect")
	class USkeletalMesh* Option5;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterSelect")
	class USkeletalMesh* Option6;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CharacterSelect")
	class USkeletalMesh* Option7;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Steering Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* SteeringAction;

	/** Throttle Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ThrottleAction;

	/** Brake Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* BrakeAction;

	/** Handbrake Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* HandbrakeAction;

	/** Look Around Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAroundAction;

	/** Toggle Camera Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ToggleCameraAction;

	/** Reset Vehicle Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ResetVehicleAction;

	/** Wheelie Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* WheelieAction;
	
	/** Respawn Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* RespawnAction;

	/** Jump Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* JumpAction;
	
	/** Duck Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	class UInputAction* DuckAction;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	class UAnimComposite* victoryComposite;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animation")
	//class ULevelSequence* VictoryLevelSequence;


	UFUNCTION(BlueprintCallable, Category = "Speed")
	void VictorySceneAndAnimation();

	/** Keeps track of which camera is active */
	bool bFrontCameraActive = false;

	/** Keeps track of whether the vehicle is in a wheelie */
	bool bIsWheelie = false;

	UPROPERTY(EditAnywhere , BlueprintReadWrite, Category = "CheckPoint")
	FVector LastCheckPointLocation;
	
	UPROPERTY(EditAnywhere , BlueprintReadWrite, Category = "CheckPoint")
	FRotator LastCheckPointRotation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CheckPoint")
	bool reachedCheckPoint = false;

	UPROPERTY(EditAnywhere, Category = "Animation")
	class UAnimMontage* JumpUpMontage;

	UPROPERTY(EditAnywhere, Category = "Animation")
	class UAnimMontage* VictoryMontage;


	UPROPERTY(EditAnywhere, Category = "Animation")
	UAnimInstance* animInst;

public:	
	UPROPERTY(EditAnywhere, Category = "Animation")
	class UAnimMontage* JumpLoopMontage;

	UPROPERTY(EditAnywhere, Category = "Animation")
	class UAnimMontage* DuckingMontage;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float additiveSteeringValue = 0.f;//

protected:

	/** Handles steering input */
	void Steering(const struct FInputActionValue& Value);

	/** Handles throttle input */
	void Throttle(const FInputActionValue& Value);

	/** Handles brake input */
	void Brake(const FInputActionValue& Value);

	/** Handles brake start/stop inputs */
	void StartBrake(const FInputActionValue& Value);
	void StopBrake(const FInputActionValue& Value);

	/** Handles handbrake start/stop inputs */
	void StartHandbrake(const FInputActionValue& Value);
	void StopHandbrake(const FInputActionValue& Value);

	/** Handles wheelie start/stop inputs */
	void StartDuck(const FInputActionValue& Value);
	void StopDuck(const FInputActionValue& Value);

	/** Handles duck start/stop inputs */
	void StartWheelie(const FInputActionValue& Value);
	void StopWheelie(const FInputActionValue& Value);

	/** Handles look around input */
	void LookAround(const FInputActionValue& Value);

	/** Handles toggle camera input */
	void ToggleCamera(const FInputActionValue& Value);

	/** Handles reset vehicle input */
	void ResetVehicle(const FInputActionValue& Value);

	/** Handles respawn input */
	void Respawn(const FInputActionValue& Value);

	void Jump(const FInputActionValue& Value);

	/** Called when the brake lights are turned on or off */
	UFUNCTION(BlueprintImplementableEvent, Category = "Vehicle")
	void BrakeLights(bool bBraking);



public:
	UFUNCTION(BlueprintImplementableEvent, Category = "Vehicle")
	void BikeInAir();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Physics")
	bool isBikeInAir = false;

	/** Returns the cast Chaos Vehicle Movement subobject */
	FORCEINLINE const UChaosWheeledVehicleMovementComponent* GetChaosVehicleMovement() const { return ChaosVehicleMovement; }

	FORCEINLINE const bool getIsWheelie() const { return bIsWheelie; }
};
