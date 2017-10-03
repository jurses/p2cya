#include "language.hpp"
#include <string>
#include <iostream>

using namespace CYA;

std::ostream& showMenu(std::ostream& os);
void calculator(void);

int main(int argc, char **argv){
	calculator();
}

void calculator(void){
	Language L1;
	Language L2;
	int option;
	std::cout << "Please define a regular language L1: ";
	L1.define(std::cin);
	std::cout << "Please define the second regular language L2: ";
	L2.define(std::cin);
	do{
		showMenu(std::cout);
		std::cout << "Option: ";
		std::cin >> option;
		switch(option){
			case 0:
				if(L1.isProdByRE()){
					L1.writeRE(std::cout);
					std::cout << std::endl;
				}
				else{
					L1.write(std::cout);
					std::cout << std::endl;
				}
			break;
			case 1:	L1.invert();
			break;
			case 2: L1.concatenate(L2);
			break;
			case 3: L1.unite(L2);
			break;
			case 4: L1.difference(L2);
			break;
			case 5: L1.intersection(L2);
			break;
			case 6:
				if(L1.subLanguage(L2))
					std::cout << "L2 is a sublanguage of L1" << std::endl;
				else
					std::cout << "L2 is not a sublanguage of L1" << std::endl;
			break;
			case 7:
				if(L1.equality(L2))
					std::cout << "These languages are equal" << std::endl;
				else
					std::cout << "These languages are not equal" << std::endl;
			break;
			case 8: 
				int n;
				std::cout << "Elevate to: ";
				std::cin >> n;
				L1.power(n);
			break;
			case 9: L1.kleenStar();
			break;
			case 10: L1.kleenPlus();
			break;
			default: std::cout << "Incorrect option, try again" << std::endl;
		}
	}while(option != 0);
}

std::ostream& showMenu(std::ostream& os){
	os << "Operations with L1" << std::endl;
	os << "1. Invert" << std::endl
	<< "2. Concatenate with L2" << std::endl
	<< "3. Unite with L2" << std::endl
	<< "4. Difference with L2" << std::endl
	<< "5. Intersection with L2" << std::endl
	<< "6. Check if L2 is sublanguage of L1" << std::endl
	<< "7. Check if L1 and L2 are equal" << std::endl
	<< "8. Power L1" << std::endl
	<< "9. KleenStar of L1" << std::endl
	<< "10. KleenPlus of L1" << std::endl
	<< "0. Exit and show result" << std::endl;

	return os;
}