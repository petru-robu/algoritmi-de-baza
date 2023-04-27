#include <bits/stdc++.h>
using namespace std;

ifstream fin("trie.in");
ofstream fout("trie.out");

struct Trie
{
  int cnt, nrFii;
  Trie *fiu[26];
  Trie()
  {
    cnt = nrFii = 0;
    memset(fiu, 0, sizeof(fiu));
  }
};

void inserare(Trie* t, string s, int p);
bool stergere(Trie* t, string s, int p);
int nrAp(Trie* t, string s, int p);
int prefix(Trie* t, string s, int p, int level);

Trie *trie = new Trie;

int main()
{
  int x;
  string s;
  while(fin>>x>>s)
  {
    cout<<x<<' '<<s<<'\n';
    if(x == 0)
      inserare(trie, s, 0);
    if(x == 1)
      stergere(trie, s, 0);
    if(x == 2)
      fout<<nrAp(trie, s, 0)<<'\n';
    if(x == 3)
      fout<<prefix(trie, s, 0, 0)<<'\n';
  }
}

void inserare(Trie* t, string s, int p)
{
  if(p == s.size())
  {
    t->cnt ++;
    return;
  }

  if(t->fiu[ s[p] - 'a'  ] == 0)
  {
    t->fiu[ s[p] - 'a'  ] = new Trie;
    t->nrFii++;
  }
  inserare(t->fiu[ s[p] - 'a'  ], s, p+1);
}

bool stergere(Trie* t, string s, int p)
{
  if(p == s.size())
    t->cnt --;
  else
    if( stergere( t->fiu[ s[p] - 'a'  ], s, p+1) )
    {
      t->fiu[ s[p] - 'a'  ] = 0;
      t->nrFii--;
    }

  if(t->cnt == 0 && t->nrFii == 0 && t != trie) //terminal
  {
    delete t;
    return 1;
  }

  return 0;
}

int nrAp(Trie* t, string s, int p)
{
  if(p == s.size())
    return t->cnt;

  if(t->fiu[ s[p] - 'a'  ])
    return nrAp(t->fiu[ s[p] - 'a'  ], s, p+1);

  return 0;
}

int prefix(Trie* t, string s, int p, int level)
{
  if( p == s.size() || !t->fiu[ s[p] - 'a' ] )
    return level;
  return prefix( t->fiu[s[p] - 'a' ], s, p+1, level+1);
}
