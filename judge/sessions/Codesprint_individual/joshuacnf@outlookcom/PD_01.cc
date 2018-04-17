#include <cstdio>
using namespace std;

#define N 1000007

int n;
int I[10];
char ans[10];
int L[N], R[N];
char cmd[N] = {0};

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
	scanf("%d %d %c", &L[i], &R[i], &cmd[i]);
    for (int i = 0; i < 4; i++)
    {
	scanf("%d", &I[i]);
	ans[i] = 'a';
    }

    for (int i = 0; i < n; i++)
    {
	for (int j = 0; j < 4; j++)
	    if (L[i] <= I[j] && I[j] <= R[i])
		ans[j] = cmd[i];
    }

    for (int i = 0; i < 4; i++)
	printf("%c ", ans[i]);
    printf("\n");
    return 0;
}
