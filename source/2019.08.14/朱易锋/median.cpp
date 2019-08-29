#include<bits/stdc++.h>
#define R register
#define V void
#define I inline
#define ll long long
using namespace std;
I int read()
{
    R int f=1,num=0;
    R char ch=getchar();
    while(0==isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(0!=isdigit(ch)) num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
    return num*f;
}
const int N=500000+107;
int a[N],b[N];
int bin[40];
I int getans(R int l1,R int r1,R int l2,R int r2)
{
	R int res=0,ans=0;
	R int len=(r1-l1+1)+(r2-l2+1);
	R int L1=l1,R1=r1,L2=l2,R2=r2;
	len++;
	R int ret=0;
	R int last_l1=0,last_l2=0;
	while(ret<len/2)
	{
			R int k=0;
			for(R int k=30;k>=0;k--)
			{
				if(l1+bin[k]>r1)continue;
				if(a[l1+bin[k]]<=b[l2])
				{
					l1=l1+bin[k];
					ret=(l1-L1+1)+(l2-L2+1);
					if(a[l1]<b[l2])ret--;
					if(ret>=len/2)return a[l1-(ret-len/2)];
				}
			}
			if(l1<r1&&a[l1]<b[l2])l1++;
			for(R int k=30;k>=0;k--)
			{
				if(l2+bin[k]>r2)continue;
				if(b[l2+bin[k]]<a[l1])
				{
					l2=l2+bin[k];
				}
			}
			ret=(l1-L1+1)+(l2-L2+1);
			if(ret==len/2)return a[l1];
			else if(ret>len/2)
			{
				return b[l2-(ret-len/2)+1];
			}

			for(R int k=30;k>=0;k--)
			{
				if(l2+bin[k]>r2)continue;
				if(b[l2+bin[k]]<=a[l1])
				{
					l2=l2+bin[k];
					ret=(l1-L1+1)+(l2-L2+1);
					if(b[l2]<a[l1])ret--;
					if(ret>=len/2)return b[l2-(ret-len/2)];
					
				}
			}
			if(l2<r2&&b[l2]<a[l1])l2++;
			
			for(R int k=30;k>=0;k--)
			{
				if(l1+bin[k]>r1)continue;
				if(a[l1+bin[k]]<b[l2])l1=l1+bin[k];
			}
			ret=(l1-L1+1)+(l2-L2+1);
			if(ret==len/2)return b[l2];
			else if(ret>len/2)
			{
				return a[l1-(ret-len/2)+1];
			}
			if(l1==r1)
			{
				return b[l2+(len/2-ret)];
			}
			if(l2==r2)
			{
				return a[l1+(len/2-ret)];
			}
	}
}
int main()
{
	freopen("median.in","r",stdin);
	freopen("median.out","w",stdout);
	R int n=read(),m=read();
	bin[0]=1;
	for(R int i=1;i<=30;i++)
	{
		bin[i]=bin[i-1]<<1;
	}
	for(R int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(R int i=1;i<=n;i++)
	{
		b[i]=read();
	}
	for(R int i=1;i<=m;i++)
	{
		R int opt=read();
		if(opt==1)
		{
			R int x=read(),y=read(),z=read();
			if(x==0)a[y]=z;
			else b[y]=z;
		}
		else
		{
			R int l1=read(),r1=read(),l2=read(),r2=read();
			cout<<getans(l1,r1,l2,r2)<<endl;
		}
	}
	return 0;
}
