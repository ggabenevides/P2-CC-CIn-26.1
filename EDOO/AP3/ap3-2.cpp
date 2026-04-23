#include <iostream>
#include <string>
#include <limits>

int main() {
    bool tryAgain = true;
    char answer;

    while (tryAgain) {
        std::cout << "Enter a word: ";
        std::string s1;
        std::getline(std::cin, s1);

        int len = s1.length() / 2;
        bool palindrome = true;

        for (int i = 0; i < len; i++) {
            if (s1[i] != s1[s1.length() - (i + 1)]) {
                palindrome = false;
                break; // parar de checar quando achar a confirmação que não é um palindromo
            }
        }

        if (palindrome && !s1.empty()) {
            std::cout << "This word is a palindrome." << std::endl;
        } else {
            std::cout << "This word is NOT a palindrome." << std::endl;
        }

        std::cout << "Do you want to try again? (y/n) ";
        std::cin >> answer;

        // limpar o buffer pra funcionar mais de uma iteração do loop
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        tryAgain = (answer == 'y' || answer == 'Y');
    }

    return 0;
}