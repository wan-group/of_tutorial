#include "fvCFD.H"
#include "myLib.H"
#include "PtrList.H"
#include "IOdictionary.H"

int main(int argc, char* argv[])
{

	Info << "Test begin" << endl;

	// autoPtr will automatcially delete the object when each loop is over
	// while the normal pointer deletes it when the program ends
	
	for( int i=0; i<3; i++)
	{
		Info << "Loop: " << i << endl;
		autoPtr<myLib> m1(new myLib("autoPtr",101));
		myLib* m2 = new myLib("normal", 102);
	}


    Info << nl << "Program ends" << nl << endl;

    return 0;
}
