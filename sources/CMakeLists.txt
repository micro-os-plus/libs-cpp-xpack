#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus)
# Copyright (c) 2021 Liviu Ionescu
#
# This Source Code Form is subject to the terms of the MIT License.
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# https://cmake.org/cmake/help/v3.20/

# PRIVATE: build definitions, used internally
# INTERFACE: usage definitions, passed up to targets linking to it
# PUBLIC: both

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/../package.json")
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

message(VERBOSE "+ sources/src/cxx.cpp")
message(VERBOSE "+ sources/src/system-error.cpp")

target_include_directories(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    "include"
)

message(VERBOSE "+ sources/include")

target_link_libraries(
  micro-os-plus-libs-cpp-interface

  INTERFACE
    micro-os-plus::diag-trace
)

# ---------------------------------------------------------------------------
# Aliases.

add_library(micro-os-plus::libs-cpp ALIAS micro-os-plus-libs-cpp-interface)
message(VERBOSE "micro-os-plus::libs-cpp -> micro-os-plus-libs-cpp-interface")

# -----------------------------------------------------------------------------
