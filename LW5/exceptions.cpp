#include "exceptions.h"

EmptyArrayException::EmptyArrayException()
{
    text = "You can't pop from empty array";
}

EmptyArrayException::EmptyArrayException(std::string _text)
{
    text = _text;
}

std::string EmptyArrayException::what()
{
    return text;
}

EmptyListException::EmptyListException()
{
    text = "You can't pop item from empty list";
}

EmptyListException::EmptyListException(std::string _text)
{
    text = _text;
}

std::string EmptyListException::what()
{
    return text;
}