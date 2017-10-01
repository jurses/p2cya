#ifndef REGEXP_H
#define REGEXP_H

#include <string>
#include <ostream>

namespace CYA{
	class RegExp{
	private:
		std::string re_;
		std::string parcialLangGen_;
		void calculateLangGen(void);
	public:
		std::ostream& sample(std::ostream&);
		std::string obtRE(void);
		std::string obtPLG(void);
	};
}

#endif	// REGEXP_H