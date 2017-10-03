#ifndef	WORD_H
#define	WORD_H

#include <string>
#include <cmath>
#include <ostream>
#include "alphabet.hpp"

namespace CYA{
	class Word{
	private:
		Alphabet alphabet_;
		std::string word_;
		bool empty_;	// indica si es la cadena vacía
	public:
		Word();
		Word(const Alphabet&);
		Word(const Word&);
		Word& operator=(const char*);
		Word& operator=(const Word&);
		bool operator==(const Word&)const;
		const char* obtWord(void);
		bool operator<(const Word&)const;
		void concatenate(Word);
		void invert(void);

		std::ostream& write(std::ostream&);
		std::string obtString(void);
	};
}


#endif	// WORD_H	