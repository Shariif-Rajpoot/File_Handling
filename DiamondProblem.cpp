#include <iostream>
#include <fstream>
using namespace std;
class Student
{
protected:
    int rollNumber;

public:
    Student();
    Student(int);
};
Student::Student() {}
Student::Student(int r) : rollNumber(r) { cout << "First Constructor" << endl; }
class Exam : virtual public Student
{
protected:
    float math;
    float physics;

public:
    Exam();
    Exam(float, float);
};
Exam::Exam() {}
Exam::Exam(float m1, float m2) : math(m1), physics(m2) { cout << "Second Constructor" << endl; }
class Sports : virtual public Student
{
protected:
    float score;

public:
    Sports();
    Sports(float);
};
Sports::Sports() {}
Sports::Sports(float s) : score(s) { cout << "Third Constructor" << endl; }
class Result : public Exam, public Sports
{
    float total;

public:
    Result();
    Result(int, float, float, float);
    void calculateTotal();
    void displayResult();
};
Result::Result() {}
Result::Result(int r, float s, float m1, float m2) : Student(r), Exam(m1, m2), Sports(s) { cout << "Fourth Constructor" << endl; }
void Result::calculateTotal()
{
    total = math + physics + score;
}
void Result::displayResult()
{
    ofstream ofs;
    ofs.open("record.txt", ios::app);
    if (ofs.is_open())
    {
        ofs << "Roll Number      => " << rollNumber << endl;
        ofs << "Marks of maths   => " << math << endl;
        ofs << "Marks of physics => " << physics << endl;
        ofs << "Sports Score     => " << score << endl;
        ofs << "The total marks  => " << total << endl;
        ofs << endl
            << endl;
    }
    ofs.close();
    ifstream ifs;
    ifs.open("record.txt");
    if (ifs.is_open())
    {
        string line;
        while (!ifs.eof())
        {
            getline(ifs, line);
            cout << line << endl;
        }
    }
    ifs.close();
}
int main()
{
    Result mohsin(22, 5, 99, 98);
    mohsin.calculateTotal();
    mohsin.displayResult();
    Result jawad(21, 9, 99, 99);
    jawad.calculateTotal();
    jawad.displayResult();
    return 0;
}