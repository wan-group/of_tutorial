#include "fvCFD.H"
#include "myLib.H"
#include "PtrList.H"
#include "IOdictionary.H"

int main(int argc, char* argv[])
{

	Info << "Test begin" << endl;

	// construct from name and ID
	autoPtr<myLib> aptr(new myLib("shen",101));

	// set full name
	aptr->setFullName("Zhirong_Shen");  // operator-> is just like normal pointer
	
	// set email
	aptr().setEmail("zrshen.sjtu@gmail.com");   // operator() returns reference of the object

	Info << aptr() << endl;

    Info << nl << "Program ends" << nl << endl;

    return 0;
}
