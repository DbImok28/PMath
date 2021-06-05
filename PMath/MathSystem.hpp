#pragma once
#include "PMath.hpp"

template<class T>
class MathSystem
{
private:
public:
	std::vector<MathFunction<T>> Functions;
	/*MathSystem(const MathSystem&) = delete;
	MathSystem(MathSystem&&) = delete;
	MathSystem& operator=(const MathSystem&) = delete;
	MathSystem& operator=(MathSystem&&) = delete;*/

	MathSystem(std::initializer_list<MathFunction<T>>&& l) : Functions(l) {}
	MathSystem(std::vector<MathFunction<T>> v) : Functions(v) {}
	MathSystem() = default;
	T Calculate(std::string FunctionName)
	{
		for (const MathFunction<T>& fun : Functions)
		{
			if (fun.GetName() == FunctionName)
			{
				return fun.Calculate(*this);
			}
		}
		throw PMathBadExpression("Error MathSystem: Unknown variable " + FunctionName);;
		// error
	}/*
	const std::vector<MathFunction<T>&>& GetFunctions() const noexcept
	{
		return Functions;
	}*/
};