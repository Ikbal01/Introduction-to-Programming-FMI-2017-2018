#include <iostream>
#include <string>

using namespace std;


void swap(char *xp, char *yp)
{
	char temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(char arr[], int n)
{
	int i, j, min;

	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min])
				min = j;

		swap(&arr[min], &arr[i]);
	}
}

char * toArray(string str)
{
	char * arr = new char[str.length()];

	for (int i = 0; i < str.length(); i++)
	{
		arr[i] = str[i];
	}
	return arr;
}

void substring(string a, string b)
{
	char * arrA = toArray(a);
	char * arrB = toArray(b);

	selectionSort(arrA, a.length());

	for (int i = 0; i < a.length(); i++)
	{
		for (int j = 0; j < b.length(); j++)
		{
			if (arrA[i] == arrB[j])
			{
				cout << arrA[i];
				arrB[j] = '0';
				break;
			}
		}
	}

	delete[] arrA;
	delete[] arrB;
	cout << endl;
}

int main()
{
	string a, b;

	cin >> a;
	cin >> b;

	substring(a, b);

	system("pause");
	return 0;
}