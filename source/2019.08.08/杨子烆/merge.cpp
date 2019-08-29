#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
vector<int> a[6001];
int ans[6001];
int get(int x){
	if(x==a[x].front())return x;
	else{
		a[x].front()=get(a[x].front());
		return a[x].front();
	}
}
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,q,y,x,b,s;
	read(n);read(q);
	for(int i=1;i<=n;i++){
		a[i].push_back(i);
	}
	for(int i=1;i<=q;i++){
		read(b);
		read(x);
		read(y);
		if(b==1){
			x=get(x);
			y=get(y);
			if(x!=y){
			
				if(x>y){
					s=x;
					x=y;
					y=s;
				}
				for(int i=0;i<a[y].size();i++){
					a[x].push_back(a[y][i]);	
				}
				a[y].clear();
				a[y].front()=x;
		}
	}
		if(b==2){
			x=get(x);
			for(int i=0;i<a[x].size();i++){
				ans[a[x][i]]+=y;	
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
/*
3 4
2 1 1
1 2 1
1 2 3
2 1 3
*/
