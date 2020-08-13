// Fill out your copyright notice in the Description page of Project Settings.


#include "GhoulEnemy.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AGhoulEnemy::AGhoulEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* EnemyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ghoul Mesh"));
	EnemyMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMeshAsset(TEXT("/Game/Enemies/Pawn_Ghoul.Pawn_Ghoul"));

	if (EnemyMeshAsset.Succeeded()) {
		EnemyMesh->SetStaticMesh(EnemyMeshAsset.Object);
		EnemyMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AGhoulEnemy::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGhoulEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGhoulEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

