#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
long long s[maxn],d[maxn],ans;
int n;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int i,j,u,v;
	long long k;
	read(n);
	for(i=1;i<=n;i++){
		read(a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(i=1;i<=n;i++){
		if(d[i-1]<0)
			d[i]=a[i];
		else
			d[i]=d[i-1]+a[i];
		k=max(k,d[i]);
	}
	s[i]=s[i-1]+a[i];
	for(i=1;i<=n;i++)
		for(j=i;j<=n;j++)
			if(s[j+1]-s[i]+k<=ans)
				continue;
			else
				for(u=j+1;u<=n;u++)
					for(v=u;v<=n;v++)
						ans=max(ans,s[v+1]-s[u]+s[j+1]-s[i]);
	printf("%d",ans);
	return 0;
}


