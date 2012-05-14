/**
 * @file myIOdictionary.C
 * @Description: test class IOdictionary
 * @author Zhirong Shen <zrshen.sjtu@gmail.com>
 * @version 0.10
 * @date 2012-05-14
 */

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
	void testRegistry(const fvMesh& mesh);  // function declaration

	#include "setRootCase.H" // create args defined by createTime
	#include "createTime.H"  // required by createMesh.H
	#include "createMesh.H"  // to initialize mesh (class fvMesh)

	IOdictionary dict
	(
		IOobject
		(
			"testDict",  // name
			runTime.constant(),  // path (constant/)
			mesh,  // register --> class fvMesh
			IOobject::MUST_READ,   // read option
			IOobject::NO_WRITE,    // write option
			true                   // register or not  (default is true)
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


    // regular expression
    scalar something = readScalar(dict.lookup("somethign"));

	Info << "name: " << name << tab << "score:" << score << tab << "direction: " << direction<< tab << "something: " << something <<endl;


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

/* --------------------------------------------------------------------------*/
/**
 * @Description: Try to use registry to find loookupObject
 *
 * @Param fvMesh& mesh, the registry
 */
/* ----------------------------------------------------------------------------*/
void testRegistry(const fvMesh& mesh)
{

	Info << nl << "test registry lookup" << endl;

	const IOdictionary& refDict = mesh.lookupObject<IOdictionary>("testDict");  //find testDict and return reference of testdict "must be const reference"
    IOdictionary newDict = mesh.lookupObject<IOdictionary>("testDict"); // find testDict and create a copy 

	Info << "refDict:" << nl << refDict << endl
       << "newDict:" << nl << newDict << endl;

}

