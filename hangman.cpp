#include <iostream> 
using namespace std; 
#include <regex>

int main() 
{ 
    string guessword; 
    string letter;
    int lives; 
    int iswinner;
    string scoreboard; 

    cout << "Enter your hangman word: "; 
    cin >> guessword;
    cout << "\n\n\n\n\n";
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
        
        vector<int> positions;

        int pos = guessword.find(letter, 0);
        if (found != std::string::npos)
            while(pos != std::string::npos)
            {
                positions.push_back(pos);
                scoreboard = scoreboard.replace(pos, 1,  letter);
                pos = guessword.find(letter,pos+1);
            }
            
        if (found == std::string::npos)
        lives = lives-1;

        cout << "You have " << lives << " lives left.\n\n";
        cout << scoreboard << endl;

        iswinner = scoreboard.find('_');
        if (iswinner == std::string::npos)
        lives = 0;

        cout << "\n----------------------------------------\n\n";   
        }

    if (iswinner == std::string::npos)
    cout << "Winner! The word is " << scoreboard << "\n\n";
    else
    cout << "You have lost. You are out of guesses.\n";
    
    return 0; 
}