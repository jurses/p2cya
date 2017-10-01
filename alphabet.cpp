#include "alphabet.hpp"

namespace CYA{
	const std::set<char> Alphabet::obtSet(void){
		assert(!setAlphab_.empty());	// el alfabeto no puede estar vacío
		return setAlphab_;
	}

	void Alphabet::insert(const char w){
		setAlphab_.insert(w);
	}
}