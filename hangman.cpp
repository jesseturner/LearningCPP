#include <iostream> 
using namespace std; 
  
int main() 
{ 
    string guessword; 
    char letter;
  
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
        scoreboard = scoreboard.replace(found, 1, '_',  letter);
        if (found != std::string::npos)
        cout << letter << " is in position " << found+1 << " in the word.\n" << scoreboard << endl;
        else
        cout << letter << " is not in the word\n"; // not found
        }
    cout << "you are out of guesses.\n";
    return 0; 
}