#include<cstdio>
using namespace std;
typedef long long ll;
ll y;
struct emm{
	int l,r; 
}bian[100000010];

int main(){
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	scanf("%d",&y);
    if(y==1){
    	printf("2 1\n1 2\n");return 0;
	}
	int n,m=0;
    ll ans=0,ans1=0;
	for(ll i=1;i<=100000;i++){
        ans1=ans+1; 
		for(ll j=1;j<=i;j++){
			ll sum=1;for(ll k=j+1;k<=i;k++)sum*=k;
			if(i-j==0){
				ans+=sum; break;
			}else{
				for(int k=1;k<=i-j;k++)sum/=k;
			}
			ans+=sum;
		}
		if(ans+1>=y){n=i+2;break;}
		for(int j=1;j<i+1;j++)
		  bian[++m].l=j,bian[m].r=i+1;
	}
	
	printf("%d ",n); 
	for(int i=1;i<n;i++)bian[++m].l=i,bian[m].r=n;
	int i=2; 
	while(ans1<=y&&i<n-1){  
		bian[++m].l=i,bian[m].r=n-1;i++;
		ll ans=0;
		for(int j=1;j<i;j++){
			ll sum=1; for(ll k=j+1;k<i;k++)sum*=k;
			if(i-j==0){
				ans+=sum;break;
			}else{
				for(int k=1;k<i-j;k++)sum/=k;
			}
			ans+=sum;
		}
		ans1+=ans;
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++){
		printf("%d %d\n",bian[i].l,bian[i].r);
	}
	return 0;
}

