#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;


//PRIMEIRO: Conexão, SEGUNDO: valor
vector<pii> rodo[1010];
vector<pii> ferro[1010];
vector<int> custo(1010,99999);
vector<bool> flagferro(1010,0);
vector<bool> flagrodo(1010,0);
void dfs(int atual)
{

		cout << atual << endl;
		vector <pii> vferro = ferro[atual];
		vector <pii> vrodo = rodo[atual];
		for (const auto& par : vferro)
		{
			if (custo[atual] + par.second < custo[par.first])
			{
				 
				custo[par.first] = custo[atual] + par.second;
				flagferro[par.first] = true;
				int proximo = par.first;
				dfs(proximo);
			}
		}
		
		for (const auto& par : vrodo)
		{
			if (custo[atual] + par.second < custo[par.first] and !flagferro[par.first]){
				custo[par.first] = custo[atual] + par.second;
				int proximo = par.first;
				dfs(proximo);
			}
		}
		
	
}

int main(){
	int N,F,R; 
	cin >> N;
	cin >> F;
	cin >> R;
	custo[1]= 0;
	for (int i=0; i<F; ++i)
	{
		int A,B,C;
		cin >> A >> B >> C;
		ferro[A].push_back(mp(B,C) );
		ferro[B].push_back(mp(A,C));
	}
	for (int i=0; i<R; ++i)
	{
		int A,B,C;
		cin >> A >> B >> C;
		rodo[A].push_back(mp(B,C));
		rodo[B].push_back(mp(A,C));
	}
	vector <int> proximos;
	
	proximos.push_back(1);
	int atual = 1;
	a:
		vector<pii> vrodo = rodo[atual];
		vector<pii> vferro = ferro[atual];
		for (const auto& par : vferro)
		{
			if (custo[atual] + par.second < custo[par.first])
			{
				custo[par.first] = custo[atual] + par.second;
				flagferro[par.first] = true;
				atual = par.first;
				goto a;
			}
		}
		for (const auto& par : vrodo)
		{
			if (custo[atual] + par.second < custo [par.first])
			{
				custo[par.first] = custo[atual] + par.second;
				atual = par.first;
				goto a;
			}
		}
	
	
	
	int res = -1;
	for (int i=1; i<=N;i++)
	{
		if (custo[i] = 99999)
		{
			for (const auto& fer : ferro[i])
			{
				if (custo[fer.first] + fer.second < custo[i])
				{
					custo[i] = custo[fer.first] + fer.second;
					flagrodo[i] = true;
				}
			}
			if (!flagrodo[i])
			{
				for (const auto& rod: rodo[i])
				{
					if (custo[rod.first] + rod.second < custo[i])
					{
						custo[i] = custo[rod.first] + rod.second;
					}
				}
			}
		}
		if (custo[i] > res)
			res = custo[i];
		cout << '\n' << custo[i] << '\n';
	}
	cout << res;
	return 0;
}
