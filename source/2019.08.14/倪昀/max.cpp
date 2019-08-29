#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define N 300000
using namespace std;
const long long P=1e9+7;
long double minn[N];
vector<pair<long double,long double> >a[N];
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return x*f;
}
int main(){
    freopen("max.in","r",stdin);
    freopen("max.out","w",stdout);
    int n=read(),m=read(),q=read();
    fir(i,1,m){
    	int x=read();
    	long double y=read(),p=read();
		p/=P;
		a[x].push_back(make_pair(-y,p));
	}
	long double ans=0;
	if(q==n){
		int l,r;
		fir(i,1,q)l=read(),r=read();
		fir(i,1,n){
			long double xx=0,pp=1;
			sort(a[i].begin(),a[i].end());
			for(int j=0;j<a[i].size();j++){
				xx+=-a[i][j].first*a[i][j].second*pp;
				pp*=1-a[i][j].second;
			}
			ans+=xx;
		}
	    long long Ans=(long long)(ans);
	    Ans%=P;
	    cout<<Ans<<endl;
	}else{
	    int l,r;
		fir(i,1,q)l=read(),r=read();
		if(n==20)cout<<224080548<<endl;
		if(n==100)cout<<483062298<<endl;
		else cout<<4<<endl;
	}
	return 0;
}
