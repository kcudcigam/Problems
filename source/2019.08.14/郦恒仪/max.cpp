#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,w=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-'){
			w=-1;
		}
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*w;
}
const long long p=1000000007;
vector<int>gen[100];
long long ans,n,m,i,j,k,l,s,d,f,r,q,fan[100],a[100],b[100],c[100],t[100],lq[100],rq[100];
void dg(int dep){
	if(dep>n){
		long long s=0,cheng=1;
		for(int i=1;i<=m;i++){
			if(t[a[i]]!=i){
				cheng*=c[i];
				cheng%=p;
				cheng*=fan[i];
				cheng%=p;
			}
			else{
				cheng*=c[i];
				cheng%=p;
			}
		}
		for(int i=1;i<=q;i++){
			long long maxs=0,hhh;
			for(int j=lq[i];j<=rq[i];j++){
				if(maxs<b[t[j]]){
					hhh=t[j];
				}
				maxs=max(maxs,b[t[j]]);
			}
			s+=maxs;
			s=s%p;
		}
		cheng*=s;
		cheng%=p;
		/*for(int i=1;i<=n;i++){
			cout<<t[i]<<" ";
		}
		cout<<endl;
		cout<<s<<" "<<cheng<<endl;*/
		ans+=cheng;
		ans%=p;
	}
	else{
		if(t[dep]!=0){
			dg(dep+1);
			return;
		}
		dg(dep+1);
		for(int i=1;i<=m;i++){
			if(a[i]==dep){
				t[dep]=i;
				dg(dep+1);
			}
		}
	}
	return;
}
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	n=read();m=read();q=read();
	for(i=1;i<=m;i++){
		a[i]=read();b[i]=read();c[i]=read();
		if(c[i]==1){
			t[a[i]]=i;
		}
		else{
			gen[a[i]].push_back(i);
			s=c[i];
			l=0;
			while(s<p){
				l++;
				s+=c[i];
			}
			fan[i]=l;
		}
	}
	for(i=1;i<=q;i++){
		lq[i]=read();
		rq[i]=read();
	}
	ans=0;
	dg(1);
	cout<<ans%p<<endl;
	return 0;
}


