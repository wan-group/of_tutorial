#include"method.H"

namespace Foam
{

	defineRunTimeSelectionTable(method, dictionary);

	defineTypeNameAndDebug(method,0);

	method::method(const fvMesh& mesh)
	:
		IOdictionary
		(
			IOobject
			(
				"methodDict",
				mesh.time().constant(),
				mesh,
				IOobject::MUST_READ,
				IOobject::NO_WRITE
			)
		),
		mesh_(mesh),
		type_(lookup("type")),
		value_(0)
	{
	}

	autoPtr<method> method::New(const fvMesh& mesh)
	{
		const word type = IOdictionary
		(
			IOobject
			(
				"methodDict",
				mesh.time().constant(),
				mesh,
				IOobject::MUST_READ,
				IOobject::NO_WRITE
			)
		).lookup("type");

		dictionaryConstructorTable::iterator cstrIter =
			dictionaryConstructorTablePtr_->find(type);

		// if not found
		if(cstrIter == dictionaryConstructorTablePtr_->end())
		{
			FatalErrorIn("method::New(const fvMesh& mesh)") 
				<< "Unknown method type" << type  << endl
				<< "Valid method types are " << endl
				<< dictionaryConstructorTablePtr_->toc()
				<< exit(FatalError);
		}

		Info << endl << endl << type << " is selected. " << endl << endl;

		return autoPtr<method>(cstrIter()(mesh));

	}




}


