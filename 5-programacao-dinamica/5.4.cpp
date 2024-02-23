#include <bits/stdc++.h>

using namespace std;

int dfs(vector<vector<int>> g, vector<bool> v, int i)
{
    if (v[i])
        return 0;

    v[i] = true;

    int count = 1;

    for (auto u : g[i])
    {
        count += dfs(g, v, u);
    }

    return count;
}

void dfs_path(vector<vector<int>> g, vector<bool> v, int i, vector <int> &path)
{
    path.push_back(i);

    if (v[i])
        return;

    v[i] = true;

    for (auto u : g[i])
        dfs_path(g, v, u, path);
}

int max_path_dag(vector<vector<int>> g, int n)
{

    vector<int> dag(n);

    int index = 0;

    for (int i = 0; i < n; i++)
    {
        vector <bool> v (n, false);

        dag[i] = dfs(g, v, i);

        if (dag[index] < dag[i])
            index = i;
    }

    cout << "Dag resultante: ";

    for (int i = 0; i < n; i++)
    {
        cout << i << ":" << dag[i] << " ";
    }

    cout << endl;

    cout << "Caminho: ";

    vector <int> path;

    dfs_path(g, vector <bool> (n, false), index, path);

    for (auto p: path)
    {
        cout << p << " ";
    }
    
    cout << endl;

    return dag[index];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g( n, vector <int> ());

    for (int i = 0; i < m; i++)
    {
        int v, u;

        cin >> v >> u;
        v--;
        u--;
        g[v].push_back(u);
    }

    cout << max_path_dag(g, n) << "\n";

    return 0;
}