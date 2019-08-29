#include<bits/stdc++.h>
using namespace std;
struct info{int x,y,num;};
int x,y,cnt=0;
long long ans=0;
int mm[40];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
map<pair<int,int>,int> ma; 
queue<info> q;
int logg(int x){
	for(int i=0;i<=31;i++){
		if(mm[i]>=x)return mm[i-1];
	}
}
void dg(int x,int y){
	if(x<=2&&y<=2){
		if(x==2&&y==2)cnt++;
		return ;
	}
	int maxn=max(x,y);
	int lg=logg(maxn);
	int l=lg+1,r=lg*2;
	if((x>=l&&x<=r)&&(y>=l&&y<=r))cnt++;
	if(x>lg)x-=lg;
	if(y>lg)y-=lg;
	dg(x,y);
}
int cal(int x,int y){
	cnt=0;dg(x,y);
	if(cnt%2==1)return -1;
	return 1;
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	mm[0]=1;
	for(int i=1;i<=31;i++)mm[i]=mm[i-1]*2;
	int x,y;cin>>x>>y;x++,y++;
	int numm=cal(x,y);
	q.push((info){x,y,numm});
	ma.insert(make_pair(make_pair(x,y),1));ans=1;
	while(!q.empty()){
		info p=q.front();q.pop();
		if(p.x==1||p.y==1){
			cout<<"infinity"<<endl;
			return 0;
		}
		for(int i=0;i<4;i++){
			int dx=p.x+dir[i][0];
			int dy=p.y+dir[i][1];
			if(dx>=1&&dy>=1&&ma.count(make_pair(dx,dy))==0){
				int num=cal(dx,dy);
				if(num==p.num){
					q.push((info){dx,dy,num});
					ma.insert(make_pair(make_pair(dx,dy),1));
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
//100000000 1000000000

