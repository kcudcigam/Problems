#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct node_ {
	int a,b,c;
} q[400005] ;

int net1[400005],net2[400005],net3[400005];

bool cmp(node_ x,node_ y)<%return x.a>y.a;%>

char s[5];

int main(void) {
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	
	int n;
	scanf("%d",&n);
	bool flag=true;
	for(int i=1;i<=n;++i) {
		cin>>s>>q[i].a; 
		if(s[0]=='1')q[i].b=true;
		else q[i].b=false;
		if(s[1]=='1')q[i].c=true;
		else q[i].c=false;
		if(q[i].b!=q[i].c)flag=true;
	}
	sort(q+1,q+1+n,cmp);
	if(flag) {
		int tot=0,ans=0;
		for(int i=1;i<=n;++i) {
			if(q[i].b&&q[i].c)++tot;
				ans+=q[i].a;
		}
		for(int i=1;i<=n;++i) {
			if(!q[i].b&&!q[i].c) {
				--tot;
				ans+=q[i].a;
				if(tot==0)break;
			}
		}
		printf("%d",ans);
		return 0;
	}
	int sum=0,cnt1=0,cnt2=0,t1=0,t2=0,t3=0;
	for(int i=1;i<=n;++i) {
		if(q[i].b&&!q[i].c)++cnt1;
		if(!q[i].b&&q[i].c)++cnt2;
		net1[i]=t1;
		net2[i]=t2;
		net3[i]=t3;
		if(q[i].b&&!q[i].c)
			t1=i;
		if(!q[i].b&&q[i].c)
			t2=i;
		if(!q[i].b&&!q[i].c)
			t3=i;
		sum+=q[i].a;
	}
	while(cnt1<n/2) {
		--cnt2;--n;
		if(t2<t3) {
			sum-=q[t2].a;
			t2=net2[t2];
		}
		else {
			--cnt1;
			sum-=q[t3].a;
			t3=net3[t3];
		}
	}
	while(cnt2<n/2) {
		--cnt1;--n;
		if(t1<t3) {
			sum-=q[t1].a;
			t1=net1[t1];
		}
		else {
			--cnt2;
			sum-=q[t3].a;
			t3=net3[t3];
		}
	}
	printf("%d",sum);
} 
