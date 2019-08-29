#include<bits/stdc++.h>
using namespace std;

template<typename T>void read(T &x){
    x=0;char c=getchar();
    int f=1;
    for(;!isdigit(c);c=getchar()) if (c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-48;
    x=x*f;
}

struct node{
	int x,y,t;
}a[100010];

bool cmp(node x,node y){
	return x.t<y.t;
}

int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T;
	read(T);
	while (T--){
		int n;
		read(n);
		for (int i=1;i<=n;++i){
			read(a[i].t);
			read(a[i].x);
			read(a[i].y);
		}
		sort(a+1,a+n+1,cmp);
		bool f=true;
		for (int i=1;i<=n;++i){
			int dis=abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y);
			int tim=a[i].t-a[i-1].t;
			if (dis>tim||(dis-tim)&1){
				f=false;
				break;
			}
		}
		if (f)	printf("YES\n");
			else printf("NO\n");
	}
	return 0;
}


