#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };

Choice getBotChoice()
{
    return static_cast<Choice>(rand() % 3);
}

void displayChoice(Choice choice)
{
    switch (choice)
    {
    case ROCK:
        cout << "Rock";
        break;
    case PAPER:
        cout << "Paper";
        break;
    case SCISSORS:
        cout << "Scissors";
        break;
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Choice userChoice, botChoice;

    cout << "Enter your choice (0: Rock, 1: Paper, 2: Scissors): ";
    int userInput;
    cin >> userInput;
    userChoice = static_cast<Choice>(userInput);

    botChoice = getBotChoice();

    cout << "You chose: ";
    displayChoice(userChoice);
    cout << "\nBot chose: ";
    displayChoice(botChoice);
    cout << endl;

    if (userChoice == botChoice)
    {
        cout << "It's a tie!" << endl;
    }
    else if ((userChoice == ROCK && botChoice == SCISSORS) ||
             (userChoice == PAPER && botChoice == ROCK) ||
             (userChoice == SCISSORS && botChoice == PAPER))
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << "Bot wins!" << endl;
    }

    return 0;
}