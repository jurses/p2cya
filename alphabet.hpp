#ifndef ALPHABET_H
#define ALPHABET_H

#include <set>
#include <cassert>

namespace CYA{
	class Alphabet{
	private:
		std::set<char> setAlphab_;
	public:
		void insert(const char);
		const std::set<char> obtSet(void);
		Alphabet& operator=(const Alphabet&);
	};
}

#endif	// ALPHABET_H