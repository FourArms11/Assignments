// 4) String Related Programs
// (a) Write a program to concatenate one string to another string.
// (b) Write a program to reverse a string.
// (c) Write a program to delete all the vowels from the string.
// (d) Write a program to sort the strings in alphabetical order.
// (e) Write a program to convert a character from uppercase to lowercase.



#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[100], str2[100];

    cout << "Enter first string: ";
    cin.getline(str1, 100);
    cout << "Enter second string: ";
    cin.getline(str2, 100);

    strcat(str1, str2); // concatenate str2 to str1

    cout << "After concatenation: " << str1 << endl;
    return 0;
}





#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int len = strlen(str);
    for (int i = len - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}





#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    char result[100];
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';

    cout << "String after removing vowels: " << result << endl;
    return 0;
}





#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    char str[10][100];
    cout << "Enter string:"<<endl;
    for (int i = 0; i < n; i++) {
        cin.getline(str[i], 100);
    }

    // Simple bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                char temp[100];
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << str[i] << endl;
    }

    return 0;
}







#include <iostream>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32; // ASCII conversion
        cout << "Lowercase: " << ch << endl;
    } else {
        cout << "Character is not uppercase!" << endl;
    }
    return 0;
}
