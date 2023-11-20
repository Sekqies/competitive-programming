#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;




int main()
{
	int N,M;
	cin >> N >> M;
	vector <int> alt(N+1);
	for (int i=0; i<N; ++i)
	{
		int input;
		cin >> input;
		alt[i] = input-M;
	}
	
	int res=0;
	for (int i=0; i<N-1; i++)
	{
		int dista = alt[i];
		alt[i+1] -= dista;
		alt[i] = 0;
		res += abs(dista);
	}
	cout << res;
}
