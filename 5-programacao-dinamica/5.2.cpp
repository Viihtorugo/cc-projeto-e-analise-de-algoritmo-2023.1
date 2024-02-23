#include <bits/stdc++.h>

using namespace std;

void max_coin(vector<vector<int>> map, int n, int m)
{
    vector<vector<int>> count = map;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            count[i][j] += max(count[i - 1][j], count[i][j - 1]);
        }
    }

    cout << "Matriz count:\n\n";

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << count[i][j] << " ";
        }

        cout << endl;
    }
    
    cout << "\n\nValor máximo: " << count[n][m] << endl;

    stack <pair<int, int>> path;
    int l = n, c = m;

    while (l != 0 && c != 0)
    {
        path.push({ l, c});

        if (count[l][c] == count[l - 1][c])
        {
            l--;
        }
        else if (count[l][c] == count[l][c - 1])
        {
            c--;
        }
        else if (l == 1) {
            c--;
        }
        else if (c == 1)
        {
            l--;
        }
        else if (count[l - 1][c] + 1 == count[l][c]) 
        {
            l--;
        }
        else if (count[l][c - 1] + 1 == count[l][c]) 
        {
            c--;
        }
    }

    cout << "Caminho: ";
    while (!path.empty())
    {
        cout << "(" << path.top().first << ", " << path.top().second << ")";
        path.pop();

        if (path.empty())
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
    
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector <vector <int>> map (n + 1, vector<int> (m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
        }
    }

    max_coin(map, n, m);

    return 0;
}