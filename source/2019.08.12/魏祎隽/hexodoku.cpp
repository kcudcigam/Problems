#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int k,n,_,a[32],us[32][32];
set<int> v[32];
void lnk(vector<int> a){
	for(int i:a)for(int j:a)if(i!=j)
		v[i].insert(j);
}
void dfs(int p){
	if(p==32){
		if(!--n){
			puts("Found");
			for(int i=1;i<32;i++)printf("%d%c",a[i]," \n"[i==31]);
			exit(0);
		}
		return ;
	}
	if(a[p]){dfs(p+1);return;}
	for(int i=1;i<=k;i++)if(!us[p][i]){
		for(int j:v[p])us[j][i]++;
		a[p]=i;dfs(p+1);a[p]=0;
		for(int j:v[p])us[j][i]--;
	}
}
int main(){
	freopen("hexodoku.in","r",stdin),freopen("hexodoku.out","w",stdout);
	scanf("%d%d",&k,&n);
	if(k<7){puts("No way");exit(0);}
	for(int i=1;i<32;i++)
		scanf("%d",a+i);
	lnk({1,2,4,5,6,10,11});
	lnk({3,4,8,9,10,14,15});
	lnk({3,4,5,6,7});
	lnk({8,9,10,11,12,13});
	lnk({14,15,16,17,18});
	lnk({19,20,21,22,23,24});
	lnk({25,26,27,28,29});
	lnk({6,7,11,12,13,17,18});
	lnk({10,11,15,16,17,21,22});
	lnk({14,15,19,20,21,25,26});
	lnk({17,18,22,23,24,28,29});
	lnk({21,22,26,27,28,30,31});
	lnk({2,6,12,18,24});
	lnk({1,5,11,17,23,29});
	lnk({4,10,16,22,28});
	lnk({3,9,15,21,27,31});
	lnk({8,14,20,26,30});
	lnk({1,4,9,14,19});
	lnk({2,5,10,15,20,25});
	lnk({6,11,16,21,26});
	lnk({7,12,17,22,27,30});
	lnk({13,18,23,28,31});
	for(int i=1;i<32;i++)
		for(int j:v[i])us[j][a[i]]++;
	dfs(1);
	puts("No way");
	return 0;
}
