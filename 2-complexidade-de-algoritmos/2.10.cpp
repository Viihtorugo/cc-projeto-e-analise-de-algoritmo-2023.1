#include <bits/stdc++.h>

using namespace std;

/*
    No quicksort a escolha do pivô tente a modificar sua complexidade.
    Assim, ao escolher o pivô como o ultimo elemento e como o array
    com elementos iguais 

    T(n) = {
        t(n + 1) + n, se n menor que o tamanho do array;
        0, caso contrário
    }
*/

void swap(int &x, int &y)
{
    int aux = x;
    x = y;
    y = aux;
}

void quicksort(vector <int> &A, int i, int f, int &count)
{
    if (i < f)
    {
        int p = f;
        int l = i, r = f;

        while (l < r)
        {
            while(l <= f && A[l] <= A[p])
            {
                l++;
                count++;
            }

            while (r > i && A[r] > A[p])
            {
                r--;
                count++;
            }

            if (l < r)
                swap(A[l], A[r]);
        }

        swap(A[p], A[r]);

        p = r;

        cout << "i = " << i << " e f = " << f << " pivo = " << p << endl;

        //separa o quicksort em 2 arrays através do pivot no fim
        quicksort(A, i, p - 1, count);
        quicksort(A, p + 1, f, count);
    }
}

int main ()
{
    int n;
    cout << "Digite o numero de elementos do array: ";
    cin >> n;
    
    if (n <= 0)
    {
        cout << "Digite um valor acima de 0!"<< endl;

        return -1;
    }

    vector <int> A (n + 1, 4);

    //Execute esse for para entender o pivô com números distintos
    //for (int i = 0; i < n + 1; i++)
    //    A[i] = rand() % 100;
    
    cout << endl << "Array: ";
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl << endl;

    int count = 0;

    cout << endl << "Execuções do algoritmo!" << endl << endl;
    quicksort(A, 1, n, count);
    
    cout << endl << "Array: ";
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl << endl;

    cout << "O algoritmo executou " << count << " passos!" << endl;
}