#ifndef ENUMS_H
#define ENUMS_H

 /**
  * @file    enums.h
  * @brief   Various enums used both in the API and internally in libsedml-script.
  * @author  Lucian Smith
  *
  */

/**
 * block_type defines the different elements that define indented blocks in sedml-script.
 * - btFor: A for loop.
 * - btIf: Conditional.
 * - btDef: Function definition.
 * - btUnknown: An unknown or illegal block definition keyword.
 */
enum statement_type {stEquals, stExecute, stBlockFor, stBlockIf, stBlockElse, stBlockElif, stBlockDef, stUnknown};


  
  
/**
 * block_type defines the different elements that define indented blocks in sedml-script.
 * - btFor: A for loop.
 * - btIf: Conditional.
 * - btDef: Function definition.
 * - btUnknown: An unknown or illegal block definition keyword.
 */
enum block_type {btFor = 0, btIf, btElif, btElse, btDef, btUnknown};

/**
 * python_library defines the programming environments that this library knows about
 * for using SED-ML Script.
 * - pl_roadrunner: The python libroadrunner library.
 */
enum python_library {pl_roadrunner = 0};

#endif // ENUMS_H
