#include <bits/stdc++.h>
using namespace std;

//Breadth first search
//Compelxitate: 0(n+m)

vector<int> graf[100001];
bitset<100001> viz;
ifstream fin("graf.txt");


void citire()
{
    int n, m, x, y;
    fin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        fin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
}

void DFS(int nod)
{
    cout << nod << " ";
    int y;
    viz[nod] = 1;
    for(int i = 0; i < graf[nod].size(); i++)
    {
        y = graf[nod][i];
        if(!viz[y]) DFS(y);
    }
}


int main()
{
    citire();
    DFS(1);
}