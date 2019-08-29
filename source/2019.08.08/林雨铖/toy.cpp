#include<bits/stdc++.h>
using namespace std;
int m,a[1001],n,f[1001];
int w(int dep,int k,int s)
{
	if (f[dep]!=0)return f[dep];
	if (k<0)return 0;
	if (dep>n)return s;
	int b=max(w(dep+1,k,s),w(dep+2,k-a[dep],s+1));
	f[dep]=b;
	return b;
}
int main()
{
	freopen("toy.in","r",stdin);
	freopen("toy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cout<<w(1,m,0)<<endl;
	return 0;
}

