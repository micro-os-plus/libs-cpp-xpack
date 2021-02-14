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

if(micro-os-plus-libs-cpp-included)
  return()
endif()

set(micro-os-plus-libs-cpp-included TRUE)

message(STATUS "Including micro-os-plus-libs-cpp...")

# -----------------------------------------------------------------------------

function(target_sources_micro_os_plus_libs_cpp target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_sources(
    ${target}

    PRIVATE
      ${xpack_current_folder}/src/cxx.cpp
      ${xpack_current_folder}/src/system-error.cpp
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_include_directories_micro_os_plus_libs_cpp target)

  get_filename_component(xpack_current_folder ${CMAKE_CURRENT_FUNCTION_LIST_DIR} DIRECTORY)

  target_include_directories(
    ${target}

    PUBLIC
      ${xpack_current_folder}/include
  )

endfunction()

# -----------------------------------------------------------------------------

function(target_compile_definitions_micro_os_plus_libs_cpp target)

  # None

endfunction()

# =============================================================================

function(add_libraries_micro_os_plus_libs_cpp)

  # ---------------------------------------------------------------------------

  find_package(micro-os-plus-diag-trace)

  # -----------------------------------------------------------------------------
  
    if(NOT TARGET micro-os-plus-libs-cpp-objects)

    add_library(micro-os-plus-libs-cpp-objects OBJECT EXCLUDE_FROM_ALL)

    target_sources_micro_os_plus_libs_cpp(micro-os-plus-libs-cpp-objects)
    target_include_directories_micro_os_plus_libs_cpp(micro-os-plus-libs-cpp-objects)
    target_compile_definitions_micro_os_plus_libs_cpp(micro-os-plus-libs-cpp-objects)

    add_library(micro-os-plus::libs-cpp ALIAS micro-os-plus-libs-cpp-objects)
    message(STATUS "micro-os-plus::libs-cpp")

    target_link_libraries(
      micro-os-plus-libs-cpp-objects

      PUBLIC
        micro-os-plus::common
        micro-os-plus::diag-trace
    )

  endif()

  # ---------------------------------------------------------------------------

if(true)
  if(NOT TARGET micro-os-plus-libs-cpp-static)

    add_library(micro-os-plus-libs-cpp-static STATIC EXCLUDE_FROM_ALL)

    target_sources_micro_os_plus_libs_cpp(micro-os-plus-libs-cpp-static)
    target_include_directories_micro_os_plus_libs_cpp(micro-os-plus-libs-cpp-static)
    target_compile_definitions_micro_os_plus_libs_cpp(micro-os-plus-libs-cpp-static)

    add_library(micro-os-plus::libs-cpp-static ALIAS micro-os-plus-libs-cpp-static)

    target_link_libraries(
      micro-os-plus-libs-cpp-static
      
      PUBLIC
        micro-os-plus::common
        micro-os-plus::diag-trace-static
    )

  endif()
endif()

  # ---------------------------------------------------------------------------

endfunction()

# -----------------------------------------------------------------------------
