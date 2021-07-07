/**********************************************************************
 
 AudMonkey: A Digital Audio Editor
 
 TrackUtilities.h
 
 Paul Licameli split from TrackMenus.h
 
 **********************************************************************/

#ifndef __AUDMONKEY_TRACK_UTILITIES__
#define __AUDMONKEY_TRACK_UTILITIES__

class AudMonkeyProject;
class Track;

namespace TrackUtilities {

   enum MoveChoice {
      OnMoveUpID, OnMoveDownID, OnMoveTopID, OnMoveBottomID
   };
   /// Move a track up, down, to top or to bottom.
   AUDMONKEY_DLL_API void DoMoveTrack(
      AudMonkeyProject &project, Track* target, MoveChoice choice );
   // "exclusive" mute means mute the chosen track and unmute all others.
   AUDMONKEY_DLL_API
   void DoTrackMute( AudMonkeyProject &project, Track *pTrack, bool exclusive );
   // Type of solo (standard or simple) follows the set preference, unless
   // exclusive == true, which causes the opposite behavior.
   AUDMONKEY_DLL_API
   void DoTrackSolo( AudMonkeyProject &project, Track *pTrack, bool exclusive );
   AUDMONKEY_DLL_API
   void DoRemoveTrack( AudMonkeyProject &project, Track * toRemove );
   AUDMONKEY_DLL_API
   void DoRemoveTracks( AudMonkeyProject & );

}

#endif
