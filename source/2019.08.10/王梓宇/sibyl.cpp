#include<bits/stdc++.h>
using namespace std;
const int N=300005;
const int M=300005;
inline int read(){
	int f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
	while(ch<='9'&&ch>='0'){x*=10;x+=ch-'0';ch=getchar();}
	return x*f;
}
int Head[N],Next[M*2],Ver[M*2];
int In[N],root[N],be[N];
int a[N],vis[N],lazy,tag[N];
int tot,n,m,Q;
inline void add(int x,int y){
	Ver[++tot]=y;
	Next[tot]=Head[x];
	Head[x]=tot;
	In[y]++;In[x]++;
}
inline void change(int x,int y){
	for(int i=Head[x];i;i=Next[i]){
		int v=Ver[i];
		a[v]+=y;
	}
	a[x]+=y;
}
void case_3(){
	int x,y,op;
	for(int i=Head[1];i;i=Next[i]){
		int u=Ver[i];
		vis[u]=1;
	}
	while(Q--){
			op=read();
			if(op==1){
				x=read(),y=read();
				if(x!=1){
					for(int i=Head[x];i;i=Next[i]){
						int v=Ver[i];
						a[v]+=y;
					}
					a[x]+=y;
				}
				if(x==1){
					a[1]+=y;
					lazy+=y;
				}
				
			}
			else{
				x=read();
				if(vis[x]){
					printf("%d\n",lazy+a[x]);
				}
				else{
					printf("%d\n",a[x]);
				}
			}
		}
}
void case_4(){
	int x,y,op;
	while(Q--){
		op=read();
		if(op==1){
			x=read(),y=read();
			if(be[x]!=0){
				a[be[x]]+=y;
				a[x]+=y;	
			}
			if(root[x]){
				tag[x]+=y;
				a[x]+=y;
			}
		}
		else{
			x=read();
			if(root[x]){
				printf("%d\n",a[x]);
			}
			if(be[x]!=0){
				printf("%d\n",a[x]+tag[be[x]]);
			}
		}
	}
}
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	n=read(),m=read(),Q=read();
	int x,y;
	if(n<=3000&&m<=3000&&Q<=3000){
		for(int i=1;i<=m;++i){
			x=read(),y=read();
			add(x,y);add(y,x);
		}
		int op;
		while(Q--){
			op=read();
			if(op==1){
				x=read(),y=read();
				change(x,y);
			}
			else{
				x=read();
				printf("%d\n",a[x]);
			}
		}
		return 0;
	}
	for(int i=1;i<=m;++i){
		x=read(),y=read();
		add(x,y);add(y,x);
	}
	bool fg_stb_3=true;
	for(int i=2;i<=n;++i){
		if(In[i]>=10){
			fg_stb_3=false;
		}
	}
	if(fg_stb_3){
		case_3();
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(In[i]>1){
			root[i]=1;
		}
	}
	for(int i=1;i<=n;++i){
		if(In[i]==1){
			for(int j=Head[i];j;j=Next[j]){
				int y=Ver[j];
				be[i]=y;
			}
		}
	}
	case_4();
	return 0;
}


