#include "fvCFD.H"
#include "myLib.H"
#include "group.H"
#include "PtrList.H"
#include "IOdictionary.H"

int main(int argc, char* argv[])
{

	// ------
	//  create PtrList from dictionary
	// ------
	
	#include "setRootCase.H"
	#include "createTime.H"
	#include "createMesh.H"

    group g1(mesh);

	Info << nl <<  "Display member name:" << endl;

    g1.displayName();

	Info << nl << "Display member ID:" << endl;

    g1.displayID();

    Info << nl << "Display member email: " << endl;

    g1.displayEmail();

    Info << nl << "Program ends" << nl << endl;


    return 0;
}
