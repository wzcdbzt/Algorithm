#include<algorithm>
#include<iostream>
#include<cstdlib>
#include <ctime>
#include<time.h>

using namespace std;
int gArraySize = 0;
int smallSum(int arr[], int n);
int mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

/**********************************ReversePair****************************************/
//��һ�������У���ߵ���������ұߵ�������������������һ������ԣ����ӡ���������
int ReversePair(int arr[], int n)
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
	int mid = l + ((r - l) >> 1);
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	merge(arr, l, mid, r);
}

void merge(int arr[], int l, int m, int r) {
	int* help = new int[r - l + 1];
	int i = 0;
	int p1 = l;
	int p2 = m + 1;
	int res = 0;
	while (p1 <= m && p2 <= r) {
		int tmp = p2;
		if (arr[p1] < arr[p2] )
		{
			while (tmp <= r)
			{
				cout << "(" << arr[p1] << "," << arr[tmp++] << ")" << "  ";
			}
		}
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
	cout << endl;
	return;
}

/**********************************ReversePair****************************************/
//����������
//ʱ��O(N^2)
void comparator(int arr[], int n)
{
	if (arr == NULL || n < 2) {
		return ;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[i] < arr[j])
				cout << "(" << arr[i] << "," << arr[j] << ")" << "  ";
		}
		cout << endl;
	}
	return ;
}

int* generateRandomArray(int maxSize, int maxValue)
{
	unsigned seed = time(0);
	srand(seed);
	gArraySize = (int)(rand() % (maxSize + 1));
	int* arr = new int[gArraySize];//[0~maxSize]����С��size
	for (int i = 0; i < gArraySize; ++i) {
		arr[i] = (int)(rand() % (maxValue + 1));//Ԫ��ֵ[0~maxValue]����Сֵ
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
	return a1 == a2 ? true : false;
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

/*
ʹ�ù鲢����ķ�ʽ�ƺ���û�б������㷨����
*/
int main(int argc, char** argv)
{
	int maxSize = 1000;
	int maxValue = 1000;
	int* arr1 = generateRandomArray(maxSize, maxValue);
	int* arr2 = copyArray(arr1);
	clock_t start, finish;
	
	cout << "ԭʼ����" << endl;
	printArray(arr1, gArraySize);

	cout << "�����鲢����" << endl;
	start = clock();
	ReversePair(arr1, gArraySize);
	finish = clock();
	cout << "����ʱ��Ϊ" << (double)(finish - start) / CLOCKS_PER_SEC << "�룡" << endl;

	cout << "������������" << endl;
	start = clock();
	comparator(arr2, gArraySize);
	finish = clock();
	cout << "����ʱ��Ϊ" << (double)(finish - start) / CLOCKS_PER_SEC << "�룡" << endl;

	system("pause");
	return 0;
}
