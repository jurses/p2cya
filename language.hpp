#ifndef	LANGUAGE_H
#define LANGUAGE_H

#include "word.hpp"
#include "regExp.hpp"
#include <set>
#include <string>
#include <iostream>

namespace CYA{
	class Language{
	private:
		std::set<Word> setWords_;
		RegExp regularExpression_;
		bool prodByRE_;	// Indica si este lenguaje es producido por una E.R. dada por el usuario
						// quedará desfasado este atributo
		bool empty_;
		void powerR(int);
	public:
		Language();
		std::istream& define(std::istream&);
		void invert(void);
		void concatenate(Language);
		void unite(Language&);
		void difference(Language&);
		void intersection(Language&);
		Language& operator=(const Language&);
		bool subLanguage(Language&);
		bool equality(Language&);
		void power(int);
		void kleenStar(void);
	};
}

#endif	// LANGUAGE_H