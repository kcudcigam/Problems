#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int> q1, q2, q3;

int main(){
	freopen("debate.in", "r", stdin);
	freopen("debate.out", "w", stdout); 
	scanf("%d", &n);
	int cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++){
		char opt[5]; int val;
		scanf("%s%d", opt, &val);
		if (opt[0] == '1' && opt[1] == '1'){
			ans += val;
			cnt++;
		}
		if (opt[0] == '0' && opt[1] == '0') q3.push(val);
		if (opt[0] == '1' && opt[1] == '0') q2.push(val);
		if (opt[0] == '0' && opt[1] == '1') q1.push(val);
	}
	while (q1.size() && q2.size()){
		ans += q1.top() + q2.top();
		q1.pop(); q2.pop();
	}
	if (!q1.size()) swap(q1, q2);
	for (int i = 1; i <= cnt && (q1.size() || q3.size()); i++){
		int top1 = 0, top2 = 0;
		if (q1.size()) top1 = q1.top();
		if (q3.size()) top2 = q3.top();
		if (top1 > top2){
			ans += top1;
			q1.pop();
		} else {
			ans += top2;
			q3.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}
