#pragma once

#include "hgrev.h"

// TODO: Change Version Number Every Time
#define WSPM_VERSION_NUMBER "1.5.0"
#define WSPM_WILL_NOT_EXPIRE
#define WSPM_VERSION_TEST "Preview 5"

#ifdef WSPM_VERSION_TEST
#	define WSPM_TESTING 1
#else
#	define WSPM_TESTING 0
#	define WSPM_VERSION_TEST ""
#endif

#ifdef _DEBUG
#	define WSPM_DEBUG_SUFFIX " (Debug)"
#else
#	define WSPM_DEBUG_SUFFIX ""
#endif

#if HG_MODS == 1
#	define WSPM_VERSION_MODS_SUFFIX "m"
#else
#	define WSPM_VERSION_MODS_SUFFIX
#endif

#define WSPM_VERSION WSPM_VERSION_NUMBER WSPM_VERSION_MODS_SUFFIX " " WSPM_VERSION_TEST WSPM_DEBUG_SUFFIX

#if WSPM_TESTING == 1 && !defined(WSPM_WILL_NOT_EXPIRE)
/* NOTE: Assume that date is following this format: "Jan 28 2010" */
bool is_expired(const char * date);
#	define IS_EXPIRED(date) (is_expired(__DATE__))
#else
#	define IS_EXPIRED(date) (false)
#endif
