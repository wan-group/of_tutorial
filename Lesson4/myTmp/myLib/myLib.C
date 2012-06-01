#include "myLib.H"

namespace Foam
{


myLib::myLib(word name, label ID, word fullName, word email)
:
    refCount(),
    name_(name),
    ID_(ID),
    fullName_(fullName),
	email_(email)	
{
} 

myLib::myLib(word name, dictionary dict)
:
    refCount(),
    name_(name),
	ID_(readScalar(dict.lookup("ID"))),  // do not forget readScalar
    fullName_(dict.lookup("fullName")),
	email_(dict.lookup("email"))
{
}

myLib::myLib(const myLib& m)
:
    refCount(),
    name_(m.name_),
    ID_(m.ID_),
    fullName_(m.name_),
    email_(m.email_)
{
    Info << name_ << " is copied!" << endl;
}


myLib::~myLib()
{
    Info << name_ << " is killed " << endl;
}


Ostream& operator<<(Ostream& os, const myLib& ml)
{
    os << "name: " <<  ml.name_ << tab  << "ID: " << ml.ID_ 
	<<	tab << "full name: " << ml.fullName_ 
	<<	tab << "email: " << ml.email_;
    return os;
}

} // namespace Foam
    





