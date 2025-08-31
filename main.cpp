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
void Member::borrowItem(int itemId) {
    borrowedItemId.push_back(itemId);
}
void Member::returnItem(int itemId) {
    borrowedItemId.erase(remove(borrowedItemId.begin(), borrowedItemId.end(), itemId), borrowedItemId.end());
}
void Member::display() const {
    Person::display();
    cout << "Borrowed items: ";
    if (borrowedItemId.empty()) {
        cout << "None";
    } else {
        for (int id : borrowedItemId) {
            cout << id << " ";
        }
    }
    cout << endl;
}
const vector<int>& Member::getBorrowedItemId() const {
    return borrowedItemId;
}
// class item section ---------------------------
class Item {
    protected:
        string title;
        int itemID;
        bool isAvailable;
        public:
        Item();
        Item(string, int, bool);
        
        void setTitle(string);
        void setItemID(int);
        void setIsAvailable(bool);
        
        string getTitle() const;
        int getItemID() const;
        bool getIsAvailable() const;
    
        virtual void displayInfo() const;
    };
     Item::Item() {
        title = "";
        itemID = 0;
        isAvailable = true;
    }
    Item::Item(string t, int id, bool avail) {
        setTitle(t);
        setItemID(id);
        setIsAvailable(avail);
    }
    void Item::setTitle(string t) {
        if (t.length() >= 2)
            title = t;
        else
            cout << "Error! must be at least 2 characters." << endl;
    }
    void Item::setItemID(int id) {
        if (id >= 0)
            itemID = id;
        else
            cout << "Error! ID must be Positive." << endl;
    }
    void Item::setIsAvailable(bool avail) {
        isAvailable = avail;
    }
    string Item::getTitle() const {
        return title;
    }
    
    int Item::getItemID() const {
        return itemID;
    }
    
    bool Item::getIsAvailable() const {
        return isAvailable;
    }
    void Item::displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Item ID: " << itemID << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
    //class Book section ----------------------
class Book : public Item {
    private:
        string author;
        string ISBN;
        public:
        Book();
        Book(string, int, bool, string, string);
        
        void setAuthor(string);
        void setISBN(string);
    
        string getAuthor() const;
        string getISBN() const;
    
        void displayInfo() const override;
    };
    Book::Book() : Item() {
        author = "";
        ISBN = "";
    }
    Book::Book(string t, int id, bool avail, string a, string isbn) : Item(t, id, avail) {
        setAuthor(a);
        setISBN(isbn);
    }
    void Book::setAuthor(string a) {
        if (a.length() >= 3)
            author = a;
        else
            cout << "Error! must be at least 3 characters." << endl;
    }
    void Book::setISBN(string isbn) {
        if (isbn.length() == 13)
            ISBN = isbn;
        else
            cout << "Error! must be 13 characters." << endl;
    }
    string Book::getAuthor() const {
        return author;
    }
    
    string Book::getISBN() const {
        return ISBN;
    }
    void Book::displayInfo() const {
        Item::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
    }
    // class magazin section -----------------
class Magazine : public Item {
    private:
        int issueNumber;
        string publisher;
int main() {
    return 0;
}