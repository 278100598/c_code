#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define X first
#define Y second
using namespace std;
vector <PII> v, hull;
int cross(PII a, PII b, PII c){
    PII A = {b.X-a.X, b.Y-a.Y}, 
        B = {c.X-a.X, c.Y-a.Y};
    return A.X*B.Y-A.Y*B.X;
}
void convex_hull(){
    sort(v.begin(), v.end());
    int top = 0;
    for (int i = 0; i < v.size(); i++){
        while (top >= 2 && cross(hull[top-2], hull[top-1], v[i]) <= 0)
            hull.pop_back(), top--;
        hull.emplace_back(v[i]), top++;
    }
    for (int i = v.size()-2, t=top+1; i >= 0; i--){
        while (top >= t && cross(hull[top-2], hull[top-1], v[i]) <= 0)
            hull.pop_back(), top--;
        hull.emplace_back(v[i]), top++;
    }
    
    /*for(auto i:hull) {
    	cout<<i.first<<" "<<i.second<<endl;
	}*/
    hull.pop_back();
}
int area(int a, int b, int c){
	return cross(hull[a], hull[b], hull[c]);
}
double len(PII a, PII b){
	int A = abs(a.X-b.X),
		B = abs(a.Y-b.Y);
	return sqrt(A*A+B*B);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r, x, y;
	cin >> n >> r;
	for (int i = 0; i < n; i++){
		cin >> x >> y;
		v.emplace_back(x, y);
	}
	convex_hull();
	if (hull.size() < 4){
		cout << "0\n";
		return 0;
	}
	int now = 0;
	double ans = 1e18;
	for (int i = 2; ; i++){
		cout<<now<<" "<<i<<endl;
		if (now >= (int)hull.size()-1) break;
		if (i >= hull.size()) i -= hull.size();
		if (area(now, now+1, (i+1)%hull.size()) < area(now, now+1, i)){
			ans = min(ans, area(now, now+1, i)/len(hull[now], hull[now+1]));
			now++;
		}
	}
	
	for(auto i:hull) cout<<i.first<<" "<<i.second<<endl;
	cout << fixed << setprecision(7) << ans << "\n";
}


