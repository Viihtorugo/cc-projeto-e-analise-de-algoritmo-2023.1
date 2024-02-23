#include <bits/stdc++.h>

using namespace std;

int regua[int(1e5)];

void rec (int traco, int esquerda, int direita, int meio)
{
    if(!traco)
    {
        return;
    }
    else
    {
        regua[meio] = traco;
        rec(traco - 1, esquerda, meio, (esquerda+meio)/2);
        rec(traco - 1, meio, direita, (direita+meio)/2);
    }
}


int main()
{
    int ordem;
    cin >> ordem;

    int valor = pow(2, ordem);
    rec(ordem, 0, valor, valor/2);
    for(int i = 0; i <= valor; i ++)
    {  
        printf("%2d . ", i);
        for(int j = 0; j < regua[i]; j++)
        {
            cout<<"-";
        }
        cout << endl;
    }

    return 0;
}
