#pragma once
#include "PMath.hpp"

template<class T>
class MathExpression
{
public:
	virtual T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const = 0;
	virtual ~MathExpression() = default;
};