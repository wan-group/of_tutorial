#include "myLib.H"

namespace Foam
{

myLib::myLib()
:
    name_("none"),
    ID_(0),
	email_("none")
{
}

myLib::myLib(word name, label ID, word email)
:
    name_(name),
    ID_(ID),
	email_(email)	
{} 

myLib::myLib(dictionary dict)
:
	name_(dict.lookup("name")),
	ID_(readScalar(dict.lookup("ID"))),  // do not forget readScalar
	email_(dict.lookup("email"))
{}


myLib::~myLib()
{
    Info << name_ << " is killed " << endl;
}


Ostream& operator<<(Ostream& os, const myLib& ml)
{
    os << "name: " <<  ml.name_ << tab  << "ID: " << ml.ID_ 
	<<	tab << "email: " << ml.email_;
    return os;
}

} // namespace Foam
    





