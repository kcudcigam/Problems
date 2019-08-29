#include<bits/stdc++.h>
#define N 500005
using namespace std;
typedef long long LL;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
LL cf[N],a[N],q[N];
LL n,m,l,r,s,e,cha,ans=0;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
    read(n);read(m);
    for (int i=1;i<=m;++i){
    	read(l);read(r);read(s);read(e);
        cha=(e-s)/(r-l);
        cf[l+1]+=cha;
        cf[r+1]-=cha;
        q[l]+=s;q[r+1]+=-e;
    }
    for (int i=1;i<=n;++i){
        cf[i]=cf[i-1]+cf[i];
        a[i]=a[i-1]+cf[i]+q[i];
        ans=ans^a[i];
    }
    cout<<ans<<'\n';
    return 0;
}
