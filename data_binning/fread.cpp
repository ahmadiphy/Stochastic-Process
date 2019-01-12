#include "fread.h"
using namespace std;

Fread::Fread()
{

}
//
void Fread::Read(ostringstream &fnm, iMatrix &mym)
{
    string line;
    ifstream data(fnm.str().c_str(),ios_base::binary);
    if (data.is_open())
    {
        while(getline (data,line))
        {
            string::size_type sz;
            double num = stod (line,&sz);
            double value = stod (line.substr(sz));
            mym[0].push_back(num);
            mym[1].push_back(value);
        }
        data.close();
    }
}
