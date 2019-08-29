#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MAXN=305;

ll n,m,t[6],ans,ccnt,nl,nr,cnt,maxn,b[MAXN];
ll ta[MAXN],tmaxn;
ll a[MAXN];
ll vis[MAXN];
//queue<ll> q;
struct Per
{
	ll l,r;
}per[MAXN];

void read(ll &p)
{
	char s=getchar();ll flag=1;p=0;
	while(!isdigit(s))
	{
		if(s=='-') flag=-1;
		s=getchar();
	}
	for(;isdigit(s);s=getchar()) p=p*10+s-'0';
	p*=flag;
 } 

bool cmp(Per x,Per y)
{
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}

queue<ll> q;


int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n);read(m);
	for(ll i=1;i<=5;i++) read(t[i]);
	for(ll i=1;i<=n;i++)
	{
		read(per[i].l);read(per[i].r);
	 } 
	
	sort(per+1,per+n+1,cmp);
	per[n+1].l=per[n].r+1;

	while(ccnt<n)
	{
		maxn=0;while(q.size())q.pop();
		for(ll i=1;i<=n;i++)
		{
			if(!vis[i])	{nl=i;nr=per[i].r;q.push(i);break;}
		}
		
		for(ll i=nl+1;i<=n+1;i++)
		{
			if(!vis[i])
			{
				if(per[i].l<=nr)
				{
					q.push(i);
					nr=min(nr,per[i].r);
				}
				else
				{
					nr=per[i].r;
					tmaxn=0;
					while(q.size()) {tmaxn++;ta[tmaxn]=q.front();q.pop();}
				//	cout<<"A"<<tmaxn<<" "<<maxn<<" ";
					for(ll j=1;j<=tmaxn;j++)
					{
						if(per[ta[j]].r>=per[i].l)
						{
							q.push(ta[j]);nr=min(nr,per[ta[j]].r);
						}
					}
					q.push(i);
				//	cout<<q.size()<<endl;for(ll i=1;i<=tmaxn;i++) cout<<ta[i]<<" ";cout<<endl;
					if(tmaxn>maxn) {for(ll j=1;j<=tmaxn;j++) a[j]=ta[j];	maxn=tmaxn;}
				}
			}
		}
		ccnt+=maxn;ll tem=maxn;
		//cout<<maxn<<endl;
		for(ll i=1;i<=5;i++) ans+=t[i]*tem,tem*=maxn;
		for(ll i=1;i<=maxn;i++) {vis[a[i]]=1;}//cout<<endl;
		maxn=0;
	}
	
	cout<<ans<<endl;
	
	return 0;
 } 
