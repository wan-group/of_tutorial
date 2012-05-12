#include "myLib.H"

namespace Foam
{

myLib::myLib()
:
    name_("none"),
    ID_(0)
{
}

myLib::myLib(word name, label ID)
:
   name_(name),
   ID_(ID)
{} 

myLib::myLib(word member, dictionary dict)
:
	name_(dict.lookup("name")),
	ID_(readScalar(dict.lookup("ID")))
{}


myLib::~myLib()
{
    Info << "I'm killed " << endl;
}

const word& myLib::name() const
{
    return name_;
}

const label& myLib::ID() const
{
    return ID_;
}

void myLib::setName(word name)
{
    name_=name;
}

void myLib::setScore(label ID)
{
    ID_=ID;
}

Ostream& operator<<(Ostream& os, const myLib& ml)
{
    os << "name: " <<  ml.name_ << tab  << "ID: " << ml.ID_ ;
    return os;
}

} // namespace Foam
    





