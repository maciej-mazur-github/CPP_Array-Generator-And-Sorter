#include <cstdlib>
#include <iostream>
#include <ctime>
#include <utility>
#include "array_generator_and_sorter.h"

using namespace std;



void ArrayGeneratorSorter::printSortingOptions()
{
	cout << "\nChoose one of below 3 sorting methods:\n"
		<< "\t1) Bubble sort\n"
		<< "\t2) Selection sort\n"
		<< "\t3) Insertion sort\n\n"
		<< "\tWhat is your choice? (numbers 1-3 allowed only): ";
}


void ArrayGeneratorSorter::sortingAlgoritmChoice(int arraySize, int arr[])
{
	printSortingOptions();
	int choice;
	cin >> choice;

	while (choice < 1 || choice > 3)
	{
		cout << "\tWrong number provided. Numbers 1-3 allowed only.\n\n";
		printSortingOptions();
		cin >> choice;
	}

	cout << "Array status before sorting:\n\t";
	printArray(arraySize, arr);

	switch (choice)
	{
	case 1:
		bubbleSort(arraySize, arr);
		break;
	case 2:
		selectionSort(arraySize, arr);
		break;
	case 3:
		insertionSort(arraySize, arr);
	}

	cout << "Array status after sorting:\n\t";
	printArray(arraySize, arr);
}


void ArrayGeneratorSorter::insertionSort(int arraySize, int arr[])
{
	int insertedElement;
	int j;

	for (int i = 1; i < arraySize; i++)
	{
		insertedElement = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > insertedElement)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = insertedElement;
	}
}


void ArrayGeneratorSorter::selectionSort(int arraySize, int arr[])
{
	int min = 0;

	for (int i = 0; i < arraySize; i++)
	{
		min = minElementIndex(i, arraySize, arr);

		if (min != i)
		{
			swap(arr[i], arr[min]);
		}
	}
}


int ArrayGeneratorSorter::minElementIndex(int startIndex, int arraySize, int arr[])
{
	int min = startIndex;

	for (int i = startIndex + 1; i < arraySize; i++)
	{
		if (arr[i] < arr[min])
		{
			min = i;
		}
	}


	return min;
}


void ArrayGeneratorSorter::bubbleSort(int arraySize, int arr[])
{
	for (int i = 0; i < arraySize; i++)
	{
		for (int j = 0; j < arraySize - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

int* ArrayGeneratorSorter::generateArrayManualFillIn(int arraySize)
{
	int* generatedArray = new int[arraySize];
	userArrayManualFillIn(arraySize, generatedArray);
	return generatedArray;
}


int* ArrayGeneratorSorter::generateArrayAutomaticFillIn(int arraySize)
{
	int* generatedArray = new int[arraySize];
	userArrayAutomaticFillIn(arraySize, generatedArray);
	return generatedArray;
}



void ArrayGeneratorSorter::userArrayAutomaticFillIn(int arraySize, int userArray[])
{
	srand(time(0));

	for (int i = 0; i < arraySize; i++)
	{
		userArray[i] = rand() % 101;      // results in range 0 - 100 both sides inclusive
	}
}


void ArrayGeneratorSorter::userArrayManualFillIn(int arraySize, int userArray[])
{
	int element;

	for (int i = 0; i < arraySize; i++)
	{
		cout << "\tEnter element at position " << i << ": ";
		cin >> element;
		userArray[i] = element;
	}
}


void ArrayGeneratorSorter::printArray(int arraySize, int arr[])
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << "\t";
	}

	cout << endl;
}