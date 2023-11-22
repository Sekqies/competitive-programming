#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string a,b;
	int mins = min(a.size(),b.size());
	int maxs = max(a.size(),b.size());
	cin >> a >> b;
	int res = -1;
	for (int i=0; i<mins; i++)
	{
		if (a==b)
		{
			cout << "PJpsa";
			res = i;
			break;
		}
		a[i] = ' ';
		b[i] = ' ';
	}
	cout << res;
	if (res==-1)
		res = maxs;
	cout << res;
}
