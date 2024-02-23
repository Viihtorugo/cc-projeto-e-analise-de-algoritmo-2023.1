#include <bits/stdc++.h>

using namespace std;

void sum_descent(vector<vector<int>> t, int n)
{
	if (n <= 0)
		return;

	int index = 1;

	vector<vector<int>> s(n + 1, vector<int>(n + 1, INT_MIN));

	s[1][1] = t[1][1];

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{

			s[i][j] = t[i][j] + max(s[i - 1][j], s[i - 1][j - 1]);

			if (s[i][index] < s[i][j])
				index = j;
		}
	}

	cout << "\n\nMatriz resultante n = " << n << ":\n\n";
	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= i; j++)
		{
			cout << s[i][j] << " ";
		}

		cout << endl;
	}

	cout << "\nA soma é igual a " << s[n][index] << endl;

	
	stack <pair<int, int>> caminho;

	for (int i = n; i >= 1; i--)
	{

		if (s[i][index] - s[i - 1][index] == t[i][index])
		{
			caminho.push({i, t[i][index]});
		}
		else
		{
			caminho.push({i, t[i][index]});
			index--;
		}
		
	}

	cout << "\nElementos: \n";

	while (!caminho.empty())
	{
		cout << "linha " << caminho.top().first << ": " << caminho.top().second << " elem\n";
		caminho.pop();
	}
	
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> t(n + 1, vector<int>(n + 1, INT_MIN));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> t[i][j];

	cout << "Matriz inicial n = " << n << ":\n\n";
	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= i; j++)
		{
			cout << t[i][j] << " ";
		}

		cout << endl;
	}

	sum_descent(t, n);

	return 0;
}
