#ifdef GROUP_H // do not forget
#define GROUP_H

#include "myLib.H"
#include "PtrList.H"
#include "IOdictionary.H"
#include "messageStream.H"

class group
{
    private:
        const fvMesh& mesh_;
        const IOdictionary& dict_;
        PtrList<myLib> group_;

    public:

        // construct from fvMesh
        group(const fvMesh& mesh_);

        // display all group members' names
        void displayName();

        // display all group members' IDs
        void displayID();

        // display all group members' emails
        void displayEmail();

}


        



#endif
