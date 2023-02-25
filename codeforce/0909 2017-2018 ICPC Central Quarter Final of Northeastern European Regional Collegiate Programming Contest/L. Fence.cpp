#include<iostream>
#include<algorithm>
#include<cMath>
#include<iomanip>
#include<vector>
#define PII pair<double,double>
#define X first
#define Y second
using namespace std;
vector<PII> v,up,low,hull;

double cross(PII a, PII b, PII c) {
	return (b.X-a.X)*(c.Y-a.Y)-(b.Y-a.Y)*(c.X-a.X);
}

void convex_hull() {
    sort(v.begin(), v.end());
    
    for (int i = 0; i < v.size(); i++){
        while (up.size() >= 2 && cross(up[up.size()-2], up[up.size()-1], v[i]) <= 0)
            up.pop_back();
        while (low.size() >= 2 && cross(low[low.size()-2],low[low.size()-1], v[i]) >= 0)
            low.pop_back();
        
        up.emplace_back(v[i]);
        low.emplace_back(v[i]);
    }
    
    for(PII i:up) hull.push_back(i);
    for(int i=low.size()-2;i>=1;i--) hull.push_back(low[i]);
    // hull.pop_back()
}

int N;
double R,ans=0;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	//cout<<fixed<<setprecision(100)<<acos(-1)<<endl;
	cin>>N>>R;
	for(int i=0;i<N;i++) {
		int k;
		cin>>k;
		for(int j=0;j<k;j++) {
			PII p;
			cin>>p.X>>p.Y;
			v.push_back(p);
		}
	}
	convex_hull();
	
	PII pre=hull.back();
	for(PII p:hull) {
		ans+= sqrt((pre.X-p.X)*(pre.X-p.X) + (pre.Y-p.Y)*(pre.Y-p.Y));
		pre = p;
	}
	ans += (2*R*acos(-1));
	
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}
/*
1 1 
4
1 1
1 2
2 1
2 2
*/
