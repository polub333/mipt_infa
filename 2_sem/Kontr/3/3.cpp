#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	int l;
	cin>>l;
	
	
	int res = 1;
	int i=0, j=0;
	while(j != n-1){
		if(v[j+1] <= v[i]+l){
			++j;
		}
		else{
			if(j-i+1 > res){
				res = j-i+1;
			}
			++i;
			if(i < j){
				j = i;
			}
		}
	}
	if(j-i+1 > res){
		res = j-i+1;
	}
	cout<<res;
	
	/*
	sort(v.begin(), v.end());
	
	
	int res = 0;
	int b, e;
	for(int i=0;i<n;++i){
		auto it = lower_bound(v.begin(), v.end(), v[i]+l+1);
		int dist = it - (v.begin() + i);
		if(dist > res){
			res = dist;
			
		}
	}
	cout<<res<<endl;
	
	*/
	
	
	return 0;
}
