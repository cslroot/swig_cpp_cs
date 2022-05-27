cmake_minimum_required(VERSION 3.16.0)

set(PROJ_NAME common)

add_library(${PROJ_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

file(GLOB_RECURSE ${PROJ_NAME}_SRC CONFIGURE_DEPENDS "*.cpp")
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_SRC})

target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


#----- Generate bindings -----
# ----- build wrapper for C# and generate .cs files -----
if(CS_BUILD_CSHARP)

# REMARK: currently, we use execute_process() instead of the commands for swig(e.g. swig_add_library).
# This is because cmake system cannot recognize the generated cs files at configure time, that files will be generated at build time. 
# So that we use swig directly via command in order to retreive C# project delivertives(e.g. wrapper .dll) with calling `cmake --build` just once.

# swig
find_package(SWIG REQUIRED)
cmake_policy(SET CMP0122 NEW) # UseSWIG use standard library name conventions for CSharp
include(UseSWIG)
set(UseSWIG_MODULE_VERSION 2)

set(CS_SWIG_INTERFACE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/bindings/common_cs.i)
set(CS_SWIG_EXPORT_CS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bindings/cs)

file(MAKE_DIRECTORY ${CS_SWIG_EXPORT_CS_DIR})

execute_process(
  COMMAND ${SWIG_EXECUTABLE}
    -c++ -csharp
    -module cs_common  # module name
    -cppext cpp     # file extension 
    # -includeall
    -I${CMAKE_CURRENT_BINARY_DIR}
    -I${CMAKE_CURRENT_SOURCE_DIR}/include
    -outdir ${CS_SWIG_EXPORT_CS_DIR}
    # C# specific options
    -dllimport common.dll  # .cs code using DllImport(xxxx) as this name
    -namespace CS.Common   # Generate wrappers into C# namespace <nm>
    # -noproxy          # Generate the low-level functional interface instead of proxy classes
    # -oldvarnames	    # Old intermediary method names for variable wrappers
    # -outfile ${CMAKE_CURRENT_BINARY_DIR}/bindings/cs  # Write all C# into a single <file> located in the output directory
    ${CS_SWIG_INTERFACE_FILE}
  COMMAND_ECHO STDOUT
)
# -> generate wrapper.c++ and .cs files


enable_language(CSharp)
set(PROJ_NAME_CS common_cs)
file(GLOB_RECURSE ${PROJ_NAME_CS}_SRC CONFIGURE_DEPENDS ${CS_SWIG_EXPORT_CS_DIR}/*.cs)

add_library(${PROJ_NAME_CS} ${CS_LIB_TYPE})
target_compile_options(${PROJ_NAME_CS} PRIVATE "/langversion:latest")
# set_property(TARGET ${PROJ_NAME_CS} PROPERTY VS_DOTNET_TARGET_FRAMEWORK_VERSION "net6.0")

target_sources(${PROJ_NAME_CS} PRIVATE ${${PROJ_NAME_CS}_SRC})

set_target_properties(${PROJ_NAME_CS} PROPERTIES FOLDER cs)
set_property(TARGET ${PROJ_NAME_CS} PROPERTY WIN32_EXECUTABLE FALSE)
set_property(TARGET ${PROJ_NAME_CS} PROPERTY VS_CONFIGURATION_TYPE ClassLibrary)
set_property(TARGET ${PROJ_NAME_CS} PROPERTY VS_DOTNET_REFERENCES
	"Microsoft.CSharp"
	"System"
	"System.Core"
	"System.Data"
	"WindowsBase"
)

endif()