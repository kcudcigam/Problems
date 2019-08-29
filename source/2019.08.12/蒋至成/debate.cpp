#include<bits/stdc++.h>
using namespace std;
struct node{
	int u;
};
int n,w[400010],ans,wn;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
vector<node> a,b,c;
bool cmp(node A,node B){
	return  A.u>B.u;
}
int main(){
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout); 
	read(n);
	for(int i=1;i<=n;++i){
		string st;
		cin>>st;
		read(w[i]);
		if(st=="11"){
			ans+=w[i];
			wn++;
		}
		else if(st=="00")a.push_back((node){w[i]});
		else if(st=="01")b.push_back((node){w[i]});
		else c.push_back((node){w[i]});
	}
	stable_sort(b.begin(),b.end(),cmp);
	stable_sort(c.begin(),c.end(),cmp);
	if(b.size()<c.size()){
		for(int i=0;i<b.size();++i)ans+=(b[i].u+c[i].u);
		for(int i=b.size();i<c.size();++i)a.push_back((node){c[i].u});
	}
	else{
		for(int i=0;i<c.size();++i)ans+=(b[i].u+c[i].u);
		for(int i=c.size();i<b.size();++i)a.push_back((node){b[i].u});
	}
	stable_sort(a.begin(),a.end(),cmp);
	for(int i=0;i<min(wn,(int)a.size());++i)ans+=a[i].u;
	cout<<ans;
	return 0;
}


