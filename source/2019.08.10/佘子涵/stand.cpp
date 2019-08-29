#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
template <typename T> void read(T &x){
	long long f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f= -f;
	for (; isdigit(c);c=getchar()) x=x*10+c -'0';
	x*=f;
}
int n,m,a[6],l[500],r[500],t[500],c[10000100];
struct dio{
	int l,r,cd;
} b[500];
long long ans;
long long so(long long x){
	return (long long)a[1]*x+a[2]*x*x+a[3]*x*x*x+a[4]*x*x*x*x+a[5]*x*x*x*x*x;
}
void dfs(int x){
	if(x==n+1){
		long long now=0;
		for(int i=1;i<=m;i++){
			now+=so(t[i]);
		}
		if(now>ans){
			ans=now;
		}
		return;
	}
	if(b[x].cd==1){
		t[b[x].l]++;
		dfs(x+1);
		t[b[x].l]--;
		return;
	}
	for(int i=b[x].l;i<=b[x].r;i++){
		if(c[i]<=1) continue;
		t[i]++;
		dfs(x+1);
		t[i]--;
	}
}
bool cmp(dio a,dio b){
	return a.cd<b.cd;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=5;i++) read(a[i]);
	bool fl=1;
	for(int i=1;i<=n;i++){
		read(b[i].l);read(b[i].r);
		c[b[i].l]++;c[b[i].r+1]--;
		if(b[i].l!=1) fl=0;
		for(int j=1;j<i;j++){
			if((b[i].l<=b[j].l&&b[j].l<=b[i].r)||(b[i].l<=b[j].r&&b[j].r<=b[i].r)){
				b[i].cd++;b[j].cd++;
			}
		}
	}
	if(fl){
		printf("%lld\n",so(n));
		return 0;
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=m;i++) c[i]+=c[i-1];
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}

