// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnGates.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/Class.h"
#include "GameFramework/Character.h"
#include "MyCharacter.h"
#include "Math/Vector.h"
#include "BaseDrone.h"

// Sets default values
ASpawnGates::ASpawnGates()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set the gateMesh
	gateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	gateMesh->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> gateMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	if (gateMeshAsset.Succeeded()) {
		gateMesh->SetStaticMesh(gateMeshAsset.Object);
		gateMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	
	
}

// Called when the game starts or when spawned
void ASpawnGates::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpawnGates::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASpawnGates::SpawnDrone(UObject* worldContextObject, UClass* droneClass, int32 gateNum) {
	FActorSpawnParameters droneSpawnParams;
	FTransform thisTransform = GetActorTransform();
	FVector loc = FVector(0.0f, 0.0f, 0.0f);
	FRotator rot = FRotator(0.0f, 0.0f, 0.0f);
	UWorld* world = GEngine->GetWorldFromContextObject(worldContextObject);
	if (world) {
		ACharacter* aCharReference = UGameplayStatics::GetPlayerCharacter(world, 0);
		AMyCharacter* myCharReference;
		if (aCharReference != nullptr) {
			myCharReference = Cast<AMyCharacter>(aCharReference);
		}
		world->SpawnActor<AActor>(droneClass, thisTransform, droneSpawnParams);
	}
}