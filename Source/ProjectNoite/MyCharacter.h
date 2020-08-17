// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Containers/Array.h"
#include "SpawnGates.h"
#include "MyCharacter.generated.h"

UCLASS()
class PROJECTNOITE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	UPROPERTY(BlueprintReadWrite)
		TArray<ASpawnGates*> spawnGateCollection;

	UFUNCTION(BlueprintCallable)
		void AddSpawnGate(ASpawnGates* spawnGate);

	UPROPERTY(BlueprintReadOnly)
		int32 maxGates;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
