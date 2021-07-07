/**********************************************************************

  AudMonkey: A Digital Audio Editor

  Keyboard.h

  Dominic Mazzoni
  Brian Gunlogson

**********************************************************************/

#ifndef __AUDMONKEY_KEYBOARD__
#define __AUDMONKEY_KEYBOARD__

#include "Identifier.h"
#include <wx/defs.h>

class wxKeyEvent;

struct NormalizedKeyStringTag;
// Case insensitive comparisons
using NormalizedKeyStringBase = TaggedIdentifier<NormalizedKeyStringTag, false>;

struct AUDMONKEY_DLL_API NormalizedKeyString : NormalizedKeyStringBase
{
   NormalizedKeyString() = default;
   explicit NormalizedKeyString( const wxString &key );

   wxString Display(bool usesSpecialChars = false) const;
};

namespace std
{
   template<> struct hash< NormalizedKeyString >
      : hash< NormalizedKeyStringBase > {};
}

AUDMONKEY_DLL_API
NormalizedKeyString KeyEventToKeyString(const wxKeyEvent & keyEvent);

#endif
