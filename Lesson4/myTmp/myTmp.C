#include "fvCFD.H"
#include "myLib.H"
#include "PtrList.H"
#include "IOdictionary.H"

	
/* --------------------------------------------------------------------------*/
/**
 * @Description: 
 *
 *   tmp  is a wrapper class that allows large local objects to be returned
 *   from functions / methods without being copied. It also allows a program 
 *   to quickly clear a large object out of memory, which can be used to 
 *   reduce the peak memory. tmp works in the background and is not usually 
 *   visible at the top­level code.
 *
 * @Reference:
 *
 *   http://openfoamwiki.net/index.php/OpenFOAM_guide/tmp
 *  
 */
/* ----------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{

	Info << "Test begin:" << nl << endl;


    // allocate memory for new object by using tmp
    tmp<myLib> p1(new myLib("by_tmp",1001));

<<<<<<< HEAD
    // Note: tmp<Type> uses class refCount to count the number of references.
    // So, Type (here myLib) must be derived type of refCount so that Type can
    // use the member functions of refCount which is required by tmp<Type> template.

=======
>>>>>>> eae145017851255586f59561634c9ab135b65f48
    // p1 & p2 share the same object.
    // p2 just copy the pointer and reference from p1
    tmp<myLib> p2(p1);

    // p1, p2 share the same object
    Info << p1 << endl;
    Info << p2 << endl;

    IOobject::writeDivider(Info);
    
    // allocate memory for new obj by normal method
    myLib p0("normal",1002);

    for (int i=0; i<3; i++)
    {
        Info << nl << "Loop #" << i << endl;
        tmp<myLib> p4(p1);  // share the same obj as p1
        myLib p5(p0);       // copy a new obj from p0. 
        Info << p4() << endl;  // () return reference
        Info << p5 << endl;

        // the obj p5 points to is allocated and deallocated in each loop
        // while p4 just redirects its pointer and the obj remains unchanged.
        // Pay attention to the output info of constructor and destructor of myLib
    }

    IOobject::writeDivider(Info);

    // USAGE:
    // tmp is usually used as return type of a function
    // to avoid running copy constructor and destructor of obj
    tmp<myLib> myFunc(const word&); // return tmp<myLib>

    Info << myFunc("myFunc")().name() << endl; // myFunc() returns tmp<T> and the subsequence () 

    Info << nl << "Program ends" << nl << endl;

    return 0;
}

tmp<myLib> myFunc(const word& name)
{
    tmp<myLib> m(new myLib(name));
    return m;
}

