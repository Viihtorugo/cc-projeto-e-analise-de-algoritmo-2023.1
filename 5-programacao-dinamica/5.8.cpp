#include <bits/stdc++.h>

using namespace std;

bool subset_sum (vector <vector <bool>> &map, vector <int> v, int n, int sum)
{
    for (int i = 0; i <= n; i++)
        map[i][0] = true;
 
    for (int i = 1; i <= sum; i++)
        map[0][i] = false;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {

            if (j < v[i])
            {
                map[i][j] = map[i - 1][j];
            }
            if (j >= v[i])
            {
                map[i][j] = (map[i - 1][j] || map[i - 1][j - v[i]]);
            }
        }
    }
    
    return map[n][sum];
}

int main ()
{
    int n, sum;
    cin >> n;

    vector <int> v (n + 1, 0);
    
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    cin >> sum;

    vector<vector<bool>> map (n + 1, vector<bool> (sum + 1, false));

    if (subset_sum(map, v, n, sum))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    cout << "\nMatriz resultante: \n\n";

    for (int i = 0; i <= n; i++)
    {
        cout << v[i] << " ";
        
        for (int j = 1; j <= sum; j++)
        {
            cout << map[i][j] << " ";
        }
        
        cout << endl;
    }
    

    return 0;
}