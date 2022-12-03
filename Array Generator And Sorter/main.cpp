#include <cstdlib>
#include <iostream>
#include "array_generator_and_sorter.h"


using namespace std;

int main(void)
{
	int testArray[10];

	//ArrayGeneratorSorter::userArrayManualFillIn(10, testArray);
	//ArrayGeneratorSorter::userArrayAutomaticFillIn(10, testArray);
	//int* automaticArray = ArrayGeneratorSorter::generateArrayManualFillIn(7);
	int* automaticArray = ArrayGeneratorSorter::generateArrayAutomaticFillIn(7);
	ArrayGeneratorSorter::printArray(7, automaticArray);
}