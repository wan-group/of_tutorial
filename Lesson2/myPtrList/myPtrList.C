#include "fvCFD.H"
#include "myLib.H"
#include "PtrList.H"

int main(int argc, char* argv[])
{
    PtrList<myLib> ptl(3);			 // create a list with three pointers to myLib class
    ptl.set(0,new myLib("shen",101));  // create a pointer to a myLib class as the first element of ptl
    ptl.set(1,new myLib("ye",102));
    ptl.set(2,new myLib("liu",103));

    PtrList<myLib>& ptl2=ptl;  // create a reference to the list

	Info << "ptl " <<endl;  
    forAll(ptl, i)  // output list
    {
        Info << ptl[i] << endl;
    }

	Info << "resize to 2" << endl;  // resize the list and remove the last one

    ptl.setSize(2);

	Info << "ptl " <<endl;
    Info << ptl << endl;
	Info << "ptl2" <<endl; // output the reference
    Info << ptl2 << endl; // output is the same

    return 0;
}
