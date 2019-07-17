// Fill out your copyright notice in the Description page of Project Settings.


#include "SortGames.h"

// Sets default values
ASortGames::ASortGames()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASortGames::BeginPlay()
{
	Super::BeginPlay();

	//TArray<FString> list;
	//list.Add("Moo");
	//list.Add("Off");
	//list.Add("Zane");
	//list.Add("Lampoon");
	//list.Add("Kuzco");
	//list.Add("Zoologist");
	//list.Add("Nani");
	//list.Add("Mammy");

	//list = sortList(list);
	//printList(list);
}

// Called every frame
void ASortGames::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASortGames::exitOnError(char const *message)
{
	UE_LOG(LogTemp, Error, TEXT("%s\n"), message);
	exit(EXIT_FAILURE);
}

// Sort the given list using merge sort.
TArray<FString> ASortGames::sortList(TArray<FString> list)
{
	// A trivial list is already sorted.
	if (list.Num() < 2) {
		return list;
	}

	// Split list into two smaller lists, each about half as
	// long as the original list.

	// Length of the storage for the two half lists.
	int mid = list.Num() / 2;
	int alen = list.Num() / 2;
	int blen = (list.Num() + 1) / 2;

	// Storage for the two half lists.
	TArray<FString> a;
	TArray<FString> b;

	// Copy the first half (alen elements) of list[] to a[]
	int start = 0;
	int end = mid - 1;
	for (int i = 0; i <= end - start; i++) {
		a.Add(list[i + start]);
	}

	// Copy the rest of list[] (the remaining blen elements) to b[]
	start = mid;
	end = list.Num() - 1;
	for (int i = 0; i <= end - start; i++) {
		b.Add(list[i + start]);
	}


	// Recursively sort the two smaller lists.
	a = sortList(a);
	b = sortList(b);

	// Merge the two smaller lists into one sorted lists.

	// Current position in each of the lists.
	int leftIndex = 0;
	int rightIndex = 0;

	// Merge, Repeatedly take the next item from a[] or b[] whichever
	// is smaller, copying it to the next position in list[]
	while (leftIndex + rightIndex < list.Num()) {
		if (rightIndex == blen
			|| (leftIndex < alen && (a[leftIndex].Compare(b[rightIndex]) < 0))) {
			//UE_LOG(LogTemp, Error, TEXT("FIRST MERGE, changing %s to %s"), list[leftIndex + rightIndex], a[leftIndex]);
			list[leftIndex + rightIndex] = a[leftIndex];
			leftIndex = leftIndex + 1;
		}
		else {
			//UE_LOG(LogTemp, Error, TEXT("SECOND MERGE, changing %s to %s"), list[leftIndex + rightIndex], b[rightIndex]);
			list[leftIndex + rightIndex] = b[rightIndex];
			rightIndex = rightIndex + 1;
		}
	}
	return list;
}

// Print out a (hopefully sorted) list.
void ASortGames::printList(TArray<FString> list)
{
	for (int i = 0; i < list.Num(); i++) {
		//printf("%d", list[i]);
		UE_LOG(LogTemp, Log, TEXT("%s"), *list[i]);
		// fencepost behavior.
		//if (i + 1 < list.Num())
			//UE_LOG(LogTemp, Log, TEXT(" "));
	}
	UE_LOG(LogTemp, Warning, TEXT("\n"));
}