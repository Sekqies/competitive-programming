#include <iostream>
#include <vector>
#define MAXN 205
using namespace std;
int N,M,X,Y,K;
vector<vector<int>> imagem(MAXN, vector<int>(MAXN, 0));
int M1[] = {0,0,-1,1,1,-1,1,-1};
int M2[] = {1,-1,0,0,1,-1,-1,1};
int cont=0;
void dfs(int lin, int col)
{
imagem[lin][col] = 1;
cont++;
for (int i=0; i<8; i++)
{
    if (lin+M1[i] > 0 and lin+M1[i] <=N and col+M2[i] > 0 and col+M2[i] <=M)
    {
        if (imagem[lin+M1[i]][col+M2[i]] != 1)
            dfs(lin+M1[i],col+M2[i]);
    }
}
}

int main()
{
    cin >> N >> M >> X >> Y >> K;
    for (int i=1; i<=K; i++)
    {
        int X1,Y1;
        cin >> X1 >> Y1;
        imagem[X1][Y1] = 1;
    }
    dfs(X,Y);
    cout << cont << endl;
    return 0;
}
