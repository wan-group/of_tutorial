#include "myLib.H"

namespace Foam
{

//myLib::myLib()
//:
    //name_("none"),
    //ID_(0),
    //fullName_("none"),
	//email_("none")
//{
//}

myLib::myLib(word name, label ID, word fullName, word email)
:
    name_(name),
    ID_(ID),
    fullName_(fullName),
	email_(email)	
{} 

myLib::myLib(word name, dictionary dict)
:
    name_(name),
	ID_(readScalar(dict.lookup("ID"))),  // do not forget readScalar
    fullName_(dict.lookup("fullName")),
	email_(dict.lookup("email"))
{}

myLib::myLib(const myLib& m1)
:
    name_(m1.name_),
    ID_(m1.ID_),
    fullName_(m1.fullName_),
    email_(m1.email_)
{}

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
    





