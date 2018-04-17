#include <cstdio>
using namespace std;

int T;
int n, p;

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
	scanf("%d%d", &p, &n);
	int b, m, ans = 0;
	for (int i = 0; i < p; i++)
	{
	    scanf("%d%d", &b, &m);
	    if (!n) continue;
	    if (n >= m)
	    {
		ans += b * m;
		n -= m;
	    }
	    else
	    {
		ans += b * n;
		n = 0;
	    }
	}
	printf("%d\n", ans);
    }
    return 0;
}
