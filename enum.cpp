#include <iostream>

// Declaration of an enumeration named Days
enum Days {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int main() {
    // Using the Days enumeration
    Days today = Wednesday;

    // Switch statement with enum
    switch (today) {
        case Sunday:
            std::cout << "It's Sunday!" << std::endl;
            break;
        case Monday:
            std::cout << "It's Monday!" << std::endl;
            break;
        case Wednesday:
            std::cout << "It's Wednesday!" << std::endl;
            break;
        default:
            std::cout << "It's some other day." << std::endl;
            break;
    }

    return 0;
}
