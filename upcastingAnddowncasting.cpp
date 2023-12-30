#include <iostream>
#include <fstream>
using namespace std;
class Instrument
{

public:
    // void playing();
    virtual void playing();
    void display();
};
void Instrument::display()
{
    ifstream ifs;
    string str;
    ifs.open("Instruments.txt");
    for (; !ifs.eof();)
    {
        getline(ifs, str);
        cout << str << endl;
    }
}
void Instrument::playing()
{
    ofstream ofs("Instruments.txt", ios::app);
    ofs << "Instrument Playing" << endl;
    ofs.close();
}
class Piano : public Instrument
{
public:
    void playing();
};
void Piano::playing()
{
    ofstream ofs;
    ofs.open("Instruments.txt", ios::app);
    ofs << "Piano Playing" << endl;
    ofs.close();
}
int main()
{
    // upcasting
    Instrument *itr;
    Piano P;
    // itr = (Instrument *)&P; can't get the expected outcome until base class don't has virtual fuction.
    itr = &P;
    itr->playing();
    // downcasting
    Instrument instrument;
    Piano *ptr;
    ptr = (Piano *)&instrument;
    ptr->playing();
    ptr->display();
    return 0;
}