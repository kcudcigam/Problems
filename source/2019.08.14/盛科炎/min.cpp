#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,A,B,C,D,ans;
int a[10005];
int f(int x){
	int temp=A*x*x*x+B*x*x+C*x+D;
	return temp;
}
void deal1(){
	if(C<=0){
		int minn=0x3f3f3f;//大于0的最小值 
		int maxx=0;//小于0的最小值 
		bool vis=false; // false= - true= +
		for(int i=1;i<=n;i++){
			if(a[i]<0 && vis) {
				ans+=f(minn);
				ans+=f(a[i]);
				minn=0x3f3f3f;
				vis=false;
			}
			else if(a[i]<0 && !vis){
				ans+=f(a[i]);
			}
			else if(a[i]>0){
				minn=min(minn,a[i]);
				vis=true;
			}
		}
		printf("%d\n",ans);
		return;
	}
	else if(C>=0){
		int minn=-0x3f3f3f;
		int maxx=0;
		bool vis=false; // false= - true= +
		for(int i=1;i<=n;i++){
			if(a[i]>=0 && vis) {
				ans+=f(minn);
				ans+=f(a[i]);
				//printf("%d\n",ans);
				minn=-0x3f3f3f;
				vis=false;
			}
			else if(a[i]>=0 && !vis){
				ans+=f(a[i]);
				//printf("%d\n",ans);
			}
			else if(a[i]<0){
				minn=max(minn,a[i]);
				vis=true;
			}
			/*
			if(a[i]>0 && !vis){
				ans+=f(minn);
				vis=true;
				minn=-0x3f3f3f3f;
			}
			if(a[i]>=0 && vis){
				maxx=max(maxx,a[i]);
			}
			if(a[i]<0 && vis){
				ans+=f(maxx);
				vis=false;
				maxx=0;
			}
			if(a[i]<0 && !vis){
				minn=max(minn,a[i]);
			}
			*/		
		}
		//printf("%d\n",ans);
		//return;
	}
}

int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	scanf("%d %d %d %d %d",&n,&A,&B,&C,&D);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(A==0 && B==0){
		deal1();
	}
	
	
	return 0;
}

