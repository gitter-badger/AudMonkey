/**********************************************************************

AudMonkey: A Digital Audio Editor

SliderHandle.h

Paul Licameli

**********************************************************************/

#ifndef __AUDMONKEY_SLIDER_HANDLE__
#define __AUDMONKEY_SLIDER_HANDLE__

#include "../../UIHandle.h"

class wxMouseEvent;
class wxMouseState;
class LWSlider;
class Track;
class TranslatableString;

class AUDMONKEY_DLL_API SliderHandle /* not final */ : public UIHandle
{
   SliderHandle(const SliderHandle&) = delete;

public:
   using SliderFn = LWSlider *(*)( AudMonkeyProject*, const wxRect&, Track* );

   explicit SliderHandle
      ( SliderFn sliderFn, const wxRect &rect,
        const std::shared_ptr<Track> &pTrack );

   SliderHandle &operator=(const SliderHandle&) = default;

   std::shared_ptr<Track> GetTrack() const { return mpTrack.lock(); }
   bool IsClicked() const { return mIsClicked; }

protected:
   virtual ~SliderHandle();

   // These NEW abstract virtuals simplify the duties of further subclasses.
   // This class will decide whether to refresh the clicked cell for slider state
   // change.
   // Subclass can decide to refresh other things and the results will be ORed.
   virtual float GetValue() = 0;
   virtual Result SetValue(AudMonkeyProject *pProject, float newValue) = 0;
   virtual Result CommitChanges
      (const wxMouseEvent &event, AudMonkeyProject *pProject) = 0;

   // Define a message for the status bar and tooltip.
   virtual TranslatableString Tip(
      const wxMouseState &state, AudMonkeyProject &project) const = 0;
 
   void Enter(bool forward, AudMonkeyProject *) override;

   Result Click
      (const TrackPanelMouseEvent &event, AudMonkeyProject *pProject)
      final override;

   Result Drag
      (const TrackPanelMouseEvent &event, AudMonkeyProject *pProject)
      final override;

   HitTestPreview Preview
      (const TrackPanelMouseState &state, AudMonkeyProject *pProject)
      final override;

   Result Release
      (const TrackPanelMouseEvent &event, AudMonkeyProject *pProject,
       wxWindow *pParent) final override;

   Result Cancel(AudMonkeyProject *pProject) final override;

   // Derived class is expected to set these two before Click():
   std::weak_ptr<Track> mpTrack;
   wxRect mRect{};
   SliderFn mSliderFn;
   LWSlider *GetSlider( AudMonkeyProject *pProject );

   float mStartingValue {};

   bool mIsClicked{};
};

#endif
