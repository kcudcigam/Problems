#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
  int f=1;x=0;char c=getchar();
  for (;!isdigit(c);c=getchar()) if (c==' -') f= -f;
  for (; isdigit(c);c=getchar()) x=x*10+c -'0';
  x*=f;
}
int n,m,e,d,c,b,a,sum,nmax,smax,ans;
int l[60],r[60],aa[60],f[60]; 

int g(int x){
	int s;
	s=a*pow(x,5)+b*pow(x,4)+c*pow(x,3)+d*pow(x,2)+e*x;
	return s;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
    read(n);read(m);
    read(e);read(d);read(c);read(b);read(a);
    for(int i=1;i<=n;i++){
    	read(l[i]);read(r[i]);
    	sum=sum+r[i]-l[i]+1;
    	aa[l[i]]++;aa[r[i]+1]--;
	}
	for(int i=1;i<=m;i++)
		aa[i]=aa[i-1]+aa[i];
	smax=0;
	
	while(sum>0){
		for(int i=1;i<=m;i++){
			if(aa[i]>smax){
				smax=aa[i];
				nmax=i;
			}
		}
		ans=ans+g(aa[nmax]);
		for(int i=1;i<=n;i++){
			if(nmax>=l[i]&&nmax<=r[i]&&f[i]==0){
				f[i]=1;
				for(int j=l[i];j<=r[i];j++)
				    aa[j]--;
				sum=sum-(r[i]-l[i]+1);
			}
		}
		aa[nmax]=0;
		smax=0;
	}
	cout<<ans<<endl;
	return 0;
}


