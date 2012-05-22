#include "dictionary.H"
#include "IFstream.H"
#include "IOstreams.H"
#include "vector.H"
#include "Switch.H"
#include "IOobject.H"


using namespace Foam;

int main()
{
	fileName file="testDict";
	IFstream infile(file);

    // Construct by IFstream
	dictionary dict(infile);

	// output table of contents
	Info << dict.toc() << endl;

    // read Switch
    Switch sw =  Switch(dict.lookup("readOrNot"));

	// read word
	word name = dict.lookup("name");  

	// read scalar
	scalar score = readScalar(dict.lookup("score"));

    // look up with  default option
    scalar score2 = dict.lookupOrDefault<scalar>("score2",0);   // if found, read. if not, score=0;

	// read vector
	vector direction = dict.lookup("direction");
    
    // test regular expression
    scalar something = readScalar(dict.lookup("something"));


	Info << "readOrNot:" << sw << nl 
         << "name: " << name << tab << "score:" << score << tab << "score2: " << score2 << nl
         << "direction: " << direction << tab << "something: " << something << endl;


    IOobject::writeDivider(Info);
    Info << "test subDict" << endl;

	// test subdict
	dictionary yangDict(dict.subDict("yang"));
	word yangName =  yangDict.lookup("name");
	label yangID = readInt(yangDict.lookup("ID"));  // readInt
	Info << "yang's name: " << yangName << tab << "yang's ID: " << yangID << endl;
    IOobject::writeDivider(Info);

    Info << nl << "Program ends." << endl;


	return 0;
}

