#include <bits/stdc++.h>

using namespace std;

int dijkstra_max(vector<vector<int>> g, vector<vector<int>> w, int n, int m, int s, int t)
{
    vector<bool> visited(n, false);
    vector<int> d(n,  INT_MIN);

    priority_queue <pair<int, int>> pq;
    pq.push({s, 0});
    d[s] = 0;

    while (!pq.empty())
    {
        int u = pq.top().first;
        visited[u] = true;
        pq.pop();

        for (auto v: g[u])
        {
            if (d[u] + w[u][v] > d[v])
            {
                d[v] = d[u] + w[u][v];

                if (!visited[v])
                    pq.push({v, d[v]});
            }
        }
    }

    cout << "Dist resultante: ";

    for (int i = 0; i < n; i++)
    {
        cout << d[i] << " ";
    }

    cout << endl;

    return d[t];
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int> ());
    vector<vector<int>> w(n, vector<int>(n, INT_MIN));

    for (int i = 0; i < m; i++)
    {
        int v, u, p;

        cin >> v >> u >> p;

        w[v - 1][u - 1] = p;
        w[u - 1][v - 1] = p;

        g[v - 1].push_back(u - 1);
        g[u - 1].push_back(v - 1);
    }

    
    cout << "Matriz inicial: \n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (w[i][j] != INT_MIN)
            {
                cout << w[i][j] << " ";
            }
            else
            {
                cout << "0 ";
            }
        }

        cout << endl;
    }


    int o, d;
    cin >> o >> d;

    int max = dijkstra_max(g, w, n, m, o - 1, d - 1);

    cout << "Caminho máximo: " << max << endl;

    return 0;
}