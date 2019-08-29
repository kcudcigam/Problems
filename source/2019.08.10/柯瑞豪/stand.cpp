#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r;
}A[260];
int n,m,ans[260];
long long Xi[6],Ans;
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c&15);
		c=getchar();
	}
	return x*w;
}
bool comp(const node &a,const node &b){
	return a.r==b.r?a.l<b.l:a.r<b.r;
}
void work(){
	int i=1,j=2;
	int cnt;
	while(i<=n){
		cnt=1;
		while(j<=n&&A[j].l<=A[i].r)cnt++,j++;
		ans[++ans[0]]=cnt;
		i=j,j++;
	}
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<6;i++)scanf("%lld",&Xi[i]);
	for(int i=1;i<=n;i++)A[i].l=read(),A[i].r=read();
	sort(A+1,A+1+n,comp);
	work();
	for(int i=1;i<=ans[0];i++){
		long long x=(long long)ans[i];
	    for(int j=1;j<6;j++){
	    	Ans+=Xi[j]*x;x*=x;
		}
	}
	printf("%lld\n",Ans);
	return 0;
}
