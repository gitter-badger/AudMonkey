/**********************************************************************

AudMonkey: A Digital Audio Editor

LabelTextHandle.h

Paul Licameli split from TrackPanel.cpp

**********************************************************************/

#ifndef __AUDACITY_LABEL_TEXT_HANDLE__
#define __AUDACITY_LABEL_TEXT_HANDLE__

#include "LabelDefaultClickHandle.h"
#include "../../../SelectedRegion.h"

class wxMouseState;
class LabelTrack;
class NotifyingSelectedRegion;
class SelectionStateChanger;
class ZoomInfo;

class LabelTextHandle final : public LabelDefaultClickHandle
{
   static HitTestPreview HitPreview();

public:
   static UIHandlePtr HitTest
      (std::weak_ptr<LabelTextHandle> &holder,
       const wxMouseState &state, const std::shared_ptr<LabelTrack> &pLT);

   LabelTextHandle &operator=(const LabelTextHandle&) = default;

   explicit LabelTextHandle
      ( const std::shared_ptr<LabelTrack> &pLT, int labelNum );
   virtual ~LabelTextHandle();

   std::shared_ptr<LabelTrack> GetTrack() const { return mpLT.lock(); }
   int GetLabelNum() const { return mLabelNum; }

   void Enter(bool forward, AudMonkeyProject *) override;

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

   Result Cancel(AudMonkeyProject *pProject) override;

private:
   void HandleTextClick
      (AudMonkeyProject &project,
       const wxMouseEvent & evt, const wxRect & r, const ZoomInfo &zoomInfo,
       NotifyingSelectedRegion &newSel);
   void HandleTextDragRelease(
      AudMonkeyProject &project, const wxMouseEvent & evt);

   std::weak_ptr<LabelTrack> mpLT {};
   int mLabelNum{ -1 };
   int mLabelTrackStartXPos { -1 };
   int mLabelTrackStartYPos { -1 };
   SelectedRegion mSelectedRegion{};
   std::shared_ptr<SelectionStateChanger> mChanger;

   /// flag to tell if it's a valid dragging
   bool mRightDragging{ false };
};

#endif
