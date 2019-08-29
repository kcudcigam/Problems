#include<bits/stdc++.h>
using namespace std;
const int maxn=250,maxm=1e7+5;
int n,m;
int a[9];
int s[255][5];
struct node {
	long long num0;
	int num;
}d[maxm];
int vis[maxn];
bool cmp(node x,node y){
	return x.num>y.num;
}
int h0;
int ans;
int lowbit(int x){
	return x&(-x);
}
void work(int x){
	int h=0;
	while(x>0){
		int k=lowbit(x);
		int f=log2(k);
		if(vis[f]==0){
			vis[f]=1;
			h++;
			h0++;
		}
		x-=k;
	}
	ans+=(a[1]*h)+(a[2]*h*h)+(a[3]*h*h*h)+(a[4]*h*h*h*h)+(a[5]*h*h*h*h*h);
	return;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=5;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int l,r;
		scanf("%d%d",&s[i][1],&s[i][2]);
		l=s[i][1];r=s[i][2];
		d[l].num++;d[r+1].num--;
		d[l].num0+=(1<<i);d[r+1].num0-=(1<<i);
	}
	for(int i=1;i<=m;i++){d[i].num=d[i-1].num+d[i].num;d[i].num0=d[i-1].num0+d[i].num0;}
	sort(d+1,d+1+m,cmp);
	for(int i=1;i<=m;i++)if(h0<n)work(d[i].num0);
	printf("%d",ans);
	return 0;
}
/*
4 10
0 1 0 0 0
1 3
3 5
2 7
6 10
*/
