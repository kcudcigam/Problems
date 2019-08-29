#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct player{
	int p,w;
}a[800010];
int group[1001];
int n,mx,s,g,g1,g2,c1,c2,t;
int cmp(player x,player y)
{
	if(x.p!=y.p)
		return x.p>y.p;
	return x.w>y.w;
}
int dmp(player x,player y)
{
	return x.w>y.w;
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].p,&a[i].w);
		group[a[i].p]++;
	}
	mx=max(group[10],group[1]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].p==11)
			s+=a[i].w,g++,c1++,c2++,a[i].w=-1;
		if(a[i].p==1&&g1<mx)
			s+=a[i].w,g1++,g++,a[i].w=-1;
		if(a[i].p==10&&g2<mx)
			s+=a[i].w,g2++,g++,a[i].w=-1;
	}
	g1+=c1;
	g2+=c2;
	for(int i=1;i<=n;i++)
		if(a[i].w!=-1)
			a[++t]=a[i];
	sort(a+1,a+1+t,dmp);
	for(int i=1;i<=n;i++)
	{
		g++;
		if(a[i].p==1)
			g1++;
		if(a[i].p==10)
			g2++;
		if(g1<(g+1)/2||g2<(g+1)/2)
			break;
		s+=a[i].w;
	}
	cout<<s;
}
