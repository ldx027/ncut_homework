#include <iostream>
#include <list>
using namespace std;

int main()
{
	int a, R;
	cin >> a >> R;

	list<int> lst;

	while (a)
	{
		lst.push_front(a % R);
		a /= R;
	}

	for (auto it = lst.begin(); it != lst.end(); it++)
	{
		if (*it < 10) cout << *it;
		else cout << char('A' + *it - 10);
	}

	return 0;
}