#include <regex>
#include <string>
#include <iostream>

int main(){
	std::string s;
    std::regex reg(R"(^([1-9]\d+|\d)\.([1-9]\d+|\d)\.([1-9]\d+|\d)\.([1-9]\d+|\d)$)");
    while(std::cin>>s){
	    if(std::regex_match(s, reg)){
	    	std::cout<<"OK\n";
	    }else{
	    	std::cout<<"NG\n";
	    }
	}
    return 0;
}