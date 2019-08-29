#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int w=1,x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(x=='-'){
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
	int zuo;
	int you;
}a[1005];
int n,m,i,j,k,l,has[1005],d,f,cnt,r,ci[10],t[1000][500];
vector<int>h[1005];
long long ans,s;
bool cmp(node a,node b){
	if(a.you<b.you){
		return true;
	}
	else{
		if(a.you==b.you&&a.zuo<b.zuo){
			return true;
		}
		else{
			return false;
		}
	}
}
long long get(int x){
	long long jia=0;
	long long jia1;
	for(int i=1;i<=5;i++){
		if(ci[i]!=0){
			jia1=ci[i];
			for(int j=1;j<=i;j++){
				jia1*=x;
			}
			jia+=jia1;
		}
	}
	return jia;
}
void getji(){
	
}
void dg(int dep,long long hh){
	if(dep==n){
		s=max(hh,s);
	}
	else{
		for(int i=1;i<=m;i++){
			h[i].clear();
		}
		getji();
		int f=0;
		int r=0;
		for(int i=1;i<=n;i++){
			if(f<h[i].size()){
				f=h[i].size();
				r=i;
			}
		}
		cnt++;
		t[cnt][0]=h[r].size();
		for(int i=0;i<h[r].size();i++){
			has[h[r][i]]=1;
			t[cnt][i+1]=h[r][i];
		}
		dg(dep+h[r].size(),hh+get(t[cnt][0]));
		for(int i=1;i<=t[cnt][0];i++){
			has[t[cnt][i]]=0;
		}
		cnt--;
	}
	return;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	n=read();m=read();
	for(i=1;i<=5;i++){
		ci[i]=read();
	}
	for(i=1;i<=n;i++){
		a[i].zuo=read();
		a[i].you=read();
	}
	sort(a+1,a+n+1,cmp);
	memset(has,0,sizeof(has));
	s=0;
	cnt=0;
	dg(0,0);
	cout<<s<<endl;
	return 0;
}
