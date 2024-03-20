#include <bits/stdc++.h>

using namespace std;

auto start = chrono::high_resolution_clock::now();

vector<vector<int>> tabuleiro(9, vector<int>(9, -1));
vector<pair<int, int>> mov;

void passeio_do_cavalo(int k, int i, int j)
{
    if (k == 65)
    {
        cout << "Solução válida:\n\n";

        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
            {
                cout << tabuleiro[i][j] << " ";
            }

            cout << "\n";
        }

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;

        cout << "\nTempo de execução: " << elapsed.count() << " segundos.\n";

        exit(0);
    }

    int l = 1;

    while (l <= 8)
    {
        int x = i + mov[l].first;
        int y = j + mov[l].second;

        if (((x >= 1) && (x <= 8)) && ((y >= 1) && (y <= 8)) && tabuleiro[x][y] == -1)
        {
            tabuleiro[x][y] = k;
            passeio_do_cavalo(k + 1, x, y);
            tabuleiro[x][y] = -1;
        }
        
        l++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    mov.push_back({0, 0});
    mov.push_back({1, 2});
    mov.push_back({2, 1});
    mov.push_back({2, -1});
    mov.push_back({1, -2});
    mov.push_back({-1, -2});
    mov.push_back({-2, -1});
    mov.push_back({-2, 1});
    mov.push_back({-1, 2});

    tabuleiro[1][1] = 1;
    passeio_do_cavalo(2, 1, 1);

    return 0;
}