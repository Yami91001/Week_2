#include "Sortings.h"
#include "GA.h"

void main() {
	FILE* f1;
	fopen_s(&f1, "time.txt", "w+");
	if (f1 == NULL)
		return;
	fprintf(f1, "%s \n", "Sortings: 0= Selection Sort, 1= Insertion Sort, 2= Bubble Sort, 3= Merge Sort, 4= Quick Sort");
	fprintf(f1, "%s \n", "Sortings: 5= Heap Sort, 6= Binary Insertion Sort");
	fprintf(f1, "%s \t %s \t %s \t %s \n", "Sortings", "Data Order", "Data Size", "Duration");
	int* a, n;
	int dataSize[5] = { 3000,10000,30000,100000,300000 };
	int dataOrder[4] = { 0,1,2,3 };
	int duration = 0;
	n = dataSize[4];
	a = new int[n];
	for (int i = 0; i < 7; i++)//Sortings A
	{
		for (int j = 0; j < 4; j++)//Data Oder
		{
			for (int k = 0; k < 5; k++)//Data Size
			{
				n = dataSize[k];
				a = new int[n];
				GenerateData(a, n, j);
				auto start = std::chrono::high_resolution_clock::now();
				switch (i)
				{
				case 0:
					selectionSort(a, n);
					break;
				case 1:
					insertionSort(a, n);
					break;
				case 2:
					bubbleSort(a, n);
					break;
				case 3:
					mergeSort(a, 0, n - 1);
					break;
				case 4:
					quickSortIterative(a, 0, n - 1);
					break;
				case 5:
					heapSort(a, n);
					break;
				case 6:
					binInsertion(a, n);
					break;
				}
				auto end = std::chrono::high_resolution_clock::now();
				duration = std::chrono::duration_cast<std::chrono::milliseconds>
					(end - start).count();
				printf("%d %d %d %d\n", i, j, k, duration);
				fprintf_s(f1, "%d \t %9d \t %13d \t \t \t %d ", i, j, k, duration);
				fprintf_s(f1, "\n");
				delete[]a;
			}
		}
	}
	
}




