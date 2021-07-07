/**********************************************************************

  AudMonkey: A Digital Audio Editor

  AudMonkeyMessageBox.h

  Paul Licameli split this out of ErrorDialog.h

**********************************************************************/

#ifndef __AUDMONKEY_MESSAGE_BOX__
#define __AUDMONKEY_MESSAGE_BOX__

#include <wx/msgdlg.h>
#include "Internat.h"

extern AUDMONKEY_DLL_API TranslatableString AudMonkeyMessageBoxCaptionStr();

// Do not use wxMessageBox!!  Its default window title does not translate!
inline int AudMonkeyMessageBox(const TranslatableString& message,
   const TranslatableString& caption = AudMonkeyMessageBoxCaptionStr(),
   long style = wxOK | wxCENTRE,
   wxWindow *parent = NULL,
   int x = wxDefaultCoord, int y = wxDefaultCoord)
{
   return ::wxMessageBox(message.Translation(), caption.Translation(),
      style, parent, x, y);
}

#endif
