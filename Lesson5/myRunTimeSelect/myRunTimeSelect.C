#include "fvCFD.H"
#include "method.H"  // header file of base class
	
/* --------------------------------------------------------------------------*/
/**
 * @Description: 
 *
 *
 * @Reference:
 *
 *   http://openfoamwiki.net/index.php/OpenFOAM_guide/runTimeSelection_mechanism
 *  
 */
/* ----------------------------------------------------------------------------*/
int main(int argc, char* argv[])
{

#include "setRootCase.H"
#include "createTime.H"
#include "createMesh.H"

	Info << "Test begin:" << nl << endl;

	autoPtr<method> m1(method::New(mesh));  // use New() to select methods

	m1->correct();  // run correct() of selected method.

    Info << nl << "Program ends" << nl << endl;

    return 0;
}


