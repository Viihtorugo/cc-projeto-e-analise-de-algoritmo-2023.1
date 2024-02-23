#include <bits/stdc++.h>

using namespace std;

void floyd_warshall(vector<vector<int>> g, int n)
{

    vector<vector<int>> d(n, vector<int>(n, INT_MAX));

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][k] != INT_MAX && g[k][j] != INT_MAX && i != j)
                    d[i][j] = min(d[i][j], g[i][k] + g[k][j]);

    cout << "\nMatriz resultante: \n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] != INT_MAX)
            {
                cout << d[i][j] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < m; i++)
    {
        int v, u, w;

        cin >> v >> u >> w;

        g[v - 1][u - 1] = w;
        g[u - 1][v - 1] = w;
    }

    cout << "Matriz inicial: \n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] != INT_MAX)
            {
                cout << g[i][j] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    floyd_warshall(g, n);

    return 0;
}