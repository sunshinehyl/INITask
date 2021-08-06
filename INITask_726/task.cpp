#include <string>
#include <iostream>
#include <istream>
#include <fstream>

#include "INIReader.h"
#include "INITasks.h"


using std::string;

//  TODO 1. int类型处理
// 2. 函数命名 taskOrder*
// 3. frequency变量名*
// 4. 不用输出WFB*
// 5. 取出consist_variable不变量*
// 6. 用户自主选择排序方式
// 7. resize consist_variable*
int main(int argc, char* argv[]){

      //test
    /*variable_elem a;
    variable_elem b;
    a.double_value = -3;
    b.double_value = -1;
    if(a<b){
        std::cout<<"hello world!\n";
    }

    std::cout<<a.int_value<<"  \n";
    std::cout<<b.int_value<<"  ";

    union int_float{
        long long int int_value;
        double float_value;
    };
    int_float a;
    a.float_value = 30;
    std::cout<<a.int_value<<"\n";

    long long int b;
    b = 1027*pow(2,52)+7*pow(2,49);


    std::cout<<b<<"\n";
    std::cout<<a.int_value<<"\n";*/

    string inifile = "first.ini";
    INIReader reader(inifile.c_str());
    string freq="";
    string inci_theta="";
    string inci_phi="";
    double inci_angle=0;

    freq = reader.GetString("FREQUENCY", "Value", "0:0:0");
    inci_theta = reader.GetString("INCIDENT_WAVE", "Theta", "0:0:0");
    inci_phi = reader.GetString("INCIDENT_WAVE", "Phi", "0:0:0");
    inci_angle = reader.GetReal("INCIDENT_WAVE", "PolarizationAngle", 0);

    INITasks task;
    //加入frequence
    string freq_name;
    freq_name = "frequence";
    task.addVariable(variable_type(1),freq_name,freq);
    //添加由frequence_value得到的恒定值
    task.addInvariable(freq_name,freq);

    //加入incident_wave
    string incident_theta_name;
    incident_theta_name = "incident_theta";
    task.addVariable(variable_type(1),incident_theta_name,inci_theta);

    string incident_phi_name;
    incident_phi_name = "incident_phi";
    task.addVariable(variable_type(1),incident_phi_name,inci_phi);

    string incident_angle_name;
    incident_angle_name = "incident_angle";
    task.addInvariable(incident_angle_name, inci_angle);

    task.taskOrder(incident_theta_name);


    return 0;
}










