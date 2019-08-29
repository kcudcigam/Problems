#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
vector<int>way[333333];
int a[333333],deg[333333],inc[333333];
bool cen[333333];
int main(){
	#ifndef lpcak
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	#endif
	int n,m,q,cnt=0,c1=0;
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	F(i,1,m){
		int x,y;cin>>x>>y;
		way[x].push_back(y);
		way[y].push_back(x);
		deg[x]++,deg[y]++;
		if((x^1)&&(deg[x]>10))cnt++;
		if((y^1)&&(deg[y]>10))cnt++;
	}
	if((n<3333)&&(m<3333)&&(q<3333)){
		F(i,1,q){
			int op,x,y;cin>>op>>x;
			if(!op){
				cout<<a[x]<<"\n";
				continue;
			}
			cin>>y;a[x]+=y;
			F(j,0,way[x].size()-1){
				a[way[x][j]]+=y;
			}
		}
		return 0;
	}
	if(!cnt){
		F(i,1,n){
			F(j,0,way[i].size()-1)
				if(way[i][j]==1)cen[i]=1;
		}
		F(i,1,q){
			int op,x,y;cin>>op>>x;
			if(!op){
				if(cen[x])
					cout<<c1+a[x]<<"\n";
				else cout<<a[x]<<"\n";
				continue;
			}
			cin>>y;a[x]+=y;
			if(x==1)c1+=y;
			else{
				F(j,0,way[x].size()-1)
					a[way[x][j]]+=y;
			}
		}
		return 0;
	}
	F(i,1,n)if(deg[i]>1)cen[i]=1;
	F(i,1,q){
		int op,x,y,jb=0;cin>>op>>x;		
		if(!op){
			if(cen[x])cout<<a[x]<<"\n";
			else{
				F(j,0,way[x].size()-1){
					if(!way[x].size())
						break;
					int v=way[x][j];
					jb+=cen[v]*inc[v];
				}
				cout<<a[x]+jb<<"\n";
			}
			continue;
		}
		cin>>y;a[x]+=y;inc[x]+=y;
		if(!cen[x]){
			F(j,0,way[x].size()-1){
				if(!way[x].size())break;
				a[way[x][j]]+=y;
			}
		}
	}
	return 0;
}
