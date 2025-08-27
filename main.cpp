#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Person {
private:
    string name;
    int id;
    public:
    Person();
    Person(string n, int i);
    void setName(string);
    void setId(int);
    virtual void display() const; 
    string getName() const;
    int getId() const;
};
Person::Person() {
    name = "";
    id = 0;
}

Person::Person(string n, int i) {
    setName(n);
    setId(i);
}
void Person::setName(string n) {
    if (n.length() >= 3)
        name = n;
    else
        cout << "Error! Name must be at least 3 characters." << endl;
}

void Person::setId(int i) {
    if (i >= 0)
        id = i;
    else
        cout << "Error! ID must be non-negative." << endl;
}
int main() {
    return 0;
}