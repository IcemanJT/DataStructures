#include "setArr.h"

bool setArr::checkRangeCorrectness(int x)
{
    if (x < 0 || x >= universeSize)
    {
        std::cout << "Error: " << x << " is out of range" << std::endl;
        return false;
    }
    return true;
}

setArr::setArr()
{
    size = 0;
    table = new bool[universeSize];
    for (int i = 0; i < universeSize; i++)
    {
        table[i] = false;
    }
}

setArr::~setArr()
{
    delete[] table;
}

void setArr::insert(int x)
{
    if (checkRangeCorrectness(x))
    {
        if (!table[x])
        {
            table[x] = true;
            size++;
        }
    }
}

void setArr::withdraw(int x)
{
    if (checkRangeCorrectness(x))
    {
        if (table[x])
        {
            table[x] = false;
            size--;
        }
    }
}

bool setArr::isInSet(int i)
{
    if (checkRangeCorrectness(i))
    {
        return table[i];
    }
    return false;
}

int setArr::getSize()
{
    return size;
}

void setArr::clearSet()
{
    for (int i = 0; i < universeSize; i++)
    {
        table[i] = false;
    }
    size = 0;
}

void setArr::printSet()
{
    int i = 0;
    while (i < universeSize)
    {
        if (table[i])
        {
            std::cout << i << " ";
        }
        i++;
    }
}

setArr setArr::operator+(setArr &object)
{
    setArr result;
    for (int i = 0; i < universeSize; i++)
    {
        if (table[i] || object.table[i])
        {
            result.insert(i);
        }
    }
    return result;
}

setArr setArr::operator*(setArr &object)
{
    setArr result;
    for (int i = 0; i < universeSize; i++)
    {
        if (table[i] && object.table[i])
        {
            result.insert(i);
        }
    }
    return result;
}

setArr setArr::operator-(setArr &object)
{
    setArr result;
    for (int i = 0; i < universeSize; i++)
    {
        if (table[i] && !object.table[i])
        {
            result.insert(i);
        }
    }

    return result;
}

bool setArr::operator==(setArr &object)
{
    for (int i = 0; i < universeSize; i++)
    {
        if (table[i] != object.table[i])
        {
            return false;
        }
    }
    return true;
}

bool setArr::operator<=(setArr &object)
{
    for (int i = 0; i < universeSize; i++)
    {
        if (table[i] && !object.table[i])
        {
            return false;
        }
    }
    return true;
}