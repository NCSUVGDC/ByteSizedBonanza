// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class VGDC_MINIGAMES_API Sorter
{
public:
	Sorter();
	~Sorter();
	void exitOnError(char const *message);
	int readList(int *list);
	void sortList(int *list, int len);
	void printList(int *list, int len);
	int main();
};
