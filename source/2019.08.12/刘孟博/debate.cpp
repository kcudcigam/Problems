#include<bits/stdc++.h>
using namespace std;
const int MAXN=4e5+10;
int n,s,cnt,v,ans;char c[5];
vector<int>a[3];
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s%d",c+1,&v);int t1,t2;
		t1=(c[1]=='1'),t2=(c[2]=='1');
		if(t1==1&&t2==1)++cnt,ans+=v;
		else if(!t1&&!t2)a[0].push_back(-v);
		else if(t1) a[1].push_back(-v);
		else if(t2) a[2].push_back(-v);
	}
	sort(a[1].begin(),a[1].end());
	sort(a[2].begin(),a[2].end());int t=min(a[1].size(),a[2].size());
	for(int i=0;i<t;i++){ans+=(-a[1][i]);ans+=(-a[2][i]);}
	if(a[1].size()>t){for(int i=t;i<a[1].size();i++)a[0].push_back(a[1][i]);}
	else if(a[2].size()>t){for(int i=t;i<a[2].size();i++)a[0].push_back(a[2][i]);}
	sort(a[0].begin(),a[0].end());
	for(int i=0;i<min((int)a[0].size(),cnt);i++) ans+=(-a[0][i]);
	printf("%d\n",ans);
	return 0;
}
