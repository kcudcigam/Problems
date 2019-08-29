#include<bits/stdc++.h>
using namespace std;
string s;
long long n,k,i,m;
void sze(int n)
{
	if (n!=0) {
		s=char(n%2+48)+s;
		sze(n/2);
	}
}
int main(){
  freopen("glass.in","r",stdin);
  freopen("glass.out","w",stdout);
  cin>>n>>k;
  sze(n);
  i=1;
  while (i<k)
  {
  	while (s[0]=='0') s.erase(s.begin());
  	s.erase(s.begin());
  	i++;
  }
  while (s[0]=='0') s.erase(s.begin());
  if (s.size()==0) cout<<0<<endl;
  else {
  	long long k=1;
  	for (int i=s.size()-1;i>=0;i--)
  	{
  		m+=(s[i]-48)*k;
  		k*=2;
	  }
	k=1;
	while (k<m) k*=2;
	cout<<k-m<<endl;
  }
  return 0;
}

