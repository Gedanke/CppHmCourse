#include <iostream>
#define MAX 1000

using namespace std;

struct Person
{
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct AddressBook
{
    Person personArray[MAX];
    int size;
};

void showMenu();
void addPerson(AddressBook *abs);
void showPerson(const AddressBook *abs);
int isExist(const AddressBook *abs, string name);
void deletePerson(AddressBook *abs);
void findPerson(const AddressBook *abs);
void modifyPerson(AddressBook *abs);
void cleanPerson(AddressBook *abs);
void deal(AddressBook *abs);