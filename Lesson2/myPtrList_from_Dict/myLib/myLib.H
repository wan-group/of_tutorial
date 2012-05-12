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
	word email_;

public:

    //  Constructor
    myLib();
    
    myLib(word name, label ID, word email="none");

	// construct from dictionary
	myLib(dictionary dict);

    ~myLib();

	// inline function is better
    const word& name() const
	{
		return name_;
	}

    const label& ID() const
	{
		return ID_;
	}

	const word& email() const  
	{
		return email_;
	}

    void setName(word name)
	{
		name_ = name;
	}

    void setScore(label ID)
	{
		ID_ = ID;
	}

	void setEmail(word email)
	{
		email_ = email;
	}

    friend Ostream& operator<<(Ostream& os, const myLib& ml);

	
	/* ----------------------------------------------------*/
	/**
	 * @Description: iNew class is requied by PtrList. It's important
	 */
	/* ----------------------------------------------------*/
	class iNew
	{
		private:

		public:
		iNew()
		{}

		/* -------------------------------------------------*/
		/**
		 * @Description: used by constructor of PtrList
		 *
		 * @Param Istream& is (do not change)
		 *
		 * @Returns  autoPtr<myLib> (an automatic pointer to myLib class) 
		 */
		/* -------------------------------------------------*/
		autoPtr<myLib> operator()(Istream& is) const
		{
			word member(is);
			dictionary dict(is);
			return autoPtr<myLib>(new myLib(dict));
		}
	};

	// required by PtrList, but does nothing here.
	autoPtr<myLib> clone() const
	{
		notImplemented("autoPtr<myLib> myLib::clone() const");
		return autoPtr<myLib>(NULL);
	}

};
}

#endif
