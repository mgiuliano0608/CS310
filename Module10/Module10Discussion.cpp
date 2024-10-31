#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
    string firstName;
    string lastName;
    int age;

    public:
    Person(string firstName, string lastName, int age) {
        this->firstName = firstName;
        this->lastName = lastName;
        this->age = age;
    }

    string getFirstName() { return firstName; }

    void setFirstName(string firstName) { this->firstName = firstName; }

    string getLastName() { return lastName; }

    void setLastName(string lastName) { this->lastName = lastName; }

    int getAge() { return age; }

    void setAge(int age) { this->age = age; }
}

void displayPersonInfo(Person *person) {
    cout << "First Name: " << person->getFirstName() << endl;
    cout << "Last Name:  " << person->getLastName() << endl;
    cout << "Age:        " << person->getAge() << endl;
}

int main() {
    Person person = Person("Michael", "Giuliano", 40);

    cout << "Person object is located at memory address " << &person << "\n\n";

    displayPersonInfo(person);

    return 0;
}