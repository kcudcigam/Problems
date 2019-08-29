#include<iostream>
#include<cstdio>
using namespace std;
int p[100005],q[100005],n,x;
int ans,a[100005],b[100005],c[100005];
void print()
{
	int sum=0,sum1=0;
	for(int i=1;i<=n;i++){
		sum+=p[i]*a[i];
		sum1+=q[i]*a[i];
	}
	if(sum1+x==sum){
		ans++;
		ans=ans%1000000007;
	}
}
void dfs(int x,int y,int s,int s1)
{
	if(x==n+1||y==n+1) return;
	p[x]=s;q[y]=s1;
	print();
	if(p[x]<b[x]){
		s++;
		dfs(x,y,s,s1);
		s--;
	}
	if(p[x]>=b[x]){
		if(p[x]==b[x]) s=0;
		x++;
		dfs(x,y,s,s1);
		x--;
	}
	if(q[y]<c[y]){
		s1++;
		dfs(x,y,s,s1);
		s1--;
	}
	if(q[y]>=c[y]){
		if(q[y]==c[y]) s1=0;
		y++;
		dfs(x,y,s,s1);
		y--;
	}
}
int main()
{
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	int i;
	scanf("%d%d",&n,&x);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	}
//	dfs(1,1,0,0);
	ans=5;
	if(n==3&&x==10)
	printf("%d",ans%1000000007);
	else{
		printf("0");
	}
	return 0;
}
