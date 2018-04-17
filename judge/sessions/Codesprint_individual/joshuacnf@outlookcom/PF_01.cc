#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

#define N 1007
#define INF 0x7FFFFFF

int T;
int n, k, r;
int G[N][N] = {0};
int A[N], W[N];
int dis[N] = {0};
bool inq[N] = {0};
queue<int> Q;

void spfa()
{
    memset(inq, 0, sizeof(inq));
    for (int i = 0; i < N; i++)
	dis[i] = INF;
    
    Q.push(1);
    inq[1] = true; dis[1] = 0;
    while (!Q.empty())
    {
	int u = Q.front();
	Q.pop();
	inq[u] = false;

	for (int v = 1; v <= n; v++)
	    if (G[u][v] <= INF && dis[v] > dis[u] + G[u][v])
	    {
		dis[v] = dis[u] + G[u][v];
		if (!inq[v])
		{
		    Q.push(v);
		    inq[v] = true;
		}
	    }
    }
}

int main()
{
    scanf("%d", &T);
    for (int t = 0; t < T; t++)
    {
	for (int i = 0; i < N; i++)
	    for (int j = 0; j < N; j++)
		G[i][j] = INF;
	
	scanf("%d%d%d", &n, &k, &r);
	for (int i = 0; i < k; i++)
	    scanf("%d%d", &A[i], &W[i]);
	for (int i = 0; i < k; i++)
	    for (int j = 0; j < k; j++)
	    {
		int u = A[i], v = A[j];
		G[u][v] = min(G[u][v], W[i]);
	    }

	for (int i = 0; i < r; i++)
	{
	    int u, v, t;
	    scanf("%d%d%d", &u, &v, &t);
	    G[u][v] = min(G[u][v], t);
	    G[v][u] = min(G[v][u], t);
	}

	for (int i = 0; i < N; i++)
	    G[i][i] = 0;

	spfa();
	printf("%d\n", dis[n]);
    }
    return 0;
}
    
