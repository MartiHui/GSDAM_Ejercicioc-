#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <utility>
#include <string>
#include <vector>

class DataStruct {
private:
    int numCampos;
    std::vector<std::pair<std::string, int> > campos;
public:
    void setNumCampos(int num);
    int getNumCampos();
    int addCampo(std::string nombre, int len);
};
#endif // DATASTRUCT_H
