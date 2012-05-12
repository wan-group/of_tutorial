#include "myLib.H"

namespace Foam
{

myLib::myLib()
:
    name_("none"),
    score_(0)
{
}

myLib::myLib(word name, scalar score)
:
   name_(name),
   score_(score)
{} 

myLib::~myLib()
{
    Info << " I'm killed " << endl;
}

const word& myLib::name() const
{
    return name_;
}

const scalar& myLib::score() const
{
    return score_;
}

void myLib::setName(word name)
{
    name_=name;
}

void myLib::setScore(scalar score)
{
    score_=score;
}

Ostream& operator<<(Ostream& os, const myLib& ml)
{
    os << "name: " <<  ml.name_ << tab  << "score: " << ml.score_ ;
    return os;
}

} // namespace Foam
    





