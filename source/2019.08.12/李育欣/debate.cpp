#include<bits/stdc++.h>
using namespace std;
const int N=100;
struct A{
	int st,ed,d;
}a[N];
int n,ans;
bool cmp(A x,A y){
	if(x.ed==1&&y.ed==1)return x.d>y.d;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	int flag1=1,flag2=1;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		scanf("%d",&a[i].d);
		a[i].st=(s[0]-'0');a[i].ed=(s[1]-'0');
		if(a[i].st!=a[i].ed)flag1=0;
		if(a[i].d!=a[1].d)flag2=0;
	}
	if(flag1){
		int fd[N],g=0;
		for(int i=1;i<=n;i++){
			if(a[i].ed)ans+=a[i].d;
			else fd[++g]=-a[i].d;
		}
		sort(fd+1,fd+1+g);
		for(int i=1;i<=floor(n/2);i++)ans-=fd[i];
		printf("%d",ans);
		return 0;
	}
	if(flag2){
		int p1=0,p2=0,m=floor(n/2);
		for(int i=1;i<=n;i++){
			int xx=0,yy=0;
			if(!a[i].st)xx=1;
			if(!a[i].ed)yy=1;
			if(p1+xx<=m&&p2+yy<=m){
				ans+=a[i].d;
				p1+=xx;p2+=yy;
			}
		}
		printf("%d",ans);
		return 0;
	}
	return 0;
}


