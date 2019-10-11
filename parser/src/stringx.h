#ifndef STRINGX_H
#define STRINGX_H

#include <string>
#include <vector>
#include <set>
#include "sedml-script-namespace.h"
#include "enums.h"

SEDMLSCRIPT_CPP_NAMESPACE_BEGIN
//String functions
std::string SizeTToString(size_t num);
std::string DoubleToString(double num);
std::string getStringFrom(const std::vector<const std::string*>* name, std::string cc=".");
std::string getStringFrom(const std::vector<std::string>* name, std::string cc=".");
std::string getStringFrom(const std::vector<double>& numbers);
std::vector<std::string> getStringVecFromDelimitedString(const std::string& var, std::string delimiter="_____");

std::string getStringFrom(block_type btype);
block_type getBlockTypeFrom(std::string btype);

bool IsReal(const std::string& src);
bool IsInt(const std::string& src);

bool CaselessStrCmp(const std::string& lhs, const std::string& rhs);
SEDMLSCRIPT_CPP_NAMESPACE_END

#endif //STRINGX_h
