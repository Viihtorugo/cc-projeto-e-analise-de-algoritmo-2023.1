#include <bits/stdc++.h>

using namespace std;

bool flag = true;

void caminho_hamiltoniano_vertice_fixado(vector<vector<int>> g, int k, int s, vector<int> &path)
{
    if (g.size() == k)
    {
        cout << "O grafo possui caminho hamiltoniano;\n";
        cout << "Caminho: ";

        for (auto v : path)
            cout << v << " ";

        cout << endl;

        exit(0);
    }

    for (auto v : g[s])
    {
        bool ve = false;

        for (int i = 0; i < path.size(); i++)
            if (path[i] == v)
                ve = true;

        if (!ve)
        {
            path[k] = v;
            caminho_hamiltoniano_vertice_fixado(g, k + 1, v, path);
            path[k] = -1;
        }

    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int v, w;
        cin >> v >> w;

        graph[v].push_back(w);
        graph[w].push_back(v);
    }

    int s;
    cin >> s;

    vector<int> path(n, -1);
    path[0] = s;
    caminho_hamiltoniano_vertice_fixado(graph, 1, s, path);

    if (flag)
        cout << "O grafo não possui caminho hamiltoniano\n";

    return 0;
}