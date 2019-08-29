#include<bits/stdc++.h>
using namespace std;
long long n,a[100001],l[100001],r[100001],ans=-999999999;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
    read(n);
    for(register int i=1;i<=n;i++)
    read(a[i]);
    
    l[1]=a[1];
    for(register int i=2;i<=n;i++)
    l[i]=max(l[i-1]+a[i],a[i]);
    for(register int i=2;i<=n;i++)
    l[i]=max(l[i-1],l[i]);
    
    r[n]=a[n];
    for(register int i=n-1;i>=1;i--)
    r[i]=max(r[i+1]+a[i],a[i]);
    for(register int i=n-1;i>=1;i--)
    r[i]=max(r[i],r[i+1]);
    
    for(register int i=1;i<n;i++)
    ans=max(ans,l[i]+r[i+1]);
    
    printf("%lld",ans);
	return 0;
}

