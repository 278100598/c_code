#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>//用tree
#include<ext/pb_ds/hash_policy.hpp>//用hash
#include<ext/pb_ds/trie_policy.hpp>//用trie
#include<ext/pb_ds/priority_queue.hpp>//用priority_queue
using namespace __gnu_pbds;
using namespace std;
typedef tree<
int,
null_type,
less_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int main()
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	ordered_set x;
	string a;
	int b;
	while(cin>>a)
	{
		if(a=="INSERT")
		{
			cin>>b;
			x.insert(b);
		}
		if(a=="POP_LARGE")
		{
			if(x.begin()==x.end())
			{
				cout<<"Nothing To Do :)"<<endl;
			}
			else
			{
				cout<<*--x.end()<<endl;
				x.erase(--x.end());
			}
		}
		if(a=="POP_SMALL")
		{
			if(x.begin()==x.end())
			{
				cout<<"Nothing To Do :)"<<endl;
			}
			else
			{
				cout<<*x.begin()<<endl;
				x.erase(x.begin());
			}
		}
		if(a=="END")
		{
			break;
		}
	}
	return 0;
}
