#include "fvCFD.H"
#include "myLib.H"
#include "PtrList.H"

int main(int argc, char* argv[])
{
    PtrList<myLib> ptl(3);			 // create a list with three pointers to myLib class
    ptl.set(0,new myLib("shen",101));  // create a pointer to a myLib class as the first element of ptl
    ptl.set(1,new myLib("shen",102));
    ptl.set(2,new myLib("shen",103));

    PtrList<myLib>& ptl2=ptl;  // only reference available

	Info << "ptl " <<endl;
    forAll(ptl, i)
    {
        Info << ptl[i] << endl;
    }

	Info << "resize to 2" << endl;

    ptl.setSize(2);

	Info << "ptl " <<endl;
    Info << ptl << endl;
	Info << "ptl2" <<endl;
    Info << ptl2 << endl; // output is the same

    return 0;
}
