#include <bits/stdc++.h>

using namespace std;

int number_magic(int n) 
{
    int sum = (n*(n + 1))/2;

    int ans = n - 1;

    while (ans--) 
    {
        int number;
        cin >> number;

        sum -= number;
    }

    return sum;
}

int main () {
    int n;
    cin >> n;
    
    cout << "Maria adivinhou o numero: " number_magic(n) << endl;

    return 0;
}