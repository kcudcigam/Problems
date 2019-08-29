#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=100005;
int dir[5][5]={(-1,0),(1,0),(0,1),(0,-1)};
int T,n,now_x,now_y;
int l_t;
bool ans=true,vis=true;
struct Node{
	int t,x,y;
}a[MAXN];

void judge(){
	if(l_t%2==1)
	{
		ans=false;
		vis=false;
	}
	else {
		ans=true;
	}
}

void deal(int x){
	if(a[x].t< (abs(a[x].x-now_x) + abs(a[x].y-now_y)) ){
		ans=false;
		return;
	}
	else {
	l_t=(a[x].t-( abs(a[x].x-now_x) + abs(a[x].y-now_y) ) );
	//now_x=a[x].x;
	//now_y=a[x].y;	
	judge();
	}
	
	
}

int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=true;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i].t,&a[i].x,&a[i].y);
		}
		now_x=0;
		now_y=0;
		for(int i=1;i<=n;i++){
			deal(i);
			
		}
		if(ans && vis)
		printf("Yes\n");
		else 
		printf("No\n");
		
	}
	return 0;
}


