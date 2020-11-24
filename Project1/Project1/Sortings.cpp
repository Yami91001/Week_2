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
	int n2 = r - l;
	L = new int[n1];
	R = new int[n2];
	for (int i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (int i = 0; i < n2; i++)
		R[i] = a[m + 1 + i];


}
