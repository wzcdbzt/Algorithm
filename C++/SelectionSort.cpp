#include<algorithm>
#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;
int gArraySize = 0;

/**********************Selection Sort****************************/
void swap(int arr[], int i, int j) {
	if (i == j)//i==j时会令元素变成0
		return;
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

/*思想：
0~N-1选一个最小的放0位置
1~N-1选一个最小的放1位置
*/
void SelectionSort(int arr[], int n)
{
	if (arr == NULL || n < 2)
	{
		return;
	}
	for (int i = 0; i < n; ++i) {//i~N-1选一个最小的
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			minIndex = arr[j] < arr[minIndex] ? j : minIndex;
		}
		swap(arr, i, minIndex);
	}
}
/**********************Selection Sort****************************/

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
		SelectionSort(arr1, gArraySize);
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