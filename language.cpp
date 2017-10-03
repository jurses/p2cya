#include "language.hpp"

	/*
	Atención:
	Nadie se molestó en decirme que std::set guarda los datos constantes,
	es decir nadie puede modificarlos para evitar perder el hash, estructura,
	interna..., lo correcto quitar y volver a poner
	*/

namespace CYA{

	Language::Language(){

	}

	void Language::invert(void){
		Word tempWord;
		for(std::set<Word>::iterator it = setWords_.begin(); it != setWords_.end(); it++){
			tempWord = *it;
			setWords_.erase(*it);
			tempWord.invert();
			setWords_.insert(tempWord);
		}
	}

	void Language::concatenate(Language L){
		Word tempWord;
		for(std::set<Word>::iterator it1 = setWords_.begin(); it1 != setWords_.end(); it1++)
			for(std::set<Word>::iterator it2 = L.setWords_.begin(); it2 != L.setWords_.end(); it2++){
				tempWord = *it1;
				setWords_.erase(*it1);
				tempWord.concatenate(*it2);
				setWords_.insert(tempWord);
			}
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
			for(std::set<Word>::iterator it2 = L.setWords_.begin(); it2 != L.setWords_.end(); it2++){
				if(*it1 == *it2)
					aux.insert(*it1);
			}
	}

	bool Language::subLanguage(Language& L){
		Word tempWord1, tempWord2;
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

	Language& Language::operator=(const Language& L){
		setWords_ = L.setWords_;
		regularExpression_ = L.regularExpression_;
		prodByRE_ = L.prodByRE_;
		return *this;
	}

	std::istream& Language::define(std::istream& is){
		std::string rawLanguage;
		is >> rawLanguage;
		if(rawLanguage[0] == '{' && rawLanguage[rawLanguage.size() - 1] == '}'){
			if(rawLanguage.size() == 2)
				empty_ = true;
			else{
				Word tW;
				std::string w;
				for(int i = 1; i < rawLanguage.size() - 1; i++){
					if(rawLanguage[i] != ',')
						w.push_back(rawLanguage[i]);
					else{
						tW = w.c_str();
						w.clear();
						setWords_.insert(tW);
					}
				}
			}
		}
		
		return is;
	}
}