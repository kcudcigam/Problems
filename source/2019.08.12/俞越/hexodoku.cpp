#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define ms(a,b) memset(a,b,sizeof a)
#define SZ(x) (int)x.size()-1
#define pb push_back
#define LL long long
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
int t[32];
bool dif[32][32];
void hang(int l,int r,int d){
	for(int i=l;i<=r;i+=d){
		for(int j=l;j<=r;j+=d){
			dif[i][j]=1;
		}
	}
}
int bao[7][7]{
	{1,2,4,5,6,10,11
	},
	{3,4,8,9,10,14,15
	},
	{6,7,11,12,13,17,18
	},
	{10,11,15,16,17,21,22
	},
	{14,15,19,20,21,25,26
	},
	{21,22,26,27,28,30,31
	},
	{17,18,22,23,24,28,29
	}
};
void block(){
	F(i,0,6){
		F(j,0,6){
			F(k,0,6){
				dif[bao[i][j]][bao[i][k]]=1;
			}
		}
	}
}
int k,n;
double T;
int fixed[32];
int num;
void dfs(int x){
//	double UU=clock();
//	if ((UU-T)/1000>=1.8){
//		cout<<"No way\n";
//		exit(0);
//	}
	if (x==32){
		num++;
		if (num==n){
			cout<<"Found\n";
			F(i,1,31) cout<<t[i]<<" ";//<<i<<"\n";
			cout<<"\n";
			exit(0);
		}
		return ;
	}
	if (t[x]){
		dfs(x+1);
		return ;
	}
	bool opt[k+2];
	ms(opt,0);
	F(i,1,31){
		if (dif[x][i]) opt[t[i]]=1;
	}		
//	if (x==15) cout<<t[14]<<" "<<opt[8]<<"         jj\n";

	F(i,1,k){
		if (!opt[i]){
			t[x]=i;
			dfs(x+1);
		}
	}
	t[x]=0;
}
void hhang(int l,int r,int d,int p){
	for (int i=l;i<=r;i+=d){
		dif[i][p]=dif[p][i]=1;
	}
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	T=clock();
	k=read(); n=read();
	F(i,1,31) {
		t[i]=read();
	}
//	cout<<1;
	hang(1,2,1); hang(3,7,1); hang(8,13,1); hang(14,18,1); hang(19,24,1); hang(25,29,1); hang(30,31,1);
	hang(1,4,3); hang(2,5,3); hang(27,30,3); hang(28,31,3);
	hang(3,8,5); hang(4,19,5); hang(5,25,5); hang(6,26,5); hang(7,27,5); hang(13,28,5); hang(24,29,5);
	hang(1,5,4); hang(2,6,4); hang(26,30,4); hang(27,31,4);
	hang(7,13,6); hang(6,24,6); hang(19,25,6); hang(8,26,6); hang(3,27,6); hang(4,28,6); hang(5,29,6);
	hhang(4,19,5,1); hhang(5,25,5,2); hhang(7,27,5,30); hhang(13,28,5,31);
	hhang(5,29,6,1); hhang(6,24,6,2); hhang(8,26,6,30); hhang(3,27,6,31);
	block();
//	cout<<dif[15][14]<<"\n";
	dfs(1);
	cout<<"No way\n";
	return 0;
}

