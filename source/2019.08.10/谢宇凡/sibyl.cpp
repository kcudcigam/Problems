#include<bits/stdc++.h>
using namespace std;

template<typename T>void read(T &x){
    x=0;char c=getchar();
    int f=1;
    for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    x=x*f;
}

int a[300010],b[300010],ver[300010],next[300010],head[300010],sum[300010];
int tot;

void add(int x,int y){
	ver[++tot]=y;next[tot]=head[x];head[x]=tot;
	ver[++tot]=x;next[tot]=head[y];head[y]=tot;
	sum[x]++;sum[y]++;
}

int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,Q,u,v,x,y,t;
	read(n);read(m);read(Q);
	for (int i=1;i<=m;++i){
		read(u);read(v);
		add(u,v);
	}
	while (Q--){
		read(t);
		if (t==1){
			read(x);read(y);
			if (sum[x]>100)	a[x]+=y;
				else {
					for (int i=head[x];i;i=next[i])
						b[ver[i]]+=y;
				}
			continue;
		}
		read(x);
		int ans=0;
		if (sum[x]>100)	ans=a[x]+b[x];
			else {
				for (int i=head[x];i;i=next[i])
					ans+=a[ver[i]];
				ans+=b[x];
			}
		printf("%d\n",ans);
	}
	return 0;
}



