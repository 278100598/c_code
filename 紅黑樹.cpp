#include<bits/stdc++.h>
using namespace std;
struct rbtree
{
	rbtree *r=NULL;
	rbtree *l=NULL;
	rbtree *p=NULL;
	bool red;
	int data;
	int repeat;
};
rbtree *root=NULL;
rbtree *bro(rbtree *p)
{
	if(p->p==NULL)
	{
		return NULL;
	}
	if(p->p->l==p)
	{
		return p->p->r;
	}
	else
	{
		return p->p->l;
	}
}
void color(rbtree *p,int x)
{
	if(p==NULL)
	{
		cout<<x<<" ";
		return;
	}
	if(p->red==false)
	{
		x++;
	}
	color(p->l,x);
	color(p->r,x);
}
void out(rbtree *p)
{
	if(p==NULL)
	{
		return;
	}
	if(p->l!=NULL)
	{
		out(p->l);
	}
	cout<<p->data<<" ";
	if(p->r!=NULL)
	{
		out(p->r);
	}
}
rbtree *small(rbtree *p)
{
	if(p->l==NULL)
	{
		return p;
	}
	else
	{
		return small(p->l);
	}
}
rbtree *gp(rbtree *n)
{
	if(n->p==NULL)
	{
		return NULL;
	}
	else
	{
		return n->p->p;	
	}
}
rbtree *uu(rbtree *n)
{
	if(gp(n)==NULL)
	{
		return NULL;
	}
	if(gp(n)->l==n->p)
	{
		return gp(n)->r;
	}
	else
	{
		return gp(n)->l;
	}
}
void rr(rbtree *n)
{
	rbtree *a=gp(n);
	rbtree *b=n->r;
	rbtree *c=n->p;
	c->l=b;
	n->r=c;
	c->p=n;
	n->p=a;
	if(b!=NULL)
	{
		b->p=c;
	}
	if(root==c)
	{
		root=n;
	}
	if(a!=NULL)
	{
		if(a->l==c)
		{
			a->l=n;
		}
		else
		{
			a->r=n;
		}
	}
}
void lr(rbtree *n)
{
	rbtree *a=gp(n);
	rbtree *b=n->l;
	rbtree *c=n->p;
	c->r=b; 
	n->l=c;
	c->p=n;
	n->p=a;
	if(b!=NULL)
	{
		b->p=c;
	}
	if(root==c)
	{
		root=n;
	}
	if(a!=NULL)
	{
		if(a->r==c)
		{
			a->r=n;
		}
		else
		{
			a->l=n;
		}
	}
}
bool find(int n,rbtree *root,rbtree *p,rbtree *pp)
{
	if(root==NULL)
	{
		p=pp;
		return false;
	}
	else if(root->data==n)
	{
		p=root;
		return true;
	}
	else if(root->data<n)
	{
		find(n,root->r,p,root);
	}
	else if(n<root->data)
	{
		find(n,root->l,p,root);
	}
}
void in2(rbtree *p)
{
	if(p->p==NULL)
	{
		root=p;
		p->red=false;
		return;
	}
	else if(p->p->red==false)
	{
		p->red=true;
		return;
	}
	else
	{
		if(uu(p)!=NULL&&uu(p)->red)
		{
			p->p->red=false;
			uu(p)->red=false;
			gp(p)->red=true;
			in2(gp(p));
		}
		else
		{
			if(p==p->p->r&&gp(p)->l==p->p)
			{
				lr(p);
				p=p->l;
			}
			else if(p==p->p->l&&gp(p)->r==p->p)
			{
				rr(p);
				p=p->r;
			}
			if(p->p->l==p&&gp(p)->l==p->p)
			{
				rr(p->p);
				p->p->red=false;
				p->p->r->red=true;
			}
			else if(p->p->r==p&&gp(p)->r==p->p)
			{
				lr(p->p);
				p->p->red=false;
				p->p->l->red=true;
			}
		}
	} 
}
void in1(int n,rbtree *p)
{
	if(p->data==n)
	{
		p->repeat++;
		return;
	}
	else if(p->data<n)
	{
		if(p->r==NULL)
		{
			rbtree *i=new rbtree;
			i->repeat=0;
			i->p=p;
			p->r=i;
			i->data=n;
			i->l=NULL;
			i->r=NULL;
			i->red=true;
			in2(i);
		}
		else
		{
			in1(n,p->r);
		}
	}
	else if(n<p->data)
	{
		if(p->l==NULL)
		{
			rbtree *i=new rbtree;
			i->repeat=0;
			i->p=p;
			p->l=i;
			i->data=n;
			i->l=NULL;
			i->r=NULL;
			i->red=true;
			in2(i);
		}
		else
		{
			in1(n,p->l);
		}
	}
}
void inin(int n)
{
	if(root==NULL)
	{
		root=new rbtree;
		root->data=n;
		root->repeat=0;
		root->red=false;
		root->r=NULL;
		root->l=NULL;
	}
	else
	{
		in1(n,root);
	}
}
void dd3(rbtree *p)
{
	rbtree *i=bro(p);
	if(p->p==NULL)
	{
		p->red=false;
		return;
	}
	if(i->red)
	{
		if(p->p->r==i)
		{
			lr(i);
		}
		else
		{
			rr(i);
		}
		i->red==false;
		p->p->red=true;
	}
	if(p->p->red==false&&i->red==false&&(i->r==NULL||i->r->red==false)&&(i->l==NULL||i->l->red==false))
	{
		i->red=true;
		dd3(p->p);
	}
	else
	{
		if(p->p->red&&i->red==false&&(i->r==NULL||i->r->red==false)&&(i->l==NULL||i->l->red==false))
		{
			p->p->red=false;
			i->red=true;
			return;
		}
		if(i==i->p->r&&(i->r==NULL||i->r->red==false)&&i->l->red)
		{
			i->l->red=false;
			i->red=true;
			rr(i->l);
		}
		else if(i==i->p->l&&(i->l==NULL||i->l->red==false)&&i->r->red)
		{
			i->r->red=false;
			i->red=true;
			rr(i->r);
		}
		rbtree *s=bro(p);
		if(s==s->p->r&&s->r->red)
		{
			s->red=p->p->red;
			s->r->red=false;
			lr(s);
			p->p->red=false;
		}
		else if(s==s->p->l&&s->l->red)
		{
			s->red=p->p->red;
			s->l->red=false;
			rr(s);
			p->p->red=false;
		}
	}
}
void dd2(rbtree *p)
{
	rbtree *i=p->l==NULL?p->r:p->l;
	if(p->p==NULL&&p->r==NULL&&p->l==NULL)
	{
		root=NULL;
		return;
	}
	if(p->p==NULL)
	{
		root=i;
		root->p=NULL;
		root->red=false;
		return;
	}
	if(p==p->p->r)
	{
		p->p->r=i;
	}
	else if(p==p->p->l)
	{
		p->p->l=i;
	}
	if(i!=NULL)
	{
		i->p=p->p;
	}
	if(p->red==false)
	{
		if(i==NULL)
		{
			i=new rbtree;
			i->p=p->p;
			i->red=false;
			if(p->p->r==NULL)
			{
				p->p->r=i;
			}
			else if(p->p->l==NULL)
			{
				p->p->l=i;
			}
			dd3(i);
			if(i==i->p->r)
			{
				i->p->r=NULL;
			}
			else if(i==i->p->l)
			{
				i->p->l=NULL;
			}
		}
		else if(i->red)
		{
			i->red=false;
		}
		else
		{
			dd3(i);
		}
	}
	delete p;
}
void dd1(rbtree *p)
{
	if(p->r==NULL)
	{
		dd2(p);
		return;
	}
	else
	{
		rbtree *i=small(p->r);
		p->data=i->data;
		dd2(i);
	}
}
bool dd(rbtree *p,int n)
{
	if(p->repeat!=0&&p->data==n)
	{
		p->repeat--;
		return true;
	}
	if(p->data<n)
	{
		if(p->r==NULL)
		{
			return false;
		}
		else
		{
			return dd(p->r,n);
		}
	}
	else if(n<p->data)
	{
		if(p->l==NULL)
		{
			return false;
		}
		else
		{
			return dd(p->l,n);
		}
	}
	else if(p->data==n)
	{
		dd1(p);
		return true;
	}
}
int main()
{
	
	return 0;
}
