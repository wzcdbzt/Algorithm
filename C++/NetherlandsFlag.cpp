#include<algorithm>
#include<iostream>
#include<cstdlib>
#include <ctime>

using namespace std;
int gArraySize = 0;

/**********************NetherlandsFlag****************************/
void swap(int arr[], int i, int j) {
	if (i == j)//i==j时会令元素变成0
		return;
	arr[i] = arr[i] ^ arr[j];
	arr[j] = arr[i] ^ arr[j];
	arr[i] = arr[i] ^ arr[j];
}

/*_________________________________________________________________
 |        <x         |          =X         |         >X            |
 ———————————————————————————————————————————————————————————————————
 */
int* Partition(int arr[], int L,int R,int p)
{
	int *border = new int[2];//等于x的边界
	int less = L - 1;
	int more = R + 1;
	while (L<more)
	{
		if (arr[L] < p)
			swap(arr, ++less, L++);
		else if (arr[L] > p)
			swap(arr, --more, L);
		else
			L++;
	}
	*border = less + 1;
	*(border + 1) = more - 1;
	return border;
}
/**********************NetherlandsFlag****************************/

/*对数器测试
{99, 3, 65, 5, 10}使用Partition 结果{3 5 10 65 99}
{99, 3, 65, 5, 10}使用comparator 结果{3 5 10 99 65}
因此这个不能用对数器比较
*/
void comparator(int arr[], int n,int p)
{
	int i = 0;
	int* help = new int[n];

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < p)
		{
			*(help++) = arr[i];
		}
	}
	for (i = 0; i < n; ++i)
	{
		if (arr[i] == p)
		{
			*(help++) = arr[i];
		}
	}
	for (i = 0; i < n; ++i)
	{
		if (arr[i] > p)
		{
			*(help++) = arr[i];
		}
	}
	help--;
	for (i = n-1; i >= 0; --i)
	{
		arr[i]  = *(help--);
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
	int testTime = 5000;
	int maxSize = 100;
	int maxValue = 100;
	bool succeed = true;

	int* arr = generateRandomArray(maxSize, maxValue);
	printArray(arr, gArraySize);
	Partition(arr, 0,gArraySize-1,55);
	printArray(arr, gArraySize);
	system("pause");
	return 0;
}
