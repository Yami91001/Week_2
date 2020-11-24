#include "Sortings.h"

void main() {
	int* a, n;
	inputArray(a, n);
	bubbleSort(a, n);
	printArray(a, n);
	delete[]a;
}