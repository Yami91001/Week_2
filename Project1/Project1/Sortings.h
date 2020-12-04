#pragma once

#include <chrono>
#include <iostream>
#include <cmath>
using namespace std;


int findMin(int* a, int n, int i);

void selectionSort(int* a, int n);

void insertionSort(int* a, int n);

void bubbleSort(int* a, int n);

void merge(int* a, int l, int r, int m);

void mergeSort(int* a, int l, int r);

int partition(int* a, int l, int r);

void quickSortIterative(int* a, int l, int r);

void heapify(int* a, int n, int i);

void heapSort(int* a, int n);

int recursiveBinarySearch(int* a, int left, int right, int key);

void binInsertion(int* a, int n);


