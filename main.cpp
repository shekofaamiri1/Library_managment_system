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
string Person::getName() const {
    return name;
}

int Person::getId() const {
    return id;
}
void Person::display() const {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}
// کلاس فرزند: Member
class Member : public Person {
private:
    vector<int> borrowedItemId;
public:
    Member();
    Member(string, int);
    void borrowItem(int);
    void returnItem(int);
    void display() const override; 
    const vector<int>& getBorrowedItemId() const;
};
Member::Member() = default;

Member::Member(string n, int i) : Person(n, i) {}
int main() {
    return 0;
}