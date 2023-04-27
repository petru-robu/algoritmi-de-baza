#include <bits/stdc++.h>
#define pb push_back
#define mod 666013
using namespace std;

ifstream fin("kfib.in");
ofstream fout("kfib.out");

vector<vector<int>> inmultire(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    vector<vector<int>> res;

    int m1 = mat1[0].size(), n1 = mat1.size();
    int m2 = mat2[0].size(), n2 = mat2.size();

    for(int i=0; i<n1; i++)
    {
       vector<int> aux;
       for(int j=0; j<m2; j++)
       {
        int r = 0;
        for(int k=0; k<m1; k++)
          r=(r+((long long)mat1[i][k]*mat2[k][j]%mod))%mod;
        aux.pb(r);
       }
       res.pb(aux);
    }
    return res;
}

vector<vector<int>> ridicare(vector<vector<int>> &mat, int p)
{

    vector<vector<int>> res = mat;
    for(int i=0; i<res.size(); i++)
      for(int j=0; j<res.size(); j++)
        res[i][j] = (i==j) ? 1 : 0;

    while(p!=0)
    {
      if(p%2!=0)
      {
        res = inmultire(mat, res);
      }
      mat = inmultire(mat, mat);
      p/=2;
    }
    return res;
}

int main()
{
  int n;
  fin>>n;

  vector<vector<int>> z; vector<int> aux;
  aux.pb(0); aux.pb(1); z.pb(aux);
  aux[0]=1; z.pb(aux);

  vector<vector<int>> sol;
  sol = ridicare(z, n-1);

  fout<<sol[1][1];
}
