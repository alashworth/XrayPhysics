cmake_minimum_required(VERSION 4.2)

project(xrayphysics
    VERSION 1.2.1
    DESCRIPTION "X-ray cross sections, x-ray source spectra modeling, multi-material beam hardening correction, and dual energy decomposition algorithms."
    HOMEPAGE_URL "https://github.com/kylechampley/XrayPhysics"
    LANGUAGES CXX
)

if(DEFINED CMAKE_CXX_STANDARD)
    if(CMAKE_CXX_STANDARD EQUAL 98 OR CMAKE_CXX_STANDARD LESS 17)
        message(FATAL_ERROR "This project requires at least C++17")
    endif()
else()
    set(CMAKE_CXX_STANDARD 17)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(NOT DEFINED CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

find_package(OpenMP REQUIRED)

if (WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
  set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
endif()

add_library(xrayphysics)

target_sources(xrayphysics
    PRIVATE
        src/xrayphysics.cpp
        src/xsec.cpp
        src/xscatter.cpp
        src/xrayphysics_c_interface.cpp
        src/xsec_raw.cpp
        src/xscatter_raw.cpp
        src/xsource.cpp
        src/dual_energy_decomposition.cpp
        src/xrayphysics.h
        src/xsec.h
        src/xscatter.h
        src/xsec_raw.h
        src/xscatter_raw.h
        src/xsource.h
        src/dual_energy_decomposition.h
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS src
        FILES src/xrayphysics_c_interface.h
)

include(GenerateExportHeader)
generate_export_header(xrayphysics)
target_sources(xrayphysics
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_BINARY_DIR}
        FILES ${CMAKE_CURRENT_BINARY_DIR}/xrayphysics_export.h
)

target_compile_definitions(xrayphysics PRIVATE 
    XRAY_PHYSICS_VERSION=\"${PROJECT_VERSION}\"
    USE_OPENMP=1
)

include(GNUInstallDirs)

install(TARGETS xrayphysics)