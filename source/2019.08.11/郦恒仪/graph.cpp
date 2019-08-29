#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
struct node{
	int fro;
	int too;
	int chang;
}bian[300005];
vector<int>a[300005],b[300005];
int n,m,i,j,k,l,s,d,f,r,mm,hh[3000005],h[300005];
bool cmp(node x,node y){
	return x.chang<y.chang;
}
int zhao(int x){
	if(h[x]==x){
		return x;
	}
	h[x]=zhao(h[x]);
	return h[x];
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read();m=read();mm=read();
	for(i=1;i<=n;i++){
		h[i]=i;
	}
	for(i=1;i<=m;i++){
		f=read();r=read();l=read();
		a[f].push_back(r);
		a[r].push_back(f);
		b[f].push_back(l);
		b[r].push_back(l);
		h[zhao(f)]=zhao(r);
		bian[i].fro=f;
		bian[i].too=r;
		bian[i].chang=l;
	}
	sort(bian+1,bian+m+1,cmp);
	memset(hh,0x3f3f3f3f,sizeof(hh));
	for(i=1;i<=m;i++){
		hh[bian[i].fro]=min(hh[bian[i].fro],bian[i].chang);
		hh[bian[i].too]=min(hh[bian[i].too],bian[i].chang);
	}
	for(i=1;i<=mm;i++){
		f=read();r=read();
		if(zhao(f)!=zhao(r)){
			printf("%d\n",-1);
		}
		else{
			printf("%d\n",max(hh[f],hh[r]));
		}
	}
	return 0;
}


