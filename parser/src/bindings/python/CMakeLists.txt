###############################################################################
#
# Description  : CMake build script for phrasedml Python bindings
# Author(s)    : Lucian Smith, from libsbml and Frank Bergmann
#
###############################################################################

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
#include(FindPythonLibs)
#include(FindPythonInterp)
find_package(PythonInterp)
# specify that the same python library should be found
# as the one the selected interpreter uses
set (Python_ADDITIONAL_VERSIONS ${PYTHON_VERSION_STRING})
find_package(PythonLibs)

SET(LIBPHRASEDML_VERSION_STRING_NO_V "${LIBPHRASEDML_VERSION_MAJOR}.${LIBPHRASEDML_VERSION_MINOR}${LIBPHRASEDML_VERSION_PATCH}${LIBPHRASEDML_VERSION_RELEASE}")

####################################################################
#
# determine local dependencies, so as to re-swig if one of them changed
#

file(GLOB SWIG_DEPENDENCIES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.i
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.i
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.h
        )

#
# Remove SWIG wrappers if requested
#
if (PHRASEDML_REMOVE_WRAPPERS)
  foreach(file
    ${CMAKE_CURRENT_BINARY_DIR}/phrasedml_wrap.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/pydoc-normal.i
    ${CMAKE_CURRENT_BINARY_DIR}/pydoc-doxygen.i
  )
  if (EXISTS ${file})
      FILE(REMOVE ${file})
  endif()
  endforeach()
endif(PHRASEDML_REMOVE_WRAPPERS)

ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/phrasedml_wrap.cpp
    COMMAND "${PYTHON_EXECUTABLE}"
    ARGS    "${CMAKE_CURRENT_SOURCE_DIR}/../swig/swigdoc.py"
             --language python
             --top "${CMAKE_CURRENT_SOURCE_DIR}/../../../"
             --master "${CMAKE_CURRENT_SOURCE_DIR}/../swig/phrasedml.i"
             --output "${CMAKE_CURRENT_BINARY_DIR}/pydoc-doxygen.i"
             ${SWIG_SWIGDOCDEFINES}
    COMMAND "${PYTHON_EXECUTABLE}"
    ARGS    "${CMAKE_CURRENT_SOURCE_DIR}/doc-converter/rewrite_pydoc.py"
            -f "${CMAKE_CURRENT_BINARY_DIR}/pydoc-doxygen.i"
            -o "${CMAKE_CURRENT_BINARY_DIR}/pydoc-normal.i"
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename pydoc-doxygen.i pydoc.i
    COMMAND "${SWIG_EXECUTABLE}"
    ARGS    -I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
            -I${CMAKE_CURRENT_SOURCE_DIR}
            -I${CMAKE_CURRENT_BINARY_DIR}
            -I${CMAKE_SOURCE_DIR}/src
            -I${CMAKE_SOURCE_DIR}/include
            -I${LIBSBML_INCLUDE_DIR}
            -c++
            -python
            ${SWIG_EXTRA_ARGS}
            -o ${CMAKE_CURRENT_BINARY_DIR}/phrasedml_wrap.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/phrasedml.i
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename pydoc.i pydoc-doxygen.i
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename phrasedml.py phrasedml-doxygen.py
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename pydoc-normal.i pydoc.i
    COMMAND "${SWIG_EXECUTABLE}"
    ARGS    -I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
            -I${CMAKE_CURRENT_SOURCE_DIR}
            -I${CMAKE_CURRENT_BINARY_DIR}
            -I${CMAKE_SOURCE_DIR}/src
            -I${CMAKE_SOURCE_DIR}/include
            -I${LIBSBML_INCLUDE_DIR}
            -c++
            -python
            ${SWIG_EXTRA_ARGS}
            -o ${CMAKE_CURRENT_BINARY_DIR}/phrasedml_wrap.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/phrasedml.i
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename pydoc.i pydoc-normal.i
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/phrasedml.i
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
            ${CMAKE_CURRENT_SOURCE_DIR}/doc-converter/rewrite_pydoc.py
            ${CMAKE_CURRENT_SOURCE_DIR}/../swig/swigdoc.py
            ${SWIG_DEPENDENCIES}
    COMMENT "Swig Python source")

add_custom_target(binding_python_swig ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/phrasedml_wrap.cpp)

####################################################################
#
# Build native library
#

include_directories(${INCLUDE_DIRECTORIES} ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${INCLUDE_DIRECTORIES} ${CMAKE_CURRENT_SOURCE_DIR}/../swig)
include_directories(${INCLUDE_DIRECTORIES} ${CMAKE_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIRECTORIES} ${PYTHON_INCLUDE_DIRS})
include_directories(${INCLUDE_DIRECTORIES} ${LIBSBML_INCLUDE_DIR})
include_directories(${INCLUDE_DIRECTORIES} ${LIBSEDML_INCLUDE_DIR})
if (EXTRA_INCLUDE_DIRS)
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

if (MSVC)
  # the build fails when compiled with packages as the object file is too
  # big adding the big flag makes it work!
  add_definitions(/bigobj)
