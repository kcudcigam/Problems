#include<bits/stdc++.h>
using namespace std;
int n,i,j;
map<string,int> a;
string s,x;
int ks(int p,int n)
{
	if (n==1) return p;
	else return p*ks(p,n-1); 
 } 
void dg(int p,int k)
{
	if (p>(n-x.size())) {
		for (int i=1;i<=x.size()-k;i++)
		s+=x[k+i-1];
		a[s]=1;
	}
	else {
		for (int i='a';i<='z';i++)
		{
			s+=char(i);
			dg(p+1,k);
			s.erase(s.begin()+s.size()-1);
		}
	}
}
int main(){
  freopen("magic.in","r",stdin);
  freopen("magic.out","w",stdout);
  cin>>n;
  cin>>x;
  for (i=0;i<=x.size();i++)
  {
  	s="";
  	for (j=1;j<=i;j++)
  	s+=x[j-1];
  	dg(1,i);
  }
  cout<<ks(26,n)-a.size()<<endl;
  return 0;
}


