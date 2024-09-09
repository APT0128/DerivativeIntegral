#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Integrate.h"
#include "Derivative.h"
using namespace std;

int main() {
    cout << "Input variable: (I.E. x in 3x)" << endl;
    string var;
    cin >> var;
    cout << "Input function: (Use '^' to emphasize the power (put in parentheses and can only handle non-variables), can only handle one trig, and must contain no spaces)" << endl;
    string funct;
    cin >> funct;
    unsigned int end_pos = 0;
    string char_to_str = "";
    vector<string> trig_list{"sin", "cos", "tan", "sec", "csc", "cot"};
    vector<string> funct_list;
    if (funct.find(var) < funct.length() && ((funct.find('-') < funct.length() && funct.find('-') > 0) || funct.find('+') < funct.length())) {
        while (end_pos < funct.length()) {
            for (unsigned int i = end_pos; i < funct.length(); i++) {
                if ((funct[i] == '-' && funct[i-1] != '(' && i > 0) || funct[i] == '+' || i == funct.length() - 1) {
                    string part_funct = funct.substr(end_pos, i+1);
                    funct_list.push_back(part_funct);
                    if (i < funct.length() - 1) {
                        char_to_str.append(1, funct[i]);
                        funct_list.push_back(char_to_str);
                        char_to_str = "";
                        end_pos = i+1;
                    } else {
                        end_pos = i+1;
                    }
                    break;
                }
            }
        }
    } else {
        funct_list.push_back(funct);
    }
    double num;
    double pow;
    string trig = "";
    int trig_index;
    bool contain_trig = false;
    cout << "Input 1 for Integration and 2 for Derivatives" << endl;
    int input;
    while (input != 1 && input != 2) {
        cin >> input;
    }
    for (unsigned int i = 0; i < funct_list.size(); i++) {
        if (funct_list[i] != "+" && funct_list[i] != "-") {
            // Finding if the function contains trigonometry
            for (unsigned int j = 0; j < trig_list.size(); j++) {
                if (funct_list[i].find(trig_list[j]) < funct_list.size()) {
                    trig_index = funct_list[i].find(trig_list[j]);
                    trig = trig_list[j];
                    contain_trig = true;
                    break;
                }
            }
            if (contain_trig) {
                if (trig_index == 0) {
                    num = 1.00;
                } else {
                    num = stod(funct_list[i].substr(0, trig_index));
                }
            } else {
                if (funct_list[i].find(var) == 0) {
                    num = 1.00;
                } else {
                    if (funct_list[i].find(var)) {
                        num = stod(funct_list[i].substr(0, funct_list[i].find(var)));
                    } else {
                        num = stod(funct_list[i]);
                    }
                }
            }
            // Finding the power of the function through detecting "^"
            unsigned int pow_start_index = funct_list[i].find('(');
            if (pow_start_index < funct_list[i].size() && funct_list[i].find('^') == pow_start_index - 1) {
                pow = stod(funct_list[i].substr(pow_start_index + 1, funct_list[i].find(')')));
            } else {
                if (funct_list[i].find(var) < funct_list[i].size()) {
                    pow = 1.00;
                } else {
                    pow = 0.00;
                }
            }

            // Use of Integrate Function
            switch (input) {
                case 1:
                    if (trig != "") {
                        cout << num << " " << var << " " << trig << endl;
                        Integrate trig_int(num, var, trig);
                        string result = trig_int.trig_integrate();
                        funct_list[i] = result;
                    } else {
                        cout << num << " " << pow << " " << var << endl;
                        Integrate var_int(num, pow, var);
                        string result = var_int.var_integrate();
                        funct_list[i] = result;
                    }
                    break;
                case 2:
                    if (trig != "") {
                        cout << num << " " << var << " " << trig << endl;
                        Derivative trig_der(num, var, trig);
                        string result = trig_der.trig_derivative();
                        funct_list[i] = result;
                    } else {
                        cout << num << " " << pow << " " << var << endl;
                        Derivative var_der(num, pow, var);
                        string result = var_der.var_derivative();
                        funct_list[i] = result;
                    }
                    break;
            }
        }
    }
    if (funct_list[0] == "-") {
        if (funct_list[1][0] == '-') {
            funct_list[1] = funct_list[1].substr(1);
        } else {
            funct_list[1] = "-" + funct_list[1];
        }
        funct_list.erase(funct_list.begin());
    }
    for (unsigned int k = 0; k < funct_list.size(); k++) {
        if (funct_list[k] == "+" && funct_list[k+1][0] == '-') {
            funct_list[k] = "-";
            funct_list[k+1] = funct_list[k+1].substr(1);
        } else if (funct_list[k] == "-" && funct_list[k+1][0] == '-') {
            funct_list[k] = "+";
            funct_list[k+1] = funct_list[k+1].substr(1);
        }
    }
    string new_funct;
    for (unsigned int l = 0; l < funct_list.size(); l++) {
        new_funct = new_funct + " " + funct_list[l];
    }
    switch (input) {
        case 1:
            cout << "Integral of " << funct << " is:" << new_funct << " + C";
            break;
        case 2:
            cout << "Derivative of " << funct << " is: " << new_funct;
            break;
    }
    return 0;
}