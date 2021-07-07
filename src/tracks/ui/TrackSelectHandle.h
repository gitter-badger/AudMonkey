/**********************************************************************

AudMonkey: A Digital Audio Editor

TrackSelectHandle.h

Paul Licameli split from TrackPanel.cpp

**********************************************************************/

#ifndef __AUDMONKEY_TRACK_SELECT_HANDLE__
#define __AUDMONKEY_TRACK_SELECT_HANDLE__

#include "../../UIHandle.h"

class wxMouseEvent;
class Track;

class TrackSelectHandle final : public UIHandle
{
   TrackSelectHandle(const TrackSelectHandle&) = delete;

public:
   explicit TrackSelectHandle( const std::shared_ptr<Track> &pTrack );

   TrackSelectHandle &operator=(const TrackSelectHandle&) = default;

   static UIHandlePtr HitAnywhere
      (std::weak_ptr<TrackSelectHandle> &holder,
       const std::shared_ptr<Track> &pTrack);

   virtual ~TrackSelectHandle();

   Result Click
      (const TrackPanelMouseEvent &event, AudMonkeyProject *pProject) override;

   Result Drag
      (const TrackPanelMouseEvent &event, AudMonkeyProject *pProject) override;

   HitTestPreview Preview
      (const TrackPanelMouseState &state, AudMonkeyProject *pProject)
      override;

   Result Release
      (const TrackPanelMouseEvent &event, AudMonkeyProject *pProject,
       wxWindow *pParent) override;

   Result Cancel(AudMonkeyProject *) override;

   bool StopsOnKeystroke() override { return true; }

private:
   std::shared_ptr<Track> mpTrack;
   bool mClicked{};

   // JH: if the user is dragging a track, at what y
   //   coordinate should the dragging track move up or down?
   int mMoveUpThreshold {};
   int mMoveDownThreshold {};
   int mRearrangeCount {};

   void CalculateRearrangingThresholds(
      const wxMouseEvent & event, AudMonkeyProject *project);
};

#endif
