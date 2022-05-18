cmake_minimum_required(VERSION 3.20.0)
project(cpp_cs VERSION 0.1.0)

option(CS_BUILD_CSHARP "C# bindings" ON)
if (WIN32)
else()
set (CS_BUILD_CSHARP OFF)
endif()

cmake_policy(SET CMP0054 NEW)

# same destinatin directory for dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # .exe, .dll with SHARED, .pdb
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # .dll, .so with MODULE
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/arc)  # .lib .exp, .a with STATIC

enable_language(CXX)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# information
message(STATUS "CMAKE_GENERATOR: " ${CMAKE_GENERATOR})
message(STATUS "CMAKE_CXX_COMPILER_ID: " ${CMAKE_CXX_COMPILER_ID})

# ignore warning
# warning C4996: 'std::codecvt_utf8_utf16<wchar_t,1114111,(std::codecvt_mode)0>': warning STL4017: std::wbuffer_convert, std::wstring_convert, and the <codecvt> header (containing std::codecvt_mode, std::codecvt_utf8, std::codecvt_utf16, and std::codecvt_utf8_utf16) are deprecated in C++17. (The std::codecvt class template is NOT deprecated.) The C++ Standard doesn't provide equivalent non-deprecated functionality; consider using MultiByteToWideChar() and WideCharToMultiByte() from <Windows.h> instead. You can define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING or _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS to acknowledge that you have received this warning.
add_definitions(-D_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING)
add_definitions(-D_USE_MATH_DEFINES)

#  for MSVC (cl)
if(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    message(STATUS "MSVC settings")
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-DNOMINMAX)
    add_definitions(-D_UNICODE -DUNICODE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zc:__cplusplus /MP /EHsc")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /W3" )
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ot /openmp /MD -DNDEBUG" )
endif()
# for VS Generator
if("${CMAKE_GENERATOR}" MATCHES "^Visual Studio.*")
    # prevent MinSizeRel and RelWithDebInfo for vcxproj
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "limited configs" FORCE)
    # suppress ZERO_CHECK project generation
    set(CMAKE_SUPPRESS_REGENERATION true)
    # enable to filter in project
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    set_property(GLOBAL PROPERTY CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY true)
    set_property(GLOBAL PROPERTY CMAKE_SKIP_INSTALL_ALL_DEPENDENCY true)
endif()



add_subdirectory(src)
add_subdirectory(examples)
