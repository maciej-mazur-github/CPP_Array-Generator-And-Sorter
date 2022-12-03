#pragma once

class ArrayGeneratorSorter
{
public:
	static void userArrayManualFillIn(int arraySize, int arr[]);
	static void userArrayAutomaticFillIn(int arraySize, int arr[]);
	static int* generateArrayManualFillIn(int arraySize);
	static int* generateArrayAutomaticFillIn(int arraySize);
	static void sortingAlgoritmChoice(int arraySize, int arr[]);
	static void printArray(int arraySize, int arr[]);
private:
	static void printSortingOptions();
	static int minElementIndex(int startIndex, int arraySize, int arr[]);
	static void bubbleSort(int arraySize, int arr[]);
	static void selectionSort(int arraySize, int arr[]);
	static void insertionSort(int arraySize, int arr[]);
};