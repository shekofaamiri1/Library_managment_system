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
int main() {
    return 0;
}