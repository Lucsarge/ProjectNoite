// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonAnimControl.h"
#include "UObject/Class.h"
#include "Engine/Blueprint.h"
#include "Engine/World.h"

UThirdPersonAnimControl::UThirdPersonAnimControl()
{
	Speed = 0.0;
	IsInAir = false;
	IsCrouching = false;
	IsPunching = false;

	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Meshes/ProjectileBlast.ProjectileBlast'"));
	if (ItemBlueprint.Object) {
		ProjectileBlastBlueprint = (UClass*)ItemBlueprint.Object->GeneratedClass;
		UE_LOG(LogTemp, Warning, TEXT("It Added the generated class"))
	}
}

void UThirdPersonAnimControl::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);
	AActor* OwningActor = GetOwningActor();

	if (OwningActor != nullptr) {
		Speed = OwningActor->GetVelocity().Size();
	}
}

void UThirdPersonAnimControl::ShowBlastBlueprint(FVector Loc, FRotator Rot, AActor* &SpawnedActorRef) {
	if (ProjectileBlastBlueprint != nullptr) {
		// I think this was crashing when it was outside of this if statement
		AActor* OwningActor = GetOwningActor();
		FActorSpawnParameters Params;
		AActor* SpawnBlast = GetWorld()->SpawnActor<AActor>(ProjectileBlastBlueprint.Get(), Loc, Rot, Params);
		SpawnedActorRef = SpawnBlast;
		UE_LOG(LogTemp, Warning, TEXT("Projectile Blast isn't Null"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Projectile Blast is Null"));
	}
}

void UThirdPersonAnimControl::ReturnActor(bool &ReturnActorVariable) {
	ReturnActorVariable = false;
}