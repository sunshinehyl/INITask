#ifndef INI_HANDLER_H
#define INI_HANDLER_H

#include <map>
#include <string>
#include <vector>
#include "INIReader.h"

using std::string;

class INI_Handler
{
private:
    /* data */
    string ini_file;
    string out_file;
    string name;
    std::map<string,double> mat_value;

    int _error;
public:
    INI_Handler(const string& filename_ini, const string& filename_out, const string& name_pos);
    ~INI_Handler();
    //生成不做改变的文件，出现错误，返回-1
    int copyfile(const string& read_flie,string write_file); 
    int C_FGP();
    int C_VGP(); 
    //以指定的字符，分割字符串
    void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c);
    //以空格分割字符串，不管连续空格的数量
    void Split_String(const std::string& s, std::vector<std::string>& v);
    //生成CRWG_CSWG_VSIE_Tet.DAT文件，出现错误，返回-2
    int Ctet_file(INIReader reader);
    int Ctet_file_matr(std::map<string,int> matr_num,int tetrahedron_num);
    //生成INCF_BiRCS.DAT文件，出现错误，返回-3
    int Incf_file(INIReader reader,const string& incf_flie);
    //生成WFB_BiRCS.DAT文件出现，出现错误，返回-4
    int Wfb_file(INIReader reader,const string& wfb_flie,std::map<string,int>& pre_,std::map<string,int>& type_,std::array<double,15>& wfb_model);
    //生成node.geo文件，出现错误，返回-5
    int node_geo(std::ifstream& infile, std::vector<std::string>& geo_v, const string& out_file);
    //生成elem.geo文件，出现错误，返回-6,读mat文件出错，返回-7
    int mat_read();
    int mid_elem(std::ifstream& infile, std::vector<std::string>& geo_v, const string& out_file);
    int elem_geo(std::ifstream& infile, std::vector<std::string>& geo_v, const string& out_file);
    //生成geo文件，读配置geo网格出现错误返回2，生成geo文件时要读.dat文件，然而ini_out会生成.dat文件，
    //为保证读取对的.dat文件，所以需先执行geo_out，如果不需生成geo文件，则只要执行ini_out即可
    int geo_out();
    //生成配置文件,读配置ini文件出现错误返回1
    int ini_out(std::array<double,15>& wfb_model);
    
};

void setPolizationDirection(double * inc_dir, double angle_, double& pol_theta, double& pol_phi);

#endif  // INI_HANDLER_H
