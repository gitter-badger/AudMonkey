/**********************************************************************

  AudMonkey: A Digital Audio Editor

  @file ModuleSettings.h

  Paul Licameli split from ModulePrefs.h

**********************************************************************/

#ifndef __AUDMONKEY_MODULE_SETTINGS__
#define __AUDMONKEY_MODULE_SETTINGS__

#include "Identifier.h"

enum {
   kModuleDisabled = 0,
   kModuleEnabled = 1,
   kModuleAsk = 2,     // Will ask, each time, when audmonkey starts.
   kModuleFailed = 3,  // AudMonkey thinks this is a bad module.
   kModuleNew = 4      // AudMonkey will ask once, and remember the answer.
};

namespace ModuleSettings {

int GetModuleStatus( const FilePath &fname );
void SetModuleStatus( const FilePath &fname, int iStatus );

}

#endif
