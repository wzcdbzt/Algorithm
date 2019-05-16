#include<algorithm>
#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;
int gArraySize = 0;

/**********************Bubble Sort****************************/
void swap(int arr[], int i, int j) {
	if (i == j)//i==jʱ����Ԫ�ر��0
		return;
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

/*
˼�룺��������Ԫ�رȽϣ�ÿһ��ȷ��һ��Ԫ��
0~N-1
0~N-2
...
*/
void bubbleSort(int arr[], int n)
{
	for (int end = n - 1; end > 0; --end)//����ð�ݱȽϷ�Χ
	{
		for (int i = 0; i < end; ++i)//��ÿһ�ַ�Χ����[1,2][2,3][3,4]...�Ƚ�
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr, i, i + 1);
			}
		}
	}
}

void bubbleSort_new(int arr[], int n)
{
	for (bool sorted = false; sorted = !sorted; --n)
	{
		for (int pos = 0; pos < n; ++pos)
		{
			if (arr[pos] > arr[pos + 1])
			{
				swap(arr, pos, pos + 1);
			}
		}
	}
}
/**********************Bubble Sort****************************/

//����������
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
	int maxSize = 1000;
	int maxValue = 1000;
	bool succeed = true;
	for (int i = 0; i < testTime; i++) {
		int* arr1 = generateRandomArray(maxSize, maxValue);
		int* arr2 = copyArray(arr1);
		bubbleSort(arr1, gArraySize);
		comparator(arr2, gArraySize);
		if (!isEqual(arr1, arr2)) {
			succeed = false;
			cout << (succeed ? "Nice!\n" : "Fucking fucked!\n");
			cout << "������ȷ�Ľ����" << endl;
			printArray(arr2, gArraySize);
			cout << "�Լ��㷨�Ľ����" << endl;
			printArray(arr1, gArraySize);
			break;
		}
	}
	cout << (succeed ? "Nice!\n" : "Fucking fucked!\n");
	system("pause");
	return 0;
}
