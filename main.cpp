#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

 
string filename = "names.txt";
string delimiter = ":";
int find_age = 26;
size_t pos = 0;
int k = 1;

class Fraction{
public:
  Fraction(int num, int den)
    : numerator_(num)
    , denominator_(den) {}

  Fraction(int num)
    : Fraction(num, 1) {}

  int Numerator() const {
    return numerator_;
  }
  int Denominator() const {
    return denominator_;
  }

  void PrintFraction() const {
    cout << this->Numerator() << "/" << this->Denominator() << endl;
  }

  friend Fraction operator*(const Fraction& lhs, const Fraction& rhs){
    return Fraction(lhs.numerator_ * rhs.numerator_, lhs.denominator_ * rhs.denominator_);
  }

  Fraction& operator*=(const Fraction& rhs) {
    numerator_ *= rhs.numerator_;
    denominator_ *= rhs.denominator_;
    return *this;
  }

private:
  int numerator_;
  int denominator_;
};

class Point{
public:
  Point(int x, int y)
    : xcord_(x)
    , ycord_(y){}

  Point(int num)
    : Point(num, 1) {}

  int Xcord() const {
    return xcord_;
  }
  int Ycord() const {
    return ycord_;
  }
  void PrintPoint() const {
    cout << this->Xcord() << "-" << this->Ycord() << endl;
  }
  friend Point operator+(const Point& lhs, const Point& rhs){
    return Point(lhs.xcord_ + rhs.xcord_, lhs.ycord_ + rhs.ycord_);
  }

  Point& operator+=(const Point& rhs) {
    xcord_ += rhs.xcord_;
    ycord_ += rhs.ycord_;
    return *this;
  }
private:
  int xcord_;
  int ycord_;
};

class Student{
public:
  int id;
  string name;
  int age;
  Student* left;
  Student* right;


  void PrintStudent(){
    cout << "id " << id  << endl;
    cout << "name " << name << endl;
    cout << "age " << age <<  endl;
  }

};

vector<Student> students;
vector<Student*> p_students;

void read_students(){
  ifstream file(filename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      Student tmp_student;
      tmp_student.age = atoi(line.substr(0, line.find(delimiter)).c_str());
      line.erase(0, line.find(delimiter) + delimiter.length());
      tmp_student.name = line;
      tmp_student.id = k;
      k++;
      students.push_back(tmp_student);
      //p_students.push_back(&tmp_student);
    }
    file.close();
  }
}

int main() {
  Fraction foo(2, 4);
  cout << foo.Numerator() << endl;
  foo.PrintFraction();
  const Fraction bar(2);
  bar.PrintFraction();

  const Fraction foo_bar_mul = foo * bar;
    foo_bar_mul.PrintFraction();
  
  foo *= bar;
  foo.PrintFraction();

  Student Sam;
  Sam.id = 12312;
  Sam.name = "rrr";
  Sam.age = 24;
  Sam.PrintStudent();

  for (int i = 0; i < students.size(); i++) {
        students[i].PrintStudent();
    }
  
  //cout << (foo > bar)  << endl;
  //cout << (foo < bar)  << endl;
  
  return 0;
}