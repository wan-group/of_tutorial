#include"method2.H"
#include"addToRunTimeSelectionTable.H"

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
		p1_(readScalar(dict_.lookup("p1"))),
		p2_(readScalar(dict_.lookup("p2"))),
		p3_(readScalar(dict_.lookup("p3"))),
		sum_(0),
		mean_(0)
	{
	}

	void method2::correct()
	{
		sum_ = (p1_ + p2_ + p3_);
		mean_ = mean_/3.0;
		Info << "typeName: " << typeName << endl;
		Info << "p1: " << p1_ << endl
		    << "p2: " << p2_ << endl
		    << "p3: " << p3_ << endl
		    << "sum: " << sum_ << endl
		    << "mean: " << mean_ << endl;


		// do something ...
		//
	}

}


