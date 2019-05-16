#include<algorithm>
#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;
int gArraySize = 0;
int* Partition(int arr[], int L, int R);
void quickSort(int arr[], int n);
void quickSort(int arr[], int L, int R);
/**********************Quick Sort****************************/
void swap(int arr[], int i, int j) {
	if (i == j)//i==j时会令元素变成0
		return;
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

//时间复杂度O(N*logN)，额外空间复杂度O(logN)
void quickSort(int arr[], int n) {
	if (arr == NULL || n < 2) {
		return;
	}
	quickSort(arr, 0, n - 1);
}

void quickSort(int arr[], int L, int R) {
	if (L < R) {
		unsigned seed = time(0);
		srand(seed);
		//(int)(rand() % (R - L + 1) + L)为L~R之间的随机位置
		swap(arr, (int)(rand() % (R - L + 1) + L), R);
		int* border = Partition(arr, L, R);
		quickSort(arr, L, *border - 1);
		quickSort(arr, *(border + 1) + 1, R);
	}
}

int* Partition(int arr[], int L, int R)
{
	int* border = new int[2];//等于x的边界
	int less = L - 1;
	int more = R;
	while (L < more)
	{
		if (arr[L] < arr[R])
			swap(arr, ++less, L++);
		else if (arr[L] > arr[R])
			swap(arr, --more, L);
		else
			L++;
	}
	swap(arr, more, R);
	*border = less + 1;
	*(border + 1) = more - 1;
	return border;
}


/**********************Quick Sort****************************/

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
	int testTime = 5000;
	int maxSize = 100;
	int maxValue = 100;
	bool succeed = true;
	for (int i = 0; i < testTime; i++) {
		int* arr1 = generateRandomArray(maxSize, maxValue);
		int* arr2 = copyArray(arr1);
		quickSort(arr1, gArraySize);
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
