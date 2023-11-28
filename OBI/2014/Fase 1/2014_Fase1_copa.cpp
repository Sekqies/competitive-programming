#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10e5;

int pai[MAXN];
int peso[MAXN] = {0};
vector<array<int,4>> caminhos;


int find(int x)
{
	if (pai[x] == x)
		return x; 
	else
		return pai[x] = find(pai[x]);
}
bool join(int x, int y)           
{
	x = find(x);
	y = find(y);

	if (x==y)
		return false;
	if(peso[x] > peso[y])
		pai[y] = x;
	else if (peso[x] < peso[y])
		pai[x] = y;
	
	else if (peso[x] == peso[y])
	{
		pai[x] = y;
		peso[y]++;
	}
	return true;
}

bool sortPerso(array<int,4> x, array<int,4> y)
{
	if (x[0] != y[0])
		return x[0] < y[0];
	else
		return x[3] < y[3];
}

int main()
{
	int n,r,f;
	cin >> n >> f >> r;
	for (int i=1; i<=n; i++)
	{
		pai[i]=i;
	}
	for (int i=0; i<f; i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		caminhos.push_back({1,a,b,c} );
	}
	for (int i=0; i<r;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		caminhos.push_back({2,a,b,c} );
	}
	sort(caminhos.begin(),caminhos.end(),sortPerso);
	 int res = 0;
	for (const auto& cam : caminhos)
	{
		if (join(cam[1],cam[2]))
			res+= cam[3];
	}
	
	cout << res;
}
