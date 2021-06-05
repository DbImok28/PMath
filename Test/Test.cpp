#include <iostream>
#include <optional>
#include "PMath.hpp"

using namespace PMath;
int main()
{
    //MathSystem<float> ms({ { "x", Devide(Add(Num(2.f),Num(3.f)),Var<float>("y")) }, { "y",  Sqrt(Num(5.f)) } });

    auto numA = Num(2.f);
    auto numB = Num(3.f);
    auto numC = Num(25.f);
    auto varY = Var<float>("y");
    auto add = Add(numA, numB);
    auto devide = Devide(add, varY);
    auto sqr = Sqrt(numC);
    auto root = Root(numC, numB);
    auto pow = Pow(numA, numB);
    auto multiply = Multiply(numA, numB);

    MathSystem<float> ms({ { "x", devide },{ "y", sqr } });
    std::cout << root.Calculate() << std::endl;
    std::cout << pow.Calculate() << std::endl;
    std::cout << multiply.Calculate() << std::endl;
    std::cout << sqr.Calculate() << std::endl;
    std::cout << ms.Calculate("x") << std::endl;
    try
    {
        std::cout << devide.Calculate() << std::endl;
    }
    catch (const PMathBadExpression& e)
    {
        std::cout << e.what() << std::endl;
    }
}
