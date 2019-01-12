#include "in.h"
#ifndef HIST_H
#define HIST_H


class Hist
{
public:
    Hist();
    void SimpleDist(iMatrix &m1);
    void LogLogBinning(iMatrix &m1);
    void Cumulative(iMatrix &m1);
    void CumulativeA(iMatrix &m1);
};

#endif // HIST_H
