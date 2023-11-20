#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N; 
	cin >> N;
	string tabuleiro[100];
	vector<int> comidas;
	for (int i=0; i<N;i++)
	{
		string a; cin >> a;
		tabuleiro[i] = a;
	}
	bool chave = false;
	int cont =0;
	for (int i=0; i<N; i++)
	{
		int jota=0;
		if (chave)
			jota=N -1;
		chave = !chave;
		for (int j=0; j<N; j++)
		{
			int val = abs(jota-j);
			 
			if (tabuleiro[i][val] == 'o') {
				cont++;
			}
			if (tabuleiro[i][val] == 'A') {
				comidas.push_back(cont);
				cont=0;
			}
		}
	}
	comidas.push_back(cont);
	int res = -1;
	for (const int val : comidas)
	{
		if (val > res)
			res= val;
		 
	}
	cout << res;
}
