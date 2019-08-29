#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long
#pragma GCC optimize("Ofast")
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
bool walk(int x,int len,bool o){
	if (x>>len&1) return o^1;
	return o;
}
tr1::unordered_map<int,bool> mp;
bool Get(int x,int y){
	bool org=1;
	DF(i,30,0){
		if (y>>i&1) org=walk(x,i,org);
	}
	return org;
}
int lg[11000];
struct node{
	bool now;
	int x,y;
}q[1543600+411];
const int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int id(int x,int y){
	return x*10000+y;
}
void bfs(int x,int y){
	int l=1,r=1;
	q[1]=(node){Get(x,y),x,y}; mp[id(x,y)]=1;
	while (l<=r){
		node t=q[l++]; 
		//ans++;
//		cout<<t.now<<" "<<"\n";
		for (int i=0;i<4;i++){
			int tx=t.x+dx[i],ty=t.y+dy[i];
			if (mp.count(id(tx,ty))) continue; 
			bool gg=Get(tx,ty);
			if (t.now==gg){
				mp[id(tx,ty)]=1;
				q[++r]=(node){gg,tx,ty};
				if (r>=1543600){
					puts("infinity");
					return ;
				}
			}
		}
	}
	cout<<r<<"\n";
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
//	cout<<Get(1,3)<<"\n";
	F(i,2,10000) lg[i]=lg[i>>1]+1;
	int x,y;
	cin>>x>>y;
	bfs(x,y);
//	F(i,0,31){
//		F(j,0,31){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	system("pause");
	return 0;
}

