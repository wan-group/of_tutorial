#include "group.H"

namespace Foam
{
group::group(const fvMesh& mesh)
:
    PtrList<myLib>(),
    mesh_(mesh),
    dict_
    (
         IOobject
         (
              "testDict",
              mesh_.time().constant(),
              mesh_,
              IOobject::MUST_READ,
              IOobject::NO_WRITE,
              true
         )
    )
{
    PtrList<myLib> newGroup
    (
         dict_.lookup("group"),
         myLib::iNew()
    );
    transfer(newGroup);
}

void group::displayName()
{
    forAll(*this, i)
    {
        Info << (*this)[i].name() << endl;
    }
}

void group::displayID()
{
    forAll(*this, i)
    {
        Info << (*this)[i].ID() << endl;
    }
}

void group::displayEmail()
{
    forAll(*this, i)
    {
        Info << (*this)[i].email() << endl;
    }
}
}
