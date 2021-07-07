/**********************************************************************

AudMonkey: A Digital Audio Editor

SampleHandle.h

Paul Licameli

**********************************************************************/

#ifndef __AUDMONKEY_SAMPLE_HANDLE__
#define __AUDMONKEY_SAMPLE_HANDLE__

#include "../../../../UIHandle.h"
#include "audmonkey/Types.h"

class wxMouseEvent;
class wxMouseState;

class Track;
class ViewInfo;
class WaveTrack;

class SampleHandle final : public UIHandle
{
   SampleHandle(const SampleHandle&) = delete;
   static HitTestPreview HitPreview
      (const wxMouseState &state, const AudMonkeyProject *pProject, bool unsafe);

public:
   explicit SampleHandle( const std::shared_ptr<WaveTrack> &pTrack );

   SampleHandle &operator=(const SampleHandle&) = default;

   static UIHandlePtr HitAnywhere
      (std::weak_ptr<SampleHandle> &holder,
       const wxMouseState &state, const std::shared_ptr<WaveTrack> &pTrack);
   static UIHandlePtr HitTest
      (std::weak_ptr<SampleHandle> &holder,
       const wxMouseState &state, const wxRect &rect,
       const AudMonkeyProject *pProject, const std::shared_ptr<WaveTrack> &pTrack);

   virtual ~SampleHandle();

   std::shared_ptr<WaveTrack> GetTrack() const { return mClickedTrack; }

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

   bool StopsOnKeystroke() override { return true; }

private:
   float FindSampleEditingLevel
      (const wxMouseEvent &event, const ViewInfo &viewInfo, double t0);

   std::shared_ptr<WaveTrack> mClickedTrack;
   wxRect mRect{};

   sampleCount mClickedStartSample{};
   sampleCount mLastDragSample{};
   float mLastDragSampleValue{};
   bool mAltKey{};
};

#endif
