#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `add_subdirectory("xpacks/micro-os-plus-libs-cpp")`
#
# The result is a library that can be added to the linker with:
#
# `target_link_libraries(your-target PUBLIC micro-os-plus::libs-cpp)`
#
# To avoid poluting this file with test related details, there is a separate
# CMake configuration in the `tests` folder.

# -----------------------------------------------------------------------------
## Preamble ##

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

project(
  micro-os-plus-libs-cpp
  DESCRIPTION "µOS++ complementary C++ library functions"
)

# PRIVATE: build definitions, used internally
# INTERFACE: usage definitions, passed up to targets linking to it
# PUBLIC: both

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------

add_library(micro-os-plus-libs-cpp-interface INTERFACE EXCLUDE_FROM_ALL)

# ---------------------------------------------------------------------------

target_sources(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    "src/cxx.cpp"
    "src/system-error.cpp"
)

message(VERBOSE "+ src/cxx.cpp")
message(VERBOSE "+ src/system-error.cpp")

target_include_directories(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    "include"
)

message(VERBOSE "+ include")

target_link_libraries(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    micro-os-plus::diag-trace
)

# ---------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::libs-cpp ALIAS micro-os-plus-libs-cpp-interface)
message(VERBOSE "> micro-os-plus::libs-cpp -> micro-os-plus-libs-cpp-interface")

# -----------------------------------------------------------------------------
