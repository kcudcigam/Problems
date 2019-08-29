#include<bits/stdc++.h>
#define N 200010
#define ll long long 
using namespace std;
template <typename T> void read(T &x){
	x=0;
	T f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	x*=f;
}
ll a[N];
ll f[N];
ll n,A,B,C,D;
ll ans;
bool flag;
ll fu[N];
ll t;
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	read(n),read(A),read(B),read(C),read(D);
	if(!A&&!B){
		if(!C){
			for(int i=1;i<=n;i++){
			read(a[i]);
			}
			if(D>0) printf("%lld\n",n*D);
			else printf("%lld\n",D);
		}else{
			if(C<0){
				for(int i=1;i<=n;i++){
					read(a[i]);
					f[i]=C*a[i]+D;
					if(f[i]>0) ans+=f[i];
				}
				printf("%lld\n",ans);
			}else{
				for(int i=1;i<=n;i++){
					read(a[i]);
					f[i]=C*a[i]+D;
				}
				for(int i=1;i<=n;i++){
					if(f[i]<0){
					t++;
					fu[t]=i;
					}
				}
				if(t){
					for(int i=1;i<t;i++){
						for(int j=i+1;j<=t;j++){
							ll sum=0;
							for(int k=fu[i]+1;k<fu[j];k++) sum+=f[k];
							if(sum<-1*max(f[fu[i]],f[fu[j]])){
								for(int k=fu[i]+1;k<fu[j];k++)
									f[k]=0;
								if(f[fu[i]]<=f[fu[j]]) f[fu[i]]=0;
								else f[fu[j]]=0;
							}
						}
					}
				}
				for(int i=1;i<=n;i++)
					ans+=f[i];
				printf("%lld\n",ans);
			}
		}
	}
	if(A<0){
		for(int i=1;i<=n;i++){
				read(a[i]);
				f[i]=C*a[i]+D;
				if(f[i]>0) ans+=f[i];
			}
		printf("%lld\n",ans);
	}
	if(A>0){
		for(int i=1;i<=n;i++){
		read(a[i]);
		f[i]=A*a[i]*a[i]*a[i]+B*a[i]*a[i]+C*a[i]+D;
		}
		for(int i=1;i<=n;i++){
			if(f[i]<0){
				t++;
				fu[t]=i;
			}
		}
		if(t){
			for(int i=1;i<t;i++){
				for(int j=i+1;j<=t;j++){
					ll sum=0;
					for(int k=fu[i]+1;k<fu[j];k++) sum+=f[k];
					if(sum<-1*max(f[fu[i]],f[fu[j]])){
						for(int k=fu[i]+1;k<fu[j];k++)
							f[k]=0;
						if(f[fu[i]]<=f[fu[j]]) f[fu[i]]=0;
						else f[fu[j]]=0;
					}
				}
			}
		}
				for(int i=1;i<=n;i++)
					ans+=f[i];
				printf("%lld\n",ans);
	}
	return 0;
}


