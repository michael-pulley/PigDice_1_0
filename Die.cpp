#include "Die.h"
#include <ctime>

void Die::generateNumbers()
{
    for (int i = 0; i < 624; i++)
    {
        unsigned long y =
            (mt[i] & 0x80000000UL) +
            (mt[(i + 1) % 624] & 0x7fffffffUL);

        mt[i] = mt[(i + 397) % 624] ^ (y >> 1);

        if (y % 2 != 0)
        {
            mt[i] = mt[i] ^ 0x9908b0dfUL;
        }
    }

    index = 0;
}

unsigned long Die::extractNumber()
{
    if (index >= 624)
    {
        generateNumbers();
    }

    unsigned long y = mt[index];

    y = y ^ (y >> 11);
    y = y ^ ((y << 7) & 0x9d2c5680UL);
    y = y ^ ((y << 15) & 0xefc60000UL);
    y = y ^ (y >> 18);

    index++;

    return y;
}

Die::Die()
{
    m_numOfSides = 6;
    m_dieValue = 1;

    unsigned long seed = static_cast<unsigned long>(time(0));
    mt[0] = seed;

    for (int i = 1; i < 624; i++)
    {
        mt[i] =
            1812433253UL *
            (mt[i - 1] ^ (mt[i - 1] >> 30)) +
            i;
    }

    index = 624;
}

void Die::set_dieValue(int value)
{
    m_dieValue = value;
}

int Die::get_dieValue()
{
    return m_dieValue;
}

void Die::set_numOfSides(int sides)
{
    if (sides == 4 || sides == 6 || sides == 8)
    {
        m_numOfSides = sides;
    }
}

int Die::get_numOfSides()
{
    return m_numOfSides;
}

void Die::rollDie()
{
    m_dieValue =
        static_cast<int>(extractNumber() % m_numOfSides) + 1;
}
