/**
  * @file    sedml-script_api.h
  * @brief   The API for the Sedml-Script parser
  * @author  Lucian Smith
  *
  * libsedml-script uses a bison parser and internal C++ objects to read, convert, store, and output abstracted descriptions of biological simulation experiments.  Information about creating phraSEDML-formatted input files is available from http://sedml-script.sourceforge.net/.  The functions described in this document are a plain C API (application programming interface) to be used in programs that want to convert phraSEDML models to their own internal formats, and/or to convert phraSEDML models to and from SBML models.
  *
  * Note:  It is not currently possible to convert an internally-formatted model into an phraSEDML model (the API has several 'get' functions, but no 'set' functions).  This restriction may be relaxed in future versions of the library.
  *
  * Converting files may be accomplished fairly straightforwardly using 'loadFile' to read in a file (of phraSEDML or SEDML formats), and the 'writeSedmlScriptFile', 'writeSEDMLFile', 'writeSedmlScriptString', and 'writeSEDMLString' routines to write them out again.
  *
  * In general, phraSEDML models may contain:
  * - Models
  * - Simulations
  * - Tasks (and repeated tasks)
  * - Outputs
  *
  * <b>Returned Pointers</b><br/>
  * The majority of the functions described below return pointers to arrays and/or strings.  These pointers you then own, and are created with 'malloc':  you must 'free' them yourself to release the allocated memory.  Some programming environments will handle this automatically for you, and others will not.  If you want to not bother with it, the function 'freeAllSedmlScript' is provided, which will free every pointer created by this library.  In order for this to work, however, you must have not freed a single provided pointer yourself, and you must not subsequently try to reference any data provided by the library (your own copies of the data will be fine, of course).
  *
  * If the library runs out of memory when trying to return a pointer, it will return NULL instead and attempt to set an error mes * @if python
 * getLastError()'.
 * @else
 * getLastSedmlScriptError()'.
 * @endif
  *
 */


#ifndef PHRASEDML_API_H
#define PHRASEDML_API_H

#ifndef LIBPHRASEDML_VERSION_STRING //Should be defined in the makefile (from CMakeLists.txt)
#define LIBPHRASEDML_VERSION_STRING "v1.0.3"
#endif

#include "libutil.h"
#include "sedml-script-namespace.h"

BEGIN_C_DECLS

SEDMLSCRIPT_CPP_NAMESPACE_BEGIN

/**
 * Convert a file from phraSEDML to SEDML, or visa versa.  If NULL is returned, an error occurred, which can be retrieved with
 * @if python
 * getLastError()'.
 * @else
 * getLastSedmlScriptError()'.
 * @endif
 *
 * @return The converted file, as a string.
 *
 * @param filename the filename as a character string.  May be either absolute or relative to the directory the executable is being run from.
 *
 * @if python
 * @see getLastError()
 * @else
 * @see getLastSedmlScriptError()
 * @endif
 */
LIB_EXTERN char* convertFile(const char* filename);

/**
 * Convert a model string from phraSEDML to SEDML, or visa versa.  If NULL is returned, an error occurred, which can be retrieved with
 * @if python
 * getLastError().
 * @else
 * getLastSedmlScriptError().
 * @endif
 *
 * @return The converted model, as a string.
 *
 * @param model the model as a character string.  May be either SED-ML or phraSED-ML.
 *
 * @if python
 * @see getLastError()
 * @else
 * @see getLastSedmlScriptError()
 * @endif
 */
LIB_EXTERN char* convertString(const char* model);

/**
 * When any function returns an error condition, a longer description of the problem is stored in memory, and is obtainable with this function.  In most cases, this means that a call that returns a pointer returned 'NULL' (or 0).
 */
LIB_EXTERN char*  getLastSedmlScriptError();

/**
 * Returns the line number of the file where the last error was obtained, if the last error was obtained when parsing a phraSED-ML file.  Otherwise, returns 0.
 */
LIB_EXTERN int getLastSedmlScriptErrorLine();

/*
 * When translating some other format to phraSEDML, elements that are unable to be translated are saved as warnings, retrievable with this function (returns NULL if no warnings present).
 */
//LIB_EXTERN char*  getSedmlScriptWarnings();

/**
 * If a previous 'convert' call was successful, the library retains an internal representation of the SEDML and the SedmlScript.  This call converts that representation to SEDML and returns the value, returning an empty string if no such model exists.
 */
LIB_EXTERN char*  getLastSEDML();

/**
 * If a previous 'convert' call was successful, the library retains an internal representation of the SEDML and the SedmlScript.  This call converts that representation to SedmlScript and returns the value, returning an empty string if no such model exists.
 */
LIB_EXTERN char*  getLastSedmlScript();

/**
 * Frees all pointers handed to you by libphraSEDML.
 * All libphraSEDML functions above that return pointers return malloc'ed pointers that you now own.  If you wish, you can ignore this and never free anything, as long as you call 'freeAllSedmlScript' at the very end of your program.  If you free *anything* yourself, however, calling this function will cause the program to crash!  It won't know that you already freed that pointer, and will attempt to free it again.  So either keep track of all memory management yourself, or only use this function every time you want to clean up memory.
 *
 * Note that this function only frees pointers handed to you by other sedml-script_api functions.  The models themselves are still in memory and are available.  (To clear that memory, use clearPreviousLoads() )
 */
LIB_EXTERN void freeAllSedmlScript();

SEDMLSCRIPT_CPP_NAMESPACE_END
END_C_DECLS

#endif //PHRASEDML_API_H
