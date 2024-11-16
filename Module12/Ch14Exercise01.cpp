#include <iostream>
#include <string>
#include <regex>

using namespace std;

class baseException {
    private:
    string message;

    public:
    baseException() {
        this->message = "";
    }

    baseException(string message) {
        this->message = message;
    }

    string getMessage() {
        return message;
    }

    void setMessage(string message) {
        this->message = message;
    }
};

class negativeNumber : public baseException {
    public:
    negativeNumber() : baseException() {}

    negativeNumber(string message) : baseException(message) {}
};

class nonNumber : public baseException {
    public:
    nonNumber() : baseException() {}

    nonNumber(string message) : baseException(message) {}
};

const regex signedNumberRegex(R"([+-]?([0-9]*[.])?[0-9]+)");
void validateInput(string sFeet, string sInches);
bool isNumber(string value);
float convertToCenti(int feet, int inches);

int main() {
    
    string sFeet;
    int feet;
    string sInches;
    int inches;

    cout << endl
        << "**************************************************" << endl
        << "**          FEET/INCHES TO CENTIMETERS          **" << endl
        << "**************************************************" << endl << endl;

    bool isValid;
    do {
        isValid = true;
        cout << "Enter a length in feet and inches (Ex: 5 10): ";
        cin >> sFeet;
        cin >> sInches;

        try {
            validateInput(sFeet, sInches);
        }
        catch (negativeNumber ex) {
            isValid = false;
            cout << ex.getMessage() << endl;
        }
        catch (nonNumber ex) {
            isValid = false;
            cout << ex.getMessage() << endl;
        }
    } while (!isValid);

    feet = stoi(sFeet);
    inches = stoi(sInches);
    float centimeters = convertToCenti(feet, inches);
    
    cout << endl << feet << " feet " << inches << " inches = " << centimeters << " centimeters" << endl;

    return 0;
}

void validateInput(string sFeet, string sInches) {
    // validate feet
    if (!isNumber(sFeet))
        throw nonNumber("Feet value is not a number.");
    
    if (stoi(sFeet) < 0)
        throw negativeNumber("Feet must be greater than or equal to 0.");

    // validate inches
    if (!isNumber(sInches))
        throw nonNumber("Inches value is not a number.");
    
    if (stoi(sInches) < 0)
        throw negativeNumber("Inches must be greater than or equal to 0.");
}

bool isNumber(string value) {
    return regex_match(value, signedNumberRegex);
}

float convertToCenti(int feet, int inches) {
    int totalInches = feet * 12 + inches;
    return totalInches * 2.54;
}