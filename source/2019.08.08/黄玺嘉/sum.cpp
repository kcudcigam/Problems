#include<bits/stdc++.h>
using namespace std;
int n, a[10010],mini,maxi,jiyi;
long long s[10010],mins = 1000000000,maxs = -1000000000,ans = 0,sum1,sum2;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	
	scanf("%d", &n);
	s[0] = 0;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		s[i] = s[i - 1] + a[i];
		if(s[i] < mins){
			mins = s[i];
			mini = i;
		}
	}
	for(int i = mini; i <= n; ++i){
		if(s[i] > maxs){
			maxs = s[i];
			maxi = i;
		}
	}
	ans += maxs - mins;
	
	jiyi = mini;
	
	mins = 1000000000;
	maxs = -1000000000;
	for(int i = maxi; i <= n; ++i){
		if(s[i] < mins){
			mins = s[i];
			mini = i;
		}
	}
	for(int i = mini; i <= n; ++i)
		maxs = max(maxs, s[i]);
	sum1 = maxs - mins;
	mins = 1000000000;
	maxs = -1000000000;
	for(int i = jiyi; i >= 0; --i){
		if(s[i] > maxs){
			maxs = s[i];
			maxi = i;
		}
	}
	for(int i = maxi; i >= 0; --i){
		mins = min(mins, s[i]);
	}
	sum2 = maxs - mins;
	ans += max(sum1, sum2);
	
	printf("%d", ans);
	return 0;
}
