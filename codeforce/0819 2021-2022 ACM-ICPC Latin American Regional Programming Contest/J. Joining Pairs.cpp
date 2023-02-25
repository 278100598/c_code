#include<iostream>
#include<vector>
#include<algorithm> 
#define mp make_pair
using namespace std;
int W,H,N;
vector<pair<int,int> >st;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>W>>H>>N;
	for(int i=0;i<N;i++) {
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		bool a=((x1==0 || x1==W)||(y1==0 || y1==H));
		bool b=((x2==0 || x2==W)||(y2==0 || y2==H));
		//cout<<a<<" "<<b<<endl;
		if(a&&b) {
			if(x1==0) st.push_back(mp(-H-W-2+y1,i));
			else if(y1==H) st.push_back(mp(-W-1+x1,i));
			else if(x1==W) st.push_back(mp(H-y1,i));
			else if(y1==0) st.push_back(mp(H+1+W-x1,i));
			
			if(x2==0) st.push_back(mp(-H-W-2+y2,i));
			else if(y2==H) st.push_back(mp(-W-1+x2,i));
			else if(x2==W) st.push_back(mp(H-y2,i));
			else if(y2==0) st.push_back(mp(H+1+W-x2,i));
		}
	}
	
	sort(st.begin(),st.end());
	vector<int>v;
	for(int i=0;i<st.size();i++) {
		if(!v.empty() && v.back()==st[i].second) v.pop_back();
		else v.push_back(st[i].second);
	}
	if(v.empty()) {
		cout<<"Y";
	} else {
		cout<<"N";
	}
	
	return 0;
}
