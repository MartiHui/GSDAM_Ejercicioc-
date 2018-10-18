#include <string>
#include <sstream>

#include "m_utilities.h"

template<class T>
std::string to_string(T t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
}
