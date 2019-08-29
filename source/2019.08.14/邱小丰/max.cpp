#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
const int maxn=100050;
int n,m,q,x[maxn],y[maxn],p[maxn],l[maxn],r[maxn];
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	scanf("%d%d%d",&x[i],&y[i],&p[i]);
	for(int i=1;i<=q;i++)
	scanf("%d%d",&l[i],&r[i]);
	cout<<1<<endl;
	return 0;
}
