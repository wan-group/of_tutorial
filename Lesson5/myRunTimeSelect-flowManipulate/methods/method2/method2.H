#ifndef METHOD1_H
#define METHOD1_H

#include"method.H"
#include"primitiveFields.H"

namespace Foam
{

class method2
:
	public method
{		

	private:

		dictionary dict_;

		scalar a_, b_;

		//- Disallow default bitwise copy construct
        method2(const method2&);

        //- Disallow default bitwise assignment
        void operator=(const method2&);


	public:

		TypeName("method2");

		

		// contructor 
		method2(const fvMesh& mesh);

		// run method
		virtual void correct();

};



}// namespace Foam

#endif
