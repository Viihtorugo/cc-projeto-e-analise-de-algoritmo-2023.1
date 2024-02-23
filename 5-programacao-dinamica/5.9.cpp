#include <bits/stdc++.h>

using namespace std;

vector <int> dfs (vector<vector<int>> g, vector<bool> visited, int o, int d, vector <int> path)
{
    path.push_back(o);

    if (o == d || visited[o])
        return path;

    visited[o] = true;

    for (auto v: g[o])
    {
        vector <int> aux = dfs(g, visited, v, d, path);
        
        if (aux[aux.size() - 1] != d)
        {
            aux.pop_back();
        }
        else
        {
            return aux;
        }
    }

    return path;
}

int count_paths_dag (vector<vector<int>> g, int n, int o, int d)
{
    vector<bool> visited(n, false);
    vector <int> path = dfs(g, visited, o, d, vector <int> ());
    
    vector <vector <vector<int>>> paths (path.size());
    vector <int> count (paths.size(), 0);

    cout << "path = " << path.size() << endl;
    
    if(path.size() == 0)
        return 0;

    vector <int> p;
    p.push_back(path[0]);
    paths[0].push_back(p);
    count[0] = paths[0].size();

    for (int i = 1; i < path.size(); i++)
    {
        for (int j = 0; j <= i; j++)
        {

            p = vector <int> ();

            for (int k = j; k <= i; k++)
            {
                p.push_back(path[k]);
            }

            for (auto elem: p)
            {
                cout << elem << " ";
            }

            cout << endl;

            paths[i].push_back(p);
        }

        count[i] = paths[i].size() + count[i - 1];
    }

    return count[count.size() - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    
    for (int i = 0; i < m; i++)
    {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
    }
    
    int s, t;
    cin >> s >> t;

    int min = count_path_dag(g, n, s, t);

    cout << min << endl;

    return 0;
}