#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int N,K;
	cin >> N >> K;
	vector <string> alunos;
	for (int i=0;i<N;i++)
	{
		string a; cin >> a;
		alunos.push_back(a);
	}	
	sort(alunos.begin(), alunos.end());
	cout << alunos[K-1];
		
}

