#ifndef MYLIB_H
#define MYLIB_H

#include "word.H"
#include "scalar.H"
#include "Ostream.H"
#include "messageStream.H"

namespace Foam
{
class myLib
{

private:
    word name_;  // string
    scalar score_;  // double or float
public:

    //  Constructor
    myLib();
    
    myLib(word name, scalar score);

    ~myLib();

    const word& name() const;

    const scalar& score() const;

    void setName(word name);

    void setScore(scalar score);

    friend Ostream& operator<<(Ostream& os, const myLib& ml);

};
}

#endif
