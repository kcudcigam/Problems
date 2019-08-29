
#include<bits/stdc++.h>
#define LL long long
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=3e5+10;
int n,m,q,rl[M],tg[M];
bool bad[M];
int head[M],to[M<<1],nxt[M<<1],cnt;
void add(int x,int y){
	nxt[++cnt]=head[x]; to[cnt]=y; head[x]=cnt;
}
int de[M];
vector<int> v[M];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=read(); m=read(); q=read(); int lim=sqrt(m);
	F(i,1,m) {
		int x=read(),y=read();
		add(x,y); add(y,x);
		de[x]++; de[y]++;
	}
	F(i,1,n)
	if (de[i]>=lim) {
		bad[i]=1;
		for (int j=head[i];j;j=nxt[j]){
			v[to[j]].pb(i);
		}
	}
	while (q--){
		int tp=read();
		if (tp){
			int x=read(),y=read();
			rl[x]+=y;
			if (bad[x]){
				tg[x]+=y;
			}
			else{
				for (int i=head[x];i;i=nxt[i]){
					rl[to[i]]+=y;
				}
			}
		}
		else {
			int x=read();
			int tmp=rl[x];
			F(i,0,SZ(v[x])){
				tmp+=tg[v[x][i]];
			}
			cout<<tmp<<"\n";
		}
	}
	return 0;
}

