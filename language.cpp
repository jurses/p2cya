#include "language.hpp"

namespace CYA{
	void Language::invert(void){
		for(std::set<Word>::iterator it = setWords_.begin(); it != setWords_.end(); it++)
			it->invert();
	}

	void Language::concatenate(Language& L){
		for(std::set<Word>::iterator it1 = setWords_.begin(); it1 != setWords_.end(); it1++)
			for(std::set<Word>::iterator it2 = L.setWords_.begin(); it2 != L.setWords_.end(); it2++)
				it1->concatenate(*it2);
	}

	void Language::unite(Language& L){
		for(std::set<Word>::iterator it = L.setWords_.begin(); it != L.setWords_.end(); it++)
			setWords_.insert(*it);
	}

	void Language::difference(Language& L){
		for(std::set<Word>::iterator it = L.setWords_.begin(); it != L.setWords_.end(); it++)
			setWords_.erase(*it);
	}

	void Language::intersection(Language& L){
		std::set<Word> aux;
		for(std::set<Word>::iterator it1 = setWords_.begin(); it1 != setWords_.end(); it1++)
			for(std::set<Word>::iterator it2 = L.setWords_.begin(); it2 != L.setWords_.end(); it2++)
				if(*it1 == *it2)
					aux.insert(*it1);
	}

	bool Language::subLanguage(Language& L){
		std::set<Word> aux;
		for(std::set<Word>::iterator it1 = setWords_.begin(); it1 != setWords_.end(); it1++)
			for(std::set<Word>::iterator it2 = L.setWords_.begin(); it2 != L.setWords_.end(); it2++){
				if(*it1 == *it2)
					aux.insert(*it1);
		}

		if(aux.size() == L.setWords_.size())	// pregunta si tiene los mismos elementos comunes
			return true;
		else
			return false;
	}

	bool Language::equality(Language& L){
		if(subLanguage(L) && L.subLanguage(*this))
			return true;
		else
			return false;
	}

	void Language::power(int n){		
		powerR(n);
	}

	void Language::powerR(int n){
		if(n == 0){
			Word A;
			setWords_.clear();
			setWords_.insert(A);
		}else if(n > 0){
			concatenate(*this);
			powerR(n - 1);
		}
	}

	void Language::kleenStar(void){
		prodByRE_ = true;
	}
}