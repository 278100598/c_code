#include<iostream>
#include<vector>
#include<algorithm>
#define ff first
#define ss second
using namespace std;
struct Point {
	int r,c,w;
	Point (int x,int y,int z) {r=x,c=y,w=z;};
	bool operator < (Point &a) {
		return w<a.w;
	}
};
const int MX=1e3;
vector<Point> v;
int Z,N,M,T,lv[MX][MX],q[100000],p[MX*MX];
pair<int,int> mo[4] = {{0,1},{0,-1},{1,0},{-1,0}};

int find(int x) {
	if(p[x] < 0) return x;
	p[x] = find(p[x]);
	return p[x];
}
bool merge(int x,int y) {
	x = find(x), y = find(y);
	if(x==y) return false;
	if(abs(p[x]) < abs(p[y])) swap(x,y);
	p[x] += p[y];
	p[y] = x;
	return true;
}

int main() {
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	cin>>Z;
	while(Z--) {
		cin>>N>>M;
		v.clear();
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				p[i*MX+j] = -1;
				cin>>lv[i][j];
				v.emplace_back(i,j,lv[i][j]);
			}
		}
		sort(v.begin(),v.end());
		
		cin>>T;
		for(int i=0;i<T;i++) cin>>q[i];
		int now=0;
		for(int i=T-1;i>=0;i--) {
			while(!v.empty() && v.back().w>q[i]) {
				Point x = v.back();
				v.pop_back();
				now++;
				
				for(int j=0;j<4;j++) {
					int r=x.r+mo[j].ff, c=x.c+mo[j].ss;
					if(0<=r&&r<N&&0<=c&&c<M&&lv[r][c]>q[i]) {
						if(merge(x.r*MX+x.c,r*MX+c)) now--;
					}
				}
				//cout<<x.r<<' '<<x.c<<' '<<x.w<<' '<<now<<'\n';
			}
			q[i]=now;
		}
		for(int i=0;i<T;i++) cout<<q[i]<<' ';
		cout<<'\n';
	}
	
	return 0;
}
