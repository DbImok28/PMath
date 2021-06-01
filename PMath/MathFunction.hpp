#pragma once
#include "PMath.hpp"

template<class T>
class MathFunction
{
private:
	std::string Name;
	MathExpression<T>& Expression;
public:
	MathFunction(std::string Name, MathExpression<T>& Expression) : Name(Name), Expression(Expression) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const
	{	
		return Expression.Calculate(ms);
	}
	const std::string_view& GetName() const noexcept
	{
		return Name;
	}
};