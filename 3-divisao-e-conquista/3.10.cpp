#include <bits/stdc++.h>

using namespace std;

vector<int> remove_elem_equal(int i, int n, vector<int> array)
{
    if (i < n)
    {
        int mid = (i + n) / 2;

        vector<int> a1 = remove_elem_equal(i, mid, array);
        vector<int> a2 = remove_elem_equal(mid + 1, n, array);

        vector<int> a3;

        int i1 = 0, i2 = 0;
 
        a1.push_back(INT_MAX);
        a2.push_back(INT_MAX);

        while (a1[i1] != INT_MAX || a2[i2] != INT_MAX)
        {
            if (a3.size() > 0)
            {
                if (a3[a3.size() - 1] == a1[i1])
                    i1++;

                if (a3[a3.size() - 1] == a2[i2])
                    i2++;
            }

            if (a1[i1] < a2[i2])
            {
                a3.push_back(a1[i1]);
                i1++;
            }
            else
            {
                a3.push_back(a2[i2]);
                i2++;
            }
        }

        return a3;
    }

    vector<int> aux;
    aux.push_back(array[i]);

    return aux;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Informe o tamanho da lista: ";
    cin >> n;

    vector<int> array(n + 1);

    for (int i = 1; i <= n; i++)
    {
        // cout << "Elemento " << i << ":" << endl;
        //  cin >> array[i];
        array[i] = rand() % 10;
    }

    cout << "Lista inicial: ";

    for (int i = 1; i <= n; i++)
    {
        cout << array[i];

        if (i == n)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    vector<int> new_array = remove_elem_equal(1, n, array);

    cout << "Lista sem elementos repetidos: ";

    for (int i = 0; i < new_array.size(); i++)
    {
        cout << new_array[i];

        if (i + 1 == new_array.size())
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    cout << "A nova lista possui " << new_array.size() << " elemento(s)\n";
}