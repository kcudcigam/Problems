#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n;
char k,a[40],vis[40][40],f[40],g[40],h[40],b[40],c[40][40],nw;

int rd(){
	int re=0,f=1;char c=getchar();
	while ((c<'0')||(c>'9')) {if (c=='-') f=-f;c=getchar();}
	while ((c>='0')&&(c<='9')) {re=re*10+c-'0';c=getchar();}
	return re*f;
}

void Add(char x){
	c[x][++b[x]]=nw;
}

void Push(char x,char k){
	char y=a[x];
	vis[f[x]][y]+=k;
	vis[g[x]][y]+=k;
	vis[h[x]][y]+=k;
	for (char i=1;i<=b[x];++i)
		vis[c[x][i]][y]+=k;
}

char pd(char x,char y){
	if ((vis[f[x]][y]>0)||(vis[g[x]][y]>0)||(vis[h[x]][y]>0))
		return 0;
	for (char i=1;i<=b[x];++i)
		if (vis[c[x][i]][y]>0)
			return 0;
	return 1;	
}

void dfs(char x){
	if (n<0) return;
	if (x>31){
		--n;
		if (n==0){
			cout<<"Found\n";
			for (char i=1;i<31;++i) cout<<(int)(a[i])<<' ';
			cout<<(int)(a[31])<<'\n';
		}
		return;
	}
	if (a[x]!=0){
		dfs(x+1);
		return;
	}
	for (char i=1;(i<=k)&&(n>0);++i)
		if (pd(x,i)==1){
			a[x]=i;
			Push(x,1);
			dfs(x+1);
			Push(x,-1);
			a[x]=0;
		}
	a[x]=0;
}

int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	f[1]=f[2]=1;
	for (char i=3;i<=7;++i) f[i]=2;
	for (char i=8;i<=13;++i) f[i]=3;
	for (char i=14;i<=18;++i) f[i]=4;
	for (char i=19;i<=24;++i) f[i]=5;
	for (char i=25;i<=29;++i) f[i]=6;
	f[30]=f[31]=7;
	
	g[3]=g[8]=8;
	g[1]=g[4]=g[9]=g[14]=g[19]=9;
	g[2]=g[5]=g[10]=g[15]=g[20]=g[25]=10;
	g[6]=g[11]=g[16]=g[21]=g[26]=11;
	g[7]=g[12]=g[17]=g[22]=g[27]=g[30]=12;
	g[13]=g[18]=g[23]=g[28]=g[31]=13;
	g[24]=g[29]=14;
	
	h[7]=h[13]=15;
	h[2]=h[6]=h[12]=h[18]=h[24]=16;
	h[1]=h[5]=h[11]=h[17]=h[23]=h[29]=17;
	h[4]=h[10]=h[16]=h[22]=h[28]=18;
	h[3]=h[9]=h[15]=h[21]=h[27]=h[31]=19;
	h[8]=h[14]=h[20]=h[26]=h[30]=20;
	h[19]=h[25]=21;
	
	memset(b,0,sizeof(b));
	nw=22;
	Add(1);Add(2);Add(4);Add(5);Add(6);Add(10);Add(11);
	nw=23;
	Add(3);Add(4);Add(8);Add(9);Add(10);Add(14);Add(15);
	nw=24;
	Add(6);Add(7);Add(11);Add(12);Add(13);Add(17);Add(18);	
	nw=25;
	Add(10);Add(11);Add(15);Add(16);Add(17);Add(21);Add(22);
	nw=26;
	Add(14);Add(15);Add(19);Add(20);Add(21);Add(25);Add(26);
	nw=27;
	Add(17);Add(18);Add(22);Add(23);Add(24);Add(28);Add(29);
	nw=28;
	Add(21);Add(22);Add(26);Add(27);Add(28);Add(30);Add(31);

	k=(char)(rd());n=rd();
	memset(vis,0,sizeof(vis));	
	for (char i=1;i<=31;++i){
		a[i]=(char)(rd());
		if (a[i]>0) Push(i,1);
	}
	
	dfs(1);
	if (n>0) cout<<"No way\n";
	return 0;
}
