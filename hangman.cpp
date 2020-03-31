#include <iostream> 
using namespace std; 
  
int main() 
{ 
    string guessword; 
    char letter;
  
    cout << "Enter your hangman word: "; 
    cin >> guessword;
    cout << "The word is " << guessword.length() << " letters long.\n";
    for (int i = 0; i <= 3; i++) {
        cout << "Enter a letter to guess: ";
        cin >> letter;
        int found;
        found = guessword.find(letter);
        if (found != std::string::npos)
        cout << letter << " is in position " << found+1 << " in the word.\n"; // found
        else 
        cout << letter << " is not in the word\n"; // not found
        found = guessword.find(letter+1);
        if (found != std::string::npos)
        cout << letter << " is also in position " << found+1 << " in the word.\n";
        
        cout << "you have " << 3-i << " more guesses.\n";
        }
    cout << "you are out of guesses.\n";
    return 0; 
}