#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char ch=getchar();
	while(ch<'0' || ch>'9')ch=getchar();
	int ans=0;
	while(ch>='0' && ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans;
}
const int maxn=100010;
int n;
struct node{
	int t,x,y;
	void reads(){
		t=read(),x=read(),y=read();
	}
}a[maxn];
inline int dis(int i,int j){
	return abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y);
}
int main()
{
	freopen("charlotte.in ","r",stdin );
	freopen("charlotte.out","w",stdout);
	int T=read();
	while(T--){
		//读入 
		n=read();
		for(int i=1;i<=n;++i)a[i].reads();
		//处理
		int flag=true,d,t;
		for(int i=0;i<n && flag;++i){
			d=dis(i,i+1),t=a[i+1].t-a[i].t;
			//两种情况下走不到:
			//1.曼哈顿距离大于时间
			//2.时间减去曼哈顿距离后的剩余时间不是偶数
			if(d>t || (t-d)%2)flag=false;
		}
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
