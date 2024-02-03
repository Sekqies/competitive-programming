#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 500;

int main()
{
	int N, estrada[MAXN], val[MAXN][MAXN] = {0};
	bool dp[MAXN][MAXN] = {0};
	cin >> N;
	for (int i=0; i<N; i++)
	{
		int x; cin>> x;
		estrada[i] = x;
	}
	int res = 1;
	for (int i=0; i<N-1; i++)
	{
		for (int j=i+2; j<N; j++)
		{
			if (estrada[i] < estrada[j] and not dp[j][estrada[i]])
			{
				val[estrada[i]][estrada[j]]+=2;
				dp[j][estrada[i]] = true;
				dp[estrada[i]][j] = true;
				res = max(val[estrada[i]][estrada[j]],res);
			}
		}
	}
	cout << res;
	
}
