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
	//���� 
	cin>>n;
	for(int i=1;i<=n;++i){
		string s;int val;
		cin>>s>>val;
		if(s=="00")q[0].push(val);
		else if(s=="10")q[1].push(val);
		else if(s=="01")q[2].push(val);
		//����������ⶼ֧�֣���ôһ��Ҫѡ 
		else size3++,ans+=val;
	}
	//����
	//�������ⶼ֧�ֵ��Ѿ�ѡ����
	//ֻ֧��һ�������,����֤��,��ȫ�ܴ�����ѡ,����
	while(!q[1].empty() && !q[2].empty()){
		ans+=q[1].top()+q[2].top();
		q[1].pop(),q[2].pop(); 
	}
	//��ѧ�Ƶ�:����ѡ�������
	//���a[0]��k1��,a[1]/a[2]��k2��
	//ֻҪ��֤size3>=k1+k2����
	for(int k=0;k<3;++k)
		while(!q[k].empty()){
			nq.push(q[k].top());
			q[k].pop();
		}
	int cnt=min(size3,(int)nq.size());
	for(int i=1;i<=cnt;++i){
		ans+=nq.top(),nq.pop();
	}
	//����𰸲����� 
	cout<<ans<<endl;
	return 0;
}
