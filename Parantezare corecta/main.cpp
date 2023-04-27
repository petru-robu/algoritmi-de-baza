#include <bits/stdc++.h>
using namespace std;

bool parantezat_corect(string s)
{
  char st[100];
  int i=0, top=0;

  while(s[i]!=0)
  {
    if(s[i]=='('||s[i]=='['||s[i]=='{') st[++top]=s[i];
    else if(s[i]==')'&&st[top]=='('&&top>0)
            top--;
    else if(s[i]==']'&&st[top]=='['&&top>0)
            top--;
    else if(s[i]=='}'&&st[top]=='{'&&top>0)
            top--;
    else return false;
    i++;
  }
  if(top==0) return true;
	else return false;
}



int main()
{
  string s;
  cin>>s;
  cout<<parantezat_corect(s);
  return 0;
}
