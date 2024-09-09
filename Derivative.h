#ifndef DERIVATIVE_H
#define DERIVATIVE_H
#include <string>
class Derivative {
    public:
        Derivative(double num, double pow, std::string var);
        Derivative(double num, std::string var, std::string trig);
        std::string var_derivative();
        std::string trig_derivative();
        double num;
        double pow;
        std::string var;
        std::string trig;
};

#endif