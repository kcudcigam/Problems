#include<bits/stdc++.h>
using namespace std;
int n,ans,tot,ta,tb;//tot,ta,tb��ǰѡ������� ans��Ծֵ
priority_queue<int> ab,oa,ob,oo;
int main()
{
	freopen("debate.in","r",stdin);
	freopen("debate.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,w;
		scanf("%d %d",&x,&w);
		if(x==11) ab.push(w);
		if(x==10) oa.push(w);
		if(x==1) ob.push(w);
		if(x==0) oo.push(w);
	}//��ab,oa,ob,oo�Ķ��˰���Ծ�ȷŽ��ĸ������
	
	while((!oa.empty())&&(!ob.empty()))
	{
		ans+=oa.top();
		ans+=ob.top();
		oa.pop();
		ob.pop();
		tot+=2;
		ta++;
		tb++;
	}//�Ȱ�oa,ob�����˵�����С����ѡ��
	
	//����oa,ob��ֻ��һ��oxʣ����
	while(!ab.empty())
	{
		ans+=ab.top();
		ab.pop();
		tot++;
		ta++;
		tb++;//ab����Ҫȫ��ѡ
		
		//����ѡ�����oo��ox����
		if( (!oa.empty()||!ob.empty()) && (oo.empty()) )
		{
			int Temp=0;
			oo.push(Temp);
		}//��������ֻ��ox����
		
		if(!oo.empty())
		{
			if((!oa.empty())&&oa.top()>oo.top())
			{
				if(ta+1>=(tot+1)/2)
				{
					ans+=oa.top();
					oa.pop();
					tot++;
					ta++;
				}//����һ���˿���ͬʱ֧��AB,����֧��A��B����������������һ������
			}//���oa����Ȩ�ر�oo��,�һ����Է���,��ѡ��oa
			else
			{
				if((!ob.empty())&&ob.top()>oo.top())
				{
					if(tb+1>=(tot+1)/2)
					{
						ans+=ob.top();
						ob.pop();
						tot++;
						tb++;
					}
				}//obͬ��
				else
				{
					ans+=oo.top();
					oo.pop();
				}//oa,ob��û�˻򶼲���������,��ѡ��oo����
			}
		}
	}//��ѡ��ab����,ͬʱ��������Щʣ�µ���
	
	printf("%d\n",ans);
	
	return 0;
}


