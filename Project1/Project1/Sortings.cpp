#include "Sortings.h"

int findMin(int* a, int n, int i) {
	int min = a[i], index = i;
	for (int j = i + 1; j < n; j++)
	{
		if (a[j] < min) {
			min = a[j];
			index = j;
		}
	}
	return index;
}

void selectionSort(int* a, int n) {
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		idx = findMin(a, n, i);
		swap(a[i], a[idx]);
	}
}

void insertionSort(int* a, int n)
{
	int temp = 0, j = 0;
	for (int i = 1; i < n; i++)
	{
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

void bubbleSort(int* a, int n)
{
	
	for (int i = 0; i < n - 1; i++)
	{
		bool swapped = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j + 1] < a[j])
			{
				swap(a[j], a[j + 1]);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
	}
}

void merge(int* a, int l, int r, int m)
{
	int* L, * R;
	int n1 = m - l + 1;
	int n2 = r - m;
	L = new int[n1];
	R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int i = 0; i < n2; i++)
		R[i] = a[m + 1 + i];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		a[k] = L[i];
		k++;
		i++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		k++;
		j++;
	}
}

void mergeSort(int* a, int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r - 1) / 2;
	mergeSort(a, l, m);
	mergeSort(a, m + 1, r);
	merge(a, l, r, m);
}

int partition(int* a, int l, int r)
{
	int pivot = a[l], i = l + 1, temp;
	for (int j = l+1; j <= r; j++)
	{
		if (a[j] < pivot)
		{
			swap(a[i], a[j]);
			i++;
		}
	}
	swap(a[l], a[i - 1]);
	return i-1;
}


void quickSortIterative(int* a, int l, int r)
{
	int k = r - l + 1;
	int* stack = new int[k];
	int top = -1;
	stack[++top] = l;
	stack[++top] = r;
	while (top >= 0) {
		r = stack[top--];
		l = stack[top--];
		int p = partition(a, l, r);
		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}
		if (p + 1 < r) {
			stack[++top] = p + 1;
			stack[++top] = r;
		}
	}
}

void heapify(int* a, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}

void heapSort(int* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(a, n, i);
	for (int i = n - 1; i > 0; i--) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

int recursiveBinarySearch(int* a, int left, int right, int key) {
	int m = 0;
	if (left <= right) {
		m = left + (right - left) / 2;
		if (a[m] == key)
			return m + 1;
		if (a[m] < key)
			return recursiveBinarySearch(a, m + 1, right, key);
		if (a[m] > key)
			return recursiveBinarySearch(a, left, m - 1, key);
	}
	else
		return(key > a[left]) ? left + 1 : left;
}

void binInsertion(int* a, int n)
{
	int temp = 0, j = 0, sent = 0;
	for (int i = 1; i < n; i++)
	{
		j = i - 1;
		temp = a[i];
		sent = recursiveBinarySearch(a, 0, j, temp);
		while (j >= sent)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}
