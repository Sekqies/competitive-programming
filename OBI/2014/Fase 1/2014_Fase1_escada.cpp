#include <iostream>

using namespace std;

int main()
{
	int N,M;
	cin >> N >> M;
	int m[500][500];
	bool boom = false;
	
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			int x; cin >> x;
			m[i][j] = x;
		}
	}
	
	for (int i=0; i<N; ++i)
	{
		for (int j=0; j<M; ++j)
		{
			if (m[i][j] != 0 and i!= N-1)
			{
				for (int k =i+1; k<N; ++k)
				{
					if(m[k][j] !=0)
					{
						boom = true;
						break;
					}
				}
				break;
			}
			if (boom)
				break;
				
				
			if (j==M-1)
			{
				for (int a= i+1; a<N; a++)
				{
					if (m[a][j] !=0)
					{
						boom = true;
						break;
					}
				}
			}
		}
	}
	
	if (boom)
		cout << "N";
	else
		cout << "S";
}
