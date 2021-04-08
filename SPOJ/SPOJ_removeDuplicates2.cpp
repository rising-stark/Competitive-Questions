#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	int i,n;
	unordered_set<int> s;
	vector<int> v;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		if(s.find(x)==s.end()){
			s.insert(x);
			v.push_back(x);
		}
	}
	vector<int>::iterator it;
	for(it=v.begin();it!=v.end();it++){
		cout<<*it<<" ";
	}cout<<endl;
	
	vector<int>::reverse_iterator it1;
	for(it1=v.rbegin();it1!=v.rend();it1++){
		cout<<*it1<<" ";
	}cout<<endl;
	return 0;
}