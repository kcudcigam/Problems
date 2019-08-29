#include<bits/stdc++.h>
#define fir(i,a,b) for(int i=a;i<=b;i++)
#define N 7
#define L 2000
using namespace std;
int a[L][L],w[L][L];
pair<int,int>fa[L][L];
inline pair<int,int> Find(pair<int,int>p){
	int x=p.first,y=p.second;
	if(fa[x][y]!=p)fa[x][y]=Find(fa[x][y]);
	return fa[x][y];
}
int main(){
    freopen("area.in","r",stdin);
    freopen("area.out","w",stdout);
	int qk1,qk2;
	cin>>qk1>>qk2;
	int l=2;
	a[1][1]=1,a[1][2]=1,a[2][1]=1,a[2][2]=-1;
    fir(i,1,N){
    	fir(j,1,l)
    	    fir(k,1,l)
    	    	a[l+j][k]=a[j][k],a[j][l+k]=a[j][k],a[l+j][l+k]=-a[j][k];
    	l*=2;
	}
	fir(i,1,l)
	    fir(j,1,l)
	        fa[i][j]=make_pair(i,j);
	fir(i,1,l)
	    fir(j,1,l)
	        w[i][j]=1;
	fir(i,2,l)
	    fir(j,2,l){
	    	if(a[i][j]==a[i-1][j]&&Find(make_pair(i,j))!=Find(make_pair(i-1,j))){
	    		pair<int,int>p=Find(make_pair(i,j));
	    		pair<int,int>pp=Find(make_pair(i-1,j));
	    		int x=p.first,y=p.second,xx=pp.first,yy=pp.second;
	    		fa[x][y]=pp;
	    		w[xx][yy]+=w[x][y];
			}
			if(a[i][j]==a[i][j-1]&&Find(make_pair(i,j))!=Find(make_pair(i,j-1))){
	    		pair<int,int>p=Find(make_pair(i,j));
	    		pair<int,int>pp=Find(make_pair(i,j-1));
	    		int x=p.first,y=p.second,xx=pp.first,yy=pp.second;
	    		fa[x][y]=pp;
	    		w[xx][yy]+=w[x][y];
			}
		}
	qk1+=1,qk2+=1;
	if(qk1>100||qk2>100||a[qk1][qk2]==1)puts("infinity");
	else{
		pair<int,int>p=Find(make_pair(qk1,qk2));
		int x=p.first,y=p.second;
		cout<<w[x][y]<<endl;
	}
	return 0;
}
