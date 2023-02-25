#include<iostream>
#include<set>
#include<stack>
#include<math.h>
#include<iomanip>
#define pii pair<int,int>
#define x first
#define y second
using namespace std;
double cross(pii o, pii a, pii b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
int main() {
	int n;
	cin>>n;
	set<pii> s;
	for(int i=0;i<n;i++) {
		pii point;
		cin>>point.x>>point.y;
		s.insert(point);
	}
	
	stack<pii>up,low;
	up.push(*s.begin());
	low.push(*s.begin());
	for(auto it=++s.begin();it!=s.end();it++) {
		pii pre;
		pre = up.top();
		up.pop();
		while(!up.empty() && cross(up.top(),pre,*it) >= 0) {
			pre = up.top();
			up.pop();
		}
		up.push(pre);
		up.push(*it);
		pre = low.top();
		low.pop();
		while(!low.empty() && cross(low.top(),pre,*it) <= 0) {
			pre = low.top();
			low.pop();
		}
		low.push(pre);
		low.push(*it);
	}
	double sum=0;
	pii pre = up.top();
	up.pop();
	while(!up.empty()) {
		int xx = up.top().x-pre.x,yy=up.top().y-pre.y;
		sum+=sqrt(xx*xx+yy*yy);
		pre = up.top();
		up.pop();
	}
	pre = low.top();
	low.pop();
	while(!low.empty()) {
		int xx = low.top().x-pre.x,yy=low.top().y-pre.y;
		sum+=sqrt(xx*xx+yy*yy);
		pre = low.top();
		low.pop();
	}
	cout<<fixed<<setprecision(2)<<sum;
	return 0;
}
