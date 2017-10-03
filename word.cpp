#include "word.hpp"
#include <iostream>
namespace CYA{
	Word::Word(){
		word_.resize(0);
		empty_ = true;
	}

	Word::Word(const Alphabet& A)
	{
		alphabet_ = A;
	}

	Word::Word(char c){
		if(c == '&')
			empty_ = true;

		word_.push_back(c);
	}

	Word::Word(const std::string& ws){
		word_ = ws;
		empty_ = false;
	}

	Word::Word(const Word& w){
		alphabet_ = w.alphabet_;
		word_ = w.word_;
		empty_ = w.empty_;
	}

	const char* Word::obtWord(void)const{
		return word_.c_str();
	}

	Word& Word::operator=(const Word& word){
		word_ = word.word_;	// qué lío ;-)
		// Word es la clase
		// word es el objeto de la clase Word
		// word_ es el atributo string del objeto word de la clase Word...
		empty_ = word.empty_;
		return *this;
	}

	Word& Word::operator=(const char* word){
		word_ = word;
		empty_ = false;
		return *this;
	}

	bool Word::operator<(const Word& word)const{	// necesario, promete al compilador no tocar el word
		if(word_.size() != word.word_.size())
			return word_.size() < word.word_.size();

		for(int i = 0; i < word_.size(); i++)
			if(word_[i] != word.word_[i])
				return word_[i] < word.word_[i];
		
		return false;	// es la misma palabra
	}

	void Word::invert(void){
		char swapTemp;
		for(int i = 0; i < word_.size()/2; i++){
			swapTemp = word_[i];
			word_[i] = word_[word_.size() - 1 - i];
			word_[word_.size() - 1 - i] = swapTemp;
		}
	}

	std::string Word::obtString(void){
		return word_;
	}

	void Word::concatenate(Word w){
		if(!empty_)
			word_ += w.obtString();
		else
			word_ = w.obtString();
	}

	bool Word::operator==(const Word& w)const{
		if(word_.compare(w.word_) == 0)
			return true;
		else
			return false;
	}

	std::ostream& Word::write(std::ostream& os){
		os << word_;
		return os;
	}

	bool Word::isEmpty(void){
		return empty_;
	}
}