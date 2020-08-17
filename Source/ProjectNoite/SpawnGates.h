// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "SpawnGates.generated.h"

UCLASS()
class PROJECTNOITE_API ASpawnGates : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASpawnGates();

	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* gateMesh;

	UFUNCTION(BlueprintCallable, meta = (WorldContext = "worldContextObject", UnsafeDuringActorConstruction = "true"))
		void SpawnDrone(UObject* worldContextObject, UClass* droneClass, int32 gateNum);

	
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
