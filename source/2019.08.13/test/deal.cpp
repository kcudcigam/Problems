#include<bits/stdc++.h>
using namespace std;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return x * f;
}
const long long p=1000000007;
long long ff[20005],f[20005],g[20005],ans,maxf,maxg;
vector<int>t;
int a[100005],b[100005],c[100005],h[1000005],hh[100005],n,m,i,j,k,l,s,d,r;
void dg(int dep){
	int k=t.size();
	for(int i=0;i<k;i++){
		for(int j=1;j<=b[dep];j++){
			if(t[i]+j*a[dep]<m+a[dep]){
				if(hh[t[i]+j*a[dep]]==0){
					t.push_back(t[i]+j*a[dep]);
					hh[t[i]+j*a[dep]]=1;
				}
				if(h[t[i]+j*a[dep]]!=dep){
					ff[t[i]+j*a[dep]]=f[t[i]];
				}
				else{
					ff[t[i]+j*a[dep]]=(ff[t[i]+j*a[dep]]+f[t[i]])%p;
				}
				h[t[i]+j*a[dep]]=dep;
			}
		}
	}
	for(int i=0;i<m+a[dep];i++){
		if(h[i]==dep){
			if(dep==1){
			}
			f[i]=(f[i]+ff[i])%p;
			hh[i]=1;
		}
	}
	return;
}
int main(){
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	n=read();m=read();
	a[0]=0;
	for(i=1;i<=n;i++){
		a[i]=read();b[i]=read();c[i]=read();
	}
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(h,0,sizeof(h));
	f[0]=1;
	g[0]=1;
	h[0]=-1;
	maxf=0;
	maxg=0;
	memset(hh,0,sizeof(hh));
	t.push_back(0);
	for(i=1;i<n;i++){
		for(j=0;j<a[n];j++){
			if(g[j]){
				for(k=1;k<=c[i];k++){
					if(j+k*a[i]<a[n]){
						if(h[j+k*a[i]]!=i){
							ff[j+k*a[i]]=g[j];
						}
						else{
							ff[j+k*a[i]]=(ff[j+k*a[i]]+g[j])%p;
						}
						h[j+k*a[i]]=i;
					}
				}
			}
		}
		for(j=0;j<=a[n];j++){
			if(h[j]==i){
				g[j]=(g[j]+ff[j])%p;
			}
		}
	}
	ans=0;
	memset(h,0,sizeof(h));
	memset(hh,0,sizeof(hh));
	for(i=n;i>=1;i--){
		dg(i);
		for(j=max(m,m+a[i-1]);j<m+a[i];j++){
			if(f[j]>0){
				ans=(ans+(f[j]*g[j-m])%p)%p;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}