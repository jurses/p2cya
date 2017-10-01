#ifndef	WORD_H
#define	WORD_H

#include <string>
#include <cmath>
#include "alphabet.hpp"

namespace CYA{
	class Word{
	private:
		std::string word_;
		bool empty_;	// indica si es la cadena vacía
	public:
		Word();
		Word(const Alphabet);
		Word& operator=(const char*);
		Word& operator=(const Word&);
		bool operator==(Word&);
		const char* obtWord(void);
		bool operator<(const Word&);
		void concatenate(Word&);
		void invert(void);

		std::string obtString(void);
	};
}


#endif	// WORD_H	