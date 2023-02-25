#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
vector<vector<int>> p(7,vector<int>());
queue<int> deck;
map<vector<vector<int>>,set<queue<int>>> record;
int x;

int main() {
	
	while(cin>>x) {
		if(x==0) break;
		
		record.clear();
		while(!deck.empty()) deck.pop();
		for(int i=0;i<7;i++) p[i].clear();
		p[0].push_back(x);
		for(int i=1;i<7;i++) {
			cin>>x;
			p[i].push_back(x);
		}
		for(int i=7;i<52;i++) {
			cin>>x;
			deck.push(x);
		}
		
		for(int t=8,i=0;;t++,i=(i+1)%7) {
			while(p[i].size()==0) i=(i+1)%7;
			vector<int> &v=p[i]; 
			v.push_back(deck.front());
			deck.pop();
			
			while(v.size()>=3) {
				if((v[0]+v[1]+v[v.size()-1])%10 == 0) {
					deck.push(v[0]);
					deck.push(v[1]);
					deck.push(v[v.size()-1]);
					v.pop_back();
					v.erase(v.begin(),v.begin()+2);
				} else if((v[0]+v[v.size()-2]+v[v.size()-1])%10 == 0) {
					deck.push(v[0]);
					deck.push(v[v.size()-2]);
					deck.push(v[v.size()-1]);
					v.pop_back();
					v.pop_back();
					v.erase(v.begin());
				} else if((v[v.size()-3]+v[v.size()-2]+v[v.size()-1])%10 == 0) {
					deck.push(v[v.size()-3]);
					deck.push(v[v.size()-2]);
					deck.push(v[v.size()-1]);
					v.pop_back();
					v.pop_back();
					v.pop_back();
				} else {
					break;
				}
			}
			
			if(deck.size() == 52) {
				cout<<"Win : "<<t<<'\n';
				break;
			} else if(deck.size() == 0) {
				cout<<"Loss: "<<t<<'\n';
				break;
			} else if(record[p].count(deck) != 0) {
				cout<<"Draw: "<<t<<'\n';
				break;
			}
			record[p].insert(deck);
		}
	}
	
	return 0;
}
