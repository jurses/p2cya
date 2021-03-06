#include "language.hpp"

	/*
	Atención:
	Nadie se molestó en decirme que std::set guarda los datos constantes,
	es decir nadie puede modificarlos para evitar perder el hash, estructura,
	interna..., lo correcto quitar y volver a poner
	*/

namespace CYA{

	Language::Language(){
		prodByRE_ = false;
	}

	void Language::L2RE(void){
		regularExpression_.obtRE().clear();
		if(!empty_){
			std::string tempW;
			for(std::set<Word>::iterator it = setWords_.begin(); it != --setWords_.end(); it++){
				tempW = it->obtWord();
				regularExpression_.obtRE().append(tempW);
				regularExpression_.obtRE().push_back('|');
			}
			
			regularExpression_.obtRE().append(setWords_.rbegin()->obtWord());
		}
		else
			regularExpression_.obtRE().push_back('0');

	}

	void Language::invert(void){
		Word tempWord;
		std::set<Word> tempSetWord;
		for(std::set<Word>::iterator it = setWords_.begin(); it != setWords_.end(); it++){
			tempWord = *it;
			tempWord.invert();
			tempSetWord.insert(tempWord);
		}

		setWords_ = tempSetWord;
		L2RE();
	}

	void Language::concatenate(Language L){
		if(!empty_){
			Word tempWord;
			std::set<Word> tempSetWord;
			for(std::set<Word>::iterator it1 = setWords_.begin(); it1 != setWords_.end(); it1++)
				for(std::set<Word>::iterator it2 = L.setWords_.begin(); it2 != L.setWords_.end(); it2++){
					tempWord = *it1;
					tempWord.concatenate(*it2);
					tempSetWord.insert(tempWord);
				}

			setWords_ = tempSetWord;
		}
		L2RE();
	}

	void Language::unite(Language& L){
		if(!empty_)
			for(std::set<Word>::iterator it = L.setWords_.begin(); it != L.setWords_.end(); it++)
				setWords_.insert(*it);
		L2RE();
	}

	void Language::difference(Language& L){
		if(!empty_)
			for(std::set<Word>::iterator it = L.setWords_.begin(); it != L.setWords_.end(); it++)
				setWords_.erase(*it);

		if(setWords_.size() == 0)
			empty_ = true;
		L2RE();
	}

	void Language::intersection(Language& L){
		std::set<Word> aux;
		if(!empty_){
			for(std::set<Word>::iterator it1 = setWords_.begin(); it1 != setWords_.end(); it1++)
				for(std::set<Word>::iterator it2 = L.setWords_.begin(); it2 != L.setWords_.end(); it2++){
					if(*it1 == *it2)
						aux.insert(*it1);
				}
			setWords_ = aux;
			if(setWords_.size() == 0)
				empty_ = true;
		}
		L2RE();
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
		if(n > 0)	
			powerR(n);
		else if(n == 0){
			Word w('&');
			setWords_.insert(w);
			empty_ = false;
		}
		L2RE();
	}

	void Language::powerR(int n){
		if(n == 0){
			Word A('&');
			setWords_.insert(A);
		}
		else if(n > 0){
			concatenate(*this);
			powerR(n - 1);
		}
		L2RE();
	}

	void Language::kleenStar(void){
		L2RE();
		prodByRE_ = true;
		std::string tempER;
		tempER.push_back('(');
		tempER.append(regularExpression_.obtRE());
		tempER.push_back(')');
		tempER.push_back('*');
		regularExpression_ = tempER;
	}

	void Language::kleenPlus(void){
		L2RE();
		this->writeRE(std::cout);
		std::cout << std::endl;
		prodByRE_ = true;
		std::string tempER;
		tempER.push_back('(');
		tempER.append(regularExpression_.obtRE());
		tempER.push_back(')');
		tempER.push_back('+');
		regularExpression_ = tempER;
	}

	Language& Language::operator=(const Language& L){
		setWords_ = L.setWords_;
		regularExpression_ = L.regularExpression_;
		prodByRE_ = L.prodByRE_;
		L2RE();
		return *this;
	}

	std::istream& Language::define(std::istream& is){
		std::string rawLanguage;
		std::getline(is, rawLanguage);
		if(rawLanguage[0] == '{' && rawLanguage[rawLanguage.size() - 1] == '}'){
			if(rawLanguage.size() == 2)
				empty_ = true;
			else{
				std::string w;
				for(int i = 1; i < rawLanguage.size() - 1; i++){
					if(rawLanguage[i] != ',' && !isspace(rawLanguage[i]))
						w.push_back(rawLanguage[i]);

					if(rawLanguage[i] == ',' || rawLanguage[i + 1] == '}'){
						Word tW(w);
						w.clear();
						setWords_.insert(tW);
					}
				}
			}
		}
		L2RE();
		return is;
	}

	std::ostream& Language::write(std::ostream& os){
		os << '{';
		if(!empty_){
			os << setWords_.begin()->obtWord();
			for(std::set<Word>::iterator it = ++setWords_.begin(); it != setWords_.end(); it++)
				os << ", " << it->obtWord();
		}
		os << '}';
		return os;
	}
	
	std::ostream& Language::writeRE(std::ostream& os){
		regularExpression_.write(os);
		return os;
	}

	bool Language::isProdByRE(void){
		return prodByRE_;
	}

	bool Language::isEmpty(void){
		return empty_;
	}
}