#include <iostream>
#include <vector>
#include <cmath>

template<typename T>
auto print(std::vector<T> array,bool reverse = false) 
 -> void{
 	if(reverse){
		auto iterator = array.rbegin();
		std::cout<<*iterator;
		iterator++;
		for(;iterator != array.rend();++iterator){
			std::cout<<" "<< *iterator;
		}

	}else{
		auto iterator = array.begin();
		std::cout<<*iterator;
		iterator++;
		for(;iterator != array.end();++iterator){
			std::cout<<" "<< *iterator;
		}
	}
	std::cout<<"\n";
}

template<typename T>
auto println(std::vector<T> array) 
 -> void{
	for(auto v : array){
		std::cout<< v <<"\n";
	}
}


auto main()
 -> int{

	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	std::cout<<"This is template file.\n";
	return 0;
}

