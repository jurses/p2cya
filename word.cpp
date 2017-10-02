#include "word.hpp"

namespace CYA{
	Word::Word(){
		word_.resize(0);
		empty_ = true;
	}

	Word::Word(const Alphabet& A)
	{
		alphabet_ = A;
	}

	Word::Word(const Word& w){
		alphabet_ = w.alphabet_;
		word_ = w.word_;
		empty = w.empty_;
	}

	const char* Word::obtWord(void){
		return word_.c_str();
	}

	Word& Word::operator=(const Word& word){
		word_ = word.word_;	// qué lío ;-)
		// Word es la clase
		// word es el objeto de la clase Word
		// word_ es el atributo string del objeto word de la clase Word...

		return *this;
	}

	Word& Word::operator=(const char* word){
		word_ = word;
		return *this;
	}

	bool Word::operator<(const Word& word){
		if(word_.size() == word.word_.size()){
			long int s1 = 0, s2 = 0;
			for(int i = 0; i < word_.size(); i++)
				s1 += pow((int)word_[i], i + 1);
			
			for(int i = 0; i < word.word_.size(); i++)
				s2 += pow((int)word.word_[i], i + 1);

			return s1 < s2;
		}
		else
			return word_.size() < word.word_.size();
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
		word_ += w.obtString();
	}

	bool Word::operator==(Word& w){
		if(word_.compare(w.word_) == 0)
			return true;
		else
			return false;
	}

	std::ostream& Word::write(std::ostream& os){
		os << word_;
		return os;
	}
}