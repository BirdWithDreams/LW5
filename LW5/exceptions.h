#pragma once
#include <string>

class EmptyArrayException
{
public:
	EmptyArrayException();
	EmptyArrayException(std::string _text);
	std::string what();

private:
	std::string text;
};

class EmptyListException
{
public:
	EmptyListException();
	EmptyListException(std::string _text);
	std::string what();

private:
	std::string text;
};