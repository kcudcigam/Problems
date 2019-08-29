#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=105+(int)(1e4);

bitset<N> a[N],b[N];
int u,v,n,m,pd,ans;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

void dfs(int x,int y){
	pd=(x==n)||(y==m)?1:pd;
	b[x][y]=1;
	++ans;
	if ((x>0)&&(b[x-1][y]==0)&&(a[x-1][y]==a[u][v])) dfs(x-1,y);
	if ((y>0)&&(b[x][y-1]==0)&&(a[x][y-1]==a[u][v])) dfs(x,y-1);
	if ((x<n)&&(b[x+1][y]==0)&&(a[x+1][y]==a[u][v])) dfs(x+1,y);
	if ((y<m)&&(b[x][y+1]==0)&&(a[x][y+1]==a[u][v])) dfs(x,y+1);
}

int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	a[0][0]=0;
	cin>>u>>v;
	n=N-5;m=N-5;
	for (int i=0;(i<<1)<=n;++i)
		for (int j=0;(j<<1)<=m;++j){
			a[(i<<1)][(j<<1)]=a[(i<<1)+1][(j<<1)]=a[(i<<1)][(j<<1)+1]=a[i][j]^0;
			a[(i<<1)+1][(j<<1)+1]=a[i][j]^1;			
		}
	ans=pd=0;
	dfs(u,v);
	if ((pd==1)&&(a[u][v]==0)) cout<<"infinity\n";else
		cout<<ans<<'\n';
	return 0;
}
