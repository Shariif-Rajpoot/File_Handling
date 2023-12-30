#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    /*
    ofstream ofs("sample.txt");
    file opened via constructor
    */
    ofstream ofs;
    ofs.open("sample.txt");
    ofs << "Hello you beautiful people" << endl;
    return 0;
}