#include<bits/stdc++.h>
using namespace std;
int l[10100000];
int r[10100000];
bool cmp(int x,int y){
	if (r[x]<r[y])return x<y;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n,m;
	long long ans=0;
	cin>>n>>m;
	int k1,k2,k3,k4,k5;
	cin>>k1>>k2>>k3>>k4>>k5;
	for (int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
	}
	sort(l+1,l+n+1,cmp);
	sort(r+1,r+n+1);
	int i=1;
	while(i<=n){
		int s=1,k=i;
		for (int j=i+1;j<=n;j++){
			if (l[j]>r[i])break;
			s++;k=j;
		}
		ans+=k1*s+k2*s*s+k3*s*s*s+k4*s*s*s*s+k5*s*s*s*s*s;
		i=k+1;
	}
	cout<<ans<<endl;
	return 0;
}


