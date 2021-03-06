/**********************************************************************

AudMonkey: A Digital Audio Editor

LabelDefaultClickHandle.h

Paul Licameli split from TrackPanel.cpp

**********************************************************************/

#ifndef __AUDMONKEY_LABEL_DEFAULT_CLICK_HANDLE__
#define __AUDMONKEY_LABEL_DEFAULT_CLICK_HANDLE__

#include "../../../UIHandle.h"

class wxMouseEvent;
class LabelTrack;

// Used as a base class.
// Adds some behavior to clicks.
class LabelDefaultClickHandle /* not final */ : public UIHandle
{
public:
   LabelDefaultClickHandle();
   virtual ~LabelDefaultClickHandle();

   LabelDefaultClickHandle &operator=
      (const LabelDefaultClickHandle&) = default;
   
   Result Click
      (const TrackPanelMouseEvent &event, AudMonkeyProject *pProject) override;

   Result Drag
      (const TrackPanelMouseEvent &event, AudMonkeyProject *pProject) override;

   // does not override Preview()

   Result Release
      (const TrackPanelMouseEvent &event, AudMonkeyProject *pProject,
       wxWindow *pParent) override;

   Result Cancel(AudMonkeyProject *pProject) override;

private:
   struct LabelState;
   std::shared_ptr< LabelState > mLabelState;
   void SaveState( AudMonkeyProject *pProject );
   void RestoreState( AudMonkeyProject *pProject );
};

#endif
