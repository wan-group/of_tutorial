#include"method1.H"
#include"addToRunTimeSelectionTable.H"
#include"dimensionedTypes.H"
#include"primitiveFieldsFwd.H"
#include"volFieldsFwd.H"
#include"pointFieldsFwd.H"
#include"surfaceFieldsFwd.H"
#include"polyMesh.H"

#include"fvCFD.H"  // cannot find the suitable header files...

namespace Foam
{

	defineTypeNameAndDebug(method1,0);

	// add to runtime constructor selection table
	addToRunTimeSelectionTable
	(
		method,  // baseType
		method1,  // this type (derived)
		dictionary
	);

	method1::method1(const fvMesh& mesh)
	:
		method(mesh),
		dict_(this->subDict(typeName + "Coeffs")),  // typeName return method1 (in method1.H, TypeName("method1");)
		r_(readScalar(dict_.lookup("r")))
	{
	}

	void method1::correct()
	{
		Info << "typeName: " << typeName << endl;
        Info << " a = (r^2-x^2-y^2)^0.5" << endl;
        Info << "r: " << r_ << endl;

        volScalarField& alpha = const_cast<volScalarField&>(mesh_.lookupObject<volScalarField>("alpha"));  // const_cast: convert const type to non-const

        dimensionedScalar r 
        (
            "r",
            dimensionSet(0,1,0,0,0,0,0),
            r_
        );


        // pay attention to the dimensionSets, which must be equal on two sides of equation
        alpha =  Foam::sqr(r)
             - Foam::sqr(mesh_.C().component(vector::X))
             - Foam::sqr(mesh_.C().component(vector::Y));

		// do something ...
		//
	}

}


