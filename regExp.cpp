#include "regExp.hpp"

namespace CYA{
    RegExp& RegExp::operator=(std::string& newRE){
        re_ = newRE;
        parcialLangGen_.clear();
        //calculateLangGen();

        return *this;
    }

    std::string& RegExp::obtRE(void){
        return re_;
    }

    std::ostream& RegExp::write(std::ostream& os){
        os << re_;
        return os;
    }
}
