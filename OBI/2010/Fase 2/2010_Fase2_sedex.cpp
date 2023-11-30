#include <iostream>
#include <math.h>
using namespace std;
const double pi = 3.14159265358979323846;


int main()
{
	int a,b,c,r;
	cin >> a >> b >> c >> r;
	long vol = a*b*c;
	long ar = 4*r*r*r;
	if (double(vol) <= double((ar*pi)/3))
		cout << "S";
	else
		cout << "N";
}
