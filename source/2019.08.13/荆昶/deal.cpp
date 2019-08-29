#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long s;
int ml[10001],md[10001];
int L(int n,int lasti)
{
	if(n==0) return 1;
	long long r=0;
	for(int i=lasti;i<=n;i++)
	if(ml[i])
	{
		ml[i]--;
		r+=L(n-i,i);
		ml[i]++;
		r%=MOD;
	}
	return r;
}
int D(int n,int lasti)
{
	if(n==0) return 1;
	long long r=0;
	for(int i=lasti;i<=n;i++)
	if(md[i])
	{
		md[i]--;
		r+=D(n-i,i);
		md[i]++;
		r%=MOD;
	}
	return r;
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	int n,x;
	cin>>n>>x;
	int a,b,c;
	while(n--)
	{
		cin>>a>>b>>c;
		ml[a]=b;md[a]=c;
	}
	for(int i=x;i<a+x;i++)
	{
		s+=L(i,i-x+1)*D(i-x,0);
		s%=MOD;
	}
	cout<<s;
	return 0;
}

