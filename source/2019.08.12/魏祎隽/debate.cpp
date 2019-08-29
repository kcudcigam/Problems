#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,a[1<<19],c,ans,sm,t,sz1,sz2;
basic_string<int> v1,v2,v0;
int calc(int c){return sz1-sz2<=c?v1.back()+v2.back() : v2.back()+v1[sz2+c-1];}
int main(){
	freopen("debate.in","r",stdin),freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d%d",a+i,&x);
		if(a[i]==11)c++,ans+=x;
		if(a[i]==1)v1+=x;
		if(a[i]==10)v2+=x;
		if(a[i]==0)v0+=x;
	}
	for(auto p:{&v1,&v2,&v0})
		sort(p->begin(),p->end(),greater<int>{});
	sz1=v1.size(),sz2=v2.size();
	if(sz1<sz2)swap(v1,v2),swap(sz1,sz2);
	for(int i=1;i<sz1;i++)v1[i]+=v1[i-1];
	for(int i=1;i<sz2;i++)v2[i]+=v2[i-1];
	t=calc(c);
	for(int i=0;i<(int)v0.size();i++)if(c-i-1>=0){
		sm+=v0[i];
		t=max(t,sm+calc(c-i-1));
	}
	printf("%d\n",t+ans);
	return 0;
}
