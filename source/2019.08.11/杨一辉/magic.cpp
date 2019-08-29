#include<bits/stdc++.h>
using namespace std;
long long n,b,f,d=1,c=1,e=1,a;
long long p=998244353;
char s[1000005];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	cin>>s;
	b=strlen(s);
	f=n-b;
	for(int i=1;i<b;i++)
	{
		if(s[i]!=s[i-1])break;
		if(s[i]==s[i-1]&&i==b-1)a=1;
	}
	if(f!=0){
		for(int i=1;i<=f;++i)d=(d%p*26%p)%p;
		d=(d%p*(b+1)%p)%p;	
	}
	if(a!=1)for(int i=1;i<=n-(2*b);++i)e=(e%p*26%p)%p;
	if(a==1)e+=n-b;
	if(f==0)e=0;
	d-=e;
	for(int i=1;i<=n;++i)c=(c%p*26%p)%p;
	cout<<(c-d+p)%p<<endl;
	return 0;
}
