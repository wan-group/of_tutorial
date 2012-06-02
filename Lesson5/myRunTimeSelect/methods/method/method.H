#ifndef METHOD_H
#define METHOD_H

#include"IOdictionary.H"
#include"autoPtr.H"
#include"fvMesh.H"
#include"Time.H"
#include"fieldTypes.H"
#include"word.H"
#include"runTimeSelectionTables.H"

namespace Foam
{

class method
:
	public IOdictionary
{		
	protected:

		const fvMesh& mesh_;
		word type_;
		scalar value_;

	private:

		//- Disallow default bitwise copy construct
        method(const method&);

        //- Disallow default bitwise assignment
        void operator=(const method&);


	public:

		TypeName("method");

		// declare runtime constructor selection table
		declareRunTimeSelectionTable
		(
			autoPtr,
			method,
			dictionary,
			(
				const fvMesh& mesh
			),
			(mesh)
		);
		

		// contructor 
		method(const fvMesh& mesh);

		// selector
		static autoPtr<method> New(const fvMesh& mesh);

		const word& name() const
		{
			return type_;
		}

		// run method
		virtual void correct() = 0;

};



}// namespace Foam

#endif
