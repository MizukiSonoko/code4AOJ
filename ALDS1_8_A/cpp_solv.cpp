#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

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

struct T
{
	long long int key;
	T *right;
	T *left;
	T *parent;
	T():key(0){};
};

T *root;

auto insert(T *z)
 -> void{


	T *y = nullptr;
	T *x = root;

	while(x != nullptr){
		y = x;
		if(z -> key < x -> key){
			x = x -> left;
		}else{
			x = x -> right;
		}
	}
	z->parent = y;

	if(y == nullptr){
		root = z;
	}else if(z -> key < y-> key){
		y -> left = z;
	}else{ 
		y -> right = z;
	}
}

auto inorder(T *t)
 -> void{

 	if(t -> left != nullptr){
		inorder(t -> left);
 	}

 	std::cout<<" "<< t -> key;

 	if(t -> right != nullptr){
		inorder(t -> right);
 	}
 }

auto preorder(T *t)
 -> void{

 	std::cout<<" "<< t -> key;

 	if(t->left != nullptr){
		preorder(t -> left);
 	}
 	
 	if(t->right != nullptr){
		preorder(t -> right);
 	}
 }

auto main()
 -> int{

	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin>>n;
	std::string cmd;

	for(int i=0;i<n;i++){
		std::cin>>cmd;
		if(cmd=="insert"){
			T* z = new T();
			std::cin>>z->key;
			insert(z);
		}else{
			inorder(root);
			std::cout<<"\n";
			preorder(root);
			std::cout<<"\n";
		}
	}

	return 0;
}

