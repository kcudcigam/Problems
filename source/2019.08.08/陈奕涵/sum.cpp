#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long a[100010];
long long query(int l,int r){
	long long ans=-1e17,t=0;
	for(int i=l;i<=r;++i){
		t+=a[i];
		ans=max(ans,t);
		if(t<0)t=0;
	}
	return ans;
}
int main()
{
	//文件输入输出 
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	//读入
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	//处理
	long long ans=-1e17;
	for(int k=1;k<n;++k)
		ans=max(ans,query(1,k)+query(k+1,n));
	printf("%lld\n",ans);
	return 0;
}

