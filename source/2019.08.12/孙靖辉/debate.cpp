#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define re register int 
const int maxn=400005;
int a1[maxn],a2[maxn],a3[maxn],a4[maxn]; //01 10 11 00 
int n,num1,num2,mid,number,get_size;// 1 2
int tot1,tot2,tot3,tot4,tot;
ll ans;
inline bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(re i=1;i<=n;i++) {
		int a;int z; scanf("%d %d",&a,&z);
		if(a==01) a1[++tot1]=z;
		else if(a==10) a2[++tot2]=z;
		else if(a==11) a3[++tot3]=z;
		else if(a==00) a4[++tot4]=z;
	}
	sort(a1+1,a1+1+tot1,cmp);
	sort(a2+1,a2+1+tot2,cmp);
	sort(a4+1,a4+1+tot4,cmp);
	if(tot1>tot2) {
		number+=tot2+tot2+1;
		num1+=tot2+1; num2+=tot2;
	}
	else if(tot1<tot2){
		number+=tot1+1+tot1;
		num1+=tot1; num2+=tot1+1;
	}
	else if(tot1==tot2) {
		number+=2*tot1;
		num1+=tot1; num2+=tot2;
	}
	for(re i=1;i<=num1;i++) ans+=a1[i];
	for(re i=1;i<=num2;i++) ans+=a2[i]; 
	tot+=number; 
	for(re i=1;i<=tot3;i++) ans+=a3[i];
//	cout<<ans<<endl;
	tot+=tot3; num1+=tot3; num2+=tot3;
	for(re i=1;i<=tot4;i++) {
		if((tot+i)%2) mid=(tot+i)/2+1;
		else mid=(tot+i)/2;
		if(num1>=mid&&num2>=mid){
			ans+=a4[i];
		}
		else break;
	}
	printf("%lld\n",ans);
	return 0;
}
