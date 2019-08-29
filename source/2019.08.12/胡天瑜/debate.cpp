#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=400010;

int n;
struct Person
{
	int theme1,theme2;
	int val;
}p[MAXN];
int twoones[MAXN],firone[MAXN],secone[MAXN],noone[MAXN];
int tto=0,ffo=0,sso=0,nno=0;
long long ans=0;

bool cmp(int a,int b) {return a>b;}

int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		string ttt;
		cin>>ttt;
		p[i].theme1=ttt[0]-'0';p[i].theme2=ttt[1]-'0';
		scanf("%d",&p[i].val);
	}
	for(int i=1;i<=n;++i)
	{
		if(p[i].theme1==1&&p[i].theme2==1) twoones[++tto]=p[i].val;
		if(p[i].theme1==1&&p[i].theme2!=1) firone[++ffo]=p[i].val;
		if(p[i].theme1!=1&&p[i].theme2==1) secone[++sso]=p[i].val;
		if(p[i].theme1!=1&&p[i].theme2!=1) noone[++nno]=p[i].val;
	}
	sort(firone+1,firone+ffo+1,cmp);sort(secone+1,secone+sso+1,cmp);
	for(int i=1;i<=tto;++i) ans=ans+twoones[i];
	if(ffo<=sso)
	{
		for(int i=1;i<=ffo;++i) ans=ans+firone[i]+secone[i];
		for(int i=ffo+1;i<=sso;++i)
		{
			noone[++nno]=secone[i];
		}
	}
	if(ffo>sso)
	{
		for(int i=1;i<=sso;++i) ans=ans+firone[i]+secone[i];
		for(int i=sso+1;i<=ffo;++i)
		{
			noone[++nno]=firone[i];
		}
	}
	sort(noone+1,noone+nno+1,cmp);
	for(int i=1;i<=tto&&i<=nno;++i)
	{
		ans=ans+noone[i];
	}
	printf("%lld\n",ans);
	return 0;
}
