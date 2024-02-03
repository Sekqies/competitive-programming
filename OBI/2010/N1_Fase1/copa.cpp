#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair

struct node {
	int left;
	int right;
	pii data;
};
node tree[16];
int res;
int preencher(int atual)
{
	if (atual>15)
	{
		return -1;
	}
	tree[atual].left = preencher(atual*2+1);
	tree[atual].right = preencher(atual*2);
	//cout << 16-atual <<":\n left: " << 16-tree[atual].left << "\n right: " << 16-tree[atual].right << "\n\n";
	return atual;
}

void percorrer(int atual)
{
	auto a = tree[atual];
	if (a.left == -1)
	{
		int val =  16-atual;
		if (a.data.first > a.data.second)
			res = (2*val -1);
		else
			res = 2*val; 		
		return;		
	}
	if (a.data.first > a.data.second)
		percorrer(a.left);
	else
		percorrer(a.right);
}
int main()
{
	preencher(1);
	for (int i=1; i<=15;i++)
	{
		int a,b;
		cin >> a >> b;
		tree[16-i].data = mp(a,b);
	}
	percorrer(1);
	cout << char('A' + res -1);
	
	
}
