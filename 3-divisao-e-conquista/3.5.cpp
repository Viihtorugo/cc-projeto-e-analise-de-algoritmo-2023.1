#include <bits/stdc++.h>

using namespace std;

int k_elem(vector<int> a1, int i, int m, vector<int> a2, int j, int n, int k)
{
    int mid1 = (i + m) / 2;
    int mid2 = (j + n) / 2;

    cout << "i = " << i << " e "
         << " m = " << m << " mid1 = " << mid1 << endl;
    cout << "j = " << j << " e "
         << " n = " << n << " mid2 = " << mid2 << endl;

    cout << "k = " << k << endl;

    if (mid1 + mid2 == k)
    {
        if (a1[mid1] < a2[mid2])
            return a2[mid2];

        return a1[mid1];
    }
    else
    {
        if (mid1 + mid2 > k)
        {
            if (a1[mid1] < a2[mid2])
            {
                return k_elem(a1, i, m, a2, j, mid2 - 1, k);
            }
            else
            {
                return k_elem(a1, i, mid1 - 1, a2, j, n, k);
            }
        }
        else
        {
            if (a1[mid1] < a2[mid2])
            {
                return k_elem(a1, mid1 + 1, m, a2, j, n, k);
            }
            else
            {
                return k_elem(a1, i, m, a2, mid2 + 1, n, k);
            }
        }
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int n, m;

    cout << "Digite o número de elementos da primeira lista: ";
    cin >> m;

    vector<int> a1(m + 1);

    a1[0] = INT_MIN;

    for (int i = 1; i <= m; i++)
        a1[i] = rand() % 10;

    cout << "Digite o número de elementos da segunda lista: ";
    cin >> n;

    vector<int> a2(n + 1);

    a2[0] = INT_MIN;

    for (int i = 1; i <= n; i++)
        a2[i] = rand() % 10;

    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    vector<int> u(m + n);

    int x = 0;

    for (int i = 1; i <= n; i++)
        u[x++] = a2[i];

    for (int i = 1; i <= m; i++)
        u[x++] = a1[i];

    sort(u.begin(), u.end());

    vector<int> r;

    for (int i = 1; i <= n + m; i++)
    {
        r.push_back(k_elem(a1, 1, m, a2, 1, n, i));
        cout << "Elemento u[" << i << "]: " << u[i - 1] << endl;
    }

    cout << "Lista 1: ";
    for (int i = 1; i <= m; i++)
    {
        cout << a1[i];

        if (i == m)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    cout << "Lista 2: ";
    for (int i = 1; i <= n; i++)
    {
        cout << a2[i];

        if (i == n)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    cout << "resultado: ";
    for (auto e : r)
        cout << e << " ";

    cout << endl;

    cout << "Lista 1 união lista 2: ";
    for (int i = 0; i < x; i++)
    {
        cout << u[i];

        if (i + 1 == x)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}