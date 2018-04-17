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
	long t, m, n, k, a, b, c, d;
	cin >> t;
	
	for (long j = 0; j < t; j++)
	{
		cin >> m >> n >> k;
		long hori = 1;
		long verti = 1;
		for (long i = 0; i < k; i++)
		{
			cin >> a >> b >> c >> d;
			if (a == c) hori++;
			if (b == d) verti++;
		}
		long answer = (hori) * (verti);
		cout << answer << endl;
	}
}
