#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{
	node *l=NULL;
	node *r=NULL;
	int data;
	int name;
};
bool cc(node *x,node *y)
{
	return x->data>y->data;
}
void find(node* x,int i)
{
	if(x->l==NULL&&x->r==NULL)
	{
		//cout<<char(x->name)<<" "<<x->data<<" "<<i<<endl;
	}
	else if(x->l!=NULL&&x->r!=NULL)
	{
		find(x->l,i+1);
		find(x->r,i+1);
	}
}
void build(deque<node*>&x)
{
	node *i=new node,*j=new node;
	while(x.size()!=1)
	{
		sort(x.begin(),x.end(),cc);
		j=x.back();
		x.pop_back();
		i=x.back();
		x.pop_back();
		node *p=new node;
		p->l=i;
		p->r=j;
		p->data=i->data+j->data;
		x.push_back(p);
		//cout<<p->data<<" "<<i->data<<" "<<j->data<<endl;
	}
}
int ss(node *x,int i)
{	
	if(x->l==NULL&&x->r==NULL)
	{
		if(i==0)
		{
			return x->data; 
		}
		else
		{
			//cout<<char(x->name)<<" "<<x->data<<" "<<i<<endl;
			return (x->data)*i;
		}
	}
	else if(x->l!=NULL&&x->r!=NULL)
	{
		return ss(x->l,i+1)+ss(x->r,i+1);
	}
}
int main()
{
	int *a=new int[127];
	for(int i=33;i<=126;i++)
	{
		a[i]=0;
	}
	deque<node*>x;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		if(33<=s[i]&&s[i]<=126)
		{
			a[int(s[i])]++;
		}
	}
	for(int i=33;i<=126;i++)
	{
		if(a[i]!=0)
		{
			node *j=new node;
			j->data=a[i];
			j->name=i;
			x.push_back(j);
		}
	}
	build(x);
	cout<<ss(x.back(),0);
	return 0;
}
