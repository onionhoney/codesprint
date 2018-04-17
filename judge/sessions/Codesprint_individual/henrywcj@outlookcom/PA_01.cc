#include <iostream>
#include <math.h>
using namespace std;

void bubblesort(int n, long a[]) // other way to pass reference??
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
			{
				long t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}

void quicksort(int *a, int *b, int left, int right)
{
	int i = left, j = right;
	int temp, temp2, pivot = a[(i + j) / 2];
	while (i <= j)
	{
		while (a[i] > pivot) i++;
		while (a[j] < pivot) j--;
		if (i <= j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			temp2 = b[i];
			b[i] = b[j];
			b[j] = temp2;
			i++;
			j--;
		}
	}
	if (i < right) quicksort(a, b, i, right);
	if (j > left) quicksort(a, b, left, j);
}



int main()
{
	int t, p, n;
	int b[1000], n1[1000];
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		cin >> p >> n;
		for (int i = 0; i < p; i++)
			cin >> b[i] >> n1[i];
		quicksort(b, n1, 0, p - 1);
		int totol = n, total = 0;
		int i = 0;
		while (totol >= n1[i] && i<= p-1)
		{
			totol = totol - n1[i];
			total = total + b[i] * n1[i];
			i++;
		}
		if (totol != 0 && i <= p-1) total = total + totol * b[i];
		cout << total << endl; 
 	}
}
