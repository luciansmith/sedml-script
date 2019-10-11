/**
 * @file    sedml-script-namespace.h
 * @brief   Defines C++ namespace of libphraSEDML
 * @author  Lucian Smith, from Akiya Jouraku
 * 
 */

#ifndef SEDMLSCRIPT_NAMESPACE_H
#define SEDMLSCRIPT_NAMESPACE_H 1

/*
 *
 * The idea of the following marcors are borrowed from 
 * Xerces-C++ XML Parser (http://xerces.apache.org/xerces-c/).
 *
 */

/* Define to enable sedml-script C++ namespace */
/* #undef SEDMLSCRIPT_USE_CPP_NAMESPACE */


#if defined(__cplusplus) && !defined(SWIG)
  /* C++ namespace of sedml-script */
  #define SEDMLSCRIPT_CPP_NAMESPACE            sedmlscript
  #define SEDMLSCRIPT_CPP_NAMESPACE_BEGIN      namespace SEDMLSCRIPT_CPP_NAMESPACE {
  #define SEDMLSCRIPT_CPP_NAMESPACE_END        }
  #define SEDMLSCRIPT_CPP_NAMESPACE_USE        using namespace SEDMLSCRIPT_CPP_NAMESPACE;
  #define SEDMLSCRIPT_CPP_NAMESPACE_QUALIFIER  SEDMLSCRIPT_CPP_NAMESPACE::

#else
  #define SEDMLSCRIPT_CPP_NAMESPACE 
  #define SEDMLSCRIPT_CPP_NAMESPACE_BEGIN
  #define SEDMLSCRIPT_CPP_NAMESPACE_END  
  #define SEDMLSCRIPT_CPP_NAMESPACE_USE 
  #define SEDMLSCRIPT_CPP_NAMESPACE_QUALIFIER 
#endif


#endif  /* SEDMLSCRIPT_NAMESPACE_H */

