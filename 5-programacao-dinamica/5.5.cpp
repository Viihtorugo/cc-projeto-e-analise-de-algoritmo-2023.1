#include <bits/stdc++.h>

using namespace std;

int max_sum_subseg (vector <int> s, int n)
{
    if(s.size() == 0)
        return 0;

    vector <int> sum = s;

    int aux = 0;

    for (int i = 1; i < n; i++)
    {
        sum[i] = max(sum[i], sum[i] + sum[i - 1]);

        if (sum[i] > sum[aux])
            aux = i;
    }

    int init = aux;

    while (sum[init] != s[init])
        init--;
    

    cout << "Subsequencia: ";

    for (int i = init; i <= aux; i++)
    {
        cout << s[i] << " ";
    }

    cout << endl;
    
    return sum[aux];
}

int main ()
{
    int n;

    vector <int> s;

    while (cin >> n)
        s.push_back(n);

    
    int max_sum = max_sum_subseg(s, s.size());

    cout << "Maior soma subsquencia: " << max_sum << endl;
    
    return 0;
}