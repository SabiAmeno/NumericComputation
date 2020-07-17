#pragma once

#include <vector>
#include <cmath>

namespace NC
{
    struct PolyCoef
    {
        double _an; //系数
        int    _ts; //次数
    };

    typedef std::vector<PolyCoef> PolyCOEFs;
    const int N0 = 20;

    class ABSPoly 
    { 
    public:
        virtual ~ABSPoly() {}

        virtual double operator() () = 0;

        void setEpsilon(double e) { _epsilon = e; }
    protected:
        double _epsilon = 0.00001;
    };

    class BinInterp : public ABSPoly
    {
    public:
        BinInterp(const PolyCOEFs& coef, double a, double b) :_coefs(coef), _a(a), _b(b) {}

        virtual double operator()() override
        {
            int i = 0;
            double a = _a;
            double b = _b;

            double m = (b - a) / 2;
            double r = calc(a + m);

            while (true) {
                if (i++ > N0 || abs(m) < _epsilon)
                    break;
                double ra = calc(a);
                double rb = calc(b);

                if (ra * r < 0)
                    b = a + m;
                else if (rb * r < 0)
                    a = a + m;

                m = (b - a) / 2;
                r = calc(a + m);
            }

            return a + m;
        }
    private:
        double calc(double x)
        {
            double sum = 0;
            for (auto co : _coefs) {
                sum += co._an * std::pow(x, co._ts);
            }

            return sum;
        }
    private:
        double _a;
        double _b;

        PolyCOEFs _coefs;
    };
}


