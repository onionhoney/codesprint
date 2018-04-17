#include <cstdio>
#include <cstring>
using namespace std;

#define N 107

int T;
int n, m, a, b;
char G[N][N];
bool vis[N][N] = {0};
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
char S[] = {'U', 'D', 'L', 'R'};

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
	memset(G, 0, sizeof(G));
	memset(vis, 0, sizeof(vis));
	
	scanf("%d%d", &m, &n);
	scanf("%d%d", &a, &b);
	getchar();
	for (int i = 1; i <= m; i++)
	{
	    for (int j = 1; j <= n; j++)
		G[i][j] = getchar();
	    getchar();
	}

	vis[a][b] = true;
	while(1)
	{
	    bool flag = false;
	    for (int i = 0; i < 4; i++)
	    {
		int x = a + dx[i], y = b + dy[i];
		if (G[x][y] == '#' && vis[x][y] == false)
		{
		    flag = true;
		    a = x, b = y;
		    vis[x][y] = true;
		    printf("%c", S[i]);
		}
	    }
	    if (!flag) break;
	}
	printf("\n");
    }
    return 0;
}
