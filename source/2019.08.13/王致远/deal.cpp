#include<bits/stdc++.h>
using namespace std;
struct q
{
	int val,xl,dy;
};
q n[1100];
int a,b,s,t[110000],tt[110000];
bool cmp(q p,q pp)
{
	return p.val<pp.val;
}
template <typename T> void read(T &x)
{
	x=0;char c=getchar();bool flg=0;
	for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	if (flg) x=-x;
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	//ios::sync_with_stdio(false);
	read(a);read(b);
	for (int i=1;i<=a;i++)
	{
		read(n[i].val);read(n[i].xl);read(n[i].dy);
	}
	t[0]=1;tt[0]=1;
	for (int i=a;i>=1;i--)
	{
		for (int j=b-1;j>=0;j--)
			for (int k=1;k<=n[i].xl;k++)
			{
				if (j+n[i].val*k-n[i].val>=b) break;				
				t[j+k*n[i].val]=(t[j]+t[j+k*n[i].val])%1000000007;
			}
	}
	for (int i=a;i>=1;i--)
	{
		for (int j=100;j>=0;j--)
			for (int k=1;k<=n[i].dy;k++)				
			tt[j+k*n[i].val]=(tt[j]+tt[j+k*n[i].val])%1000000007;
	}
	for (int i=b;i<=20000;i++)
	if ((t[i]>0)&&(tt[i-b]>0))
	{
		s=(s+t[i]*tt[i-b])%1000000007;
	}
	cout<<s<<endl;
	return 0;
}


