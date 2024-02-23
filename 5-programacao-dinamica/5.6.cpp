#include <bits/stdc++.h>

using namespace std;

int max_substring(string s1, string s2) 
{
    int m = s1.size(), n = s2.size(), k = 0;

    vector <vector <int>> count (m + 1, vector <int> (n + 1, 0));

    int l = 0, c = 0;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                count[i][j] = count[i - 1][j - 1] + 1;

                if (k < count[i][j])
                {
                    k = count[i][j];
                    l = i - 1;
                    c = j - 1;
                }
            }
        }
    }
    
    int aux = l;

    while (s1[l] == s2[c] && l >= 0 && c >= 0)
    {
        l--;
        c--;
    }

    cout << "Substring: ";

    for (int i = l + 1; i <= aux; i++)
        cout << s1[i];
    
    cout << endl;

    return k;
}

int main ()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int max = max_substring(s1, s2);

    cout << "Quantidade de caracteres da substring maxima: " << max << endl;

    return 0;
}