endif(MSVC)

add_library(binding_python_lib SHARED phrasedml_wrap.cpp)
add_dependencies( binding_python_lib binding_python_swig)

set_target_properties (binding_python_lib PROPERTIES OUTPUT_NAME "_phrasedml")
if (UNIX)
        set_target_properties (binding_python_lib PROPERTIES PREFIX "")
        set_target_properties (binding_python_lib PROPERTIES SUFFIX ".so")
else()
        if (CYGWIN)
                set_target_properties (binding_python_lib PROPERTIES PREFIX "")
                set_target_properties (binding_python_lib PROPERTIES SUFFIX ".dll")
        else()
                set_target_properties (binding_python_lib PROPERTIES SUFFIX ".pyd")
        endif()
endif()

#message(STATUS "libraries: ${LIBPHRASEDML_LIBS}\nphrasedml:${LIBPHRASEDML_LIBRARY}")


if(APPLE)
  set_target_properties(binding_python_lib PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
  target_link_libraries(binding_python_lib ${LIBPHRASEDML_LIBRARY}-static ${LIBPHRASEDML_LIBS})
else()
  target_link_libraries(binding_python_lib ${LIBPHRASEDML_LIBRARY}-static ${LIBPHRASEDML_LIBS} ${PYTHON_LIBRARIES})
endif()


#
# Use distutil's setup.py to install the bindings
#

set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
set(SETUP_PY    "${CMAKE_CURRENT_BINARY_DIR}/setup.py")
set(DEPS        "${CMAKE_CURRENT_SOURCE_DIR}/__init__.py;${CMAKE_CURRENT_BINARY_DIR}/phrasedml_wrap.cpp")
set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/phrasedml_wrap.cpp PROPERTIES GENERATED TRUE)
set(OUTPUT      "${CMAKE_CURRENT_BINARY_DIR}/timestamp")

configure_file(${SETUP_PY_IN} ${SETUP_PY})

add_custom_command(OUTPUT ${OUTPUT}
                   COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/phrasedml/
                   COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/phrasedml.py ${CMAKE_CURRENT_BINARY_DIR}/phrasedml/
                   COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/__init__.py ${CMAKE_CURRENT_BINARY_DIR}/phrasedml/
#                   COMMAND ${PYTHON_EXECUTABLE} ${SETUP_PY} build
                   COMMAND ${CMAKE_COMMAND} -E touch ${OUTPUT}
                   DEPENDS ${DEPS})
add_custom_target(target ALL DEPENDS ${OUTPUT})


#For installation, we can run setup.py for people automatically (on by default):

if (PYTHON_SYSTEM_INSTALL)
   INSTALL(TARGETS binding_python_lib DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/phrasedml)
   if (NOT UNIX)
      file(GLOB win_dependencies "${CMAKE_SOURCE_DIR}/win32/*.dll")
      list(REMOVE_ITEM win_dependencies ${CMAKE_SOURCE_DIR}/win32/QtCore4.dll)
      list(REMOVE_ITEM win_dependencies ${CMAKE_SOURCE_DIR}/win32/QtGui4.dll)
      if (NOT WITH_STATIC_SBML)
         list(APPEND win_dependencies ${LIBSBML_DLL})
      endif()
      install(FILES ${win_dependencies} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/phrasedml)
   endif()
   INSTALL(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" -E chdir ${CMAKE_CURRENT_BINARY_DIR} ${PYTHON_EXECUTABLE} ${SETUP_PY} install)")
endif()

#...and/or we can let them install python bindings in a local directory (off by default).

if (PYTHON_LOCAL_INSTALL)
   set(PYTHON_PACKAGE_INSTALL_DIR "bindings/python")

   INSTALL(TARGETS binding_python_lib DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/phrasedml)
   file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/libphrasedml.pth" "phrasedml\n")
   INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/libphrasedml.pth  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR})
   INSTALL(FILES ${CMAKE_CURRENT_SOURCE_DIR}/README.txt  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR})
   INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/setup.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR})
   file(GLOB phrasedml_python_files "${CMAKE_CURRENT_BINARY_DIR}/phrasedml/*.*")
   install(FILES ${phrasedml_python_files} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/phrasedml )

endif()

if (NOT PYTHON_SYSTEM_INSTALL)
   if (NOT PYTHON_LOCAL_INSTALL)
        message(WARNING "   Python bindings will be created, but not installed.  Install them by hand from ${CMAKE_CURRENT_BINARY_DIR},\n   or turn on PYTHON_SYSTEM_INSTALL and/or PYTHON_LOCAL_INSTALL.")
   endif()
endif()

####################################################################
#
# testing
#

#if(WITH_CHECK)

        # copy test files to build dir
#        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

        # run python tests
#        add_test(NAME test_python_binding
#                 COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/test.py
#                 -p $<TARGET_FILE_DIR:binding_python_lib> -b ${CMAKE_CURRENT_SOURCE_DIR}/test)

#endif()
