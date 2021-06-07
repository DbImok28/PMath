#pragma once

namespace PMath
{

	template<class T> 
	class PI : public MathExpression<T>
	{
	public:
		PI() = default;
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(3.14159265358979323);
		}
	};
	template<class T>
	class Sin : public MathExpression<T>
	{
	public:
		Sin(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(sin(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class Cos : public MathExpression<T>
	{
	public:
		Cos(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(cos(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class Tan : public MathExpression<T>
	{
	public:
		Tan(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(tan(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class Cot : public MathExpression<T>
	{
	public:
		Cot(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(cos(left.Calculate(ms)) / sin(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class Csc : public MathExpression<T>
	{
	public:
		Csc(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(static_cast<T>(1) / sin(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class Sec : public MathExpression<T>
	{
	public:
		Sec(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(static_cast<T>(1) / cos(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};

	template<class T> using Tg		= Tan<T>;
	template<class T> using Ctg		= Cot<T>;
	template<class T> using Cosec	= Csc<T>;

	// -----------------

	template<class T>
	class ASin : public MathExpression<T>
	{
	public:
		ASin(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(asin(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class ACos : public MathExpression<T>
	{
	public:
		ACos(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(acos(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class ATan : public MathExpression<T>
	{
	public:
		ATan(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(atan(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class ACot : public MathExpression<T>
	{
	public:
		ACot(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(static_cast<T>(3.14159265358979323846 / 2.0) - atan(left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class ACsc : public MathExpression<T>
	{
	public:
		ACsc(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(asin(static_cast<T>(1) / left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};
	template<class T>
	class ASec : public MathExpression<T>
	{
	public:
		ASec(MathExpression<T>& left) : left(left) {}
		T Calculate(const std::optional<MathSystem<T>>& ms = std::nullopt) const override
		{
			return static_cast<T>(acos(static_cast<T>(1) / left.Calculate(ms)));
		}
		MathExpression<T>& left;
	};

	template<class T> using ATg		= ATan<T>;
	template<class T> using ACtg	= ACot<T>;
	template<class T> using ACosec	= ACsc<T>;
}