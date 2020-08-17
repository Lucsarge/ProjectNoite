// Fill out your copyright notice in the Description page of Project Settings.


#include "ThirdPersonAnimControl.h"
#include "Engine/Blueprint.h"
#include "Engine/World.h"

//Constructor
UThirdPersonAnimControl::UThirdPersonAnimControl()
{
	//Default instance variable values
	Speed = 0.0;
	IsInAir = false;
	IsCrouching = false;
	IsPunching = false;

	//Retrieve class for ProjectileBlast blueprint
	static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(TEXT("Blueprint'/Game/Meshes/ProjectileBlast.ProjectileBlast'"));
	if (ItemBlueprint.Object) {
		ProjectileBlastBlueprint = (UClass*)ItemBlueprint.Object->GeneratedClass;
		UE_LOG(LogTemp, Warning, TEXT("It Added the generated class"))
	}
}

//Override for NativeUpdateAnimation
void UThirdPersonAnimControl::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);
	AActor* OwningActor = GetOwningActor();

	

	//Constantly sets value of speed variable
	if (OwningActor != nullptr) {
		Speed = OwningActor->GetVelocity().Size();
	}

	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(-1, .01f, FColor::Blue, IsInAir ? "In Air" : "Grounded");
	}
}

//
void UThirdPersonAnimControl::SpawnProjectileBlast(FVector Loc, FRotator Rot, AActor* &SpawnedActorRef) {
	if (ProjectileBlastBlueprint != nullptr) {
		AActor* OwningActor = GetOwningActor();
		FActorSpawnParameters Params;
		AActor* SpawnBlast = GetWorld()->SpawnActor<AActor>(ProjectileBlastBlueprint.Get(), Loc, Rot, Params);
		SpawnedActorRef = SpawnBlast;
		UE_LOG(LogTemp, Warning, TEXT("Projectile Blast isn't Null"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Projectile Blast is Null"))
	}
}

//Stops motion of character and plays the animation before resuming
void UThirdPersonAnimControl::TriggerPunch() {
	
}