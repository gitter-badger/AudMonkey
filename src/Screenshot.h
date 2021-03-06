/**********************************************************************

  AudMonkey: A Digital Audio Editor

  Screenshot.h

  Dominic Mazzoni

*******************************************************************//**

\file Screenshot.h

  Opens a modeless dialog that aids in rearranging the project window
  to a canonical size and state and then capturing full and partial
  screenshots to disk.

*//*******************************************************************/

#ifndef __AUDMONKEY_SCREENSHOT__
#define __AUDMONKEY_SCREENSHOT__



#include <wx/defs.h>

class AudMonkeyProject;

AUDMONKEY_DLL_API void OpenScreenshotTools( AudMonkeyProject &project );
void CloseScreenshotTools();

#endif // __AUDMONKEY_SCREENSHOT__
