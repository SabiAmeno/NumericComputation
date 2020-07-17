// NC.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "nc_binary_interpolation.h"

int main()
{
    NC::PolyCOEFs coefs;
    coefs.push_back(NC::PolyCoef{ 1, 3 });
    coefs.push_back(NC::PolyCoef{ 4, 2 });
    coefs.push_back(NC::PolyCoef{ -10, 0 });

    NC::BinInterp bip(coefs, 1, 2);
    double r = bip();

    return 0;
}
