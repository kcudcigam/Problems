#include<bits/stdc++.h>
using namespace std;
const int N=40;
int h[N][N],a[N],b[N],n,k,ans=0;
const int f[32][6]={
{0,0,0,0,0,0},
{1,9,19,22,0,0},
{1,10,20,22,0,0},
{2,8,17,23,0,0},
{2,9,18,22,23,0},
{2,10,19,22,0,0},
{2,11,20,22,24,0},
{2,12,21,24,0,0},
{3,8,16,23,0,0},
{3,9,17,23,0,0},
{3,10,18,22,23,25},
{3,11,19,22,24,25},
{3,12,20,24,0,0},
{3,13,21,24,0,0},
{4,9,16,23,26,0},
{4,10,17,23,25,26},
{4,11,18,25,0,0},
{4,12,19,24,25,27},
{4,13,20,24,27,0},
{5,9,15,26,0,0},
{5,10,16,26,0,0},
{5,11,17,25,26,28},
{5,12,18,25,27,28},
{5,13,19,27,0,0},
{5,14,20,27,0,0},
{6,10,15,26,0,0},
{6,11,16,26,28,0},
{6,12,17,28,0,0},
{6,13,18,27,28,0},
{6,14,19,27,0,0},
{7,12,16,28,0,0},
{7,13,17,28,0,0}};
void work(int dep){
	if(dep>31){
		ans++;
		if(ans==k){
			cout<<"Found\n";
			for(int i=1;i<=31;i++)
				cout<<b[i]<<" ";
			cout<<"\n";
			exit(0);
		}
		return;
	}
	int l=1,r=n;
	if(a[dep]) l=r=a[dep];
	for(int x=l;x<=r;x++){
		int fl=0;
		for(int i=0;i<6 && f[dep][i];i++)
			if(h[f[dep][i]][x]){ fl=1; break;}
		if(fl) continue;
		for(int i=0;i<6 && f[dep][i];i++)
			h[f[dep][i]][x]=1;
		b[dep]=x;
		work(dep+1);
		for(int i=0;i<6 && f[dep][i];i++)
			h[f[dep][i]][x]=0;
	}
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=31;i++)
		cin>>a[i];
	work(1);
	cout<<"No way\n";
	return 0;
}
