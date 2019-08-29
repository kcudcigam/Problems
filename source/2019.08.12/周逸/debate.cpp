#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int n,ans;
struct node{
	int a1,a2,w;
}z[maxn];
int z11[maxn],z10[maxn],z01[maxn],z00[maxn];
int tot11,tot10,tot01,tot00;
bool cmp(int a,int b){
	return a>b;
}
void read(int a){
	char c,d;
	do{
		c=getchar();
	}while(c!='0'&&c!='1');
	z[a].a1=c-'0';
	d=getchar();
	z[a].a2=d-'0';
	if(c=='0'&&d=='0')
		scanf("%d",&z00[++tot00]);
	if(c=='1'&&d=='1')
		scanf("%d",&z11[++tot11]);
	if(c=='1'&&d=='0')
		scanf("%d",&z10[++tot10]);
	if(c=='0'&&d=='1')
		scanf("%d",&z01[++tot01]);
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		read(i);
	for(i=1;i<=tot11;i++)
		ans+=z11[i];
	sort(z10+1,z10+tot10+1,cmp);
	sort(z01+1,z01+tot01+1,cmp);
	for(i=1;i<=min(tot10,tot01);i++)
		ans+=z10[i]+z01[i];
	for(i=min(tot10,tot01)+1;i<=max(tot10,tot01);i++)
		if(tot10>tot01)
			z00[++tot00]=z10[i];
		else
			z00[++tot00]=z01[i];
	sort(z00+1,z00+tot00+1,cmp);
	for(i=1;i<=min(tot00,tot11);i++)
		ans+=z00[i];
	printf("%d",ans);
	return 0;
}
