#include <iostream>
#include "Die.h"

struct GameState
{
    char choice;
    int turn_count = 0;
    int game_score = 0;
    int score_this_turn = 0;
    bool game_over = false;
    bool turn_over = false;
};

void addScore(GameState &gs)
{
    gs.game_score += gs.score_this_turn;
}

int roll(GameState &gs, Die &die)
{
    die.rollDie();

    int dieValue = die.get_dieValue();

    std::cout << "Die: " << dieValue;

    if (dieValue == 1)
    {
        gs.score_this_turn = 0;
        gs.turn_over = true;

        std::cout << std::endl;
        std::cout << "Turn over. No score." << std::endl;
    }
    else
    {
        gs.score_this_turn += dieValue;

        std::cout << " - Running score this turn: "
                  << gs.score_this_turn << std::endl;
    }

    return dieValue;
}

void hold(GameState &gs)
{
    addScore(gs);
    gs.turn_over = true;

    if (gs.game_score >= 20)
    {
        gs.game_over = true;
    }
}

void takeTurn(GameState &gs, Die &die)
{
    gs.turn_over = false;
    gs.score_this_turn = 0;

    while (!gs.turn_over)
    {
        std::cout << "roll or hold? (r/h): ";
        std::cin >> gs.choice;

        if (gs.choice == 'r')
        {
            roll(gs, die);
        }
        else if (gs.choice == 'h')
        {
            hold(gs);
        }
    }

    std::cout << "Score Banked This Turn: "
              << gs.score_this_turn << std::endl;
}

void playGame(GameState &gs, Die &die)
{
    std::cout << "Let's play PIG Dice!" << std::endl;
    std::cout << std::endl;

    std::cout << "* See how many turns it takes you to get to 20 points."
              << std::endl;

    std::cout << "* Turn ends when you hold or roll a 1."
              << std::endl;

    std::cout << "* If you roll a 1, you lose all points for the turn."
              << std::endl;

    std::cout << "* If you hold, you bank all points for the turn "
              << "to the game score."
              << std::endl;

    std::cout << std::endl;

    while (!gs.game_over)
    {
        gs.turn_count++;

        std::cout << "TURN " << gs.turn_count
                  << " - Game Score: " << gs.game_score << std::endl;

        takeTurn(gs, die);

        std::cout << std::endl;
    }

    std::cout << "You finished with a final score of "
              << gs.game_score << " in "
              << gs.turn_count << " turns!" << std::endl;

    std::cout << "Thanks for playing Pig Dice!" << std::endl;
}

int main()
{
    GameState my_game;

    Die my_die;

    int sides;

    std::cout << "Choose your die:" << std::endl;
    std::cout << "4 - Four-sided die" << std::endl;
    std::cout << "6 - Six-sided die" << std::endl;
    std::cout << "8 - Eight-sided die" << std::endl;
    std::cout << "Enter 4, 6, or 8: ";
    std::cin >> sides;

    while (sides != 4 && sides != 6 && sides != 8)
    {
        std::cout << "Invalid choice. Please enter 4, 6, or 8: ";
        std::cin >> sides;
    }

    my_die.set_numOfSides(sides);

    std::cout << std::endl;
    std::cout << "You chose a "
              << my_die.get_numOfSides()
              << "-sided die." << std::endl;

    std::cout << std::endl;

    playGame(my_game, my_die);

    return 0;
}
