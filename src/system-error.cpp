/*
 * This file is part of the µOS++ distribution.
 *   (https://github.com/micro-os-plus/)
 * Copyright (c) 2016 Liviu Ionescu.
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

#include <micro-os-plus/diag/trace.h>
#include <micro-os-plus/estd/system_error>

#if defined(__EXCEPTIONS)

#include <string>
// For unknown reasons, the C++ header does not include strerror().
#include <string.h>

#include <system_error>

#endif // defined(__EXCEPTIONS)

// ----------------------------------------------------------------------------

using namespace micro_os_plus;

// ----------------------------------------------------------------------------

#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat"
#endif

namespace micro_os_plus
{
  namespace estd
  {
    // ========================================================================

#if defined(__EXCEPTIONS)

    struct system_error_category : public std::error_category
    {
      virtual const char*
      name () const noexcept override;

      virtual std::string
      message (int i) const override;
    };

    const char*
    system_error_category::name () const noexcept
    {
      return "system";
    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

    std::string
    system_error_category::message (int i) const
    {
#if defined(MICRO_OS_PLUS_DEBUG)
      return std::string (strerror (i));
#else
      return std::string ("");
#endif
    }

    struct rtos_error_category : public std::error_category
    {
      virtual const char*
      name () const noexcept override;

      virtual std::string
      message (int i) const override;
    };

    const char*
    rtos_error_category::name () const noexcept
    {
      return "rtos";
    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

    std::string
    rtos_error_category::message (int i) const
    {
#if defined(MICRO_OS_PLUS_DEBUG)
      return std::string (strerror (i));
#else
      return std::string ("");
#endif
    }

#pragma GCC diagnostic pop

#endif

    void
    __throw_system_error (int ev, const char* what_arg)
    {
#if defined(__EXCEPTIONS)

#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-bind-to-temporary-copy"
#endif
      throw std::system_error (std::error_code (ev, system_error_category ()),
                               what_arg);
#pragma GCC diagnostic pop

#else
      trace_printf ("system_error(%d, %s)\n", ev, what_arg);
      std::abort ();
#endif
    }

    void
    __throw_rtos_error (int ev, const char* what_arg)
    {
#if defined(__EXCEPTIONS)

#pragma GCC diagnostic push

#if defined(__clang__)
#pragma clang diagnostic ignored "-Wc++98-compat-bind-to-temporary-copy"
#endif
      throw std::system_error (std::error_code (ev, rtos_error_category ()),
                               what_arg);

#pragma GCC diagnostic pop
#else
      trace_printf ("system_error(%d, %s)\n", ev, what_arg);
      std::abort ();
#endif
    }

    // ------------------------------------------------------------------------
  } // namespace estd
} // namespace micro_os_plus

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
