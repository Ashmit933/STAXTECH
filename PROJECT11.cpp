#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string generatePassword(int length, bool useLower, bool useUpper, bool useDigits, bool useSpecial) {
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    
    string characterPool = "";

    if (useLower) characterPool += lowercase;
    if (useUpper) characterPool += uppercase;
    if (useDigits) characterPool += digits;
    if (useSpecial) characterPool += special;

    if (characterPool.empty()) {
        return "Error: No character types selected.";
    }

    string password = "";
    for (int i = 0; i < length; ++i) {
        int index = rand() % characterPool.length();
        password += characterPool[index];
    }

    return password;
}

int main() {
    srand(time(0)); 
    int length;
    char includeLower, includeUpper, includeDigits, includeSpecial;

    cout << "=== Password Generator ===" << endl;

    // Input password length
    cout << "Enter password length: ";
    cin >> length;

    // User preferences
    cout << "Include lowercase letters? (y/n): ";
    cin >> includeLower;
    cout << "Include uppercase letters? (y/n): ";
    cin >> includeUpper;
    cout << "Include digits? (y/n): ";
    cin >> includeDigits;
    cout << "Include special characters? (y/n): ";
    cin >> includeSpecial;

    string password = generatePassword(length,
                                       includeLower == 'y' || includeLower == 'Y',
                                       includeUpper == 'y' || includeUpper == 'Y',
                                       includeDigits == 'y' || includeDigits == 'Y',
                                       includeSpecial == 'y' || includeSpecial == 'Y');

    cout << "\nGenerated Password: " << password << endl;

    return 0;
}
