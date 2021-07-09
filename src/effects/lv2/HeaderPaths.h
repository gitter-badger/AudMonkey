/**********************************************************************

  AudMonkey: A Digital Audio Editor

  HeaderPaths.h

  License: GPL v2.  See License.txt.

*********************************************************************/

#ifndef LV2HEADERNAMES_H
#define LV2HEADERNAMES_H

// Apparently header paths differ on different systems/distros
// The original code used <lib_name>/<header>
// But "on my machine :)" the path is <lib_name>-0/<lib_name>/<header>
// The following code tries to figure out which one to use.

// Affected files/headers and the Macros representing
// the path as the result of the mess that follows
//
// - lilv.h - LILV_H_PATH
// - suil.h - SUIL_H_PATH

// You may manually #define the macros
// to point to the correct paths if this fails.

#ifndef LILV_H_PATH
	#if defined(__has_include)
		#if __has_include("lilv/lilv.h")
			#define LILV_H_PATH "lilv/lilv.h"
		#elif __has_include("lilv-0/lilv/lilv.h")
			#define LILV_H_PATH "lilv-0/lilv/lilv.h"
		#else
			#error
				"lilv library header 'lilv.h' required but not available."
				"#define LILV_H_PATH to point to the correct header to fix this."
		#endif // __has_include("lilv/lilv.h")
	#else // defined(__has_include)
		#error
				"LILV_H_PATH not defined and the compiler doesn't support __has_include."
				"please add the definition manually."
	#endif // defined(__has_include)
#endif // LILV_H_PATH

#ifndef SUIL_H_PATH
	#if defined (__has_include)
		#if __has_include("suil/suil.h")
			#define SUIL_H_PATH "suil/suil.h"
		#elif __has_include("suil-0/suil/suil.h")
			#define SUIL_H_PATH "suil-0/suil/suil.h"
		#else 
			#error
				"suil library header 'suil.h' required but not available."
				"#define SUIL_H_PATH to point to the correct header to fix this."
		#endif // __has_include("suil/suil.h)
	#else // defined(__has_include)
		#error
				"SUIL_H_PATH not defined and the compiler doesn't support __has_include."
				"please add the definition manually."
	#endif // defined(__has_include)
#endif // SUIL_H_PATH

#endif // LV2HEADERNAMES_H
