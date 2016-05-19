/*==================================================================================================
Copyright (c) 2015 Edouard Alligand and Joel Falcou

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
=================================================================================================**/
#pragma once

// configuration macros for brigand

#ifdef _MSC_VER
#define BRIGAND_COMP_MSVC
#endif

#ifdef __GNUC__
#ifndef __clang__
#define BRIGAND_COMP_GCC
#else
#define BRIGAND_COMP_CLANG
#endif
#endif
