#include "dictionary.H"
#include "IFstream.H"
#include "IOstreams.H"
#include "vector.H"

using namespace Foam;

int main()
{
	fileName file="testDict";
	IFstream infile(file);

    // Construct by IFstream
	dictionary dict(infile);

	// output table of contents
	Info << dict.toc() << endl;

	// read word
	word name = dict.lookup("name");  

	// read scalar
	scalar score = readScalar(dict.lookup("score"));

	// read vector
	vector direction = dict.lookup("direction");
    
    // test regular expression
    scalar something = readScalar(dict.lookup("something"));

	Info << "name: " << name << tab << "score:" << score << tab << "direction: " << direction << tab << "something: " << something << endl;


	// test subdict
	dictionary yangDict(dict.subDict("yang"));
	word yangName =  yangDict.lookup("name");
	label yangID = readInt(yangDict.lookup("ID"));  // readInt
	Info << "yang's name: " << yangName << tab << "yang's ID: " << yangID << endl;


	return 0;
}

