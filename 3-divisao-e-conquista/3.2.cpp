#include <bits/stdc++.h>

using namespace std;

void print_stack(stack<int> res)
{
	cout << "START RES\n";
	while (!res.empty())
	{
		cout << res.top() << endl;
		res.pop();
	}
	cout << "END RES\n";
}

stack<int> sort(stack<int> s1, int &count)
{
	count++;

	if (s1.size() > 1)
	{
		stack<int> s2;

		int tam = s1.size() / 2;
		
		while (tam > 0)
		{
			s2.push(s1.top());
			s1.pop();
			tam--;
		}

		s1 = sort(s1, count);
		s2 = sort(s2, count);

		stack<int> s_aux;

		while (!s1.empty() || !s2.empty())
		{
			int elem1 = INT_MAX, elem2 = INT_MAX;

			if (!s1.empty())
				elem1 = s1.top();

			if (!s2.empty())
				elem2 = s2.top();


			if (elem1 < elem2)
			{
				s_aux.push(elem1);

				if (!s1.empty())
					s1.pop();
			}
			else
			{
				s_aux.push(elem2);
				
				if (!s2.empty())
					s2.pop();
			}
		}

		print_stack(s_aux);

		while (!s_aux.empty())
		{
			s1.push(s_aux.top());
			s_aux.pop();
		}
	}

	return s1;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

	stack<int> s;

	int n;
	cin >> n;

	int tam = n;

	cout << "START INPUT\n";

	for (int i = 0; i < n; i++)
	{
		int elem = rand() % 10;
		cout << elem << endl;
		s.push(elem);
	}

	cout << "END INPUT\n";

	int count = 0;

	s = sort(s, count);
	
	cout << "count = " << count << endl;

	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
}
