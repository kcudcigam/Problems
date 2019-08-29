#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define F(i,j,k) for(int i=j;i<=k;i++)
#define DF(i,j,k) for(int i=j;i>=k;i--)
#define P pair
#define M make_pair
template<typename T>inline void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}
template<typename T>inline void write(T x){
	ull y=0;
	T l=0;
	if(!x){putchar(48);return;}
	if(x<0){x=-x;putchar('-');}
	while(x){y=y*10+x%10;x/=10;l++;}
	while(l){putchar(y%10+48);y/=10;l--;}
}
template<typename T>inline void writeln(T x){
	write(x);
	puts("");
}
template<typename T>inline void writes(T x){
	write(x);
	putchar(' ');
}
template<typename T>inline void checkmax(T &a,T b){a=max(a,b);}
template<typename T>inline void checkmin(T &a,T b){a=min(a,b);}
vector<int> gl[32];
int a[11];
int n,k;
int f[32][32],p[32][32];
int num[32],nf[32],ans[32];
inline void lian(int x,int y){
	gl[x].push_back(y);
	gl[y].push_back(x);
	p[x][y]=p[y][x]=1;
}
inline void lin5(int x1,int x2,int x3,int x4,int x5){
	a[1]=x1;
	a[2]=x2;
	a[3]=x3;
	a[4]=x4;
	a[5]=x5;
	F(i,1,5)
		F(j,i+1,5)
			if(!p[a[i]][a[j]])lian(a[i],a[j]);
}
inline void lin6(int x1,int x2,int x3,int x4,int x5,int x6){
	a[1]=x1;
	a[2]=x2;
	a[3]=x3;
	a[4]=x4;
	a[5]=x5;
	a[6]=x6;
	F(i,1,6)
		F(j,i+1,6)
			if(!p[a[i]][a[j]])lian(a[i],a[j]);
}
inline void lin7(int x1,int x2,int x3,int x4,int x5,int x6,int x7){
	a[1]=x1;
	a[2]=x2;
	a[3]=x3;
	a[4]=x4;
	a[5]=x5;
	a[6]=x6;
	a[7]=x7;
	F(i,1,7)
		F(j,i+1,7)
			if(!p[a[i]][a[j]])lian(a[i],a[j]);
}
inline void pre(){
	lin5(1,4,9,14,19);
	lin5(6,11,16,21,26);
	lin5(13,18,23,28,31);
	lin5(2,6,12,18,24);
	lin5(4,10,16,22,28);
	lin5(8,14,20,26,30);
	lin5(3,4,5,6,7);
	lin5(14,15,16,17,18);
	lin5(25,26,27,28,29);
	lin6(8,9,10,11,12,13);
	lin6(19,20,21,22,23,24);
	lin6(1,5,11,17,23,29);
	lin6(3,9,15,21,27,31);
	lin6(2,5,10,15,20,25);
	lin6(7,12,17,22,27,30);
	lin7(1,2,4,5,6,10,11);
	lin7(3,4,8,9,10,14,15);
	lin7(6,7,11,12,13,17,18);
	lin7(14,15,19,20,21,25,26);
	lin7(10,11,15,16,17,21,22);
	lin7(17,18,22,23,24,28,29);
	lin7(21,22,26,27,28,30,31);
	F(i,1,31)
		F(j,1,31)
			f[i][j]=1;
}
int s;
inline void dfs(int dep){
	if(s==k){return;}
	if(dep>31){s++;F(i,1,31)ans[i]=num[i];}
	else {
		if(!nf[dep]){
			F(i,1,n)
				if(f[dep][i]==1){
					int l=gl[dep].size()-1;
					F(j,0,l)f[gl[dep][j]][i]--;
					num[dep]=i;
					dfs(dep+1);
					num[dep]=0;
					F(j,0,l)f[gl[dep][j]][i]++;
				}
		}
		else {dfs(dep+1);}
	}
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	pre();
	read(n);read(k);
	F(i,1,31){
		read(num[i]);
		if(!num[i])continue;
		nf[i]=1;
		if(!f[i][num[i]]){puts("No way");return 0;}
		int l=gl[i].size()-1;
		F(j,0,l)
			f[gl[i][j]][num[i]]=0;
	}
	dfs(1);
	if(s<k)puts("No way");
	else{puts("Found");F(i,1,30)writes(ans[i]);writeln(ans[31]);}
	return 0;
}


