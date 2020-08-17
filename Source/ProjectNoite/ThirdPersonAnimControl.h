	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "UObject/Class.h"
#include "ThirdPersonAnimControl.generated.h"
/**
 * 
 */
UCLASS(transient, Blueprintable, hideCategories=AnimInstance, BlueprintType)
class UThirdPersonAnimControl: public UAnimInstance
{
	GENERATED_BODY()
public:
	UThirdPersonAnimControl();

	UPROPERTY(EditAnywhere, Category = Players, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<class AActor> ProjectileBlastBlueprint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
		bool IsInAir;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
		bool IsCrouching;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Generic")
		bool IsPunching;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
		void SpawnProjectileBlast(FVector Loc, FRotator Rot, AActor* &SpawnedActorRef);

	UFUNCTION(BlueprintCallable)
		void TriggerPunch();
};
