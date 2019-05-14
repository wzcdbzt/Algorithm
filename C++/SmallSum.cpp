#include<algorithm>
#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;
int gArraySize = 0;
int smallSum(int arr[], int n);
int mergeSort(int arr[], int l, int r);
int merge(int arr[], int l, int m, int r);

/**********************************SmallSum****************************************/
int smallSum(int arr[],int n)
{
	if (arr == NULL || n < 2) {
		return 0;
	}
	return mergeSort(arr, 0, n - 1);
}

 int mergeSort(int arr[], int l, int r) 
 {
	if (l == r) {
		return 0;
	}
	//mid = (l+r)/2可能溢出
	//mid = l + (r-l)/2不会溢出
	int mid = l + ((r - l) >> 1);
	//整体的小和 = 左侧产生的小和+右侧产生的小和+合并过程中的小和
	return mergeSort(arr, l, mid) + mergeSort(arr, mid + 1, r) + merge(arr, l, mid, r);
}

 int merge(int arr[] , int l, int m, int r) {
	 int *help = new int[r - l + 1];
	 int i = 0;
	 int p1 = l;
	 int p2 = m + 1;
	 int res = 0;
	 while (p1 <= m && p2 <= r) {
		 res += arr[p1] < arr[p2] ? (r - p2 + 1) * arr[p1] : 0;
		 help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
	 }
	 while (p1 <= m) {
		 help[i++] = arr[p1++];
	 }
	 while (p2 <= r) {
		 help[i++] = arr[p2++];
	 }
	 for (i = 0; i < r - l + 1; i++) {
		 arr[l + i] = help[i];
	 }
	 return res;
 }

//对数器测试
int comparator(int arr[], int n)
{
	if (arr == NULL || n < 2) {
		return 0;
	}
	int res = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			res += arr[j] < arr[i] ? arr[j] : 0;
		}
	}
	return res;
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

bool isEqual(int a1, int a2)
{
	return a1==a2?true:false;
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
		if (!isEqual(smallSum(arr1, gArraySize), comparator(arr2, gArraySize))) {
			succeed = false;
			break;
		}
	}
	cout << (succeed ? "Nice!\n" : "Fucking fucked!\n");
	int* arr = generateRandomArray(maxSize, maxValue);
	printArray(arr, gArraySize);
	cout << "该数组小和为："<< smallSum(arr, gArraySize)<<endl;
	system("pause");
	return 0;
}
