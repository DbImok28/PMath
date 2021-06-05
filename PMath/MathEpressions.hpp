#pragma once
#include "PMath.hpp"
#include <cmath>

template<class T>
class Num : public MathExpression<T>
{
public:
	Num(T num) : num(num) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
	{
		return num;
	}
	T num;
};
template<class T>
class Var : public MathExpression<T>
{
public:
	Var(std::string FunctionName) : FunctionName(FunctionName) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
	{
		if (ms)
		{
			for (const MathFunction<T>& fun : ms->Functions)
			{
				if (fun.GetName() == FunctionName)
				{
					return fun.Calculate(ms);
				}
			}
		}
		throw PMathBadExpression("Error Var: Unknown variable " + FunctionName);
	}
	std::string FunctionName;
};
template<class T>
class Add : public MathExpression<T>
{
public:
	Add(MathExpression<T>& left, MathExpression<T>& right) : left(left), right(right) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
	{
		return left.Calculate(ms) + right.Calculate(ms);
	}
	MathExpression<T>& left;
	MathExpression<T>& right;
};
template<class T>
class Subtract : public MathExpression<T>
{
public:
	Subtract(MathExpression<T>& left, MathExpression<T>& right) : left(left), right(right) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
	{
		return left.Calculate(ms) - right.Calculate(ms);
	}
	MathExpression<T>& left;
	MathExpression<T>& right;
};
template<class T>
class Multiply : public MathExpression<T>
{
public:
	Multiply(MathExpression<T>& left, MathExpression<T>& right) : left(left), right(right) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
	{
		return left.Calculate(ms) * right.Calculate(ms);
	}
	MathExpression<T>& left;
	MathExpression<T>& right;
};
template<class T>
class Devide : public MathExpression<T>
{
public:
	Devide(MathExpression<T>& left, MathExpression<T>& right) : left(left), right(right) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
	{
		return left.Calculate(ms) / right.Calculate(ms);
	}
	MathExpression<T>& left;
	MathExpression<T>& right;
};
template<class T>
class Pow : public MathExpression<T>
{
public:
	Pow(MathExpression<T>& left, MathExpression<T>& right) : left(left), right(right) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
	{
		return pow<T,T>(left.Calculate(ms), right.Calculate(ms));
	}
	MathExpression<T>& left;
	MathExpression<T>& right;
};
template<class T>
class Sqrt : public MathExpression<T>
{
public:
	Sqrt(MathExpression<T>& left) : left(left) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
	{
		return static_cast<T>(sqrt(left.Calculate(ms)));
	}
	MathExpression<T>& left;
};
template<class T>
class Root : public MathExpression<T>
{
public:
	Root(MathExpression<T>& left, MathExpression<T>& right) : left(left), right(right) {}
	T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
	{
		return pow<T,T>(left.Calculate(ms), static_cast<T>(1) / right.Calculate(ms));
	}
	MathExpression<T>& left;
	MathExpression<T>& right;
};