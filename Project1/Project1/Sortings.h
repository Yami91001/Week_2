#pragma once

#include <chrono>
#include <iostream>
#include <cmath>
using namespace std;




void inputArray(int*& a, int& n);

void inputArray(int*& a, int& n);

void printArray(int* a, int n);

int findMin(int* a, int n, int i);

void selectionSort(int*& a, int n);

void insertionSort(int*& a, int n);

void bubbleSort(int*& a, int n);

void merge(int* a, int l, int r, int m);

void mergeSort(int* a, int l, int r);

int partition(int arr[], int low, int high);

void quickSort(int arr[], int low, int high);

void quickSortIterative(int arr[], int l, int h);
