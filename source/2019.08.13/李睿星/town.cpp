#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a,b,ans=1,s,f[2005][2005],x[300005],d[300005],cnt;bool v[300005];
int fa[300005];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	if(n<2005){
		memset(f,0x3f,sizeof(f));
		for(int i=1;i<=n;++i) f[i][i]=0;
		for(int i=1;i<n;++i,ans=1){
			scanf("%d%d",&a,&b);
			f[a][b]=f[b][a]=1;
			for(int j=1;j<=n;++j){
				if(f[a][j]>f[b][j]){
					f[a][j]=f[j][a]=f[b][j]+1;
					if(f[a][j]>ans) ans=f[a][j];
				}
				if(f[b][j]>f[a][j]){
					f[b][j]=f[j][b]=f[a][j]+1;
					if(f[b][j]>ans) ans=f[b][j];
				}
			}
			for(int j=1;j<=n;++j)
				for(int k=1;k<=n;++k){
					s=min(f[j][a]+f[a][k],f[j][b]+f[b][k]);
					if(f[j][k]>s){
						f[j][k]=f[k][j]=s;
						if(s>ans) ans=s;
					}
				}
			printf("%d\n",ans);
		}
	}
	else{
		for(int i=1;i<=n;++i) fa[i]=i;
		for(int i=2;i<=n;++i){
			scanf("%d%d",&a,&b);
			if(!v[a]) d[++cnt]=a,v[a]=1;
			if(!v[b]) d[++cnt]=b,v[b]=1;
			int u=find(a),v=find(b);
			if(u!=v) fa[v]=u;
			if(x[b]<x[a]) ans=x[b]=x[a]+1;
			else if(x[a]<x[b]) ans=x[a]=x[b]+1;
			else ans=++x[a],++x[b];
			for(int j=1;j<=cnt;++j)
				if((v=find(d[j]))==u) x[d[j]]=ans;
			printf("%d\n",ans);
		}
	}
	return 0;
}
