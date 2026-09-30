#ifndef DIE_H
#define DIE_H

class Die
{
private:
    int m_numOfSides;
    int m_dieValue;

    unsigned long mt[624];
    int index;

    void generateNumbers();
    unsigned long extractNumber();

public:
    Die();

    void set_dieValue(int value);
    int get_dieValue();

    void set_numOfSides(int sides);
    int get_numOfSides();

    void rollDie();
};

#endif
