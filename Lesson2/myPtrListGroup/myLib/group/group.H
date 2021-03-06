#ifndef GROUP_H // do not forget
#define GROUP_H

#include "myLib.H"
#include "PtrList.H"
#include "IOdictionary.H"
#include "messageStream.H"
#include "fvMesh.H"
#include "Time.H"

namespace Foam
{
class group
:
    public  PtrList<myLib>
{
    private:
        const fvMesh& mesh_;
        IOdictionary dict_;

    public:

        // construct from fvMesh
        group(const fvMesh& mesh);

        // display all group members' names
        void displayName();

        // display all group members' IDs
        void displayID();

        // display all group members' emails
        void displayEmail();

};
}

#endif
