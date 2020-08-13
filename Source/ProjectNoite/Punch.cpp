// Fill out your copyright notice in the Description page of Project Settings.


#include "Punch.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"


void UPunch::PunchAction(UCharacterMovementComponent* CharacterMoveComp) {
	
}

ACharacter* UPunch::BlastAction(UObject* WorldContextObject, UCharacterMovementComponent* CharacterMoveComp) {
	CharacterMoveComp->StopMovementImmediately();
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject);
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(World, 0);
	//World->SpawnActor(BlastTransfrom);
	
	return PlayerCharacter;
}