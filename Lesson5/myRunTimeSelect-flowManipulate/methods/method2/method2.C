#include"method2.H"
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

	defineTypeNameAndDebug(method2,0);

	// add to runtime constructor selection table
	addToRunTimeSelectionTable
	(
		method,  // baseType
		method2,  // this type (derived)
		dictionary
	);

	method2::method2(const fvMesh& mesh)
	:
		method(mesh),
		dict_(this->subDict(typeName + "Coeffs")),  // typeName return method2 (in method2.H, TypeName("method2");)
		a_(readScalar(dict_.lookup("a"))),
		b_(readScalar(dict_.lookup("b")))
	{
	}

	void method2::correct()
	{
		Info << "typeName: " << typeName << endl;
        Info << " alpha = a^2*b^2-b^2*x^2-a^2*y^2" << endl;
        Info << "a: " << a_ << endl;
        Info << "b: " << b_ << endl;

        volScalarField& alpha = const_cast<volScalarField&>(mesh_.lookupObject<volScalarField>("alpha"));

        dimensionedScalar a 
        (
            "a",
            dimensionSet(0,1,0,0,0,0,0),
            a_
        );

        dimensionedScalar b
        (
            "b",
            dimensionSet(0,1,0,0,0,0,0),
            b_
        );

        Info << "here" << endl;

        // pay attention to the dimensionSets, which must be equal on two sides of equation
        alpha = Foam::sqr(a)
            - Foam::sqr(mesh_.C().component(vector::X))
            - Foam::sqr(a/b*mesh_.C().component(vector::Y));

		// do something ...
		//
	}

}


