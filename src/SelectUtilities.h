/**********************************************************************
 
 AudMonkey: A Digital Audio Editor
 
 SelectUtilities.h
 
 Paul Licameli split from SelectMenus.h
 
 **********************************************************************/

#ifndef __AUDMONKEY_SELECT_UTILITIES__
#define __AUDMONKEY_SELECT_UTILITIES__

class AudMonkeyProject;
class Track;

/// Namespace for functions for Select menu
namespace SelectUtilities {

AUDMONKEY_DLL_API void DoSelectTimeAndTracks(
   AudMonkeyProject &project, bool bAllTime, bool bAllTracks);
AUDMONKEY_DLL_API void SelectAllIfNone( AudMonkeyProject &project );
AUDMONKEY_DLL_API bool SelectAllIfNoneAndAllowed( AudMonkeyProject &project );
AUDMONKEY_DLL_API void SelectNone( AudMonkeyProject &project );
AUDMONKEY_DLL_API void DoListSelection(
   AudMonkeyProject &project, Track *t,
   bool shift, bool ctrl, bool modifyState );
AUDMONKEY_DLL_API void DoSelectAll( AudMonkeyProject &project );
AUDMONKEY_DLL_API void DoSelectAllAudio( AudMonkeyProject &project );
AUDMONKEY_DLL_API void DoSelectSomething( AudMonkeyProject &project );

}

#endif
