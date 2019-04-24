#include <iostream>
using namespace std;

#include<stdio.h>

int val[20000];
int wt[20000];
int K[20000][2000];

int max(int a, int b) { return (a > b)? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }
    
    return K[n][W];
}

int main(int argc, const char * argv[]) {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, W;
        cin >> n >> W;
        for (int i = 0; i < n; i++) {
            cin >> wt[i] >> val[i];
        }
        cout << knapSack(W, wt, val, n) << endl;
    }
    return 0;
}
