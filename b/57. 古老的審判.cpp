#include<iostream>
using namespace std;
char g[3][3];
char win()
{
	for(int i=0;i<3;i++)
	{
		if(g[i][0]==g[i][1]&&g[i][0]==g[i][2]&&g[i][0]!='.')
		{
			return g[i][0];
		}
		if(g[0][i]==g[1][i]&&g[0][i]==g[2][i]&&g[0][i]!='.')
		{
			return g[0][i];
		}
	}
	if(g[0][0]==g[1][1]&&g[0][0]==g[2][2]&&g[0][0]!='.')
	{
		return g[0][0];
	}
	if(g[0][2]==g[1][1]&&g[0][2]==g[2][0]&&g[0][2]!='.')
	{
		return g[0][2];
	}
	return '.';
}
int main()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			g[i][j]='.';
		}
	}
	bool human=true;
	int x,y;
	for(int c=0;c<9&&win()=='.';c++)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				cout<<g[j][i]<<" ";
			}
			cout<<endl;
		}
		cout<<((human)?"Human's turn!":"God's turn!")<<endl;
		cin>>y>>x;
		while(x<1||3<x||y<1||3<y||g[x-1][y-1]!='.')
		{
			cout<<"Illegal!"<<endl;
			cin>>y>>x;
		}
		y--;
		x--;
		g[x][y]=(human)?'O':'X';
		human=(human)?false:true;
	}
	switch(win())
	{
		case 'O':
			cout<<"Human wins!"<<endl;
			break;
		case 'X':
			cout<<"God wins!"<<endl;
			break;
		case'.':
			cout<<"Tie"<<endl;
	}
	return 0;
}
