#include<bits/stdc++.h>
using namespace std;
int n,m,x[10],l[305],r[305];
short a[10000005];
vector<int> ans;
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	bool flag1=1;
	cin>>n>>m;
	for(int i=1;i<=5;i++){
		cin>>x[i];
	}
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		if(l[i]!=1||r[i]!=n){
			flag1=0;
		}
	}
	if(!(x[2]+x[3]+x[4]+x[5])){
		cout<<n*x[1];
		return 0;
	}
	if(flag1){
		cout<<x[1]*n+x[2]*pow(n,2)+x[3]*pow(n,3)+x[4]*pow(n,4)+x[5]*pow(n,5);
	}
	while(true){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			a[l[i]]++;
			a[r[i]+1]--;
		}
		int ans1=-1,ans2;
		for(int i=1;i<=m;i++){
			a[i]=a[i-1]+a[i];
			if(a[i]>ans1){
				ans1=a[i];
				ans2=i;
			}
		}
		if(!ans1){
			break;
		}
		ans.push_back(ans1);
		for(int i=1;i<=n;i++){
			if(l[i]<=ans2&&r[i]>=ans2){
				l[i]=0;r[i]=-1;
			}
		}
	}
	int res=0;
	for(int i=0;i<ans.size();i++){
		int t=ans[i];
		res+=x[1]*t+x[2]*pow(t,2)+x[3]*pow(t,3)+x[4]*pow(t,4)+x[5]*pow(t,5);
	}
	cout<<res;
	return 0;
}
