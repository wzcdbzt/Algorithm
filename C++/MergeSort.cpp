#include<algorithm>
#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;
int gArraySize = 0;
void mergeSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void Merge(int arr[], int l, int m, int r);

/**********************Bubble Sort****************************/

void swap(int arr[], int i, int j) {
	if (i == j)//i==j时会令元素变成0
		return;
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

/*
时间复杂度O(N*logN)，额外空间复杂度O(N)
T(N)=2T(N/2)+O(N)
思想：先左侧排好序，再右侧排好序，再利用外排的方式排好序
准准一个辅助数组，遍历左右侧，谁小填谁
*/
void mergeSort(int arr[], int n)
{
	if (arr == NULL || n < 2)
	{
		return;
	}
	mergeSort(arr, 0, n - 1);
}

void mergeSort(int arr[], int l, int r)
{
	if (l == r) {
		return;
	}
	int mid = l + ((r - l) >> 1);//L和R中点位置(L+R)/2
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	Merge(arr, l, mid, r);
}

void Merge(int arr[], int l, int m, int r)
{
	int* help = new int[r - l + 1];//L到R有多少元素
	int i = 0;
	int p1 = l;
	int p2 = m + 1;
	//谁小填谁
	while (p1 <= m && p2 <= r)
	{
		help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	}
	//两个必有且只有一个越界
	while (p1 <= m)
	{
		help[i++] = arr[p1++];
	}
	while (p2 <= r)
	{
		help[i++] = arr[p2++];
	}
	//排好序在填回原数组
	for (i = 0; i < r - l + 1; i++)
	{
		arr[l + i] = help[i];
	}
}


/**********************Bubble Sort****************************/

//对数器测试
void comparator(int arr[], int n)
{
	sort(arr, arr + n);
}

int* generateRandomArray(int maxSize, int maxValue)
{
	unsigned seed = time(0);
	srand(seed);
	gArraySize = (int)(rand() % (maxSize + 1));
	int* arr = new int[gArraySize];//[0~maxSize]个大小的size
	for (int i = 0; i < gArraySize; ++i) {
		arr[i] = (int)(rand() % (maxValue + 1));//元素值[0~maxValue]个大小值
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
	int testTime = 5000;
	int maxSize = 1000;
	int maxValue = 1000;
	bool succeed = true;
	for (int i = 0; i < testTime; i++) {
		int* arr1 = generateRandomArray(maxSize, maxValue);
		int* arr2 = copyArray(arr1);
		mergeSort(arr1, gArraySize);
		comparator(arr2, gArraySize);
		if (!isEqual(arr1, arr2)) {
			succeed = false;
			cout << (succeed ? "Nice!\n" : "Fucking fucked!\n");
			cout << "绝对正确的结果：" << endl;
			printArray(arr2, gArraySize);
			cout << "自己算法的结果：" << endl;
			printArray(arr1, gArraySize);
			break;
		}
	}
	cout << (succeed ? "Nice!\n" : "Fucking fucked!\n");
	system("pause");
	return 0;
}

