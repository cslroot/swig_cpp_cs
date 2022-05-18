cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME foo)

add_library(${PROJ_NAME})

# GENERATE_EXPORT_HEADER(${PROJ_NAME})
# install(TARGETS ${PROJ_NAME} DESTINATION ${LIBRARY_INSTALL_DIR})
# install(FILES
#  foo.h
#  ${PROJECT_BINARY_DIR}/foo_export.h DESTINATION ${INCLUDE_INSTALL_DIR}
# )
# target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_BINARY_DIR}/exports)

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

set(CS_SWIG_INTERFACE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/bindings/foo_cs.i)
set(CS_SWIG_EXPORT_CS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bindings/cs)

file(MAKE_DIRECTORY ${CS_SWIG_EXPORT_CS_DIR})

execute_process(
  COMMAND ${SWIG_EXECUTABLE}
    -c++ -csharp
    -module cs_foo  # module name
    -cppext cpp     # file extension 
    -includeall
    -I${CMAKE_CURRENT_BINARY_DIR}
    -I${CMAKE_CURRENT_SOURCE_DIR}/include
    -outdir ${CS_SWIG_EXPORT_CS_DIR}
    # C# specific options
    -dllimport foo.dll  # .cs code using DllImport(xxxx) as this name
    -namespace CS.Foo   # Generate wrappers into C# namespace <nm>
    # -noproxy          # Generate the low-level functional interface instead of proxy classes
    # -oldvarnames	    # Old intermediary method names for variable wrappers
    # -outfile ${CMAKE_CURRENT_BINARY_DIR}/bindings/cs  # Write all C# into a single <file> located in the output directory
    ${CS_SWIG_INTERFACE_FILE}
  COMMAND_ECHO STDOUT
)
# -> generate wrapper.c++ and .cs files


# # include(GenerateExportHeader)
# # include_directories(../src/foo/include)
# set_property(SOURCE ${CS_SWIG_INTERFACE_FILE} PROPERTY CPLUSPLUS ON)
# set_property(SOURCE ${CS_SWIG_INTERFACE_FILE} PROPERTY USE_TARGET_INCLUDE_DIRECTORIES TRUE)
# set_property(SOURCE ${CS_SWIG_INTERFACE_FILE} PROPERTY INCLUDE_DIRECTORIES )
# set_property(SOURCE ${CS_SWIG_INTERFACE_FILE} PROPERTY COMPILE_DEFINITIONS )
# set_property(SOURCE ${CS_SWIG_INTERFACE_FILE} PROPERTY COMPILE_OPTIONS -namespace CS.Foo -dllimport foo)
# set_property(SOURCE ${CS_SWIG_INTERFACE_FILE} PROPERTY SWIG_FLAGS "-includeall")

# set(CS_LIBNAME_CPP foo)
# set(CS_LIBNAME_CSHARP foo.wrapper.cs) # wraper C++ dll name

# target_include_directories(${CS_LIBNAME_CPP} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# swig_add_library(${CS_LIBNAME_CSHARP}
#   TYPE SHARED
#   LANGUAGE csharp
#   SOURCES ${CS_SWIG_INTERFACE_FILE}
#   OUTFILE_DIR ${CMAKE_CURRENT_BINARY_DIR}/wrap_src  # where dotnet_fooCSHARP_wrap.cxx placad in generated 
#   OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/wrap_src_cs  # where *.cs files placed
# )
# target_link_libraries(${CS_LIBNAME_CSHARP} PUBLIC ${CS_LIBNAME_CPP})

# file(GLOB CS_SRC "${CMAKE_CURRENT_BINARY_DIR}/*.cs")

# install(TARGETS ${CS_LIBNAME_CSHARP} 
#   LIBRARY DESTINATION csharp/lib
#   ARCHIVE DESTINATION csharp/lib
#   RUNTIME DESTINATION csharp/bin)

# install(FILES ${CS_SRC} DESTINATION csharp/src)
# install(TARGETS ${CS_LIBNAME_CSHARP}
#   RUNTIME DESTINATION examples/deploy/csharp)

enable_language(CSharp)
set(PROJ_NAME_CS foo_cs)
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
	"WindowsBase")

endif()