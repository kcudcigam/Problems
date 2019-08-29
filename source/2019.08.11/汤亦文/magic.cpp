#include<bits/stdc++.h>
using namespace std;
#define int long long
#define p 998244353
inline int rred()
{
	int s=0,w=1;char c=getchar();
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int n,m,ans;
char a[1000100];
int power(int x,int y)
{
	int s=1;
	for(;y;y>>=1)
	{
		if(y&1) s=s*x%p;
		x=x*x%p;
	}
	return s;
}
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n=rred();
	int x=26;
	char c=getchar();
     while(c>'z'||c<'a') c=getchar();
     while(c>='a'&&c<='z')
	 {
	 	a[++m]=c;
		if(m<n) c=getchar();
		else break;
	 }
	 if(m==n)
	 {
	 	ans=power(x,n);
	 	ans=(ans+p-1)%p;
	 	cout<<ans;
	 	return 0;
	 }
     if(m==1)
     {
     	ans=power(x,(n-2));
     	ans=((ans*25%p)*25)%p;
     	cout<<ans;
     	return 0;
	 }
    int k=power(x,n);
    int kk=power(x,(n-m))*(m+1)%p;
    ans=(k+p-kk+(m-1)*3)%p;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
	return 0;
}
