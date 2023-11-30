#include <iostream>
using namespace std;
const int MAXN = 10e6+50;
int pai[MAXN];
int peso[MAXN] = {0};



int find (int x)
{
	if (x == pai[x]) 
	return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y)
{
	x = find(x);
	y = find(y);
	
	if (peso[x] > peso[y])
		pai[y] = x;
	if (peso[y] > peso[x])
		pai[x] = y;
	if (peso[y] == peso[x])
	{
		pai[x] = y;
		peso[y]++;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	for (int i=1; i<=n; i++)
	{
		pai[i] = i;
 	}
	for (int i=0; i<k; i++)
	{
		char c;
		int a,b;
		cin >> c >> a >> b;
		if (c == 'C')
		{
			if (find(a) == find(b))
				cout << "S" << '\n';
			else
				cout << "N" << '\n';
		}
		if (c == 'F')
		{
			join(a,b);
		}
	}
}
