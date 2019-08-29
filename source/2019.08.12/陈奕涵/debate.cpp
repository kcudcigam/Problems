#include<bits/stdc++.h>
using namespace std;
int n,size3;
long long ans;
priority_queue<int>q[3];
priority_queue<int>nq;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	//读入 
	cin>>n;
	for(int i=1;i<=n;++i){
		string s;int val;
		cin>>s>>val;
		if(s=="00")q[0].push(val);
		else if(s=="10")q[1].push(val);
		else if(s=="01")q[2].push(val);
		//如果两个议题都支持，那么一定要选 
		else size3++,ans+=val;
	}
	//处理
	//两个议题都支持的已经选完了
	//只支持一个议题的,可以证明,完全能搭配着选,不亏
	while(!q[1].empty() && !q[2].empty()){
		ans+=q[1].top()+q[2].top();
		q[1].pop(),q[2].pop(); 
	}
	//数学推导:从已选情况推算
	//设从a[0]拿k1个,a[1]/a[2]拿k2个
	//只要保证size3>=k1+k2即可
	for(int k=0;k<3;++k)
		while(!q[k].empty()){
			nq.push(q[k].top());
			q[k].pop();
		}
	int cnt=min(size3,(int)nq.size());
	for(int i=1;i<=cnt;++i){
		ans+=nq.top(),nq.pop();
	}
	//输出答案并结束 
	cout<<ans<<endl;
	return 0;
}
