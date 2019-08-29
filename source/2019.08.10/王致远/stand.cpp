#include<bits/stdc++.h>
using namespace std;
struct q
{
	int l,r;
};
q n[1100],nn[1100];
int a,b,c[11],s,p[1100];
long long maxi;
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
void wrk(int s,long long ss)
{
	if (s==a)
	{
		if (ss>maxi) maxi=ss;
	}
	else
	{
		int t[110],w[1100],maxii=0,ll=0;
		memset(t,0,sizeof(t));
		for (int i=1;i<=a;i++)
			for (int j=n[i].l;j<=n[i].r;j++)
			{
				t[j]++;	
				if ((t[j]==maxii)&&(j!=0))	
				{
					ll++;
					w[ll]=j;
				}
				if ((t[j]>maxii)&&(j!=0))
				{
					maxii=t[j];	
					ll=1;w[1]=j;
				}	
			}	
		if (maxii==0) return;
		if (maxii>1)
		{
			for (int i=1;i<=ll;i++)
			{
				int o=0;
				for (int j=1;j<=a;j++)
				if ((w[i]>=n[j].l)&&(w[i]<=n[j].r))
				{
					o++;
					p[o]=j;
					n[j].l=0;
					n[j].r=0;
				}
				wrk(s+maxii,ss+maxii*c[1]+maxii*maxii*c[2]+maxii*maxii*maxii*c[3]+
				maxii*maxii*maxii*maxii*c[4]+maxii*maxii*maxii*maxii*maxii*c[5]);
				for (int j=1;j<=o;j++)
				{
					n[p[j]].l=nn[p[j]].l;
					n[p[j]].r=nn[p[j]].r;
				}
			}			
		}
		else
		{
			n[w[1]].l=0;n[w[1]].r=0;
			wrk(s+1,ss+c[1]+c[2]+c[3]+c[4]+c[5]);
			n[w[1]].l=nn[w[1]].l;n[w[1]].r=nn[w[1]].r;		
		}
	}
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);read(b);
	for (int i=1;i<=5;i++) read(c[i]);
	for (int i=1;i<=a;i++)
	{
		read(n[i].l);
		read(n[i].r);
	}
	for (int i=1;i<=a;i++) 
	{
		nn[i].l=n[i].l;
		nn[i].r=n[i].r;
	}
	wrk(0,0);
	cout<<maxi<<endl;
	return 0;
}
