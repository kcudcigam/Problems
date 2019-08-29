#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q;
int cz,x,y,tail,head;
int map[6666][6666],p[6666],rd[6666],bo[6666];
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=q;++i){
		read(cz);
		read(x);
		read(y);
		if(cz==1){
			map[x][y]=1;
			map[y][x]=1;
		}
		if(cz==2){
			for(int j=1;j<=n;++j){
				bo[j]=0;
			}
			rd[x]+=y;
			tail=1;
			head=0;
			p[tail]=x;
			bo[x]=1;
			while(tail>head){
				head++;
				for(int j=1;j<=n;++j){
					if(map[p[head]][j]==1&&bo[j]==0){
						tail++;
						bo[j]=1;
						p[tail]=j;
						rd[p[tail]]+=y;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		printf("%d ",rd[i]);
	}
	return 0;
} 
