#include "Sortings.h"

void inputArray(int*& a, int& n)
{
	cout << "Nhap vao so phan tu cua mang: ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]= ";
		cin >> a[i];
	}
}

void printArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]= " << a[i] << endl;
	}
}

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

void selectionSort(int*& a, int n) {
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		idx = findMin(a, n, i);
		swap(a[i], a[idx]);
	}
}

void insertionSort(int*& a, int n)
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

void bubbleSort(int*& a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j + 1] < a[j])
				swap(a[j], a[j + 1]);
		}
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

int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int i = (l - 1);

	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

void quickSort(int arr[], int l, int r)
{
	if (l >= r)
		return;
	int pi = partition(arr, l, r);
	quickSort(arr, l, pi - 1);
	quickSort(arr, pi + 1, r);
}

void quickSortIterative(int arr[], int l, int h)
{
	// Create an auxiliary stack 
	int k = h - l + 1;
	double *stack=new double[k];

	// initialize top of stack 
	int top = -1;

	// push initial values of l and h to stack 
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty 
	while (top >= 0) {
		// Pop h and l 
		h = stack[top--];
		l = stack[top--];

		// Set pivot element at its correct position 
		// in sorted array 
		int p = partition(arr, l, h);

		// If there are elements on left side of pivot, 
		// then push left side to stack 
		if (p - 1 > l) {
			stack[++top] = l;
			stack[++top] = p - 1;
		}

		// If there are elements on right side of pivot, 
		// then push right side to stack 
		if (p + 1 < h) {
			stack[++top] = p + 1;
			stack[++top] = h;
		}
	}
}

