#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 10e6+50;
vector<int> pai(MAXN);



int find (int x)
{
	if (x == pai[x]) 
	return x;
	
	return pai[x] = find(pai[x]);
}

void join(int x, int y)
{
	pai[find(x)] = find(y);
}


int main()
{
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
