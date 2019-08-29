#include<bits/stdc++.h>
using namespace std;

struct node{
	int l,r;
} a[300];
int n,m,x1,x2,x3,x4,x5,la;
long long ans,sum;

bool cmp(node a,node b){
	return a.r<b.r;
}

int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	cin>>n>>m;
	cin>>x1>>x2>>x3>>x4>>x5;
	for (int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
	sort(a+1,a+n+1,cmp);
	la=0;sum=0;
	for (int i=1;i<=n;i++){
		if (a[i].l<=la) {sum++;continue;}
				   else {
				   	ans+=x1*sum+x2*sum*sum+x3*sum*sum*sum+x4*sum*sum*sum*sum+x5*sum*sum*sum*sum*sum;
				   	la=a[i].r;sum=1;
				   }
	}
	ans+=x1*sum+x2*sum*sum+x3*sum*sum*sum+x4*sum*sum*sum*sum+x5*sum*sum*sum*sum*sum;
	cout<<ans<<endl;
	return 0;
}

