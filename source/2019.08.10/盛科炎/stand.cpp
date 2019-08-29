#include<bits/stdc++.h>
using namespace std;
const int MAXN=255;
int n,m,x1,x2,x3,x4,x5,x,ans;
int num[MAXN];
bool vis[MAXN],all;
bool vis_p[MAXN];
struct Node{
	int l,r;
}a[MAXN];

int G(int x,int x1,int x2,int x3,int x4,int x5){
	int asn=x1*x+x2*x*x+x3*x*x*x+x4*x*x*x*x+x5*x*x*x*x*x;
	return asn;
}

int deal(int place){
	for(int i=1;i<=n;i++){
		if(!vis_p[i]){
			if(a[i].l<= place && a[i].r>=place) {
				vis_p[i]=true;
				vis[i]=true;
				x++;
			}
		}
	}
	int as=G(x,x1,x2,x3,x4,x5);
	return as;
}

void pre_deal(){
	for(int i=1;i<=n;i++){
		int tl=a[i].l;
		int tr=a[i].r;
		for(int j=tl;j<=tr;j++)
			++num[j];
}
}
void sear(){
	pre_deal();
	int maxx=0;
	while(!all){
		int maxp;
		for(int j=1;j<=m;j++){
			if(vis[j]){
				continue;
			}
			else if(num[j]>maxx){
				maxx=num[j];
				maxp=j;
				vis[j]=true;
				}
		}
		ans+=deal(maxp);
		for(int j=1;j<=m;j++){
			if(!vis_p[j])
			all=false;
		}	
	}
}

int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%d %d %d %d %d",&x1,&x2,&x3,&x4,&x5);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].l,&a[i].r);
	}
	sear();
	printf("%d\n",ans);
	return 0;
}


