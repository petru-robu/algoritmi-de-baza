#include <bits/stdc++.h>
using namespace std;
ifstream fin  ("maxflow.in");
ofstream fout ("maxflow.out");

//Edmons-Karp
//Complexitate O(n*m^2)

const int INF = 2e9;
const int NMAX= 1005;

int n, m, x, y, c, minflow, flux;

int cap[NMAX][NMAX], flow[NMAX][NMAX];
vector <int> edge[NMAX];

int crt, parent[NMAX];
bool viz[NMAX];

bool find_path()
{
    queue<int> path;

    for(int i=1; i<=n; i++)
        viz[i] = false;

    viz[1] = true;
    path.push(1);

    while(!path.empty())
    {

        crt = path.front();
        path.pop();

        for(auto nxt : edge[crt])
            if(!viz[nxt] && flow[crt][nxt] < cap[crt][nxt])
            {
                parent[nxt] = crt;
                viz[nxt] = true;

                path.push(nxt);

                if(nxt==n)
                    return true;
            }
    }
    return false;
}

int main()
{
    fin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        fin>>x>>y>>c;
        edge[x].push_back(y);
        edge[y].push_back(x);
        cap[x][y] = c;
    }


    while(find_path())
        for(auto leaf : edge[n])
            if(viz[leaf] && flow[leaf][n] < cap[leaf][n])
            {
                parent[n] = leaf;
                minflow = INF;

                crt = n;
                while(parent[crt])
                {
                    minflow = min(minflow, cap[parent[crt]][crt] - flow[parent[crt]][crt]);
                    crt = parent[crt];
                } //bottleneck

                flux += minflow;

                crt = n;
                while(parent[crt])
                {
                    flow[parent[crt]][crt] += minflow;
                    flow[crt][parent[crt]] -= minflow;
                    crt = parent[crt];
                }
            }

    fout<<flux<<1;
    return 0;
}
