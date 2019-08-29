#include<bits/stdc++.h>
using namespace std;

long long ans;
long long a,b,c,d;
int n,x,Min;
int v[2010];
long long f[2010];
int mi[2010][2010];

long long cal(long long x){
	return ((a * x + b) * x + c) * x + d;
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	cin>>n>>a>>b>>c>>d;
	if (a==0 && b==0 && c<0) {
		x=d*-1/c;
		while (d+c*x<0) x--;
		for (int i=1;i<=n;i++) {
			cin>>v[i];
			if (v[i]<=x) ans+=cal(v[i]);
		}
		cout<<ans<<endl;
		return 0;
	}
	if (a>=0 && b>=0 && c>=0 && d>=0) {
		Min=INT_MAX;ans=0;
		for (int i=1;i<=n;i++) {
			cin>>v[i];
			ans+=cal(v[i]);
			Min=min(v[i],Min);
		}
		if (ans==0) ans+=cal(Min);
		cout<<ans<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++) cin>>v[i];
	for (int i=1;i<=n;i++){
		mi[i][i]=v[i];
		for (int j=i+1;j<=n;j++)
		mi[i][j]=min(v[j],mi[i][j-1]);
	}
	for (int i=1;i<=n;i++) f[i]=-1e14;
	for (int i=1;i<=n;i++)
		for (int j=0;j<i;j++)
		f[i]=max(f[i],f[j]+cal(mi[j+1][i]));
	cout<<f[n]<<endl;
	return 0;
}

