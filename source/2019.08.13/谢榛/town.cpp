#include<bits/stdc++.h>
using namespace std;

int n,x,y,Max,t1,t2;
vector<int> ne[30010];
int ha[30010];

void walk(int dep,int s){
	if (s>Max) Max=s;
	ha[dep]=1;
	for (int i=0;i<ne[dep].size();i++)
	if (ha[ne[dep][i]]==0) walk(ne[dep][i],s+1);
	ha[dep]=0;
}

int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	cin>>n;
	for (int i=1;i<n;i++){
		cin>>x>>y;
		Max=0;walk(x,0);t1=Max;
		Max=0;walk(y,0);t2=Max;
		cout<<t1+t2+1<<endl;
		ne[x].push_back(y);
		ne[y].push_back(x);  
	}
	return 0;
}

