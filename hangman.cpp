#include <iostream> 
using namespace std; 
#include <regex>

int main() 
{ 
    string guessword; 
    string letter;
  
    cout << "Enter your hangman word: "; 
    cin >> guessword;
    cout << "The word is " << guessword.length() << " letters long.\n";
    string scoreboard;
    scoreboard = string(guessword.length(), '_');
    cout << scoreboard << endl;
    for (int i = 0; i <= 3; i++) {
        cout << "Enter a letter to guess: ";
        cin >> letter;
        int found;
        found = guessword.find(letter);

        scoreboard = std::regex_replace(guessword, std::regex(letter), "_");
        cout << scoreboard << endl;

        /*if (found != std::string::npos)
        cout << letter << " is in position " << found+1 << " in the word.\n" << scoreboard << endl;
        else
        cout << letter << " is not in the word\n"; // not found
        if (found != std::string::npos)
        scoreboard = scoreboard.replace(found, found+2, '_',  letter);
        else
        scoreboard = scoreboard;*/
    cout << scoreboard << endl;
        }
    cout << "you are out of guesses.\n";
    return 0; 
}