#include<bits/stdc++.h>
using namespace std;
long long n,a[200000],i,s[200000],mi,x[200000],ans,y[200000];
int read()
{
char c;
int f,s=0;
  c=getchar();
  while ((c<'0'||c>'9')&&c!='-') c=getchar();
  if (c=='-') {f=-1;
        c=getchar();
	}
  else f=1;
	 while (c>='0'&&c<='9')
	 { s=s*10+c-'0';
	 c=getchar();
	 }
	 return(s*f);
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++)
	cin>>a[i];
	s[0]=0;
	for (i=1;i<=n;i++)
	s[i]=a[i]+s[i-1];
	mi=0;
	x[0]=INT_MIN*200000;
	for (i=1;i<=n;i++)
	{
	   	x[i]=max(x[i-1],s[i]-mi);
	   	mi=min(s[i],mi);
	}
	s[n+1]=0;
	for (i=n;i>=1;i--)
	s[i]=s[i+1]+a[i];
	mi=0;
	y[n+1]=INT_MIN*200000;
	for (i=n;i>=1;i--)
	{
		y[i]=max(y[i+1],s[i]-mi);
		mi=min(mi,s[i]);
	}
	for (i=2;i<=n-1;i++)
	ans=max(ans,x[i-1]+y[i+1]);
	cout<<ans<<endl;
	return 0;
}


