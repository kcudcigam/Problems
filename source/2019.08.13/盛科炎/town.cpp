#include<bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;
#define ll long long
const int MOD=1000000007;
int n,m,len;
ll ans;
vector<int>Q;

void deal(int t){
	int len=0;
	for(int i=1;i<=n;i++){
		if(Q[i].size()==1){
			search(Q[i]);
		}
	}
}
void search(int start){
	int t_size=Q[start].size();
	for(int i=1;i<=t_size;i++){
		int ne=Q[i].front();
		Q[i].clear();
		len++;
		search(ne);
	}
}

int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	scanf("%d",&n);
	int t1,t2;
	for(int i=1;i<n;i++){
		len=0;
		scanf("%d %d",&t1,&t2);
		Q[t1].push_back(t2);
		Q[t2].push_back(t1);
		deal();
		printf("%d\n",len);
		
	}
	return 0;
}


