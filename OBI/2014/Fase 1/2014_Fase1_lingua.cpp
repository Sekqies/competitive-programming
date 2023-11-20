#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	string input="";
	while (true)
	{
		char a;
		a = getchar();
		if (int (a) == 10)
			break;
		input+=a;
		
	}
	string o = "";
	int cont =0;
	for (const char& c : input) {
		if (c != ' '){
			if (cont%2!=0)
			{
				o+=c;
			}
			cont++;
		}
		else
			o+=c;
		
	}
	
	cout << o;
}
