#include<bits/stdc++.h>
using namespace std;
int a[40],n,k,t=0;
bool ok(int dep)
{
	int i=dep;
	while(1)
	{
		if(i==19||i==8||i==3||i==4||i==1||i==2||i==7)break;
		if(i==5||i==6||i==30||i==31)i-=4;
		else i-=6;
		if(a[i]==a[dep])return 0;
	}
	i=dep;
	while(1)
	{
		if(i==3||i==1||i==2||i==6||i==7||i==13||i==24)break;
		if(i==4||i==5||i==30||i==31)i-=3;
		else i-=5;
		if(a[i]==a[dep])return 0;
	}
	i=dep;
	while(1)
	{
		if(i==1||i==3||i==8||i==14||i==19||i==25||i==30)break;
		i--;
		if(a[i]==a[dep])return 0;
	}
	i=dep;
	while(1)
	{
		if(i==2||i==7||i==13||i==18||i==24||i==29||i==31)break;
		i++;
		if(a[i]==a[dep])return 0;
	}
	i=dep;
	while(1)
	{
		if(i==8||i==19||i==25||i==26||i==30||i==31||i==29)break;
		if(i==1||i==2||i==27||i==28)i+=3;
		else i+=5;
		if(a[i]==a[dep])return 0;
	}
	i=dep;
	while(1)
	{
		if(i==25||i==30||i==31||i==28||i==29||i==24||i==13)break;
		if(i==1||i==2||i==26||i==27)i+=4;
		else i+=6;
		if(a[i]==a[dep])return 0;
	}
	if(dep==1&&(a[dep]==a[10]||a[dep]==a[6]))return 0;
	if(dep==2&&(a[dep]==a[4]||a[dep]==a[11]))return 0;
	if(dep==3&&(a[dep]==a[10]||a[dep]==a[14]))return 0;
	if(dep==4&&(a[dep]==a[8]||a[dep]==a[15]||a[dep]==a[2]||a[dep]==a[11]))return 0;
	if(dep==6&&(a[dep]==a[17]||a[dep]==a[13]||a[dep]==a[1]||a[dep]==a[10]))return 0;
	if(dep==7&&(a[dep]==a[11]||a[dep]==a[18]))return 0;
	if(dep==8&&(a[dep]==a[4]||a[dep]==a[15]))return 0;
	if(dep==10&&(a[dep]==a[1]||a[dep]==a[6]||a[dep]==a[3]||a[dep]==a[14]||a[dep]==a[21]||a[dep]==a[17]))return 0;
	if(dep==11&&(a[dep]==a[4]||a[dep]==a[2]||a[dep]==a[7]||a[dep]==a[18]||a[dep]==a[15]||a[dep]==a[22]))return 0;
	if(dep==13&&(a[dep]==a[6]||a[dep]==a[17]))return 0;
	if(dep==14&&(a[dep]==a[10]||a[dep]==a[3]||a[dep]==a[25]||a[dep]==a[21]))return 0;
	if(dep==15&&(a[dep]==a[8]||a[dep]==a[4]||a[dep]==a[19]||a[dep]==a[26]||a[dep]==a[11]||a[dep]==a[22]))return 0;
	if(dep==17&&(a[dep]==a[6]||a[dep]==a[13]||a[dep]==a[28]||a[dep]==a[24]||a[dep]==a[10]||a[dep]==a[21]))return 0;
	if(dep==18&&(a[dep]==a[11]||a[dep]==a[7]||a[dep]==a[22]||a[dep]==a[29]))return 0;
	if(dep==19&&(a[dep]==a[15]||a[dep]==a[26]))return 0;
	if(dep==21&&(a[dep]==a[10]||a[dep]==a[17]||a[dep]==a[14]||a[dep]==a[25]||a[dep]==a[30]||a[dep]==a[28]))return 0;
	if(dep==22&&(a[dep]==a[15]||a[dep]==a[11]||a[dep]==a[18]||a[dep]==a[29]||a[dep]==a[26]||a[dep]==a[31]))return 0;
	if(dep==24&&(a[dep]==a[17]||a[dep]==a[28]))return 0;
	if(dep==25&&(a[dep]==a[14]||a[dep]==a[21]))return 0;
	if(dep==26&&(a[dep]==a[19]||a[dep]==a[15]||a[dep]==a[22]||a[dep]==a[31]))return 0;
	if(dep==28&&(a[dep]==a[17]||a[dep]==a[24]||a[dep]==a[21]||a[dep]==a[30]))return 0;
	if(dep==29&&(a[dep]==a[22]||a[dep]==a[18]))return 0;
	if(dep==30&&(a[dep]==a[21]||a[dep]==a[28]))return 0;
	if(dep==31&&(a[dep]==a[26]||a[dep]==a[22]))return 0;
	return 1;
}
void dfs(int dep)
{
	if(dep>31)
	{
		t++;
		if(t==k){
			cout<<"Found"<<endl;
			for(int i=1;i<=30;i++)cout<<a[i]<<' ';
			cout<<a[31]<<endl;
			exit(0);
		}
		return;
	}
	if(a[dep]!=0)
	{
		dfs(dep+1);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		a[dep]=i;
		if(ok(dep))dfs(dep+1);
		a[dep]=0;
	}
	return;
}
int main(){
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=31;i++)cin>>a[i];
	if(n<7)
	{
		cout<<"No way"<<endl;
		return 0;
	}
	dfs(1);
	cout<<"No way"<<endl;
	return 0;
}
