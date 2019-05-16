#include<algorithm>
#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;
int gArraySize = 0;

/**********************ArrayDivide2ByPivot****************************/
/*
给定一个数组arr，和一个数num，请把小于等于num的数放在数
组的左边，大于num的数放在数组的右边。
要求额外空间复杂度O(1)，时间复杂度O(N)
*/
void swap(int arr[], int i, int j) {
	if (i == j)//i==j时会令元素变成0
		return;
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

/*
思想：荷兰国旗问题的简化版
*/
void ArrayDivide2ByPivot(int arr[], int n, int pivot)
{
	int less = -1;
	int l = 0;
	while (l < n )
	{
		if (arr[l] <= pivot)
			swap(arr, ++less, l++);
		else
			l++;
	}
}

/**********************ArrayDivide2ByPivot****************************/

//对数器测试
//此题无法使用对数器，因为在满足题目要求的条件下，数字顺序不一样
void comparator(int arr[], int n , int pivot)
{
	int* help = new int[n];
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] <= pivot)
			* help++ = arr[i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > pivot)
			* help++ = arr[i];
	}
	for (int i = n-1; i>=0; --i)
	{
		arr[i] = *(--help);
	}
}

int* generateRandomArray(int maxSize, int maxValue)
{
	unsigned seed = time(0);
	srand(seed);
	gArraySize = (int)(rand() % (maxSize + 1));
	int* arr = new int[gArraySize];
	for (int i = 0; i < gArraySize; ++i) {
		arr[i] = (int)(rand() % (maxValue + 1));
	}
	return arr;
}

int* copyArray(int arr[])
{
	if (arr == NULL) {
		return NULL;
	}
	int* res = new int[gArraySize];
	for (int i = 0; i < gArraySize; i++) {
		res[i] = arr[i];
	}
	return res;
}

bool isEqual(int arr1[], int arr2[])
{
	if ((arr1 == NULL && arr2 != NULL) || (arr1 != NULL && arr2 == NULL)) {
		return false;
	}
	if (arr1 == NULL && arr2 == NULL) {
		return true;
	}
	for (int i = 0; i < gArraySize; i++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}

void printArray(int arr[], int size)
{
	if (arr == NULL) {
		return;
	}
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char** argv)
{
	int maxSize = 100;
	int maxValue = 100;
	int* arr1 = generateRandomArray(maxSize, maxValue);
	int* arr2 = copyArray(arr1);
	ArrayDivide2ByPivot(arr1, gArraySize,55);
	comparator(arr2, gArraySize,55);
	cout << "快速算法的结果：" << endl;
	printArray(arr1, gArraySize);
	cout << "慢速算法的结果：" << endl;
	printArray(arr2, gArraySize);
	system("pause");
	return 0;
}
