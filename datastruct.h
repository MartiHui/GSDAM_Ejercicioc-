#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <utility>
#include <string>
#include <vector>

class DataStruct {
private:
    int numCampos_;
    std::vector<std::pair<std::string, int> > campos_;

public:
    void setNumCampos(int num);
    int getNumCampos();
    void addCampo(std::string nombre, int len);
    std::pair<std::string, int> getCampo(int indice);
};
#endif // DATASTRUCT_H
