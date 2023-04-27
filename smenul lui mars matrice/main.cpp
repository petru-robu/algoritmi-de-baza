#include <bits/stdc++.h>

int mat[100][100];

void read()
{
  int t, x1, y1, x2, y2, val;
  fin>>n>>m>>q>>t;
  while(t--)
  {
    fin>>x1>>y1>>x2>>y2>>val;
    mat[x1][y1] += val;
    mat[x2+1][y2+1] += val;
    mat[x1][y2+1] -= val;
    mat[x2+1][y1] -= val;
  }

  //print_mat(mat, n, m);

  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];

  //print_mat(mat, n, m);

  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      if(mat[i][j] >= q)
        mat[i][j]=0;
      else
        mat[i][j]=-1;

  //print_mat(mat, n, m);
}

int main()
{
    return 0;
}