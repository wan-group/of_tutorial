#include "group.H"

namespace Foam
{
group::group(const fvMesh& mesh)
:
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
    ),
    group_
    (
         dict_.lookup("group"),
         myLib::iNew()
    )
{}

void group::displayName()
{
    forAll(group_, i)
    {
        Info << group_[i].name() << endl;
    }
}

void group::displayID()
{
    forAll(group_, i)
    {
        Info << group_[i].ID() << endl;
    }
}

void group::displayEmail()
{
    forAll(group_, i)
    {
        Info << group_[i].email() << endl;
    }
}
}
