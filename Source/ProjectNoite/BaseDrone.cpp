// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDrone.h"
#include "TimerManager.h"

// Sets default values
ABaseDrone::ABaseDrone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Assign and attach static drone mesh
	droneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	droneMesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> droneMeshAsset(TEXT("StaticMesh'/Game/Meshes/DroneMesh.DroneMesh'"));
	if (droneMeshAsset.Succeeded()) {
		droneMesh->SetStaticMesh(droneMeshAsset.Object);
		droneMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	//Set Collider around drone
	sphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Proximity Sphere"));
	sphereCollision->SetupAttachment(droneMesh);
	sphereCollision->SetSphereRadius(55.0f);
	sphereCollision->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void ABaseDrone::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseDrone::Tick(float DeltaTime)
{
	FVector newLocation = GetActorLocation();
	float newXDistance = DeltaTime * 600.0f;
	newLocation += newXDistance * GetActorForwardVector();
	SetActorLocation(newLocation);
	
}

