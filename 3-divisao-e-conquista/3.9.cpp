#include <bits/stdc++.h>

using namespace std;

bool max_point(int i, int n, vector<int> array)
{
    if (i <= n)
    {
        int mid = (i + n) / 2;

        cout << "[" << i << "]: " << array[i] << " e [" << mid << "]: " << array[mid] << " e mid = " << mid << endl;

        if (array[mid] > array[mid - 1] && array[mid] > array[mid + 1])
        {
            cout << "\nO ponto máximo p é igual a " << array[mid] << "\n";
            return true;
        }
        else
        {
            if (array[i] < array[mid - 1])
            {
                bool v = max_point(i, mid - 1, array);

                if (v == false)
                    v = max_point(mid + 1, n, array);

                return v;
            }
            else
            {
                bool v = max_point(mid + 1, n, array);

                if (v == false)
                    v = max_point(i, mid - 1, array);

                return v;
            }
        }
    }

    return false;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int n;

    cout << "Informa a quantidade de elementos: ";
    cin >> n;

    vector<int> array(n + 1);

    vector<int> aux(n/2);
    priority_queue<int> pq;

    for (int i = 0; i < n / 2; i++)
        aux[i] = rand() % n;

    sort(aux.begin(), aux.end());

    int k = 1;

    for (int i = 0; i < aux.size(); i++)
    {
        array[k] = aux[i];
        k++;
    }

    array[k] = n * 10;

    for (int i = k; i <= n; i++)
        pq.push(rand() % n);

    for (int i = k + 1; i <= n && !pq.empty(); i++)
    {
        array[i] = pq.top();
        pq.pop();
    }

    cout << "\nArray: ";

    for (int i = 1; i <= n; i++)
    {
        cout << "[" << i << "]: " << array[i];

        if (i == n)
        {
            cout << endl << endl;
        }
        else
        {
            cout << " ";
        }
    }

    max_point(1, n, array);

    return 0;
}