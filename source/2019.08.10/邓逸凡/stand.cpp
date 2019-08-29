#include<bits/stdc++.h>
using namespace std;
long long g[260];
int l[260],r[260];
int cf1[10000007],cf2[10000007],renshu[10000007];
long long ren[10000007];
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int N,M;
	scanf("%d%d",&N,&M);
	int a,b,c,e,d;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for  (int i=1;i<=N;i++)
		g[i]=(long long)a*i+b*i*i+c*i*i*i+d*i*i*i*i+e*i*i*i*i*i;
	int f1=true;
	for  (int i=0;i<N;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			if  (l[i]!=1||r[i]!=M)	f1=false;
			cf1[l[i]]++;cf1[r[i]+1]--;
			cf2[l[i]]+=(1<<i);  cf2[r[i]+1]-=(1<<i);
		}
	if  (f1)
		{
			cout<<g[N]<<endl;
			return 0;
		}
	if  (b+c+d+e==0)
		{
			cout<<g[N]<<endl;
			return 0;
		}
	int Rest=N;
	long long Ans=0;
	while  (Rest>1)
		{
			int Max=1;
			for  (int i=1;i<=M;i++)
				{
					renshu[i]=renshu[i-1]+cf1[i];
					ren[i]=ren[i-1]+cf2[i];
					if  (renshu[i]>renshu[Max])
						Max=i;
				}
			int zz=ren[Max];
			Ans+=g[renshu[Max]];
			Rest-=renshu[Max];
			for  (int i=1,ii=0;i<=zz;i<<=1,ii++)
				if  (i&zz)
					{
						cf1[l[ii]]--; cf1[r[ii]+1]++;
						cf2[l[ii]]-=i; cf2[r[ii]+1]+=i;
					}
		}
	Ans+=g[Rest];
	cout<<Ans<<endl;
	return 0;
}


