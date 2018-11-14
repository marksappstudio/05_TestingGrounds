// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UActorPool;

UCLASS()
class S05_TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();
    
     UFUNCTION(BlueprintCallable, Category = "Weapon")
    void PlaceActors(TSubclassOf<AActor> ToSpawn, int32 MinSpawn = 1, int32 MaxSpawn = 1, float Radius = 500, float MinScale = 1, float MaxScale = 1);
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    
    UPROPERTY(EditDefaultsOnly, Category = "Spawning")
    FVector MinExtent;
    UPROPERTY(EditDefaultsOnly, Category = "Spawning")
    FVector MaxExtent;
    
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    UFUNCTION(BlueprintCallable, Category = "Pool")
    void SetPool (UActorPool* Pool);

private:
    
    void PositionNavMeshBoundsVolume();
    
    bool FindEmptyLocation(FVector& OutLocation, float Radius);
    
    void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float Rotation, float Scale);
    
    bool CanSpawnAtLocation(FVector Location, float Radius);
    
    UActorPool* Pool;
    
    AActor* NavMeshBoundsVolume;
	
};
