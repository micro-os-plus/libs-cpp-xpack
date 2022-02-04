#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `add_subdirectory("xpacks/micro-os-plus-libs-cpp")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC micro-os-plus::libs-cpp)`

# -----------------------------------------------------------------------------
## Preamble ##

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

project(
  micro-os-plus-libs-cpp
  DESCRIPTION "µOS++ complementary C++ library functions"
)

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------
## The project library definitions ##

# https://cmake.org/cmake/help/v3.20/command/add_library.html?highlight=interface#normal-libraries
# PRIVATE: build definitions, used internally
# INTERFACE: usage definitions, passed up to targets linking to it
# PUBLIC: both

add_library(micro-os-plus-libs-cpp-interface INTERFACE EXCLUDE_FROM_ALL)

# -----------------------------------------------------------------------------
# Target settings.

target_include_directories(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    "include"
)

target_sources(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    "src/cxx.cpp"
    "src/system-error.cpp"
)

target_compile_definitions(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    # ... add preprocessor macro definitions.
)

target_compile_options(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    # ... perhaps ignore some warnings.
)

target_link_libraries(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    # Dependencies
    micro-os-plus::diag-trace
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists(micro-os-plus-libs-cpp-interface)
endif()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library(micro-os-plus::libs-cpp ALIAS micro-os-plus-libs-cpp-interface)
message(VERBOSE "> micro-os-plus::libs-cpp -> micro-os-plus-libs-cpp-interface")

# -----------------------------------------------------------------------------
