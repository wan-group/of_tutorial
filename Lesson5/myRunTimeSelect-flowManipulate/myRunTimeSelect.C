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

    volScalarField alpha
    (
        IOobject
        (
            "alpha",
            runTime.timeName(),
            mesh,
            IOobject::MUST_READ,
            IOobject::AUTO_WRITE
        ),
        mesh
    );

	autoPtr<method> m1(method::New(mesh));  // use New() to select methods
	// dictionary is in constant/methodDict

	m1->correct();  // run correct() of selected method.

    alpha.write();

    Info << nl << "Program ends" << nl << endl;

    return 0;
}


