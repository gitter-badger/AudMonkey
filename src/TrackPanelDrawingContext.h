/**********************************************************************

 AudMonkey: A Digital Audio Editor

 TrackPanelDrawingContext.h

 Paul Licameli

 **********************************************************************/

#ifndef __AUDMONKEY_TRACK_PANEL_DRAWING_CONTEXT__
#define __AUDMONKEY_TRACK_PANEL_DRAWING_CONTEXT__

#include <memory>

class UIHandle;
using UIHandlePtr = std::shared_ptr<UIHandle>;
class wxDC;

#include <wx/mousestate.h> // member variable

struct TrackPanelDrawingContext {
   wxDC &dc;
   UIHandlePtr target;
   wxMouseState lastState;

   void *pUserData;

   // This redundancy fixes an MSVC compiler warning:
   TrackPanelDrawingContext() = delete;
};

#endif
