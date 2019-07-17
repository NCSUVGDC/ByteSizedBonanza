// Fill out your copyright notice in the Description page of Project Settings.


#include "Sorter.h"

Sorter::Sorter()
{
}

Sorter::~Sorter()
{
}

void Sorter::exitOnError(char const *message)
{
	printf("%s\n", message);
	exit(EXIT_FAILURE);
}

// Read an input list from the user (there's a
// possible buffer overflow here)
/**
int Sorter::readList(int *list)
{
	int len;
	if (scanf_s("%d", &len) != 1)
		exitOnError("Can't read input length");

	for (int i = 0; i < len; i++)
		if (scanf_s("%d", list + i) != 1)
			exitOnError("Can't read list item");

	return len;
}
*/

// Sort the given list using merge sort.
void Sorter::sortList(int *list, const int len)
{
	// A trivial list is already sorted.
	if (len <= 1)
		return;

	// Split list into two smaller lists, each about half as
	// long as the original list.

	// Length of the storage for the two half lists.
	const int alen = (len + 1) / 2;
	const int blen = len / 2;

	// Storage for the two half lists.
	int* a = new int[alen];
	int* b = new int[blen];

	// Copy the first half (alen elements) of list[] to a[]
	for (int i = 0; i < alen; i++) {
		a[i] = list[i];
	}

	// Copy the rest of list[] (the remaining blen elements) to b[]

	int idx = 0;
	for (int i = alen; i < blen; i++) {
		b[idx] = list[i];
		idx++;
	}


	// Recursively sort the two smaller lists.
	sortList(a, alen);
	sortList(b, blen);

	// Merge the two smaller lists into one sorted lists.

	// Current position in each of the lists.
	int aIdx = 0;
	int bIdx = 0;

	// Merge, Repeatedly take the next item from a[] or b[] whichever
	// is smaller, copying it to the next position in list[]
	while (aIdx + bIdx < len) {
		if (aIdx == blen
			|| ((aIdx < alen) && (a[aIdx] < b[bIdx]))) {
			list[aIdx + bIdx] = a[aIdx];
			aIdx = aIdx + 1;
		}
		else {
			list[aIdx + bIdx] = b[bIdx];
			bIdx = bIdx + 1;
		}
	}
}

// Print out a (hopefully sorted) list.
void Sorter::printList(int *list, int len)
{
	for (int i = 0; i < len; i++) {
		printf("%d", list[i]);
		// fencepost behavior.
		if (i + 1 < len)
			printf(" ");
	}
	printf("\n");
}

int Sorter::main()
{
	int list[] = { 5, 9, 1, 2, 4, 3, 8, 6, 7, 0 };

	int len = sizeof(list) / sizeof(list[0]);
	sortList(list, len);
	printList(list, len);

	return 0;
}