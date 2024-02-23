#include <bits/stdc++.h>

using namespace std;

int pot (int aux, int b, int n)
{
    if (n == 0)
        return 1;

    if (n == 1)
        return aux;

    if (n % 2 == 1)
    {
        return b * pot(aux * aux, b, n/2);
    }
    else
    {
        return pot(aux * aux, b, n/2);
    }
}

int main()
{
    int b;
    cout << "Digite a base: ";
    cin >> b;

    cout << "Digite o expoente: ";
    int n;
    cin >> n;

    cout << "Valor do " << b << " elevado a " << n << " é igual a " << pot(b, b, n) << endl;

    return 0;
}