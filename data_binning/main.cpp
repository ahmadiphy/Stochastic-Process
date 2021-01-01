#include <iostream>
#include "in.h"
#include "fread.h"
#include "hist.h"

using namespace std;

int main()
{
    //==
    struct rlimit core_limit;
    core_limit.rlim_cur = RLIM_INFINITY;
    core_limit.rlim_max = RLIM_INFINITY;
    if (setrlimit(RLIMIT_CORE, &core_limit) < 0) {
        /* ERROR */
    }
    //==
    //|==========================| make directory |============================|
    const int dir_err = mkdir("data", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (-1 == dir_err)
    {
        cout << "Error creating directory" << endl;
        cout << "-------------- No Problem ---------------" << endl;
    }
    //|========================================================================
    ostringstream fn;
    fn << "./data/data_0.dat";//path to time serie
    iMatrix m1(2, iRow());//integer data
    Fread mf1;
    mf1.Read(fn, m1);//read data file
    Hist h1;//hist data
    h1.LogLogBinning(m1);//log log binning and distribution
    h1.Cumulative(m1);//cumulative distribution 
    h1.CumulativeA(m1);//cumulative distribution 
    h1.SimpleDist(m1);//linear binning and distribution
}
