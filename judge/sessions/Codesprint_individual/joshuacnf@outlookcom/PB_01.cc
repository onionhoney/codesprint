#include <cstdio>
using namespace std;

int T;
int m, n, k;

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
	scanf("%d%d", &m, &n);
	scanf("%d", &k);
	int x1, y1, x2, y2;
	int cntx = 0, cnty = 0;
	for (int i = 0; i < k; i++)
	{
	    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	    if (x1 == x2)
		cnty++;
	    if (y1 == y2)
		cntx++;
	}
	printf("%d\n", (cntx + 1) * (cnty + 1));
    }
    return 0;
}
