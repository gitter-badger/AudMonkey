/**********************************************************************
 
 AudMonkey: A Digital Audio Editor
 
 SelectUtilities.h
 
 Paul Licameli split from SelectMenus.h
 
 **********************************************************************/

#ifndef __AUDACITY_SELECT_UTILITIES__
#define __AUDACITY_SELECT_UTILITIES__

class AudMonkeyProject;
class Track;

/// Namespace for functions for Select menu
namespace SelectUtilities {

AUDACITY_DLL_API void DoSelectTimeAndTracks(
   AudMonkeyProject &project, bool bAllTime, bool bAllTracks);
AUDACITY_DLL_API void SelectAllIfNone( AudMonkeyProject &project );
AUDACITY_DLL_API bool SelectAllIfNoneAndAllowed( AudMonkeyProject &project );
AUDACITY_DLL_API void SelectNone( AudMonkeyProject &project );
AUDACITY_DLL_API void DoListSelection(
   AudMonkeyProject &project, Track *t,
   bool shift, bool ctrl, bool modifyState );
AUDACITY_DLL_API void DoSelectAll( AudMonkeyProject &project );
AUDACITY_DLL_API void DoSelectAllAudio( AudMonkeyProject &project );
AUDACITY_DLL_API void DoSelectSomething( AudMonkeyProject &project );

}

#endif
