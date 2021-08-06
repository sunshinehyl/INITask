#include "Basevariable.h"
#include <iostream>
#include <cmath>

using std::string;

Basevariable::Basevariable(string& variable_){
    variable = variable_;
}

//以特定字符，切割字符串
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c){
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while(std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2-pos1));
    
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if(pos1 != s.length())
        v.push_back(s.substr(pos1));
}

int StartStepEnd::variableHandle(std::vector<double>& elem_variable){

    std::vector<std::string> v_;
    double start_;
    double step_;
    double end_;
    int num_=1;

    SplitString(variable,v_,":");
    if(v_.size()<3){
        std::cout<<"the variable type is error! eg:120:10:180!\n";
        return -1;
    }

    start_ = atof(v_[0].c_str());
    step_ = atof(v_[1].c_str());
    end_ = atof(v_[2].c_str());

    if(((end_-start_)>0 && (step_<0))||(step_==0)||((start_-end_)>0 && (step_>0))){
        std::cout<<"the variable value is error!\n";
        return -1;
    }

    num_ = ceil((end_-start_)/step_);
    if(num_>0)
        num_ = std::abs(num_) + 1;

    elem_variable.resize(4);
    elem_variable[0] = start_;
    elem_variable[1] = step_;
    elem_variable[2] = num_*1.0;
    elem_variable[3] = end_;

    return 0;
}

int VariableVauleConstant::variableHandle(std::vector<double>& elem_variable){
    string variable_value;
    variable_value = variable;

    float variable_start;
    float variable_step;
    float variable_num;
    float variable_end;

    variable_start = atof(variable_value.c_str());
    variable_step = 0.0;
    variable_end = variable_start;
    variable_num = 1.0;

    elem_variable.resize(4);
    elem_variable[0] = variable_start;
    elem_variable[1] = variable_step;
    elem_variable[2] = variable_num;
    elem_variable[3] = variable_end;

    return 0;
}

















