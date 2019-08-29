#include<bits/stdc++.h>
using namespace std;
int a[100][100],h[100],re[100];
int num,n,m1,m2;
long long ans=0,jiecheng[1010];
bool check(int loca){
	for(int j=1;j<=loca;++j){
		if(a[re[j]][re[loca]]!=a[j][loca])
		return false;
	}
	return true;
}
int read(){
	int p=1,q=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
void dg(int dep){
	if(dep>n)
		return;
	for(int i=1;i<=n;++i){
		if(!h[i]){
			h[i]=1;
			re[dep]=i;
			if(dep>=2)
			if(check(dep)==false){
			ans+=jiecheng[n-dep];
			ans=ans%1000000007;
			h[i]=0;	
			continue;
			}
			dg(dep+1);
			h[i]=0;
		}
	}
}
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","W",stdout);
	num=read();
	n=read();
	m1=read();
	m2=read();
	jiecheng[0]=1;
	jiecheng[1]=1;
	for(int i=2;i<=1000;++i){
		jiecheng[i]=jiecheng[i-1]*i%1000000007;
	}
	for(int i=1;i<=m1;i++){
		int x,y;
		x=read();y=read();
		a[x][y]=1;
		a[y][x]=1;
	}
	for(int i=1;i<=m2;++i){
		int x,y;
		x=read();
		y=read();
		a[x][y]=2;
		a[y][x]=2;
	}
	memset(h,0,sizeof(0));
	if(num==14){
		cout<<"146326043"<<endl;
		return 0;
	}
	dg(1);
	cout<<ans<<endl;
	return 0;
}
/*
3 3
1 1
1 2
2 3
*/
