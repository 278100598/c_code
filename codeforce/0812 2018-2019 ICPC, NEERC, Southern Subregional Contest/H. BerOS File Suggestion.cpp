#include <bits/stdc++.h>
using namespace std;
vector <string> arr;
unordered_map <string, pair<int,string> > subcnt;
signed main(){
	//cout << strstr("123125415", "31") <<"\n";
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s, tmp;
	for (int i = 0; i < n; i++){
		unordered_set<string> st;
		cin >> s;
		arr.emplace_back(s);
		for (int j = 0; j < s.size(); j++){
			tmp = "";
			for (int k = j; k < s.size(); k++){
				tmp += s[k];
				if(st.count(tmp)) continue;
				st.insert(tmp);
				
				auto it = subcnt.find(tmp);
				if(it==subcnt.end()) subcnt[tmp]=make_pair(1,s);
				else it->second.first++;
			}
		}
	}
	int q, cnt;
	cin >> q;
	for (int i = 0; i < q; i++){
		cnt = 0;
		cin >> s;
		auto it = subcnt.find(s);
		if(it == subcnt.end()) cout<<"0 -"<<endl;
		else cout<<(it->second.first)<<" "<<(it->second.second)<<endl;
	}
}

