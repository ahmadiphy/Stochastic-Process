#include "in.h"
#ifndef FREAD_H
#define FREAD_H
using namespace std;

class Fread
{
public:
    Fread();
    void Read(ostringstream &fnm, iMatrix &mym);
};

#endif // FREAD_H
