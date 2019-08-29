#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int  read();
int a0[400005],a1[400005],a2[400005],a3[400005];
ll sum0[400005],sum1[400005],sum2[400005],sum3[400005];
int t0,t1,t2,t3;
bool gr(int a,int b)
{
	return a>b;
}
ll _max(ll a,ll b)
{
	return a>b?a:b; 
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int N=read();
	for  (int i=1;i<=N;i++)
		{
			int tt=read(),vv=read();
			if  (tt==0)
				{	t0++;a0[t0]=vv;continue;}
			if  (tt==1)
				{	t1++;a1[t1]=vv;continue;}
			if  (tt==10)
				{	t2++;a2[t2]=vv;continue;}
			if  (tt==11)
				{	t3++;a3[t3]=vv;continue;}
		}
	sort(a0+1,a0+t0+1,gr);
	sort(a1+1,a1+t1+1,gr);
	sort(a2+1,a2+t2+1,gr);
	sort(a3+1,a3+t3+1,gr);
	for  (int i=1;i<=t0;i++)	sum0[i]=sum0[i-1]+a0[i];
	for  (int i=1;i<=t1;i++)	sum1[i]=sum1[i-1]+a1[i];
	for  (int i=1;i<=t2;i++)	sum2[i]=sum2[i-1]+a2[i];
	for  (int i=1;i<=t3;i++)	sum3[i]=sum3[i-1]+a3[i];
	int N3=t3; ll Ans=0;
	for  (int n0=0;n0<=t3;n0++)
		{
			int N0=n0;
			if  (n0>t0)
				N0=t0;
			int cha=N3-n0;
			int N1,N2;
			N1=t1,N2=N1-cha;
			if  (N2<=t2&&N2>=0)
				Ans=_max(Ans,sum0[N0]+sum1[N1]+sum2[N2]+sum3[N3]);
			N1=t1,N2=N1+cha;
			if  (N2<=t2&&N2>=0)
				Ans=_max(Ans,sum0[N0]+sum1[N1]+sum2[N2]+sum3[N3]);
			N2=t2,N1=N2-cha;
			if  (N1<=t1&&N1>=0)
				Ans=_max(Ans,sum0[N0]+sum1[N1]+sum2[N2]+sum3[N3]);
			N2=t2,N1=N2+cha;
			if  (N1<=t1&&N1>=0)
				Ans=_max(Ans,sum0[N0]+sum1[N1]+sum2[N2]+sum3[N3]);
		}
	cout<<Ans<<endl;
	return 0;
}





int  read()
{
	int a=0,f=1; char c=getchar();
	for  (;!isdigit(c);c=getchar())	if  (c=='-')	f=-f;
	for  (;isdigit(c);a=a*10+c-48,c=getchar());
	return a*f;
}
