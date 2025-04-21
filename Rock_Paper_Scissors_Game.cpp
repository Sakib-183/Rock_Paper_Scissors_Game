#include <bits/stdc++.h>
using namespace std;

void welcomeScreen()
{
    cout << "===================================\n";
    cout << "WELCOME TO ROCK PAPER SCISSORS GAME\n";
    cout << "===================================\n";
    cout << "GAME RULES:\n!~~You Just Enter Your Choice Between(1,2,3)~~!\n\t\t\t&\n  !~~Computer Choice Random Between(1,2,3)~~!\n\n";
}

void clearScreen()
{
#ifdef _WIN32
    system("CLS");
#else
    system("clear");
#endif
}

string getChoiceName(int choice)
{
    if (choice == 1) return "Rock";
    if (choice == 2) return "Paper";
    return "Scissors";
}

int main()
{
    srand(time(0));
    int playerScore = 0, computerScore = 0, draws = 0;
    welcomeScreen(); ///Add Welcome Screen
    while (true)
    {
        cout << "1. Rock\n2. Paper\n3. Scissors\n4. Quit\n";
        cout << "Enter your choice: ";
        int playerChoice;
        cin >> playerChoice;
        clearScreen();
        
        if (playerChoice == 4)
        {
            ///If Palyer choice 4
            cout << "Score - You: " << playerScore << " | Computer: " << computerScore << " | Draws: " << draws << endl<<endl;
            if(playerScore>computerScore)
            {
                cout<<"Congratulations You Are The Winner...!!"<<endl;
                break;
            }
            else if(playerScore<computerScore)
            {
                cout<<"Better Luck Next Time Computer Are The Winner...!!"<<endl;
                break;
            }
            else
            {
                cout << "The Game Was Drawn...Thanks For Playing!"<<endl;
                break;
            }
        }

        if (playerChoice < 1 || playerChoice > 3) ///If player enter worng choice
        {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        int computerChoice = rand() % 3 + 1; ///Computer Take random choice
        
        cout << "You chose: " << getChoiceName(playerChoice) << endl;
        cout << "Computer chose: " << getChoiceName(computerChoice) << endl;

        if (playerChoice == computerChoice)
        {
            cout << "It's a draw!\n";
            draws++;
        }
        else if ((playerChoice == 1 && computerChoice == 3) ||
                 (playerChoice == 2 && computerChoice == 1) ||
                 (playerChoice == 3 && computerChoice == 2))
        {
            cout << "You win!\n";
            playerScore++;
        }
        else
        {
            cout << "Computer wins!\n";
            computerScore++;
        }

        cout << "Score - You: " << playerScore << " | Computer: " << computerScore << " | Draws: " << draws << endl<<endl;
    }

    return 0;
}

// This code is a simple Rock-Paper-Scissors game where the player can play against the computer.
// The player can choose Rock, Paper, or Scissors, and the computer makes a random choice.