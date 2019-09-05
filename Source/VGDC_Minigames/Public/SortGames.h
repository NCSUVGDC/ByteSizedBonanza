// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UserWidget.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SortGames.generated.h"

UCLASS()
class VGDC_MINIGAMES_API ASortGames : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASortGames();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void exitOnError(char const *message);

	UFUNCTION(BlueprintCallable, Category = "Sorting")
	TArray<UUserWidget*> sortList(TArray<UUserWidget*> list, FName sortType);

	UFUNCTION(BlueprintCallable, Category = "Sorting")
	void printList(TArray<UUserWidget*> list);

};
