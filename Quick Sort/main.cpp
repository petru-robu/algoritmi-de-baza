#include <bits/stdc++.h>
#define S_MAX 10001
using namespace std;
ifstream fin("../vector.in");

int tmp[S_MAX];

void QuickSort(int v[], int st, int dr)
{
  if(st<dr)
	{
		int m=(st+dr)/2;
		swap(v[st], v[m]);

		int i=st, j=dr, d=0;

		while(i<j)
		{
			if(v[i]>v[j])
			{
				swap(v[i], v[j]);
				d=1-d;
			}
			i+=d;
			j-= (1-d);
		}

		QuickSort(v, st , i-1);
		QuickSort(v, i+1 , dr);
	}

}

int main()
{
  int v[S_MAX], n;
  fin>>n;

  for(int i=1; i<=n; i++)
    fin>>v[i];

  QuickSort(v, 1, n);

  for(int i=1; i<=n; i++)
    cout<<v[i]<<' ';

  return 0;
}
