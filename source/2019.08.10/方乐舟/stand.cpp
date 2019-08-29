#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a,b,c,d,e;
long long step,s;
long long ss[300];
struct ll{
	long long l;
	long long r;
}p[300];
bool myc(ll x,ll y){
	if (x.l>y.l) return false;
	else return true;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	cin>>n>>m;
	cin>>a>>b>>c>>d>>e;
	for (int i=1;i<=n;i++){
		cin>>p[i].l>>p[i].r; 
	}
	sort (p+1,p+n+1,myc);
	step=p[1].r;
	s=1;
	ss[s]=1;
	for (int i=2;i<=n;i++){
		if (p[i].l<=step){
			step=min(step,p[i].r);
			ss[s]++;
		}
		else {
			step==p[i].r;
			s++;
			ss[s]++;
		}
	}
	for (int i=1;i<=s;i++){
		ans+=a*ss[i]+b*ss[i]*ss[i]+c*ss[i]*ss[i]*ss[i]+d*ss[i]*ss[i]*ss[i]*ss[i]+e*ss[i]*ss[i]*ss[i]*ss[i]*ss[i];
	}
	cout<<ans<<endl;
	return 0;
}


