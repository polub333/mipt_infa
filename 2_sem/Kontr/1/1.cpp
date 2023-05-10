#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int foo(string f)
{
	int dec = 0;
	int sz = f.size();
	for(int i=0;i<sz;++i){
		dec += (f[i] - '0')*pow(5, sz-i-1);
	}
	return dec;
}

int main()
{
	int n;
	cin>>n;
	int sum = 0;
	string num;
	for(int i=0;i<n;++i){
		cin>>num;
		int dec = foo(num);
		sum += dec;
	}
	
	string res = "";
	while(sum > 0){
		res += sum % 3 + '0';
		sum /= 3;
	}
	for(int i=res.size()-1; i>=0; --i){
		cout<<res[i];
	}	
	return 0;
}
