#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct phone {
	string num;
	int sum;
};
bool cmp_phone(phone p, phone q)
{
	return p.num < q.num;
}
char map(char ch)
{
	char c = '\0';
	if (ch == 'A' || ch == 'B' || ch == 'C')
		c = '2';
	else if (ch == 'D' || ch == 'E' || ch == 'F')
		c = '3';
	else if (ch == 'G' || ch == 'H' || ch == 'I')
		c = '4';
	else if (ch == 'J' || ch == 'K' || ch == 'L')
		c = '5';
	else if (ch == 'M' || ch == 'N' || ch == 'O')
		c = '6';
	else if (ch == 'P' || ch == 'R' || ch == 'S')
		c = '7';
	else if (ch == 'T' || ch == 'U' || ch == 'V')
		c = '8';
	else if (ch == 'W' || ch == 'X' || ch == 'Y')
		c = '9';
	return c;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	struct phone* a = new struct phone[n];
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		char str1[20];
		cin >> str1;
		int len = (int)strlen(str1);
		char str2[9];
		int s = 0;
		for (int j = 0; j < len; j++)
		{
			if (str1[j] >= '0' && str1[j] <= '9')
			{
				str2[s++] = str1[j];
			}
			else if (str1[j] >= 'A' && str1[j] <= 'Z')
			{
				str2[s++] = map(str1[j]);
			}
			if (s == 3)
			{
				str2[s++] = '-';
			}
		}
		str2[s] = '\0';
		string str3(str2);
		if (t == 0)
		{
			a[t].num = str3;
			a[t].sum = 1;
			t++;
		}
		else
		{
			int z = 0;
			for (int k = 0; k < t; k++)
			{
				if (str3 == a[t].num)
				{
					a[t].sum++;
					z = 1;
					break;
				}
			}
			if (z == 0)
			{
				a[t].num = str3;
				a[t].sum = 1;
				t++;
			}
		}
		/*if (t != 0)
		{
			bool b = false;
			for (int k = 0; k < t; k++)
			{
				if (str3 == a[t].num)
				{
					a[t].sum++;
					b = true;
					break;
				}
			}
			if (b == false)
			{
				a[t].num = str3;
				a[t].sum = 1;
				t++;
			}
		}
		else
		{
			a[t].num = str3;
			a[t].sum = 1;
			t++;
		}*/
	}
	sort(a, a + t, cmp_phone);
	bool b = false;
	for (int i = 0; i < t; i++)
	{
				if (a[i].sum >= 1)
		{
			cout << a[i].num << " " << a[i].sum << endl;
			b = true;
		}
	}
	//if (b == false)
	//{
	//	cout << "No duplicates" << endl;
	//}
	delete[] a;
	return 0;
}