#include <bits/stdc++.h>

using namespace std;

int index_equal_value (int i, int n, vector <int> array, int &index)
{
    cout << "i = " << i << " n = " << n << "\n";

    if (i <= n)
    {
        int mid = (i + n) / 2;
        
        if (array[mid] == mid)
        {
            return mid;
        }
        else
        {
            if (array[mid] > mid)
            {
                return index_equal_value(mid + 1, n, array, index);
            }
            else
            {
                return index_equal_value(i, mid - 1, array, index);
            }
        }
    }

    return 0;
}

int main ()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int n;

    cout << "Informe o numero de elementos: ";
    cin >> n;

    vector <int> array(n + 1);

    for (int i = 1; i <= n; i++)
        array[i] = rand() % 10;

    sort (array.begin(), array.end());
    
    cout << "Array: ";

    for (int i = 1; i <= n; i++)
    {
        cout << "[" << i << "]: " <<array[i];

        if (i == n)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }

    int index = index_equal_value(1, n, array, index);

    if (index)
    {
        cout << ":D - Existe o elemento do index " << index << " é igual ao seu valor, ou seja, igual a " << array[index] << "\n";
    }
    else
    {
        cout << "T-T - Não existe array[i] = i;\n";
    }

    return 0;
}