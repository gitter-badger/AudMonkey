/**********************************************************************
 
 AudMonkey: A Digital Audio Editor
 
 CrashReport.h
 
 Paul Licameli
 split from AudMonkeyApp.h
 
 **********************************************************************/

#ifndef __AUDMONKEY_CRASH_REPORT__
#define __AUDMONKEY_CRASH_REPORT__

#undef HAS_CRASH_REPORT




#if defined(EXPERIMENTAL_CRASH_REPORT)

#include <wx/setup.h> // for wxUSE* macros
#if defined(wxUSE_DEBUGREPORT) && wxUSE_DEBUGREPORT
   #define HAS_CRASH_REPORT
   #include <wx/debugrpt.h>

   namespace CrashReport
   {
      AUDMONKEY_DLL_API
      void Generate(wxDebugReport::Context ctx);
   }
#endif

#endif

#endif
