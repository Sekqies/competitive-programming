#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair

const int MAXN = 10e6;
const int MAXE = 10e3;

bool roda[MAXN][MAXE];
int indio[MAXE];

int main()
{
	int N,E;
	for (int i=0; i<E; i++)
	{
		int v,d;
		cin >> v >> d;
		roda[v][i] = true;
		indio[i] = d;
	}
	int cont = 1;
	while (cont++)
	{
		for (int i=0; i<E; i++)
		{
			if (roda)
		}
	}
	cont--;
	cout << cont;
}
