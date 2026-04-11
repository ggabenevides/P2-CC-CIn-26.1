#include <time.h> // Prototype of time()
#include <stdlib.h> // Prototypes of srand() and rand()
#include <iostream>

int main(){
    // initizalizing variables
    long sec;
    time(&sec); // Take the number of seconds and
    srand((unsigned) sec); // use it to initialise.
    int random(20);
    bool play_again(true);
    char answer;

    while(play_again){
        
        // generate a random number that satisfies requirements
        random = (rand() % 15) + 1;
        bool guessed(false);

        // loop for a round of the game - three attempts to guess
        for (int i = 1; i<=3; i++){
            int guess;
            
            std::cout << "Guess a number between 1 and 15:";
            std::cin >> guess;
            std::cout << std::endl;
            std:: cout << "Attempt " << i << " of 3: " << guess << std::endl;
            if(guess == random){
                std::cout << "Congratulations! You guessed correctly!";
                guessed = true;
                break;
            }
            else{
                std::cout << "Tough luck! You guessed incorrectly." << std::endl;
            }
        }
        std::cout << "You've finished this round! Want to play again? (y/n) ";
        std::cin >> answer;
        std::cout << std::endl;

        if(answer == 'n'){
            play_again = false;
        }
    }

}

