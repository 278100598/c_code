#include<iostream>
#include<queue>
#define pp pair<unsigned long long int,pair<int,int>>
using namespace std;
struct team{
	unsigned long long int id;
	bool over=false;
};
int main()
{
	priority_queue<pp> pq;
	int n;
	cin>>n;
	team *t = new team[n];
	for(int i=0;i<n;i++) {
		cin>>t[i].id;
	}
	int o=0;
	unsigned long long int sum=0;
	for(int ii=1;ii<n;ii++) {
		t[o].over = true;
		for(int i=0;i<n;i++) {
			if(!t[i].over && i!=o) {
				pq.push(pp(t[o].id^t[i].id,pair<int,int>(o,i)));
			}
		}
		pp p = pq.top();
		pq.pop();
		while(t[p.second.first].over && t[p.second.second].over) {
			p = pq.top();
			pq.pop();
		}
		sum+=p.first;
		if(t[p.second.first].over) o=p.second.second;
		else o=p.second.first;
	}
	cout<<sum;
	return 0;
}
