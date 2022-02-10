/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus)
 * Copyright (c) 2015 Liviu Ionescu.
 *
 * Permission to use, copy, modify, and/or distribute this software
 * for any purpose is hereby granted, under the terms of the MIT license.
 *
 * If a copy of the license was not distributed with this file, it can
 * be obtained from https://opensource.org/licenses/MIT/.
 */

// ----------------------------------------------------------------------------

#if defined(MICRO_OS_PLUS_INCLUDE_CONFIG_H)
#include <micro-os-plus/config.h>
#endif // MICRO_OS_PLUS_INCLUDE_CONFIG_H

#include <cstdlib>
#include <sys/types.h>
#include <micro-os-plus/diag/trace.h>

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

#if (!(defined(__APPLE__) || defined(__linux__) || defined(__unix__)))

// These functions are redefined locally, to avoid references to some
// heavy implementations in the standard C++ library.

namespace __gnu_cxx
{
  [[noreturn]] void
  __verbose_terminate_handler ();

  void
  __verbose_terminate_handler ()
  {
    trace::puts (__func__);
    abort ();
    /* NOTREACHED */
  }
} // namespace __gnu_cxx

#if defined(__EXCEPTIONS)

// This variable is required when exceptions are enabled.
void* __dso_handle __attribute__ ((weak));

#endif // defined(__EXCEPTIONS)

#endif // Unix

// ----------------------------------------------------------------------------

extern "C"
{
  [[noreturn]] void
  __cxa_pure_virtual ();

  [[noreturn]] void
  __cxa_deleted_virtual ();

  void
  __cxa_pure_virtual ()
  {
    // Attempt to use a virtual function before object has been constructed
    trace::puts (__func__);
    abort ();
    /* NOTREACHED */
  }

  void
  __cxa_deleted_virtual ()
  {
    trace::puts (__func__);
    abort ();
    /* NOTREACHED */
  }
}

// ----------------------------------------------------------------------------

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
