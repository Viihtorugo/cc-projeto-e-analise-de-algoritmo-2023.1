#include <bits/stdc++.h>

using namespace std;

int tree_height(vector<vector<int>> g, int i, int h, vector<bool> visited)
{
    if (visited[i])
        return h;

    visited[i] = true;

    int count;

    for (auto u : g[i])
    {
        count = tree_height(g, u, h + 1, visited);
    }

    return count;
}

void count_elem(vector<vector<int>> g, vector<vector<int>> &v, int i, int h, vector<bool> visited)
{

    if (visited[i])
        return;

    v[h].push_back(i);

    visited[i] = true;

    for (auto u : g[i])
    {
        count_elem(g, v, u, h + 1, visited);
    }
}

int min_cover(vector<vector<int>> g, int n)
{
    vector<bool> v(n, false);
    int h = tree_height(g, 0, 0, v);
    cout << "Altura da arvore: " << h << endl;

    vector<vector<int>> count_elem_level(h + 1, vector<int>());

    v = vector<bool>(n, false);

    count_elem(g, count_elem_level, 0, 1, v);

    int c1 = 0, c2 = 0;

    for (int i = 1; i <= h; i++)
    {
        cout << "nivel " << i << ": ";
        cout << count_elem_level[i].size() << "; ";

        if (i % 2 == 1)
        {
            c1 += count_elem_level[i].size();
        }
        else
        {
            c2 += count_elem_level[i].size();
        }
    }

    cout << endl << endl;

    if (c1 < c2)
    {
        cout << "Elementos da cobertura: ";

        for (int i = 1; i <= h; i += 2)
        {
            for (auto e : count_elem_level[i])
                cout << e << " ";
        }

        cout << endl;

        return c1;
    }
    else
    {
        cout << "Elementos da cobertura: ";

        for (int i = 2; i <= h; i += 2)
        {
            for (auto e : count_elem_level[i])
                cout << e << " ";
        }

        cout << endl;

        return c2;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>());

    for (int i = 0; i < m; i++)
    {
        int v, u;

        cin >> v >> u;
        v--;
        u--;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    int min = min_cover(g, n);

    cout << "Cobertura minima: " << min << endl;

    return 0;
}