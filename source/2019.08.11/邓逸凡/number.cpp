#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N[105];
ll NN[1640000];
ll MAXN;
set<ll> a1;
int tot;
void Make_(int xx,int yy,ll Num)
{
	if  (Num>MAXN)	return;
	if  (Num)
		{
			NN[++tot]=Num;
			a1.insert(Num);
		}
	if  (xx||Num)
		Make_(xx,yy,Num*10+xx);
	if  (yy||Num)
		Make_(xx,yy,Num*10+yy);
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int T;
	scanf("%d",&T);
	for  (int i=1;i<=T;i++)
		{
			scanf("%lld",&N[i]);
			if  (N[i]>=MAXN)
				MAXN=N[i];
		}
	for  (int i=0;i<10;i++)
		for  (int j=0;j<10;j++)
			Make_(i,j,0);
	for  (int i=1;i<=T;i++)
		{
			if  (a1.count(N[i])==1)
				{
					printf("%d\n",1);
					continue;
				}
			bool f=true;
			for  (int j=1;j<=tot;j++)
				if  (a1.count(N[i]-NN[j])==1)
					{
						printf("%d\n",2);
						f=false;
						break;
					}
			if  (f)  printf("%d\n",3);
		}
	return 0;
}
