#include "hist.h"

using namespace std;

Hist::Hist()
{

}
//
void Hist::SimpleDist(iMatrix &m1)
{
    ostringstream nfn;
    int max=0;
    double nonZero=0;
    for(int i=0;i<m1[0].size();++i)
    {
        if(m1[1][i]>max)
            max=m1[1][i];
        if(m1[1][i]>0)
            nonZero=nonZero+1;
    }
    //
    nfn<<"./data/degreeD_N"<<m1[0].size()<<".dat";
    ofstream out(nfn.str().c_str(),ios_base::binary);
    //
    double all=m1[1].size();
    double sumk=0;
    for(int i=0;i<max;++i)
    {
        double num=0,fr=0;
        for(int j=0;j<m1[1].size();++j)
        {
            if(m1[1][j]==i)
            {
                num++;
                sumk=sumk+i;
            }
        }
        fr=num/nonZero;
        out<<i<<" "<<fr<<endl;
    }
    cout<<"<k> = "<<sumk/nonZero<<" -- "<<sumk/all<<endl;
}
//
void Hist::LogLogBinning(iMatrix &m1)
{
    ostringstream nfn;
    double max=0;
    double nonZ=0;
    for(int i=0;i<m1[0].size();++i)
    {
        if(m1[1][i]>max)
            max=m1[1][i];
        if(m1[1][i]>0)
            nonZ++;
    }
    cout<<max<<endl;
    cout<<log10(max)<<endl;
    double lmax=(log10(max)*10),llmax;
    llmax=round(lmax);
    cout<<"llmax"<<llmax<<endl;
    int tmax=int(llmax);
    if(llmax<lmax)
        tmax=tmax+1;
    cout<<tmax<<endl;
    int limit=(tmax)-2;
    cout<<limit<<endl;
    dMatrix m2(3,dRow(limit));
    for(int i=0;i<6;++i)
    {
        m2[0][i]=i+1;
        m2[1][i]=i+1;
    }
    double exp=0.9;
    double s,ten=10;
    for(int i=6;i<limit;++i)
    {
        s=(pow(ten,exp));
        m2[0][i]=round(s);
        m2[1][i-1]=(m2[0][i]+m2[0][i-1])/2;
        exp=exp+0.1;
        s=0;
    }
    //
    //
    double SumOfAll=0;
    for(int i=0;i<limit-1;++i)
    {
        for(int j=0;j<m1[1].size();++j)
        {
            if(m1[1][j]>=m2[0][i] && m1[1][j]<m2[0][i+1])
            {
                m2[2][i]=m2[2][i]+1;
            }
        }
        SumOfAll=SumOfAll+((m2[2][i])/(m2[0][i+1]-m2[0][i]));
    }
    //
    nfn<<"./data/degreeD_LLB_N"<<m1[0].size()<<".dat";
    ofstream out(nfn.str().c_str(),ios_base::binary);
    for(int i=0;i<limit-1;++i)
    {
        //out<<m2[1][i]<<" "<<((m2[2][i])/(m2[0][i+1]-m2[0][i]))/SumOfAll<<<<endl;
        double val=(m2[2][i])/(m2[0][i+1]-m2[0][i]);
        out<<m2[1][i]<<" "<<val/nonZ<<endl;
    }
}

void Hist::Cumulative(iMatrix &m1)
{
    ostringstream nfn;
    int max=0;
    double nonZero=0;
    for(int i=0;i<m1[0].size();++i)
    {
        if(m1[1][i]>max)
            max=m1[1][i];
        if(m1[1][i]>0)
            nonZero=nonZero+1;
    }
    //
    double all=m1[1].size();
    nfn<<"./data/degreeD_CnonZ_N"<<m1[0].size()<<".dat";
    ofstream out(nfn.str().c_str(),ios_base::binary);
    //
    for(int i=0;i<max;++i)
    {
        double num=0,fr=0;
        for(int j=0;j<m1[1].size();++j)
        {
            if(m1[1][j]>i)
                num++;
        }
        fr=num/all;
        out<<i<<" "<<fr<<endl;
    }
}
//
void Hist::CumulativeA(iMatrix &m1)
{
    ostringstream nfn;
    int max=0;
    double nonZero=m1[1].size();
    for(int i=0;i<m1[0].size();++i)
    {
        if(m1[1][i]>max)
            max=m1[1][i];
    }
    //
    nfn<<"./data/degreeD_Call_N"<<m1[0].size()<<".dat";
    ofstream out(nfn.str().c_str(),ios_base::binary);
    //
    for(int i=0;i<(max-1);++i)
    {
        double num=0,fr=0;
        for(int j=0;j<m1[1].size();++j)
        {
            if(m1[1][j]>(i+1))
                num++;
        }
        fr=num/nonZero;
        out<<i+1<<" "<<fr<<endl;
    }
}
