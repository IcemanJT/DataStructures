#include "setList.h"

int setList::getSize()
{
    return vec.size();
}

void setList::printSet()
{
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
}

void setList::insert(int x)
{
    if (!isInSet(x))
    {
        vec.push_back(x);
    }
}

void setList::withdraw(int x)
{
    if (isInSet(x))
    {
        vec.remove(x);
    }
}

bool setList::isInSet(int x)
{
    for (auto i : vec)
    {
        if (i == x)
        {
            return true;
        }
    }
    return false;
}

setList setList::operator+(setList& obj)
{
    setList temp;
    for (auto i : vec)
    {
        temp.insert(i);
    }
    for (auto i : obj.vec)
    {
        temp.insert(i);
    }
    return temp;
}

setList setList::operator*(setList& obj)
{
    setList temp;
    for (auto i : vec)
    {
        if (obj.isInSet(i))
        {
            temp.insert(i);
        }
    }
    return temp;
}

setList setList::operator-(setList& obj)
{
    setList temp;
    for (auto i : vec)
    {
        if (!obj.isInSet(i))
        {
            temp.insert(i);
        }
    }
    return temp;
}

bool setList::operator==(setList& obj)
{
    if (vec.size() != obj.vec.size())
    {
        return false;
    }
    for (auto i : vec)
    {
        if (!obj.isInSet(i))
        {
            return false;
        }
    }
    return true;
}

bool setList::operator<=(setList& obj)
{
    if (vec.size() > obj.vec.size())
    {
        return false;
    }
    for (auto i : vec)
    {
        if (!obj.isInSet(i))
        {
            return false;
        }
    }
    return true;
}