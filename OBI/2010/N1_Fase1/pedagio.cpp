#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int l,d,k,p;
	cin >> l >> d >> k >> p;
	int custo = k*l + floor(l/d) * p;
	cout << custo;
}
