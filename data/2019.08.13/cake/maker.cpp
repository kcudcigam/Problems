#include<bits/stdc++.h>
using namespace std;
namespace Base{
	typedef long long ll;
	typedef double db;
	const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
	const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
	int read(){
		int f=1,g=0;char ch=getchar();
   		for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
    	for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
    	return f*g;
	}
	int getrand(){return INF&(rand()*19260817+rand()*23333+rand());}
	template<typename T> void chmax(T &x, T y){x = x < y ? y : x;}
	template<typename T> void chmin(T &x, T y){x = x > y ? y : x;}
}
using namespace Base;
namespace filename_maker{
	void pushid(char *ch,int x){
		if (x/10) pushid(ch,x/10);
		ch[strlen(ch)]=x%10+'0';
	}
	void push(char *ch,char *s){for (unsigned i=0;i<strlen(s);i++) ch[strlen(ch)]=s[i];}
}
using namespace filename_maker;
namespace input_maker{
	void make_input(){
		cerr<<"input n , m"<<endl;
		int n=read(),m=read();
		printf("%d %d\n",n,m);
	}
};
namespace output_maker{
	const int N=305,p=1000000007;
	int n,m,f[N][N];
	void check(int &x,int y){x=(x+y<p) ? (x+y) : (x+y-p);}
	int make_output(){
		n=read();m=read();
		memset(f,0,sizeof(f));
		f[1][1]=1;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			for (int k=1;k<i;k++)
			check(f[i][j],(ll)f[k][j]*f[i-k][j]%p);
			
			for (int k=1;k<j;k++)
			check(f[i][j],(ll)f[i][k]*f[i][j-k]%p);
		}
		printf("%d\n",f[n][m]);
		return 0;
	}
};
int l,r;
char I[10]=".in",O[10]=".out";
char ch[50],inp[50],oup[50];
int main(){
	cerr<<"filename:"<<endl;
	scanf("%s",ch);
	cerr<<"l - r"<<endl;
	scanf("%d %d",&l,&r);
	for (int i=l;i<=r;i++){
		memcpy(inp,ch,50);memcpy(oup,ch,50);
		filename_maker :: pushid(inp,i);
		filename_maker :: pushid(oup,i);
		filename_maker :: push(inp,I);
		filename_maker :: push(oup,O);
		cerr<<inp<<endl;
		
		freopen(inp,"w",stdout);
		input_maker :: make_input();
		
		freopen(oup,"w",stdout);
		freopen(inp,"r",stdin);
		output_maker :: make_output();
		
		freopen("CON","r",stdin);
	}
	return 0;
}
