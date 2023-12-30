#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream ofs;
    ofs.open("Mohsin.txt", ios::app);
    ofs << "Mohsin how are you" << endl;
    ifstream ifs;
    ifs.open("Mohsin.txt");
    string str;
    ifs >> str;
    while (!ifs.eof())
    {
        cout << str << " ";
        ifs >> str;
    }
    char m[10] = "Mohsin";
    for (int i = 0; m[i] != '\0'; i++)
    {
        ofs << m[i] << endl;
        cout << m[i] << endl;
    }
    ofs.close();
    ifs.close();
    return 0;
}