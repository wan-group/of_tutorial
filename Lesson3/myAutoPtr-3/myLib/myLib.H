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
    word fullName_;
	word email_;

public:

    //  Constructor
    //myLib();
    
    myLib(word name="none", label ID=0, word fullName = "none", word email="none");

	// construct from dictionary
	myLib(word name, dictionary dict);

    myLib(const myLib& m1);

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

    const word& fullName() const
    {
        return fullName_;
    }

    void setName(word name)
	{
		name_ = name;
	}

    void setScore(label ID)
	{
		ID_ = ID;
	}

    void setFullName(word fullName)
    {
        fullName_ = fullName;
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
            word name(is); // it's necessary. read the name before the dict.
                             // e.g shen {...}  
                             // 'shen' will be input to 'name'
                             // so that the contents in { } will be read by dict next
			dictionary dict(is);
			return autoPtr<myLib>(new myLib(name, dict));
		}
	};

	// create a clone and return autoPtr
	autoPtr<myLib> clone() const
	{
        return autoPtr<myLib>(new myLib(*this));
	}

};
}

#endif
