#include<bits/stdc++.h>
using namespace std;
bool A[130][130];
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
bool f[20000];
long long ans=1;
inline int read(){
	register int x=0;register int w=1;
	register char c;
	while(!isdigit(c=getchar()))if(c=='-')w=-1;
	while(isdigit(c)){
	x=(x<<1)+(x<<3)+(c&15);
	c=getchar();
	}
	return x*w;
}
void pre(){
	A[0][0]=1;A[0][1]=1;A[1][0]=1;A[1][1]=0;
	int cnt=1;
	while(cnt<7){
		int d=(1<<cnt);
		for(int x=d;x<(d<<1);x++){
			for(int y=0;y<d;y++){
				A[x][y]=A[x-d][y];
			}
		}
		for(int x=0;x<d;x++){
			for(int y=d;y<(d<<1);y++){
				A[x][y]=A[x][y-d];
			}
		}
		for(int x=d;x<(d<<1);x++){
			for(int y=d;y<(d<<1);y++){
				A[x][y]=!A[x-d][y-d];
			}
		}
		cnt++;
	}
}
void bfs(int s,int t){
	queue< pair<int,int> > q;
	q.push(make_pair(t,s));
	f[s*10+t]=1;
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;
	//	cout<<x<<" "<<y<<endl;
		q.pop();
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
	//	   cout<<" "<<xx<<" "<<yy<<endl;
			   
			if(A[xx][yy]!=A[s][t])continue;
			if(xx<0||yy<0)continue;
			if(xx==127||yy==127){ans=-1;return;}
			if(f[xx*10+yy])continue;
			
			ans++;
			f[xx*10+yy]=1;
			q.push(make_pair(yy,xx));
//			cout<<xx<<" "<<yy<<endl;
		}
	}
}
int main(){
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	pre();
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<endl;
	}
	int a=read(),b=read();
	if(a>127||b>127){cout<<"infinity"<<endl;exit(0);}
    bfs(a,b);
    if(ans<0)cout<<"infinity"<<endl;
    else cout<<ans<<endl;
	return 0;
}
