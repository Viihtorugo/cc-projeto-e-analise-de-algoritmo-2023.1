#include <bits/stdc++.h>

using namespace std;

int num_max(vector<int> A, int i, int f)
{
    if (i == f)
        return A[i];

    int m = (i + f) / 2;

    int a = num_max(A, i, m);
    int b = num_max(A, m + 1, f);

    if (a < b)
        return b;

    return a;
}

int main()
{
    vector<int> A = {1, 20, 30, 40, 5, 100, 4, 400};
    cout << num_max(A, 1, A.size()) << endl;

    return 0;
}