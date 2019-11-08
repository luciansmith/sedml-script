#include <sstream>
#include <assert.h>
#include <iostream>
#include "stringx.h"
#include "registry.h"

using namespace std;
extern bool CaselessStrCmp(const string& lhs, const string& rhs);

SEDMLSCRIPT_CPP_NAMESPACE_BEGIN
string SizeTToString(size_t number)
{
  ostringstream ostr;
  ostr << number;
  return ostr.str();
}

string DoubleToString(double number)
{
  ostringstream ostr;
  ostr << number;
  return ostr.str();
}

string getStringFrom(const vector<const string*>* name, string cc)
{
  string retval = "";
  for (size_t nn=0; nn<name->size(); nn++) {
    if (nn>0) {
      retval += cc;
    }
    retval += *(*name)[nn];
  }
  return retval;
}

string getStringFrom(const vector<string>* name, string cc)
{
  string retval = "";
  for (size_t nn=0; nn<name->size(); nn++) {
    if (nn>0) {
      retval += cc;
    }
    retval += (*name)[nn];
  }
  return retval;
}

std::string getFinnickyStringFrom(const std::vector<std::string>* name, std::string cc)
{
  return getStringFrom(name, cc);
}

string getStringFrom(const vector<double>& numbers)
{
  stringstream ret;
  for (size_t nn=0; nn<numbers.size(); nn++) {
    if (nn>0) {
      ret << ", ";
    }
    ret << numbers[nn];
  }
  return ret.str();
}

vector<string> getStringVecFromDelimitedString(const string& var, string delimiter)
{
  vector<string> ret;
  size_t begin = 0;
  size_t end = var.find(delimiter);
  while (end != string::npos) {
    string substr = var.substr(begin, end-begin);
    ret.push_back(substr);
    begin = end+5;
    end = var.find(delimiter, begin);
  }
  string substr = var.substr(begin, end);
  ret.push_back(substr);
  return ret;
}

string getStringFrom(block_type btype)
{
  switch (btype) {
  case btIf:
    return "if";
  case btFor:
    return "for";
  case btDef:
    return "def";
  case btUnknown:
    assert(false);
    return "";
  }
  assert(false);
  return "";
}

block_type getBlockTypeFrom(string btype)
{
  if (btype == "if") {
    return btIf;
  }
  if (btype == "for") {
    return btFor;
  }
  if (btype == "def") {
    return btDef;
  }
  return btUnknown;
}


bool IsReal(const string& src)
{
  if (src.empty()) return false;

  long i;
  size_t end = src.size();
  bool pointfound = false;
  for (i = 0; i < end; ++i) {
    if (!isdigit(src[i])) {
      if (isspace(src[i])) continue; // whitespace is okay
      if (src[i] == '-') continue; // minus is okay
      if (src[i] == '+') continue; // plus is okay
      if (src[i] == 'e') continue; // e is okay
      if (src[i] != '.') return false;  // neither digit nor point
      if (pointfound) return false;   // a second decimal point?!
      pointfound = true;              // okay, first decimal point
    }
  }
  return true;
} /* IsReal */

bool IsInt(const string& src)
{
  if (src.empty()) return false;

  long i;
  size_t end = src.size();
  for (i = 0; i < end; ++i) {
    if (!isdigit(src[i])) {
      return false;   // Ints only have digits
    }
  }
  return true;
} /* IsInt */

string Trim(string in)
{
  string out = in;
  while (out.size() && out[0] == ' ') {
    out.erase(0,1);
  }
  while (out.size() && out[out.size()-1] == ' ') {
    out.erase(out.size()-1, 1);
  }
  size_t retpos;
  while ((retpos = out.find('\n')) != string::npos) {
    out.replace(retpos, 1, " ");
  }
  while ((retpos = out.find('\r')) != string::npos) {
    out.replace(retpos, 1, " ");
  }
  return out;
}

bool CaselessStrCmp(const string& lhs, const string& rhs)
{

  if (lhs.size() != rhs.size()) return false;

  for (size_t i = 0; i < lhs.size(); ++i) {
    if (toupper(lhs[i]) != toupper(rhs[i])) return false;
  }
  return true;

} /* CaselessStrCmp */
SEDMLSCRIPT_CPP_NAMESPACE_END
