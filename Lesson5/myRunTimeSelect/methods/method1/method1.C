#include"method1.H"
#include"addToRunTimeSelectionTable.H"

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
		num1_(readScalar(dict_.lookup("num1"))),
		num2_(dict_.lookupOrDefault<scalar>("num2",num1_))
	{
	}

	void method1::correct()
	{
		Info << "typeName: " << typeName << endl;
		Info << "num1: " << num1_ << endl
			<< "num2: " << num2_ << endl;

		// do something ...
		//
	}

}


