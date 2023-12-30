#include <iostream>
#include <fstream>
using namespace std;
class Student
{
protected:
    string name;
    int rollNumber;

public:
    void getData(int, string);
};
void Student::getData(int r, string n)
{
    name = n;
    rollNumber = r;
}
// second class
class Exam : public Student
{
protected:
    float physics;
    float maths;

public:
    void getMarks(float, float);
    void displayMarks();
};
void Exam::getMarks(float m1, float m2)
{
    physics = m1;
    maths = m2;
}
// third class
class Result : public Exam
{
    float percentage;

public:
    void calculateResult();
    void announceResult();
};
void Result::calculateResult()
{
    percentage = (maths + physics) / 2;
}
void Result::announceResult()
{
    ofstream ofs;
    ofs.open("Result.txt", ios::app);
    if (ofs.is_open())
    {
        ofs << "Name of student     => " << name << endl;
        ofs << "Roll Number         => " << rollNumber << endl;
        ofs << "Marks Of Physics    => " << physics << endl;
        ofs << "Marks Of Maths      => " << maths << endl;
        ofs << "Percentage          => " << percentage << "%" << endl;
    }
    ofs << endl
        << endl;
    ofs.close();
}
int main()
{
    Result Mohsin;
    Mohsin.getData(22, "M.Mohsin");
    Mohsin.getMarks(98.2, 99.2);
    Mohsin.calculateResult();
    Mohsin.announceResult();
    Result Mohsina;
    Mohsina.getData(2, "Mohsina");
    Mohsina.getMarks(98.2, 99.2);
    Mohsina.calculateResult();
    Mohsina.announceResult();
    return 0;
}