#include<bits/stdc++.h>
using namespace std;
int xishu[6],str[10000010],ans=0;
int l[260],r[260],used[260],chafen[10000010];
bool cmp(int x,int y){
	return x>y;
}
int read(){
	int p=1,q=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')p=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		q=q*10+ch-'0';
		ch=getchar();
	}
	return p*q;
}
long long calc(int w){
	long long ans=0;
	for(int i=1;i<=5;++i){
		int t=w;
		for(int j=1;j<=i-1;++j){
			t*=w;
		}
		ans=ans+xishu[i]*t;
	}
	return ans;
}
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n=read(),m=read();
	bool flg=true;
	for(int i=1;i<=5;++i)xishu[i]=read();
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read();
		if(l[i]!=1||r[i]!=m)flg=false;
		str[l[i]]++;
		str[r[i]+1]--;
	}
	if(flg==true){
		cout<<calc(n)<<endl;
		return 0;
	}
	for(int i=1;i<=m;++i){
		str[i]+=str[i-1];
		chafen[i]=str[i]-str[i-1];
	}
	while(n){
		int maxx=0,loca;
		for(int i=1;i<=m;++i)
		if(str[i]>maxx){
			maxx=str[i];
			loca=i;
		}
		for(int i=1;i<=n;++i){
			if(!used[i]&&loca>=l[i]&&loca<=r[i]){
				used[i]=1;
				chafen[l[i]]-=1;
				chafen[r[i]+1]+=1;
			}
		}
		for(int i=1;i<=m;++i)str[i]=str[i-1]+chafen[i];
		ans+=calc(maxx);
		n-=maxx;
	}
	cout<<ans<<endl;
	return 0;
}
