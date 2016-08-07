#include <ostream>
using namespace std;
template <class T>
class templatedemo
{
public :
    templatedemo();//无参构造函数
    templatedemo(T value);//有参构造函数
    templatedemo(const templatedemo& num);//copy constructor
    ~templatedemo();//destructor
    templatedemo & operator=(const templatedemo& num );//operator=

public :
    //+ - * / operator
    templatedemo operator++ ();
    templatedemo operator++ (int);
    templatedemo operator-- ();
    templatedemo operator-- (int);
    templatedemo operator+= (const templatedemo& num);
    templatedemo operator-= (const templatedemo& num);
    templatedemo operator+ (const templatedemo& num);
    templatedemo operator- (const templatedemo& num);
    templatedemo operator* (const templatedemo& num);
    templatedemo operator/ (const templatedemo& num);

public :
    //compare operator
    bool operator< (const templatedemo& num) const;
    bool operator> (const templatedemo& num) const;
    bool operator== (const templatedemo& num) const;
    bool operator!= (const templatedemo& num) const;

public :
    template<T> friend ostream & operator << (ostream &os, templatedemo &num);

private :
    T _value;
};
