#pragma once
#include <string>
#include <exception>

class PMathBadExpression : std::exception
{
public:
	PMathBadExpression() = default;

	PMathBadExpression(std::string info) : info(info) {}
	virtual const char* what() const throw()
	{
		return info.c_str();
	}
private:
	std::string info;
};

