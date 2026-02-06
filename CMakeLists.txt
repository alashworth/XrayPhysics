cmake_minimum_required(VERSION 3.31 FATAL_ERROR)

project(xrayphysics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenMP REQUIRED)

if(WIN32)
  set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
  set(CMAKE_STATIC_LIBRARY_PREFIX "lib")
endif()

if(MSVC)
  add_compile_options(/wd4305 /wd4244 /wd4267)
endif()

add_library(${PROJECT_NAME} SHARED)

target_sources(${PROJECT_NAME}
  PUBLIC
    FILE_SET headers
      TYPE HEADERS
      BASE_DIRS src
      FILES
        src/xrayphysics_c_interface.h
  PRIVATE
    # Private Headers
    src/xrayphysics.h
    src/xsec.h
    src/xscatter.h
    src/xsec_raw.h
    src/xscatter_raw.h
    src/xsource.h
    src/dual_energy_decomposition.h

    # Implementation Sources
    src/xrayphysics.cpp
    src/xsec.cpp
    src/xscatter.cpp
    src/xrayphysics_c_interface.cpp
    src/xsec_raw.cpp
    src/xscatter_raw.cpp
    src/xsource.cpp
    src/dual_energy_decomposition.cpp
)

include(GenerateExportHeader)

generate_export_header(${PROJECT_NAME}
    BASE_NAME XRayPhysics
    EXPORT_MACRO_NAME XRAYPHYSICS_API
    EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/xrayphysics_export.h"
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
    "$<INSTALL_INTERFACE:include>"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

target_link_libraries(${PROJECT_NAME}
  OpenMP::OpenMP_CXX
)

install(TARGETS ${PROJECT_NAME}
  FILE_SET headers DESTINATION include
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

if(NOT DEFINED PYTHON_MODULE_INSTALL_DIR)
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
    set(PYTHON_MODULE_INSTALL_DIR ${Python3_SITELIB})
endif()

install(FILES src/xrayphysics.py
    DESTINATION ${PYTHON_MODULE_INSTALL_DIR}
)