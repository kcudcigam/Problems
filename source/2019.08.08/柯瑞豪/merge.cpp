#include<bits/stdc++.h>
using namespace std;
const int N=500010,M=500010*2;
int n,Q,tot,b;
int head[N],Next[M],ver[M];
int A[N],f[N];
bool F[N];
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
void add(int x,int y){
	ver[++tot]=y;Next[tot]=head[x];head[x]=tot;
}
int find(int x){
	return f[x]==x?x:find(f[x]);
}
void work(int x){
	F[x]=1;A[x]+=b;
	for(int i=head[x];i;i=Next[i]){
		int y=ver[i];
		if(!F[y])work(y);		
	}
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
    n=read();Q=read();
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=Q;i++){
    	int flag=read(),x=read(),y=read();
    	if(flag==1){
    		if(find(x)==find(y))continue;
    		f[y]=find(x);
    		add(x,y),add(y,x);
		}
		if(flag==2){
			b=y;
			memset(F,0,sizeof(F));
			work(x);
		}
	}
	for(int i=1;i<=n;i++)
	printf("%d ",A[i]);
	cout<<endl;
    return 0;
}
