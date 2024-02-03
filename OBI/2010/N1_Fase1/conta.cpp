#include <iostream>

using namespace std;

int main()
{
	int cont = 7;
	int a; cin >> a;
	if (a>100)
	{
		cont += 5* (a-100);
		a=100;
	}
	if (a>30)
	{
		cont += 2*(a-30);
		a=30;
	}
	if (a>10)
	{
		cont += a-10;
		a=10;
	}
	cout << cont;
}
