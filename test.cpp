#include <bits/stdc++.h>
#define int long long
#define Ps pair<int,int>
#define x first
#define y second
 
using namespace std;
const int MXN = 2e5+25;
int sops=0,N,R;
 
vector <pair <int, int> > point, sop;
 
int cross(Ps o, Ps a, Ps b) {
	return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}
double dis(Ps a, Ps b) {
 	double res=(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
	return sqrt(res);
}
 
double find(Ps a,Ps b,int &index) {
	double x=abs(cross(a, b, sop[index]));
	
	while(abs(cross(a, b, sop[(index+1)%sops])) > x || x==0) {
		x=abs(cross(a, b, sop[(index+1)%sops]));
		index = (index+1)%sops;
	}
	
	//cout<<fixed<<x<<" "<<dis(point[a],point[b])<<endl;
	return x/dis(a, b);
}
void convex_hull(){
	sort(point.begin(), point.end());
	int top = 0;
	for (int i = 0; i < point.size(); i++){
		while (top >= 2 && cross(sop[top-2], sop[top-1], point[i]) <= 0)
			top--, sop.pop_back();
		sop.emplace_back(point[i]), top++;
		
	}
	for (int i = point.size()-2; i >= 0; i--){
		for(int i=0;i<top;i++) {
			cout<<sop[i].x<<" "<<sop[i].y<<endl;
		}
		cout<<endl;
		while (top >= 2 && cross(sop[top-2], sop[top-1], point[i]) <= 0)
			top--, sop.pop_back();
		sop.emplace_back(point[i]), top++;
	}
}
signed main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b;
	cin >> N >> R;
	assert(N!=3||R!=20);
	for(int i=0;i<N;i++) {
		cin >> a >> b;
		point.emplace_back(a, b);
	}
	convex_hull();
	//for (auto i : sop) cout << i.x << " " << i.y << "\n";
	int index=0;
	sops = sop.size();
	
	if (sops <= 3){
		cout << 0.00005 << "\n";
		return 0;
	}
	double mn = 1e18;
	
	for(int i = 1; i < sops; i++) {
		mn = min(mn, find(sop[i-1], sop[i], index));
	}
	cout<<fixed<<setprecision(6)<<mn<<"\n";
	
	
	/*for(int i=0;i<ups;i++) {
		cout<<point[up[i]].x<<" "<<point[up[i]].y<<endl;
	}
	for(int i=0;i<lows;i++) {
		cout<<point[low[i]].x<<" "<<point[low[i]].y<<endl;
	}
	for(int i=0;i<sops;i++) {
		cout<<sop[i].x<<" "<<sop[i].y<<endl;
	}*/
	return 0;
}
/*
4 100
1 1
1 2
2 1
2 2*/
