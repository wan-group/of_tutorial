#include "fvCFD.H"
#include "myLib.H"
#include "PtrList.H"
#include "IOdictionary.H"

	
/* --------------------------------------------------------------------------*/
/**
 * @Description: 
 *
 *		autoPtr is not recommended to be used as a parameter of a function,
 *		because it will be cleared after transfering.
 *		But we can use operator() to return the reference, which can be used
 *		as a parameter.
 *
 *      Note: pay attention to when and where the output information of 
 *      the destructor of class  myLib (... is killed) prints.
 */
/* ----------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{

	void test1(autoPtr<myLib>);   // transfer autoPtr
	void test2(myLib&);           // transfer reference

	Info << "Test begin:" << nl << endl;

	autoPtr<myLib> p1(new myLib("shen"));
	autoPtr<myLib> p2(new myLib("wang"));

	test1(p1);  // use autoPtr as parameter
	test2(p2()); // use reference as parameter

	Info << "after transfering " << endl;

	//Info << p1 << endl;  // error, p1 is cleared.
	Info << p2 << endl;   // Ok. p2 remains unchanged.

    Info << nl << "Program ends" << nl << endl;

    return 0;
}

// transfer p1 as autoPtr
void test1(autoPtr<myLib> p1)
{
	// display name
	Info << nl << "name: " << p1->name() << endl;
}

// transfer p1 as reference
void test2(myLib& p1)
{
	// display name
	Info << nl << "name: " << p1.name() << endl;
}

