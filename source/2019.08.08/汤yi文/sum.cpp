#include<bits/stdc++.h>
using namespace std;
#define RG register
inline int r()
{
	int s=0,w=1;char c=getchar();
	while((c<'0'||c>'9')&&c!='-') c=getchar();
	if(c=='-') w=-1,c=getchar();
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*w;
}
int a[101000],n;
int f[101000];
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    n=r();
    for(RG int i=1;i<=n;i++) a[i]=r();
	int k=-1000000001;
    int r=-1,l=-1;
	for(RG int i=1;i<=n;i++)
    {
    f[i]=max(f[i-1]+a[i],a[i]);
    if(k<f[i]) k=f[i],r=i;
	}
	l=r;
	int q=k;
    while(q)
    {
    	q-=a[l];
    	--l;
	}
    ++l;
    memset(f,0,sizeof(f));
    if(l==1&&r==n) q=0;
    else
    {
    	q=-1000000001;
      for(int i=1;i<=n;i++)
      {
    	if(i<=r&&i>=l) continue;
    	f[i]=max(f[i-1]+a[i],a[i]);
    	if(q<f[i]) q=f[i];
	  }
	}
	int ans=q+k;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

