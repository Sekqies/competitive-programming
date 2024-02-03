#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
const int MAXN = 10e4 +1;



int main()
{
	ios::sync_with_stdio(0);
	int n,t;
	cin >> n >> t;
	map<int,string> alunos;
	vector<string> times [1001];
	for (int i=0; i<n;i++)
	{ 
		string a; int b;
		cin >> a >> b;
		alunos[b] = a;
	}
	int cont = n%t == 0? t : n%t;
	for (const auto& a: alunos)
	{
		times[cont].push_back(a.second);
		cont = (cont - 1)%t;
		cont = cont==0? t: cont;
	}
	
	for (int i=1; i<= t; i++)
	{
		sort(times[i].begin(),times[i].end());
		cout << "Time " << i << '\n';
		for (const string& a: times[i])
		{
			cout << a << '\n';
		}
		cout << '\n';
	}
	
}
