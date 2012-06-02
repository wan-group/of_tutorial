#ifndef METHOD1_H
#define METHOD1_H

#include"method.H"
#include"scalar.H"

namespace Foam
{

class method1
:
	public method
{		

	private:

		dictionary dict_;

		scalar num1_, num2_;

		//- Disallow default bitwise copy construct
        method1(const method1&);

        //- Disallow default bitwise assignment
        void operator=(const method1&);


	public:

		TypeName("method1");

		

		// contructor 
		method1(const fvMesh& mesh);

		// run method
		virtual void correct();

};



}// namespace Foam

#endif
