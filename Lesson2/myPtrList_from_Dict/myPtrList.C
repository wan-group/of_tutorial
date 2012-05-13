#include "fvCFD.H"
#include "myLib.H"
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

	IOdictionary dict
	(
		IOobject
		(
			"testDict",
			runTime.constant(),
			mesh,
			IOobject::MUST_READ,
			IOobject::NO_WRITE,
			true
		)
	);

	PtrList<myLib> ptl3
	(
		dict.lookup("group"),
		myLib::iNew()
	);

	Info << ptl3 << endl;

	Info << nl <<  "Display member name:" << endl;

	forAll(ptl3, i)
	{
		Info << ptl3[i].name() << endl;
	}

	Info << nl << "Display member ID:" << endl;

	forAll(ptl3, i)
	{
		Info << ptl3[i].ID() << endl;
	}

    return 0;
}
