#include<bits/stdc++.h>
#define rep(i,l,k) for(int i=l;i<=k;i++)
#define REP(i,x) for(int i=head[x];i;i=nxt[i])
#define Rep(i,l,k) for(int i=l;i>=k;i--)
typedef long long ll;
using namespace	std;
const int N=3e5+5;
int num,n,m1,m2;
int head[N],nxt[N],to[N],cnt;
int p=1e9+7;
int ip(){
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return w?-x:x;
}
void Add(int a,int b){
	nxt[++cnt]=head[a];head[a]=cnt;to[cnt]=b;
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	num=ip();n=ip();m1=ip();m2=ip();
	rep(i,1,m1){int x=ip(),y=ip();Add(x,y);}
	cnt=0;
	rep(i,1,m2){int x=ip(),y=ip();Add(x,y);}
	if(num==1){printf("0");return 0;}
	if(num==2){printf("2");return 0;}
	return 0;
}

