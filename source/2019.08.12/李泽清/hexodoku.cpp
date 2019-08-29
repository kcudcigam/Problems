#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define F(x,y,z) for (int x=y;x<=z;++x)
#define D(x,y,z) for (int x=y;x>=z;--x)
using namespace std;
const int N=40;
inline LL R(){
	LL x=0,f=1;char c=getchar();
	for (;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for (; isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
int K,n;
vector<int> v[N];
int h[40][40];
int p[40],cnt;
void Pre(){
	v[7].pb(1);v[13].pb(1);
	v[2].pb(2);v[6].pb(2);v[12].pb(2);v[18].pb(2);v[24].pb(2);
	v[1].pb(3);v[5].pb(3);v[11].pb(3);v[17].pb(3);v[23].pb(3);v[29].pb(3);
	v[4].pb(4);v[10].pb(4);v[16].pb(4);v[22].pb(4);v[28].pb(4);
	v[3].pb(5);v[9].pb(5);v[15].pb(5);v[21].pb(5);v[27].pb(5);v[31].pb(5);
	v[8].pb(6);v[14].pb(6);v[20].pb(6);v[26].pb(6);v[30].pb(6);
	v[19].pb(7);v[25].pb(7);
	
	v[3].pb(8);v[8].pb(8);
	v[1].pb(9);v[4].pb(9);v[9].pb(9);v[14].pb(9);v[19].pb(9);
	v[2].pb(10);v[5].pb(10);v[10].pb(10);v[15].pb(10);v[20].pb(10);v[25].pb(10);
	v[6].pb(11);v[11].pb(11);v[16].pb(11);v[21].pb(11);v[26].pb(11);
	v[7].pb(12);v[12].pb(12);v[17].pb(12);v[22].pb(12);v[27].pb(12);v[30].pb(12);
	v[13].pb(13);v[18].pb(13);v[23].pb(13);v[28].pb(13);v[31].pb(13);
	v[24].pb(14);v[29].pb(14);
	
	v[1].pb(15);v[2].pb(15);
	v[3].pb(16);v[4].pb(16);v[5].pb(16);v[6].pb(16);v[7].pb(16);
	v[8].pb(17);v[9].pb(17);v[10].pb(17);v[11].pb(17);v[12].pb(17);v[13].pb(17);
	v[14].pb(18);v[15].pb(18);v[16].pb(18);v[17].pb(18);v[18].pb(18);
	v[19].pb(19);v[20].pb(19);v[21].pb(19);v[22].pb(19);v[23].pb(19);v[24].pb(19);
	v[25].pb(20);v[26].pb(20);v[27].pb(20);v[28].pb(20);v[29].pb(20);
	v[30].pb(21);v[31].pb(21);
	
	v[1].pb(22);v[2].pb(22);v[4].pb(22);v[5].pb(22);v[6].pb(22);v[10].pb(22);v[11].pb(22);
	v[3].pb(23);v[4].pb(23);v[8].pb(23);v[9].pb(23);v[10].pb(23);v[14].pb(23);v[15].pb(23);
	v[6].pb(24);v[7].pb(24);v[11].pb(24);v[12].pb(24);v[13].pb(24);v[17].pb(24);v[18].pb(24);
	v[10].pb(25);v[11].pb(25);v[15].pb(25);v[16].pb(25);v[17].pb(25);v[21].pb(25);v[22].pb(25);
	v[14].pb(26);v[15].pb(26);v[19].pb(26);v[20].pb(26);v[21].pb(26);v[25].pb(26);v[26].pb(26);
	v[17].pb(27);v[18].pb(27);v[22].pb(27);v[23].pb(27);v[24].pb(27);v[28].pb(27);v[29].pb(27);
	v[21].pb(28);v[22].pb(28);v[26].pb(28);v[27].pb(28);v[28].pb(28);v[30].pb(28);v[31].pb(28);
}
void pr(){
	cout<<"Found\n";
	F(i,1,31)cout<<p[i]<<' ';
	exit(0);
}
void prr(int xx){
	F(i,1,K)printf("%d:%d\n",i,h[xx][i]);
}
void dfs(int dep){
	if(dep==32){
		++cnt;
		if(cnt==n)
		pr();
		return;
	}
	if(p[dep]){dfs(dep+1);return;}
	
	F(c,1,K){
		int fl=1;
		for(auto i:v[dep])fl&=(!h[i][c]);
		if(!fl)continue;
		for(auto i:v[dep])h[i][c]=1;
		p[dep]=c;
		//if(dep==8&&c==8)cout<<"Yes\n";
		dfs(dep+1);
		p[dep]=0;
		for(auto i:v[dep])h[i][c]=0;
	}
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	Pre();
	cin>>K>>n;
	F(u,1,31){
		cin>>p[u];
		for(auto i:v[u])h[i][p[u]]=1;
	}
	//prr(8);prr(17);prr(23);
	dfs(1);
	cout<<"No way\n";
	return 0;
}
