#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Person
{
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
Person::Person()
{
    name = "";
    id = 0;
}

Person::Person(string n, int i)
{
    setName(n);
    setId(i);
}
void Person::setName(string n)
{
    if (n.length() >= 3)
        name = n;
    else
        cout << "Error! Name must be at least 3 characters." << endl;
}

void Person::setId(int i)
{
    if (i >= 0)
        id = i;
    else
        cout << "Error! ID must be non-negative." << endl;
}
string Person::getName() const
{
    return name;
}

int Person::getId() const
{
    return id;
}
void Person::display() const
{
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
}
// کلاس فرزند: Member
class Member : public Person
{
private:
    vector<int> borrowedItemId;

public:
    Member();
    Member(string, int);
    void borrowItem(int);
    void returnItem(int);
    void display() const override;
    const vector<int> &getBorrowedItemId() const;
};
Member::Member() = default;

Member::Member(string n, int i) : Person(n, i) {}
void Member::borrowItem(int itemId)
{
    borrowedItemId.push_back(itemId);
}
void Member::returnItem(int itemId)
{
    borrowedItemId.erase(remove(borrowedItemId.begin(), borrowedItemId.end(), itemId), borrowedItemId.end());
}
void Member::display() const
{
    Person::display();
    cout << "Borrowed items: ";
    if (borrowedItemId.empty())
    {
        cout << "None";
    }
    else
    {
        for (int id : borrowedItemId)
        {
            cout << id << " ";
        }
    }
    cout << endl;
}
const vector<int> &Member::getBorrowedItemId() const
{
    return borrowedItemId;
}
// class item section ---------------------------
class Item
{
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
Item::Item()
{
    title = "";
    itemID = 0;
    isAvailable = true;
}
Item::Item(string t, int id, bool avail)
{
    setTitle(t);
    setItemID(id);
    setIsAvailable(avail);
}
void Item::setTitle(string t)
{
    if (t.length() >= 2)
        title = t;
    else
        cout << "Error! must be at least 2 characters." << endl;
}
void Item::setItemID(int id)
{
    if (id >= 0)
        itemID = id;
    else
        cout << "Error! ID must be Positive." << endl;
}
void Item::setIsAvailable(bool avail)
{
    isAvailable = avail;
}
string Item::getTitle() const
{
    return title;
}

int Item::getItemID() const
{
    return itemID;
}

bool Item::getIsAvailable() const
{
    return isAvailable;
}
void Item::displayInfo() const
{
    cout << "Title: " << title << endl;
    cout << "Item ID: " << itemID << endl;
    cout << "Availability: " << (isAvailable ? "Available" : "Borrowed") << endl;
}
// class Book section ----------------------
class Book : public Item
{
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
Book::Book() : Item()
{
    author = "";
    ISBN = "";
}
Book::Book(string t, int id, bool avail, string a, string isbn) : Item(t, id, avail)
{
    setAuthor(a);
    setISBN(isbn);
}
void Book::setAuthor(string a)
{
    if (a.length() >= 3)
        author = a;
    else
        cout << "Error! must be at least 3 characters." << endl;
}
void Book::setISBN(string isbn)
{
    if (isbn.length() == 13)
        ISBN = isbn;
    else
        cout << "Error! must be 13 characters." << endl;
}
string Book::getAuthor() const
{
    return author;
}

string Book::getISBN() const
{
    return ISBN;
}
void Book::displayInfo() const
{
    Item::displayInfo();
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
}
// class magazin section -----------------
class Magazine : public Item
{
private:
    int issueNumber;
    string publisher;

public:
    Magazine();
    Magazine(string, int, bool, int, string);

    void setIssueNumber(int);
    void setPublisher(string);

    int getIssueNumber() const;
    string getPublisher() const;

    void displayInfo() const override;
};
Magazine::Magazine() : Item()
{
    issueNumber = 0;
    publisher = "";
}
Magazine::Magazine(string t, int id, bool avail, int issue, string pub) : Item(t, id, avail)
{
    setIssueNumber(issue);
    setPublisher(pub);
}
void Magazine::setIssueNumber(int issue)
{
    if (issue > 0)
        issueNumber = issue;
    else
        cout << "Error! must be positive." << endl;
}

void Magazine::setPublisher(string pub)
{
    if (pub.length() >= 2)
        publisher = pub;
    else
        cout << "Error! must be at least 2 characters." << endl;
}
int Magazine::getIssueNumber() const
{
    return issueNumber;
}

string Magazine::getPublisher() const
{
    return publisher;
}
void Magazine::displayInfo() const
{
    Item::displayInfo();
    cout << "Issue Number: " << issueNumber << endl;
    cout << "Publisher: " << publisher << endl;
}
// class DVD section --------------------------------
class DVD : public Item
{
private:
    string director;
    float duration; // in minutes
public:
    DVD();
    DVD(string, int, bool, string, float);

    void setDirector(string);
    void setDuration(float);

    string getDirector() const;
    float getDuration() const;

    void displayInfo() const override;
};
DVD::DVD() : Item()
{
    director = "";
    duration = 0.0;
}
DVD::DVD(string t, int id, bool avail, string dir, float dur) : Item(t, id, avail)
{
    setDirector(dir);
    setDuration(dur);
}
void DVD::setDirector(string dir)
{
    if (dir.length() >= 3)
        director = dir;
    else
        cout << "Error! must be at least 3 characters." << endl;
}
void DVD::setDuration(float dur)
{
    if (dur > 0)
        duration = dur;
    else
        cout << "Error! must be greater than 0." << endl;
}
string DVD::getDirector() const
{
    return director;
}

float DVD::getDuration() const
{
    return duration;
}
void DVD::displayInfo() const
{
    Item::displayInfo();
    cout << "Director: " << director << endl;
    cout << "Duration: " << duration << " minutes" << endl;
}
// class transaction section --------------------------
class Transaction
{
private:
    int memberID;
    int itemID;
    string borrowDate;
    string returnDate;
    bool isReturned;

public:
    Transaction();
    Transaction(int, int, string);

    void setMemberID(int);
    void setItemID(int);
    void setBorrowDate(string);
    void setReturnDate(string);
    void setIsReturned(bool);

    int getMemberID() const;
    int getItemID() const;
    string getBorrowDate() const;
    string getReturnDate() const;
    bool getIsReturned() const;

    void markReturned(string returnDate);
    void display() const;
};
Transaction::Transaction()
{
    memberID = 0;
    itemID = 0;
    borrowDate = "";
    returnDate = "";
    isReturned = false;
}
Transaction::Transaction(int mID, int iID, string bDate)
{
    setMemberID(mID);
    setItemID(iID);
    setBorrowDate(bDate);
    isReturned = false;
    returnDate = "";
}
void Transaction::setMemberID(int id)
{
    if (id >= 0)
        memberID = id;
    else
        cout << "Error! must be non-negative." << endl;
}
void Transaction::setItemID(int id)
{
    if (id >= 0)
        itemID = id;
    else
        cout << "Error! Item ID must be non-negative." << endl;
}
void Transaction::setBorrowDate(string date)
{
    if (date.length() >= 6)
        borrowDate = date;
    else
        cout << "Error! Invalid borrow date format." << endl;
}
void Transaction::setReturnDate(string date)
{
    if (date.length() >= 6)
        returnDate = date;
    else
        cout << "Error! Invalid return date format." << endl;
}
void Transaction::setIsReturned(bool status)
{
    isReturned = status;
}
int Transaction::getMemberID() const
{
    return memberID;
}

int Transaction::getItemID() const
{
    return itemID;
}
string Transaction::getBorrowDate() const
{
    return borrowDate;
}

string Transaction::getReturnDate() const
{
    return returnDate;
}
bool Transaction::getIsReturned() const
{
    return isReturned;
}

void Transaction::markReturned(string rDate)
{
    setReturnDate(rDate);
    setIsReturned(true);
}
void Transaction::display() const
{
    cout << "Transaction Info:" << endl;
    cout << "Member ID: " << memberID << endl;
    cout << "Item ID: " << itemID << endl;
    cout << "Borrow Date: " << borrowDate << endl;
    cout << "Return Date: " << (isReturned ? returnDate : "Not returned yet") << endl;
    cout << "Status: " << (isReturned ? "Returned" : "Borrowed") << endl;
}
// class library section -----------------------------------
class Library
{
private:
    vector<Member> members;
    vector<Item *> items;
    vector<Transaction> transactions;

public:
    void addMember(const Member &);
    void addItem(Item *);
    void issueItem(int memberID, int itemID, const string &date);
    void returnItem(int itemID, const string &returnDate);

    Member *findMember(int memberID);
    Item *findItem(int itemID);
    void deleteMember(int);
    void deleteItem(int);
    void displayAllMembers() const;
    void displayAllItems() const;
    void displayAllTransactions() const;

    void loadFromFiles();
    void saveToFiles();
};
void Library::addMember(const Member &m)
{
    members.push_back(m);
    cout << "Member added successfully." << endl;
}
void Library::addItem(Item* item) {
        items.push_back(item);
        cout << "Item added successfully." << endl;
    }
    Member* Library::findMember(int memberID) {
        for (auto& m : members) {
            if (m.getId() == memberID)
                return &m;
        }
        return nullptr;
    }
    int main()
    {
        return 0;
    }