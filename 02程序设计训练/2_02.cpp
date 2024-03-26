#include <iostream>
using namespace std;

int power(int x, int n)
{
	int rst = 1;
    int base = x;
    while (n > 0)
    {
        if (n & 1) rst *= base;
        base *= base;
        n >>= 1;
    }
	return rst;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int R, a;
	cin >> a >> R;

	int ans = 0;
	for (int i = 0; a; i++)
	{
		ans += power(R, i) * (a % 10);
		a /= 10;
	}

	cout << ans;

	return 0;
}