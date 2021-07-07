/**********************************************************************

 AudMonkey: A Digital Audio Editor

 SelectionState.h

 **********************************************************************/

#ifndef __AUDMONKEY_SELECTION_STATE__
#define __AUDMONKEY_SELECTION_STATE__

class AudMonkeyProject;
class Track;
class TrackList;
class ViewInfo;
#include "ClientData.h"
#include <memory>
#include <vector>

// State relating to the set of selected tracks
class AUDMONKEY_DLL_API SelectionState final
   : public ClientData::Base
{
public:
   SelectionState() = default;
   SelectionState( const SelectionState & ) PROHIBITED;
   SelectionState &operator=( const SelectionState & ) PROHIBITED;

   static SelectionState &Get( AudMonkeyProject &project );
   static const SelectionState &Get( const AudMonkeyProject &project );

   static void SelectTrackLength
      ( ViewInfo &viewInfo, Track &track, bool syncLocked );

   void SelectTrack(
      Track &track, bool selected, bool updateLastPicked );
   // Inclusive range of tracks, the limits specified in either order:
   void SelectRangeOfTracks
      ( TrackList &tracks, Track &sTrack, Track &eTrack );
   void SelectNone( TrackList &tracks );
   void ChangeSelectionOnShiftClick
      ( TrackList &tracks, Track &track );
   void HandleListSelection
      ( TrackList &tracks, ViewInfo &viewInfo, Track &track,
        bool shift, bool ctrl, bool syncLocked );

private:
   friend class SelectionStateChanger;

   std::weak_ptr<Track> mLastPickedTrack;
};

// For committing or rolling-back of changes in selectedness of tracks.
// When rolling back, it is assumed that no tracks have been added or removed.
class AUDMONKEY_DLL_API SelectionStateChanger
{
public:
   SelectionStateChanger( SelectionState &state, TrackList &tracks );
   SelectionStateChanger( const SelectionStateChanger& ) = delete;
   SelectionStateChanger &operator=( const SelectionStateChanger& ) = delete;

   ~SelectionStateChanger();
   void Commit();

private:
   SelectionState *mpState;
   TrackList &mTracks;
   std::weak_ptr<Track> mInitialLastPickedTrack;
   std::vector<bool> mInitialTrackSelection;
};

#endif
