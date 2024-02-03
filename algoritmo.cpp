#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <math.h>
#include <unordered_map>
using namespace std;
using namespace std::chrono;
#define hrc() high_resolution_clock::now()
#define dc(x,y) duration_cast<microseconds>(x-y)
typedef vector<int>::iterator rait;
const int MAXN = 50000;
const int CEILING = 600000;

int MAXVALUE=-1;
int MINVALUE = CEILING +1;


void printArray(vector<int> ar)
{
	cout << "{";
	for (int i=0; i< ar.size()-1; i++)
	{
		cout << ar[i] << ", ";
	}
	cout << ar[ar.size()-1] << "}";
}

double measureTime(vector<int>& ar, void(*func)(vector<int>&))
{
	auto func_start= hrc();
	func(ar);
	auto func_end = hrc();
	return dc(func_end,func_start).count();
}
double measureTime(rait a, rait b, void(*func)(rait,rait))
{
	auto func_start= hrc();
	func(a,b);
	auto func_end = hrc();
	return dc(func_end,func_start).count();
}
void ignisSort(vector<int>& ar)
{
	int n= ar.size();
	bool isNegative = false;
	for (int i=0; i<n; i++)
	{
		MAXVALUE = max(MAXVALUE,ar[i]);
		MINVALUE = min(MINVALUE,ar[i]);
	}
	vector<int> aux(MAXVALUE-MINVALUE+1,0);
	for(int i=0; i<n; i++)
	{
		aux[ar[i]-MINVALUE]++;
	}
	int cont =0;
	for(int i=0; i<MAXVALUE-MINVALUE+1;i++)
	{
		if (aux[i])
		{
			for (int a=0; a<aux[i]; a++)
			{
				ar[cont] = i;
				cont++;
			}
		}
	}
}

void altIgnisSort(vector<int>& ar)
{
	int n= ar.size();
	unordered_map<int,int> aux;
	aux.reserve(n);
	aux.max_load_factor(0.25);
	for(int i=0; i<n; i++)
	{
		MAXVALUE = max(ar[i],MAXVALUE);
		MINVALUE = min(ar[i],MINVALUE);
	}
	for(int i=0;i<n;i++)
	{
		aux[ar[i]-MINVALUE]++;
	}
	int cont = 0;
	ar.clear();
	for (int i=0; i< MAXVALUE - MINVALUE; i++)
	{
		if (aux.find(i) != aux.end())
		{
			for (int a=0; a<aux.at(i);a++)
			{
				ar[cont] = i;
				cont++;
			}
		}
	}
}

int main()
{
	vector<int> ar(MAXN);
	vector<int> arIgnis(MAXN);
	vector<int> arIgnisAlt(MAXN);
	
	for (int i=0; i<MAXN; i++)
	{
		ar[i] = rand() % CEILING;
		arIgnis[i] = ar[i];
		arIgnisAlt[i] = ar[i];
	}
	
	double qsort_time = measureTime(ar.begin(),ar.end(),&sort);
	double isort_time = measureTime(arIgnis,&ignisSort);
	double alt_isort_time = measureTime(arIgnisAlt,&altIgnisSort);
	
	
	//char resp = arIgnis == ar? 'S' : 'N';
	cout << "Quantidade de elementos: " << MAXN << endl;
	cout << "Maior valor encontrado: " << MAXVALUE << endl;
	//cout << "Ordenadas corretamente?: " << resp << endl << endl;
	cout << "qsort time: " << qsort_time << endl;
	//cout << "qsort array: "; printArray(ar);
	cout << "ignis time: " << isort_time << endl;
	//cout << endl << "ignis array:"; //printArray(arIgnis);
	cout<< "alt ignis time: " << alt_isort_time;
}
