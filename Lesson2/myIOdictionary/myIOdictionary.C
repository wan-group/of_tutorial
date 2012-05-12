#include "dictionary.H"
#include "IFstream.H"
#include "IOstreams.H"
#include "vector.H"
#include "IOdictionary.H"
#include "argList.H"  // required by setRootCase.H
#include "Time.H"     // required by createTime.H
#include "fvMesh.H"


using namespace Foam;

int main(int argc, char* argv[])  // argc and argv are needed by setRootCase.H
{
	void testRegistry(const fvMesh& mesh);
	#include "setRootCase.H" // create args defined by createTime
	#include "createTime.H"
	#include "createMesh.H"

	IOdictionary dict
	(
		IOobject
		(
			"testDict",  // name
			runTime.constant(),  // path (in constant/)
			mesh,  // register --> fvMesh
			IOobject::MUST_READ,   // read option
			IOobject::NO_WRITE,    // write option
			true                   // register or not
		)
	);

	// output table of contents
	Info << dict.toc() << endl;

	// read word
	word name = dict.lookup("name");  

	// read scalar
	scalar score = readScalar(dict.lookup("score"));

	// read vector
	vector direction = dict.lookup("direction");

	Info << "name: " << name << tab << "score:" << score << tab << "direction: " << direction<< endl;


	// test subdict
	dictionary yangDict(dict.subDict("yang"));
	word yangName =  yangDict.lookup("name");
	label yangID = readInt(yangDict.lookup("ID"));  // readInt
	Info << "yang's name: " << yangName << tab << "yang's ID: " << yangID << endl;
	Info << nl << "end." << endl;


	// test registry
	IOobject::writeDivider(Info);  // output diverder 

	testRegistry(mesh);

	return 0;
}

void testRegistry(const fvMesh& mesh)
{

	Info << nl << "test registry lookup" << endl;

	IOdictionary dictNew = mesh.lookupObject<IOdictionary>("testDict");

	Info << dictNew << endl;

}

