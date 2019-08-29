#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int agrea[444444],agreo[444444],agret[444444],agren[444444];
int sa,so,st,sn,sd,n;
char c[3];
int a;
long long ans;
int comp(const int a,const int b){
	if(a>b){
		return 1;
	}
	else{
		return 0;
	} 
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s %d",c,&a);
		if(c[0]=='1'&&c[1]=='1'){
			sa++;
			agrea[sa]=a;
			ans+=1ll*(agrea[sa]);
		}
		if(c[0]=='1'&&c[1]=='0'){
			so++;
			agreo[so]=a;
		}
		if(c[0]=='0'&&c[1]=='1'){
			st++;
			agret[st]=a;
		}
		if(c[0]=='0'&&c[1]=='0'){
			sn++;
			agren[sn]=a;
		}
	} 
	sort(agreo+1,agreo+so+1,comp);
	sort(agret+1,agret+st+1,comp);
	sd=min(so,st);
	for(int i=1;i<=sd;++i){
		ans+=1ll*(agreo[i]);
		ans+=1ll*(agret[i]);
	}
	for(int i=sd+1;i<=so;++i){
		sn++;
		agren[sn]=agreo[i];
	}
	for(int i=sd+1;i<=st;++i){
		sn++;
		agren[sn]=agret[i];
	}
	sort(agren+1,agren+sn+1,comp);
	for(int i=1;i<=min(sn,sa);++i){
		ans+=1ll*(agren[i]);
	}
	printf("%lld\n",ans);
} 
