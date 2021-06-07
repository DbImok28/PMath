#pragma once

namespace PMath
{
	class PMathBadExpression;

	template<class T>
	class MathSystem;

	template<class T>
	class MathFunction;

	template<class T>
	class MathExpression;
}

#include <cmath>
#include <vector>
#include <optional>
#include <string>
#include <string_view>

#include "PMathException.hpp"
#include "PMathSystem.hpp"
#include "PMathExpression.hpp"
#include "PMathFunction.hpp"
#include "PMathBaseExpressions.hpp"
#include "PMathTrigonometricExpressions.h"