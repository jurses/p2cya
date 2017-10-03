#include <iostream>
#include <cstdio>
#include <string>

std::string invert(std::string s1){
	char sT;
	for(int i=0; i<s1.size()/2; i++){
		sT = s1[i];
		s1[i] = s1[s1.size() - 1 - i];
		s1[s1.size() - 1 - i] = sT;
	}
	return s1;
}

int main(void){
	std::string cadena = "hola";
	cadena.push_back('s');
	std::cout << cadena << std::endl;
}