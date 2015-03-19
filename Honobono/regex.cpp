#include <regex>
#include <string>
#include <iostream>

using namespace std;

int main(){
	string s;
    regex reg(R"(^([1-9]\d+|\d)\.([1-9]\d+|\d)\.([1-9]\d+|\d)\.([1-9]\d+|\d)$)");
    while(cin>>s){
	    if(regex_match(s, reg)){
	    	cout<<"OK\n";
	    }else{
	    	cout<<"NG\n";
	    }
	}
    return 0;
}