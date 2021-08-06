#ifndef BASEVARIABLE_H
#define BASEVARIABLE_H

#include <map>
#include <string>
#include <vector>
#include <array>

using std::string;

//base
class Basevariable
{
public:
    //接口框架的纯虚函数
    Basevariable(string& variable_);
    virtual int variableHandle(std::vector<double>& elem_variable)=0;
protected:
    string variable;
};

//variable type：start step end
class StartStepEnd: public Basevariable
{
public:
    StartStepEnd(string& variable_): Basevariable(variable_){}
    int variableHandle(std::vector<double>& elem_variable);
};

//variable type:
class VariableVauleConstant:public Basevariable
{
public:
    VariableVauleConstant(string& variable_): Basevariable(variable_) {}
    int variableHandle(std::vector<double>& elem_variable);
};

#endif  // BASEVARIABLE_H
