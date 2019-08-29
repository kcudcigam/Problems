#include<bits/stdc++.h>
using namespace std;
vector<int> a[10];
int read(){
	int x=0,f=1; char c=0;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-48;
	return x*f;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		int ch=read(),x=read(),op=0;
		if(ch==01) op=1;
		if(ch==10) op=2;
		if(ch==00) op=3;
		a[op].push_back(x);
	}
	for(int i=0;i<4;i++)
		sort(a[i].begin(),a[i].end(),greater<int>());
	for(int x=0;x<4;x++)
		for(int i=1;i<a[x].size();i++)
			a[x][i]+=a[x][i-1];
	int A=a[0].size(),B=a[1].size(),C=a[2].size(),D=a[3].size();
	if(B>C){
		swap(a[1],a[2]);
		swap(B,C);
	}
	int t=0,mx=0;
	if(a[0].size()) t+=a[0].back();
	if(a[1].size()) t+=a[1].back();
	for(int x=B;x<=C;x++){
		int y=min(A+B-x,D);
		if(y>0) mx=max(mx,t+a[2][x-1]+a[3][y-1]);
		if(y==0) mx=max(mx,t+a[2][x-1]);
	}
	cout<<mx<<"\n";
	return 0;
}
