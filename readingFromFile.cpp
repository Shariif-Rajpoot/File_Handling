#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    /*
        ifstream ifs("sample.txt");
        file is opened via constructor
    */
    ifstream ifs;
    string str;

    ifs.open("sample.txt");
    /*
    getline(ifs, str);
    cout << str << endl;
    getline is method is use to read the entire file
    line by line.
    we can't pass character or an array of characters in
    this function or method.
    char ch;
    getline(ifs,ch); this will throw an error
    or
    char chr[20];
    getline(ifs,chr); this will also throw an error
    */
    ifs >> str;
    for (; !ifs.eof();)
    {
        cout << str << " ";
        ifs >> str;
    }
    ifs.close(); // closing a file
    /*
    cout << endl;
    ifs >> str;
    cout << str << endl;
    */
    return 0;
}