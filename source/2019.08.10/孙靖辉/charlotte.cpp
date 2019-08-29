#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int 
const int maxn=100005;
struct node {
	int x,y,t;
}a[maxn];
int T,tot;
inline bool cmp(node x,node y)
{
	return x.t<y.t;
}
int main()
{
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		tot=0; int flag=0;
		int n=0; scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i].t,&a[i].x,&a[i].y);
			if(a[i].t<(a[i].x+a[i].y)||((a[i].t-(a[i].x+a[i].y))%2)!=0) {
				flag=1;
			}
		}
		if(flag) {
			cout<<"No"<<endl;
			continue;
		}
		sort(a+1,a+1+n,cmp);
		tot+=a[1].t;
		for(int i=2;i<=n;i++) {
			if(a[i].t-tot<a[i].x+a[i].y-a[i-1].x-a[i-1].y&&a[i].t-(a[i].x+a[i].y-a[i-1].x-a[i-1].y+tot)%2!=0) {
				 flag=1; 
			}
			else tot+=a[i].t; 
		}
		if(flag) {
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
	}
	return 0;
}
