#include<bits/stdc++.h>
using namespace std;
const int N=300010;
int as[N],os1[N],os2[N],ag[N];
int n,a[N],t1,t2,t3,t4,su1,su2,tot,tmp,ans,nt1,nt2,nt3,nt4;string s[N];
bool cmp(const int p,const int q)
{
	if(p>q)return 1;
	return 0;
}
int f(int a,int b,int c)
{
	if(a>=b&&a>=c&&a!=-1)return 1;
	if(b>=a&&b>=c&&b!=-1)return 2;
	if(c>=a&&c>=b&&c!=-1)return 3;
	return 0;
}
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];cin>>a[i];
		if(s[i]=="11")as[++t1]=a[i];else
		if(s[i]=="10")os1[++t2]=a[i];else
		if(s[i]=="01")os2[++t3]=a[i];else
		if(s[i]=="00")ag[++t4]=a[i];
	}
	for(int i=1;i<=t1;i++)ans+=as[i];
	tot=t1;su1=t1;su2=t1;
	sort(os1+1,os1+t2+1,cmp);
	sort(os2+1,os2+t3+1,cmp);
	sort(ag+1 ,ag+t4+1 ,cmp);
	int bj1=0,bj2=0,bj3=0,x;
	nt2=1;nt3=1;nt4=1;
	while(nt2<=t2||nt3<=t3||nt4<=t4)
	{
		bj1=0;bj2=0;bj3=0;
		if(su1+1>=tot/2+1&&su2>=tot/2+1&&nt2<=t2)bj1=1;
		if(su2+1>=tot/2+1&&su1>=tot/2+1&&nt3<=t3)bj2=1;
		if(su1>=tot/2+1&&su2>=tot/2+1&&nt4<=t4)bj3=1;
		x=f(os1[nt2]*bj1-(bj1==0),os2[nt3]*bj2-(bj2==0),ag[nt4]*bj3-(bj3==0));
		if(x==1){tot++;su1++;ans+=os1[nt2];nt2++;}else
		if(x==2){tot++;su2++;ans+=os2[nt3];nt3++;}else
		if(x==3){tot++;ans+=ag[nt4];nt4++;}
		if(bj1==0&&bj2==0&&bj3==0)break;
	}
	while(nt2<=t2&&nt3<=t3){tot+=2;su1++;su2++;ans+=os1[nt2];ans+=os2[nt3];nt2++;nt3++;}
	cout<<ans<<endl;
	return 0;
}


