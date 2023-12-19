#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<string> result;
	string str = "a,b,c,d,e";
	int start = 0, pos = 0;
	while(((pos = str.find(",", start)) != string::npos)){
		result.push_back(str.substr(start, pos-start));
		start = pos+1;
	}
	result.push_back(str.substr(start));
	for(string s : result){cout << s << " ";}
	cout << endl;
	return 0;
}