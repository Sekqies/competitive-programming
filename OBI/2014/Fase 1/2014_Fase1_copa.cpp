#include <iostream>
#include <vector>
#include <utility>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
vector<pii> rodo[1010];
vector<pii> ferro[1010];

void dfs (int atual)
{
	
}
int main()
{
	int N,R,F;
	cin >> N >> F >> R;
	for (int i=0; i<F; i++)
	{
		int A,B,C;
		cin >> A >> B >> C;
		rodo[A].push_back(mp(B,C));
		rodo[B].push_back(mp(A,C));
	}
	for (int i=0; i<F; i++)
	{
		int A,B,C;
		cin >> A >> B >> C;
		ferro[A].push_back(mp(B,C));
		ferro[B].push_back(mp(A,C));
	}
}
