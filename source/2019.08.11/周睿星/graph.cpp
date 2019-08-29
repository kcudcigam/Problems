#include<bits/stdc++.h>
using namespace std;
int h[1010],a[1010],head[1010],ver[1010],edge[1010],Next[1010],hh[1010];
int minn=INT_MAX,tot;
void cmp(int len){
	int maxx=-1;
	for(int i=1;i<=len;++i)	maxx=max(maxx,a[i]);
	if(maxx<minn)minn=maxx;
}
void dg(int x,int y,int dep){
	if(x==y){
	cmp(dep-1);	
	return;	
	}
	for(int i=head[x];i;i=Next[i]){
		if(!h[head[x]]&&!hh[ver[i]]){
			h[head[x]]=1;
			hh[ver[i]]=1;
			a[dep]=edge[i];
			dg(ver[i],y,dep+1);
			h[head[x]]=0;
			hh[ver[i]]=0;
		}
	}
}
void add(int x,int y,int z){
	ver[++tot]=y;
	edge[tot]=z;
	Next[tot]=head[x];
	head[x]=tot;
}
int read(){
	int p=1,q=0;
	char ch=getchar();
	
	while(ch>'9'||ch<'0'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
int main(){
	int n=read(),m=read(),Q=read();
	for(int i=1;i<=m;++i){
		int s=read(),e=read(),v=read();
		add(s,e,v);
		add(e,s,v);
	}
	while(Q--){
		minn=INT_MAX;
		int s=read(),e=read();
		hh[s]=1;
		dg(s,e,1);
		hh[s]=0;
		if(minn!=INT_MAX)
		cout<<minn<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
/*
5 6 5
1 2 4
1 3 3
1 4 2
3 4 4
2 3 1
3 5 5
1 3
1 2
1 5
*/
