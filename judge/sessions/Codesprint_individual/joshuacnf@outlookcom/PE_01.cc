#include <cstdio>
using namespace std;

#define MOD 10007
#define N 1000007

int T, n;
int f[N] = {0};

int main()
{
    f[0] = 1; f[1] = 1; f[2] = 2;
    for (int i = 3; i < N; i++)
    {
	f[i] = 0;
	for (int j = 1; j <= 3; j++ )
	{
	    f[i] += f[i - j];
	    f[i] %= MOD;
	}
    }
    
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
	int ans = 1;
	scanf("%d", &n); int s;
	for (int i = 0; i < n; i++)
	{
	    scanf("%d", &s);
	    ans *= f[s];
	    ans %= MOD;
	}
	printf("%d\n", ans);
    }
    return 0;
}
