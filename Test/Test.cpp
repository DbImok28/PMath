#include <iostream>
#include <optional>
#include "PMath.hpp"

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

    MathSystem<float> ms({ { "x", devide },{ "y", sqr } });
    std::cout << sqr.Calculate() << std::endl;
    std::cout << ms.Calculate("x") << std::endl;
}
