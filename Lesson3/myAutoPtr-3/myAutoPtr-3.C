#include "fvCFD.H"
#include "myLib.H"
#include "PtrList.H"
#include "IOdictionary.H"

	
/* --------------------------------------------------------------------------*/
/**
 * @Description: 
 *
 *  after copy, the original autoPtr is cleared
 *  and new autoPtr points to the object which the original autoPtr points
 */
/* ----------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{

	Info << "Test begin:" << nl << endl;

	autoPtr<myLib> p1(new myLib("shen", 101));

	autoPtr<myLib> p2=p1;  // p1 is clear. p2 points to myLib
    autoPtr<myLib> p3=p2->clone();  // clone an autoPtr<myLib>

	//Info << p1 << nl; // error, because p1 is cleared
	Info << p2 << nl;   // p2 points to myLib("shen",101)
    Info << p3 << nl;



    Info << nl << "Program ends" << nl << endl;

    return 0;
}
