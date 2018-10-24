#include <iostream>

using namespace std;


void sort(int arr[], int left, int right) {

	int i = left, j = right;
	int tmp;

	int pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
		}
		while (arr[j] > pivot) {
			j--;
		}
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};

	if (left < j)
	{
		sort(arr, left, j);
	}
	if (i < right)
	{
		sort(arr, i, right);
	}

}

int main()
{
	int productsCount, kParam;
	int sum = 0;
	int bonus = 0;

	cin >> productsCount;
	cin >> kParam;

	int * products = new int[productsCount];

	for (int i = 0; i < productsCount; i++)
	{
		cin >> products[i];
		sum += products[i];
	}
	sort(products, 0, productsCount - 1);


	for (int i = productsCount - kParam; i >= 0; i -= kParam)
	{
		bonus += products[i];
	}

	cout << sum - bonus << endl;

	delete[] products;

	system("pause");
	return 0;
}