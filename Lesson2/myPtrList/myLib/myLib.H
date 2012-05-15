#ifndef MYLIB_H
#define MYLIB_H

#include "word.H"
#include "label.H"
#include "Ostream.H"
#include "messageStream.H"
#include "dictionary.H"

namespace Foam
{
class myLib
{

private:
    word name_;  // string
    label ID_;   // int

public:

    //  Constructor
    myLib();
    
    myLib(word name, label ID);

	myLib(dictionary dict);

    ~myLib();

    const word& name() const;

    const label& ID() const;

    void setName(word name);

    void setScore(label ID);

    friend Ostream& operator<<(Ostream& os, const myLib& ml);

	/*
	class iNew
	{
		private:

		public:
		iNew()
		{}

		autoPtr<myLib> operator()(Istream& is) const
		{
			word member(is);
			dictionary dict(is);
			return autoPtr<myLib>(new myLib(member, dict));
		}
	};

	autoPtr<myLib> clone() const
	{
		notImplemented("autoPtr<myLib> myLib::clone() const");
		return autoPtr<myLib>(NULL);
	}
	*/

};
}

#endif
