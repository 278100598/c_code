#include<iostream>
#include<queue>
using namespace std;
int kill(queue<int> *x,int y)
{
	if(x->size()==1)
	{
		return x->front();
	}
	for(int i=1;i<y;i++)
	{
		x->push(x->front());
		x->pop();
	}
	x->pop();
	return kill(x,y);
}
int main()
{
	queue<int>*x=new queue<int>;
	int a,b;
	cin>>a>>b;
	for(int i=0;i<a;i++)
	{
		x->push(i);
	}
	cout<<kill(x,b);
	return 0;
}
