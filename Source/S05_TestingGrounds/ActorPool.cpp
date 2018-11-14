// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorPool.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"



// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor* UActorPool::Checkout()
{
    UE_LOG(LogTemp, Warning, TEXT("[%s] Checkout."), *GetName());
    return nullptr;
}

void UActorPool::Return(AActor* ActorToReturn)
{
    if (ActorToReturn == nullptr)
    {
    UE_LOG(LogTemp, Warning, TEXT("[%s] Returned null actor."), *GetName());
    }
    UE_LOG(LogTemp, Warning, TEXT("[%s] Actor returned: {%s}."), *GetName(), *this->GetName());
}

void UActorPool::Add(AActor* ActorToAdd)
{
    if (ActorToAdd == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("[%s] Added null actor."), *GetName());
    }
    UE_LOG(LogTemp, Warning, TEXT("[%s] Actor added: {%s}."), *GetName(), *ActorToAdd->GetName());
    
}
