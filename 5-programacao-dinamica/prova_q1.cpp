#include <bits/stdc++.h>

using namespace std;

int count_ways (vector <vector <int>> map, int n , int m)
{
    vector <vector <int> > count (n, vector<int> (m, 0));

    bool v = false;

    for (int i = 1; i < m; i++)
    {
        if (map[0][i])
            v = true;

        if (!v)
            count[0][i] = count[0][i - 1] + 1;
    }

    cout << "test\n";
    v = false;

    for (int i = 1; i < n; i++)
    {
        if (map[i][0])
            v = true;

        if (!v)
            count[i][0] = count[i - 1][0] + 1;
    }
    

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (!map[i][j])
            {
                count[i][j] += count[i - 1][j] + count[i][j - 1] + 1;
            }
            else 
            {
                count[i][j] = 0;
            }
        }
        
    }

    
    cout << "Matriz resultante :\n\n";
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{
			cout << count[i][j] << " ";
		}

		cout << endl;
	}

    cout << endl;

    return count[n - 1][m - 1];
}

int main ()
{
    int n, m;
    cin >> n >> m;

    vector <vector<int>> map (n, vector <int> (m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    cout << "Matriz mapa:\n\n";
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < m; j++)
		{
			cout << map[i][j] << " ";
		}

		cout << endl;
	}

    cout << endl;
    
    cout << "Existe " << count_ways(map, n, m) << " maneiras de chegar!\n";

    return 0;
}