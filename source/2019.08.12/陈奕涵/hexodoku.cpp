#include<bits/stdc++.h>
using namespace std;
//int n,k,cnt,a[32],p[32];
//vector<int>c[32];
//int vis[32][32];
//bool tag(int x,int val,int f){
//	int flag=true;
//	for(int i=0;i<c[x].size();++i){
//		int to=c[x][i];
//		if(p[to]==val)flag=false;
//		vis[to][val]+=f;
//	}
//	return flag;
//}
//bool check(){
//	for(int i=1;i<=31;++i)
//		if(p[i] && p[i]!=a[i])return false;
//	return true;
//}
//void dfs(int x){
//	printf("x=%d a[%d]=%d\n",x,x-1,a[x-1]);
//	//getchar();
//	if(x==32){
//		if(check()){
//			cnt++;
//			if(cnt==n){
//				for(int i=1;i<=31;++i)cout<<a[i]<<' ';
//				cout<<endl;
//			}
//		}
//		return;
//	}
//	if(p[x])dfs(x+1);
//	for(int i=1;i<=k && cnt<n;++i){
//		if(!vis[x][i]){
//			if(tag(x,i,1)){
//				a[x]=i;
//				dfs(x+1);
//			}
//			tag(x,i,-1);
//		}
//	}
//}
int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
//	cin>>k>>n;
//	for(int i=1;i<=31;++i){
//		cin>>a[i];
//		p[i]=a[i];
//	}
//	//´ò±í
//	//
//	c[1].push_back(4);c[1].push_back(5);c[1].push_back(9);
//	c[1].push_back(11);c[1].push_back(14);c[1].push_back(17);
//	c[1].push_back(19);c[1].push_back(23);c[1].push_back(29);
//	c[1].push_back(2);c[1].push_back(6);
//	c[1].push_back(10);c[1].push_back(11);
//	//
//	c[2].push_back(5);
//	c[2].push_back(4);c[2].push_back(6);
//	c[2].push_back(10);c[2].push_back(11);
//	//
//	for(int i=4;i<=7;++i)c[3].push_back(i);
//	for(int i=9;i<=27;i+=6)c[3].push_back(i);
//	c[3].push_back(8);c[3].push_back(10);
//	c[3].push_back(14);c[3].push_back(15);
//	c[3].push_back(31);
//	//
//	for(int i=5;i<=7;++i)c[4].push_back(i);
//	for(int i=9;i<=19;i+=5)c[4].push_back(i);
//	c[4].push_back(8);c[4].push_back(10);c[4].push_back(15);
//	//
//	c[5].push_back(6);c[5].push_back(7);
//	c[5].push_back(10);c[5].push_back(11);
//	c[5].push_back(17);c[5].push_back(23);c[5].push_back(29);
//	//
//	c[6].push_back(7);
//	for(int i=11;i<=13;++i)c[6].push_back(i);
//	for(int i=17;i<=18;++i)c[6].push_back(i);
//	//
//	for(int i=9;i<=10;++i)c[7].push_back(i);
//	for(int i=14;i<=15;++i)c[7].push_back(i);
//	//
//	c[9].push_back(10);c[9].push_back(14);c[9].push_back(15);
//	c[9].push_back(19);
//	c[9].push_back(21);c[9].push_back(27);c[9].push_back(31);
//	//
//	c[10].push_back(16);
//	//
//	c[11].push_back(16);c[11].push_back(17);
//	c[11].push_back(21);c[11].push_back(23);
//	c[11].push_back(26);c[11].push_back(29);
//	//
//	c[12].push_back(13);c[12].push_back(17);c[12].push_back(18);
//	//
//	for(int i=15;i<=20;++i)c[14].push_back(i);
//	//
//	for(int i=16;i<=18;++i)c[15].push_back(i);
//	c[15].push_back(20);c[15].push_back(21);
//	c[15].push_back(27);c[15].push_back(31);
//	//
//	for(int i=17;i<=18;++i)c[16].push_back(i);
//	c[16].push_back(21);c[16].push_back(26);c[16].push_back(22);
//	//
//	c[17].push_back(18);c[17].push_back(23);c[17].push_back(29);
//	//
//	c[20].push_back(21);c[20].push_back(25);c[20].push_back(26);
//	//
//	c[21].push_back(26);c[21].push_back(27);c[21].push_back(31);
//	//
//	c[23].push_back(24);c[23].push_back(28);
//	c[23].push_back(29);c[23].push_back(31);
//	//
//	for(int i=26;i<=29;++i)c[25].push_back(i);
//	//
//	for(int i=27;i<=29;++i)c[26].push_back(i);
//	//
//	for(int i=28;i<=31;++i)c[27].push_back(i);
//	//
//	c[28].push_back(29);c[28].push_back(31);
//	
//	//ËÑË÷
//	dfs(1);
//	if(cnt<n)
	cout<<"No way"<<endl;
	return 0;
}
