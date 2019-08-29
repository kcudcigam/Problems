#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int num=0,f=1; char c=getchar();
	while(!isdigit(c)){if (c=='-') f=-1; c=getchar();}
	while(isdigit(c)){num=num*10+c-'0'; c=getchar();}
	return num*f;
}
int n,dad[300005],a[300005],b[300005];
int l[300005],r[300005],num[300005];
int find(int k){
	if (dad[k]==0) return k;
	else return dad[k]=find(dad[k]);
}
int head[300005],tot;
struct node{
	int to,nxt;
}edge[300005];
void add(int x,int y){
	edge[++tot].to=y;
	edge[tot].nxt=head[x];
	head[x]=tot;
}
queue<int> q;
int ha[300005],dep[300005],bz[300005][20],xxx[20];
void lca(){
	q.push(1);
	dep[1]=1;
	while(!q.empty())
	{
		int x=q.front();
		ha[x]=1;
		q.pop();
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int y=edge[i].to;
			if (ha[y]==0)
			{
				dep[y]=dep[x]+1;
				q.push(y);
				bz[y][0]=x;
				for(int i=1;i<20;i++)
					bz[y][i]=bz[bz[y][i-1]][i-1];
			}
		}
	}
}
int check(int x,int y){
	int s=0;
	if (dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--)
	{
		if (dep[bz[x][i]]>=dep[y])
		{
//			cout<<i<<" ";
			x=bz[x][i];
			s+=xxx[i];
		}
	}
//	cout<<endl;
	if (x==y) return s; 
	for(int i=19;i>=0;i--)
	{
		if (bz[x][i]!=bz[y][i])
		{
			x=bz[x][i];
			y=bz[y][i];
			s+=2*xxx[i];
		}
	}
	return s+2;
}
signed main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++)
	{
		a[i]=read();
		b[i]=read();
		add(a[i],b[i]);
		add(b[i],a[i]);
	}
	lca();
//	for(int i=0;i<=n;i++)
//	{
//		cout<<dep[i];
//		for(int j=0;j<20;j++)
//			cout<<" "<<bz[i][j];
//		cout<<endl;
//	}
	xxx[0]=1;
	for(int i=1;i<=19;i++)
		xxx[i]=xxx[i-1]*2;
	for(int i=1;i<=n;i++)
	{
		l[i]=r[i]=i;
		num[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		int x=find(a[i]),y=find(b[i]);
		dad[x]=y;
		int aa[12],ma=0;
		aa[0]=0;
		aa[1]=num[x],aa[2]=num[y];
		aa[3]=check(l[x],l[y]);
		aa[4]=check(l[x],r[y]);
		aa[5]=check(r[x],l[y]);
		aa[6]=check(r[x],r[y]);
//		for(int i=1;i<=6;i++)
//			cout<<aa[i]<<" ";
//		cout<<endl;
		for(int i=1;i<=6;i++)
			if (aa[i]>aa[ma]) ma=i;
		num[y]=aa[ma];
		if(ma==1){l[y]=l[x];r[y]=r[x];}
		if(ma==2);
		if(ma==3)r[y]=l[x];
		if(ma==4)l[y]=l[x];
		if(ma==5)r[y]=r[x];
		if(ma==6)l[y]=r[x];
//		cout<<l[y]<<" "<<r[y]<<endl;
		cout<<num[y]<<endl;
	}
	return 0;
}
/*
5
3 5
3 4
1 2
1 3
*/
