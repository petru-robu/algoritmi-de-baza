#include <bits/stdc++.h>
using namespace std;
ifstream fin ("aib.in");
ofstream fout ("aib.out");
const int NMAX = 1e5 + 5;

int aib[NMAX], n, q;

int lsb(int i)
{
  return i & (-i);
}

void update (int pos, int val)
{
    for (int i = pos; i <= n; i += lsb(i))
        aib[i] += val;
}

int query (int pos)
{
    int s = 0;
    for (int i = pos; i >= 1; i -= lsb(i))
        s += aib[i];
    return s;
}

int binary_search(int x)
{
	int st = 1, dr = n;
	while (st <= dr)
  {
		int mij = (st + dr) / 2;
		if (query(mij) < x)
			st = mij + 1;
		else
			dr = mij - 1;
	}
	return st;
}


int main()
{
    fin>>n>>q;

    for(int i=1; i<=n; i++)
    {
        int x;
        fin>>x;
        update(i, x);
    }

    for(int i=1; i<=q; i++)
    {
        int ind, a, b;
        fin>>ind>>a;
        if(ind == 0)
        {
            fin>>b;
            update (a, b);
        }
        else if(ind == 1)
        {
            fin>>b;
            fout<< query(b) - query(a-1) <<'\n';
        }
        else
        {
            int k = binary_search(a);
            if(query(k)==a)
              fout<<k<<'\n';
            else
              fout<<"-1\n";
        }

    }

}
