#include<bits/stdc++.h>
using namespace std;

int k,n,now_n;
int way[32][3],way2[32];   // 0表示横着，1表示左下右上斜↗，2表示左上右下斜↘ 
int now_out[32];
int tow[35];
bool over;

int next(int i,int go,int haha);
void chushihua();
bool find(int point);
void baoli(int now);
void xianzhi2(int now,int num);

void xianzhi2(int now,int num)
{
	if(find(now) == 1)
	{
		for(int a1 = 0;a1 <= 2;a1++)
		{
			for(int a2 = 0;a2 <= 1;a2++)
			{
				way2[next(now,a1,a2)] = way2[next(now,a1,a2)] ^ tow[num];
			}
		}
		way2[now] = way2[now] ^ tow[num];
	}
	else
	for(int i = 0;i <= 2;i++)
	{
		for(int j = 0;j <= 1;j++)
		{
			if(find(next(now,i,j)))
			{
				int aaaa = next(now,i,j);
				for(int a1 = 0;a1 <= 2;a1++)
				{
					for(int a2 = 0;a2 <= 1;a2++)
					{
						way2[next(aaaa,a1,a2)] = way2[next(aaaa,a1,a2)] ^ tow[num];
					}
				}
				way2[aaaa] = way2[aaaa] ^ tow[num];
			}
		}
	}
}

void chushihua()
{
	tow[0] = 1;
	for(int i = 1;i <= k;i++)
	{
		tow[i] = tow[i - 1] << 1;
	}
}

int next(int i,int go,int haha)
{
	if(go == 0)
	{
		if(haha == 1)
		{
			if(i != 2 && i != 7 && i != 13 && i != 18 && i != 24 && i != 29 && i != 31)
			return i + 1;
			else return 0;
		}
		else
		{
			if(i != 1 && i != 3 && i != 8 && i != 14 && i != 19 && i != 25 && i != 30)
			return i - 1;
			else return 0;
		}
	}
	else if(go == 1)
	{
		if(haha == 1)
		{
			if(i == 1 || i == 2 || i == 27 || i == 28)
			return i + 3;
			else if(i == 8 || i == 19 || i == 25 || i == 26 || i == 30 || i == 31 || i == 29)
			return 0;
			else return i + 5;
		}
		else
		{
			if(i == 4 || i == 5 || i == 30 || i == 31)
			return i - 3;
			else if(i == 3 || i == 1 || i == 2 || i == 6 || i == 7 || i == 13 || i == 24)
			return 0;
			else return i - 5;
		}
	}
	else
	{
		if(haha == 1)
		{
			if(i == 1 || i == 2 || i == 26 || i == 27)
			return i + 4;
			else if(i == 25 || i == 30 || i == 31 || i == 28 || i == 29 || i == 24 || i == 13)
			return 0;
			else return i + 6; 
		}
		else
		{
			if(i == 5 || i == 6 || i == 30 || i == 31)
			return i - 4;
			else if(i == 19 || i == 8 || i == 3 || i == 4 || i == 1 || i == 2 || i == 7)
			return 0;
			else return i - 6; 
		}
	}
}

bool find(int point)
{
	if(point == 5 || point == 9 || point == 12 || point == 16 || point == 20 || point == 23 || point == 27)
	return 1;
	return 0;
}

void baoli(int now)
{

	if(over == 1)
	return ;
	if(now == 32)
	{
		now_n++;
		if(now_n == n)
		{
			cout<<"Found"<<endl;
			for(int i = 1;i <= 31;i++)
			cout<<now_out[i]<<' ';
			over = 1;
		}
	}
	if(now_out[now] != 0)
	{
		way[next(now,0,1)][0] = way[now][0] | way[next(now,0,1)][0];
		way[next(now,1,1)][1] = way[now][1] | way[next(now,1,1)][1];
		way[next(now,2,1)][2] = way[now][2] | way[next(now,2,1)][2];
		baoli(now + 1);
	}
	else
	for(int i = 1;i <= k;i++)
	{
		if(((( way[now][0] | way[now][1]| way[now][2] | way2[now]) & tow[i]) == 0) && over == 0)
		{
			now_out[now] = i;
			way[next(now,0,1)][0] = way[now][0] | way[next(now,0,1)][0] | tow[i];
			way[next(now,1,1)][1] = way[now][1] | way[next(now,1,1)][1] | tow[i];
			way[next(now,2,1)][2] = way[now][2] | way[next(now,2,1)][2] | tow[i];
			xianzhi2(now,i);
			baoli(now + 1);
			xianzhi2(now,i);
			way[next(now,0,1)][0] = 0;
			way[next(now,1,1)][1] = 0;
			way[next(now,2,1)][2] = 0;
			now_out[now] = 0;
		} 
	}
}

int main()
{
	freopen("hexodoku.in","r",stdin);
	freopen("hexodoku.out","w",stdout);
	cin>>k>>n;
	chushihua();
	if(k < 6)
	{
		cout<<"No way";
		return 0;
	}
	for(int i = 1;i <= 31;i++)
	{
		int in;
		cin>>in;
		if(in != 0)
		{
			int now;
			for(int z = 0;z <= 2;z++)
			{
				for(int j = 0;j <= 1;j++)
				{
					now = i;
					while(now != -1)
					{
						way[now][z] = way[next(now,z,j ^ 1)][z] | tow[in];
						now = next(now,z,j);
					}
				}
			}
			xianzhi2(i,in);
			now_out[i] = in;
		}
	}
	
	
	
	baoli(1);
	
	if(over == 0) cout<<"No way";
	
	return 0;
}


