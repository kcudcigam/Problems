#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
bool flag1;
int flag;
int n,m;
struct sb{
	int l,r;
	long long st,ed;
}s[500010];
long long add[500010],v[500010];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for(register int i=1;i<=m;i++){
		int l,r;
		long long st,ed;
		read(s[i].l);
		read(s[i].r);
		read(s[i].st);
		read(s[i].ed);
		if(st==ed){
			flag++;
			add[l]+=st;
			add[r+1]-=st;
		}
	}
	if(flag==m){
		for(register int i=1;i<=n;i++){
			add[i]+=add[i-1];
			v[i]+=add[i];
		}
		long long now=v[1];
		for(register int i=2;i<=n;i++){
			now^=v[i];
		}
		printf("%lld\n",now);
		return 0;
	}	
	for(register int i=1;i<=m;i++){
		long long d=(s[i].ed-s[i].st)/(s[i].r-s[i].l);
		for(register int j=s[i].l;j<=s[i].r;j++){
			v[j]+=d*(j-s[i].l)+s[i].st;
		}
	}
	long long now=0;
	for(register int i=1;i<=n;i++){
		now^=v[i];
	}
	printf("%lld\n",now);
	return 0;
}
