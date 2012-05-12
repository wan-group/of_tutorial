#include "fvCFD.H"
#include "myLib.H"

int main()
{
    Info << "hello world! " << endl;
    myLib st;
    st.setName("yang");
    st.setScore(59);
    Info << st << endl;
    return 0;
}
