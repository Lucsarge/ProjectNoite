// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Punch.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNOITE_API UPunch : public UBlueprintFunctionLibrary 
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Punch Action")
		static void PunchAction(UCharacterMovementComponent* CharacterMoveComp);

	UFUNCTION(BlueprintCallable, Category = "Blast Action", meta=(WorldContext="WorldContextObject", UnsafeDuringActorConstruction="true"))
		static ACharacter* BlastAction(UObject* WorldContextObject, UCharacterMovementComponent* CharacterMoveComp);
};
