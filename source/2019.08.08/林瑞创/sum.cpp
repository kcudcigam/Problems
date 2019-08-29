#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;ll A[100010],sum[100010],ans=-(1<<30);

inline ll read(){
	ll f=1,num=0; char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))num=(num<<1)+(num<<3)+ch-'0',ch=getchar();
	return f*num;
}

int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		A[i]=read(),sum[i]=sum[i-1]+A[i];  
		if(i>1)
		 for(int c=2;c<=i;c++)
		  for(int b=1;b<c;b++)
		   for(int a=1;a<=b;a++)
		    ans=max(ans,sum[i]-sum[c-1]+sum[b]-sum[a-1]);
	}
	printf("%lld\n",ans);
	return 0;
}
