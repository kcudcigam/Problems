#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const long long P=998244353;
long long n,l,ans=0,tot=0;
string s;
int a[1000000],h[1000];
int ch(string s){
	fir(i,0,s.size()-1)
	    if(s[i]!='a')return 0;
	return 1;
}
inline int Pow(int x,long long n){
	memset(h,0,sizeof(h));
	int t=0;
	while(n){
		t++;
		if(n%2)h[t]=1;
		n/=2;
	}
	int tmp=1;
	for(int i=t;i;i--){
		tmp=tmp*tmp%P;
		if(h[i])tmp=tmp*x%P;
	}
	return tmp;
}
void dfs(int dep){
	if(dep==n){
		int p=0,q=s.size()-1;
		while(p<s.size()&&a[p]==s[p])p++;
		while(q>=0&&a[q+l]==s[q])q--;
		if(p>q)tot=(tot+1)%P;
		return;
	}
	fir(i,0,25){
		a[dep]='a'+i;
		dfs(dep+1);
	}
}
int main(){
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    cin>>n;
    cin>>s;
    l=n-s.size();
    ans=Pow(26,n);
    if(ch(s)){
    	tot=1;
    	if(l)tot+=n*25,tot%=P;
    	if(l>1)tot+=(n-1)*625,tot%=P;
    	fir(i,3,l){
    		int tmp=n-i+1;
    		tmp=tmp*625%P;
    		tmp=tmp*Pow(26,i-2)%P;
    		tot=(tot+tmp)%P;
		}
	}else dfs(0);
	ans=(ans+P-tot)%P;
	cout<<ans<<endl;
	return 0;
}
