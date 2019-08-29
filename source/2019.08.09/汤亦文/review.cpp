#include<bits/stdc++.h>
using namespace std;
#define int long long
#define RG register
inline int read()
{
	int s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int Y,N,M,cnt;
int a[80];
int t[80];
int power(int a,int b)
{
	int ans=1;
	for(;b;b>>=1)
	{
		if(b&1) ans=ans*a;
		a=a*a;
	}
	return ans;
}
signed main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
    Y=read();
    int l=0,r=62;
    for(RG int i=0;i<=62;i++)
    a[i]=power(2,i);
    while(l<r)
    {
    	int mid=(l+r)>>1;
    	if(a[mid]>Y) r=mid;
    	else l=mid+1;
	}
	N=l+2;
	if(a[l-1]==Y)
	{
		--N;
		Y=0;
	for(RG int i=1;i<=N;i++)
	 M+=i-1;
	 cout<<N<<" "<<M<<endl;
	 for(RG int i=1;i<=N;i++)
	   for(RG int j=1;j<i;j++)
	   {
	   	cout<<j<<" "<<i<<endl;
	   }
	}
	else
	{
	--l;
	 while(Y)
	 {
		if(Y-a[l]>=0)
		{
			Y-=a[l];
			t[++cnt]=l+2;
		}
		--l;
	 }
	 for(RG int i=1;i<=N-1;i++)
	 M+=i-1;
	 M+=cnt;
	 cout<<N<<" "<<M<<endl;
	 for(RG int i=1;i<=N-1;i++)
	   for(RG int j=1;j<i;j++)
	   {
	   	cout<<j<<" "<<i<<endl;
	   }
	 for(RG int i=1;i<=cnt;i++)
	 cout<<t[i]<<" "<<N<<endl;
    }
    fclose(stdin);
    fclose(stdout);
	return 0;
}
