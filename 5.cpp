

//use of classess in c++


#include <iostream>
using namespace std;
#include <cstring>
class String {
char *str_; // Container
size_t len_; // Length
public:
String(const char *s) : str_(strdup(s)), // Uses malloc()

len_(strlen(str_))
{ cout << "ctor: "; print(); }
~String() {
cout << "dtor: "; print();
free(str_); // To match malloc() in strdup()
}
void print() { cout << "(" << str_ << ": "
<< len_ << ")" << endl; }

size_t len() { return len_; }
};



char monthNames[][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
char dayNames[][10] = { "Monday", "Tuesday", "Wednesday", "Thursday",
"Friday", "Saturday", "Sunday" };

class Date {
enum Month { Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec };
enum Day { Mon, Tue, Wed, Thr, Fri, Sat, Sun };
typedef unsigned int UINT;
UINT date_; Month month_; UINT year_;
public:
Date(UINT d, UINT m, UINT y) : date_(d), month_((Month)m), year_(y)
{ cout << "ctor: "; print(); }
~Date() { cout << "dtor: "; print(); }
void print() { cout << date_ << "/" << monthNames[month_ - 1] << "/" << year_ << endl; }
bool validDate() { /* Check validity */ return true; } // Not implemented
Day day() { /* Compute day from date using time.h */ return Mon; } // Not implemented
};

class Name { String firstName_, lastName_;
public:
Name(const char* fn, const char* ln) : firstName_(fn), lastName_(ln)
{ cout << "Name ctor: "; print(); cout << endl; }
~Name() { cout << "Name dtor: "; print(); cout << endl; }
void print()
{ firstName_.print(); cout << " "; lastName_.print(); }
};
class Address {
unsigned int houseNo_;
String street_, city_, pin_;
public:
Address(unsigned int hn, const char* sn, const char* cn, const char* pin) :
houseNo_(hn), street_(sn), city_(cn), pin_(pin)
{ cout << "Address ctor: "; print(); cout << endl; }
~Address() { cout << "Address dtor: "; print(); cout << endl; }
void print() {
cout << houseNo_ << " ";
street_.print(); cout << " ";
city_.print(); cout << " ";
pin_.print();
}
};

class CreditCard { typedef unsigned int UINT;
char cardNumber_[17]; // 16-digit (character) card number as C-string
Name holder_;
Address addr_;
Date issueDate_, expiryDate_;
UINT cvv_;
public:
CreditCard(const char* cNumber, const char* fn, const char* ln,
unsigned int hn, const char* sn, const char* cn, const char* pin,
UINT issueMonth, UINT issueYear, UINT expiryMonth, UINT expiryYear, UINT cvv) :
holder_(fn, ln), addr_(hn, sn, cn, pin),
issueDate_(1, issueMonth, issueYear),
expiryDate_(1, expiryMonth, expiryYear), cvv_(cvv)
{ strcpy(cardNumber_, cNumber); cout << "CC ctor: "; print(); cout << endl; }
~CreditCard() { cout << "CC dtor: "; print(); cout << endl; }
void print() {
cout << cardNumber_ << " ";
holder_.print(); cout << " ";
addr_.print(); cout << " ";
issueDate_.print(); cout << " ";
expiryDate_.print(); cout << " ";
cout << cvv_;
}
};
int main() {
CreditCard cc("5321711934640027", "Sharlock", "Holmes",
221, "Baker Street", "London", "NW1 6XE", 7, 2014, 12, 2016, 811);
cout << endl; cc.print(); cout << endl << endl;;
return 0;
}
