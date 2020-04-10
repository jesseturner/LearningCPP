#include <iostream> 
using namespace std; 
#include <regex>

int main() 
{ 
    string guessword; 
    string letter;
    int lives; 
    string scoreboard; 

    cout << "Enter your hangman word: "; 
    cin >> guessword;
    cout << "The word is " << guessword.length() << " letters long.\n";
    scoreboard = string(guessword.length(), '_');
    cout << scoreboard << endl;
    lives = 5;
    cout << "You have " << lives << " lives to get the correct answer.\n";

    while (lives > 0) {
        int found;

        cout << "----------------------------------------\n";

        cout << "Enter a letter to guess: ";
        cin >> letter;
        found = guessword.find(letter);
        
        if (found != std::string::npos)
        cout << letter << " is in position " << found+1 << " in the word.\n";
        else
        cout << letter << " is not in the word\n"; // not found
        if (found != std::string::npos)
        scoreboard = scoreboard.replace(found, 1,  letter);
        else
        lives = lives-1;

        cout << "You have " << lives << " lives left.\n";
        cout << scoreboard << endl;

        cout << "----------------------------------------\n\n";   
        }
    cout << "you are out of guesses.\n";
    
    return 0; 
}