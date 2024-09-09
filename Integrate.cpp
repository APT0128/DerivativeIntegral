#include "Integrate.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

Integrate::Integrate(double new_num, double new_pow, const std::string VAR) {
    num = new_num;
    pow = new_pow;
    var = VAR;
}
Integrate::Integrate(double new_num, const std::string VAR, string new_trig) {
    num = new_num;
    var = VAR;
    trig = new_trig;
}

string Integrate::var_integrate() {
    string answer;
    pow++;
    if (pow != 0.00) {
        num = num / pow;
    }
    string str_num = to_string(num);
    string str_pow = to_string(pow);
    str_num = str_num.substr(0, str_num.find_first_of('.') + 3);
    str_pow = str_pow.substr(0, str_pow.find_first_of('.') + 3);
    if (pow != 0.00 && pow != 1.00) {
        if (num == 1.00) {
            answer = var + "^" + str_pow;
        } else if (num == -1.00) {
            answer = "-" + var + "^" + str_pow;
        } else if (num == 0.00) {
            answer = str_num;
        } else {
            answer = str_num + var + "^" + str_pow;
        }
    } else if (pow == 0.00) {
        if (num == 1.00) {
            answer = "ln" + var;
        } else if (num == -1.00) {
            answer = "-ln" + var;
        } else if (num == 0.00) {
            answer = str_num;
        } else {
            answer = str_num + "ln" + var;
        }
    } else if (pow == 1.00) {
        answer = str_num + var;
    }
    return answer ;
}

string Integrate::trig_integrate() {
    string answer;
    string str_num;
    if (trig == "sin") {
        trig = "cos";
        num *= -1;
        str_num = to_string(num);
        str_num = str_num.substr(0, str_num.find_first_of('.') + 3);
        if (num != 1.00 && num != -1.00 && num != 0.00) {
            answer = str_num + trig + var;
        } else if (num == 1.00) {
            answer = trig + var;
        } else if (num == -1.00) {
            answer = "-" + trig + var;
        } else if (num == 0.00) {
            answer = str_num;
        }
    } else if (trig == "cos") {
        trig = "sin";
        str_num = to_string(num);
        str_num = str_num.substr(0, str_num.find_first_of('.') + 3);
        if (num != 1.00 && num != -1.00 && num != 0.00) {
            answer = str_num + trig + var;
        } else if (num == 1.00) {
            answer = trig + var;
        } else if (num == -1.00) {
            answer = "-" + trig + var;
        } else if (num == 0.00) {
            answer = str_num;
        }
    } else if (trig == "tan") {
        num *= -1;
        str_num = to_string(num);
        str_num = str_num.substr(0, str_num.find_first_of('.') + 3);
        if (num != 1.00 && num != -1.00 && num != 0.00) {
            answer = str_num + "ln|cos" + var + "|";
        } else if (num == 1.00) {
            answer = "ln|cos" + var + "|";
        } else if (num == -1.00) {
            answer = "-ln|cos" + var + "|";
        } else if (num == 0.00) {
            answer = str_num;
        }
    } else if (trig == "sec") {
        str_num = to_string(num);
        str_num = str_num.substr(0, str_num.find_first_of('.') + 3);
        if (num != 1.00 && num != -1.00 && num != 0.00) {
            answer = str_num + "ln|sec" + var + " + tan" + var + "|";
        } else if (num == 1.00) {
            answer = "ln|sec" + var + " + tan" + var + "|";
        } else if (num == -1.00) {
            answer = "-ln|sec" + var + " + tan" + var + "|";
        } else if (num == 0.00) {
            answer = str_num;
        }
    } else if (trig == "csc") {
        num *= -1;
        str_num = to_string(num);
        str_num = str_num.substr(0, str_num.find_first_of('.') + 3);
        if (num != 1.00 && num != -1.00 && num != 0.00) {
            answer = str_num + "ln|csc" + var + " + cot" + var + "|";
        } else if (num == 1.00) {
            answer = "ln|csc" + var + " + cot" + var + "|";
        } else if (num == -1.00) {
            answer = "-ln|csc" + var + " + cot" + var + "|";
        } else if (num == 0.00) {
            answer = str_num;
        }
    } else if (trig == "cot") {
        str_num = to_string(num);
        str_num = str_num.substr(0, str_num.find_first_of('.') + 3);
        if (num != 1.00 && num != -1.00 && num != 0.00) {
            answer = str_num + "ln|sin" + var + "|";
        } else if (num == 1.00) {
            answer = "ln|sin" + var + to_string('|');
        } else if (num == -1.00) {
            answer = "-ln|sin" + var + to_string('|');
        } else if (num == 0.00) {
            answer = str_num;
        }
    } else {
        answer = "0.00";
    }
    return answer; 
}