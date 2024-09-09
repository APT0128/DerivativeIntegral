#ifndef INTEGRATE_H
#define INTEGRATE_H
#include <string>
class Integrate {
    public:
        Integrate(double num, double pow, std::string var);
        Integrate(double num, std::string var, std::string trig);
        std::string var_integrate();
        std::string trig_integrate();
        double num;
        double pow;
        std::string var;
        std::string trig;
};

#endif

