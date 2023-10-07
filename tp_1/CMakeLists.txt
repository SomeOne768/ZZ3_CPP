# Project #-----------------------------------------------------------------------------------------
cmake_minimum_required ( VERSION 3.22 )

project ( tp1 )

find_package ( Threads )

# C++ Warning Level #-------------------------------------------------------------------------------
if ( CMAKE_COMPILER_IS_GNUCXX )
 set ( CMAKE_CXX_FLAGS "-Wall -pedantic ${CMAKE_CXX_FLAGS}" )
endif ()

# C++14 #-------------------------------------------------------------------------------------------
include ( CheckCXXCompilerFlag )

check_cxx_compiler_flag ( "-std=gnu++17" COMPILER_SUPPORTS_CPP17 )
check_cxx_compiler_flag ( "-std=gnu++1z" COMPILER_SUPPORTS_CPP1Z )
check_cxx_compiler_flag ( "-std=gnu++14" COMPILER_SUPPORTS_CPP14 )
check_cxx_compiler_flag ( "-std=gnu++1y" COMPILER_SUPPORTS_CPP1Y )
check_cxx_compiler_flag ( "-std=gnu++11" COMPILER_SUPPORTS_CPP11 )

if ( COMPILER_SUPPORTS_CPP17 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++17 ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP1Z )
 set ( CMAKE_CXX_FLAGS "-std=gnu++1z ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP14 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++14 ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP1Y )
 set ( CMAKE_CXX_FLAGS "-std=gnu++1y ${CMAKE_CXX_FLAGS}" )
elseif ( COMPILER_SUPPORTS_CPP11 )
 set ( CMAKE_CXX_FLAGS "-std=gnu++11 ${CMAKE_CXX_FLAGS}" )
else ()
 message ( STATUS "Compiler ${CMAKE_CXX_COMPILER} has no C++11 or above support." )
endif ()

message ( STATUS "Compiler flags: ${CMAKE_CXX_FLAGS}" )

# Sources #-----------------------------------------------------------------------------------------
set ( ZZ3_HEADERS
      src/Cartesien.hpp
      src/Nuage.hpp
      src/Point.hpp
      src/Polaire.hpp
      src/Vecteur.hpp
    )

set ( ZZ3_SOURCES
      src/Cartesien.cpp
      src/Nuage.cpp
      src/Point.cpp
      src/Polaire.cpp
      #src/Vecteur.cpp
    )

set ( ZZ3_HEADERS_TEST
    )

set ( ZZ3_SOURCES_TEST
    )

include_directories ( src/ )

# Executables #-------------------------------------------------------------------------------------
add_executable ( ${CMAKE_PROJECT_NAME}_point
                 src/main_point.cpp
                 ${ZZ3_HEADERS}
                 ${ZZ3_SOURCES}
               )

add_executable ( ${CMAKE_PROJECT_NAME}_vecteur
                 src/main_vecteur.cpp
                 ${ZZ3_HEADERS}
                 ${ZZ3_SOURCES}
               )

add_executable ( ${CMAKE_PROJECT_NAME}_test
                 test/catch.cpp
                 test/${CMAKE_PROJECT_NAME}_test.cpp
                 ${ZZ3_HEADERS}
                 ${ZZ3_SOURCES}
                 ${ZZ3_HEADERS_TEST}
                 ${ZZ3_SOURCES_TEST}
               )

# Build #-------------------------------------------------------------------------------------------
set_target_properties ( ${CMAKE_PROJECT_NAME}_point PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME}_point ${CMAKE_THREAD_LIBS_INIT} )

set_target_properties ( ${CMAKE_PROJECT_NAME}_vecteur PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME}_vecteur ${CMAKE_THREAD_LIBS_INIT} )

set_target_properties ( ${CMAKE_PROJECT_NAME}_test PROPERTIES LINKER_LANGUAGE C )
target_link_libraries ( ${CMAKE_PROJECT_NAME}_test ${CMAKE_THREAD_LIBS_INIT} )
