#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tab (3, vector<int>(3, 0));

void quadrado_magico(int k)
{
    if (k == 9)
    {
        //Verificação de solução valida
        int count = 0;

        for (int i = 0; i < 3; i++)
            count += tab[0][i];
        

        int aux;

        for (int i = 1; i < 3; i++)
        {
            aux = 0;

            for (int j = 0; j < 3; j++)
            {
                aux += tab[i][j];
            }

            if (count != aux)
                return;
        }

        aux = 0;

        for (int i = 0; i < 3; i++)
            aux += tab[i][i];

        if (count != aux)
            return;

        aux = 0;

        for (int i = 0; i < 3; i++)
            aux += tab[i][2 - i];


        if (count != aux)
            return;

        cout << "Solução válida:\n\n";

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << tab[i][j] << " ";
            }

            cout << "\n";
        }

        return;
    }

    int number = 1;

    int i = k / 3;
    int j = k % 3;

    while (number <= 9)
    {
        bool conflito = false;

        //verrificação de numeros distintos!
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (tab[i][j] == number)
                    conflito = true;

        if (!conflito)
        {
            tab[i][j] = number;
            quadrado_magico(k + 1);
            tab[i][j] = 0;
        }

        number++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    quadrado_magico(0);
    return 0;
}