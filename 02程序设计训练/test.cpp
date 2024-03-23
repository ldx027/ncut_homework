#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	int rst = 0;
	for (int i = 0; i <= n; i++) rst += n;

	cout << rst << endl;

	return 0;
}