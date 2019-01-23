#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for (int x = 0; x < t; x++)
    {
        int n, k;
        cin >> n >> k;
        vector<int> population(n);
        for (int y = 0; y < n; y++)
        {
            cin >> population[y];
        }
        
        vector<vector<pair<int, int>>> table(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < k; j++)
            {
                pair<int, int> w;
                w.first = 0;
                w.second = 1;
                table[i].push_back(w);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                table[i][0].first = population[0];
                table[i][0].second = 1;
            }
            
            else
            {
                int m = 0;
                for (int q = 0; q < i; q++)
                {
                    
                    if (max(table[q][0].first, population[i]) > m)
                        m = max(table[q][0].first, population[i]);
                    
                }
                table[i][0].first = m;
                table[i][0].second = 1;
            }
        }
        for (int q = 2; q < n; q++)
        {
            for (int s = 1; s < k; s++)
            {
                if (s - 1 >= 0)
                {
                    table[q][s].first = max(population[q] + table[q-2][s-1].first, table[q-2][s].first);
                    if (table[q][s].first == population[q] + table[q-2][s-1].first)
                    {
                        table[q][s].second += 1;
                    }
                }
                else
                {
                    table[q][s].first = table[q-2][s].first;
                    table[q][s].second = table[q-2][s].second;
                }
            }
        }
        
        
        for (int z = n-1; z >= 0; z--)
        {
            if (table[z][k-1].second == k)
            {
                cout << table[z][k-1].first;
                break;
            }
            
        }
        
    }
    // add one to each one since arrays start at 0
    
}
