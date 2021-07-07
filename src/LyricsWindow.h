/**********************************************************************

  AudMonkey: A Digital Audio Editor

  LyricsWindow.h

  Vaughan Johnson
  Dominic Mazzoni

**********************************************************************/

#ifndef __AUDMONKEY_LYRICS_WINDOW__
#define __AUDMONKEY_LYRICS_WINDOW__

#include <wx/frame.h> // to inherit

#include "Prefs.h"

class AudMonkeyProject;
class LyricsPanel;

class LyricsWindow final : public wxFrame,
                           public PrefsListener
{

 public:
   LyricsWindow(AudMonkeyProject* parent);

   LyricsPanel *GetLyricsPanel() { return mLyricsPanel; };

 private:
   void OnCloseWindow(wxCloseEvent & WXUNUSED(event));

   void OnStyle_BouncingBall(wxCommandEvent &evt);
   void OnStyle_Highlight(wxCommandEvent &evt);
   void OnTimer(wxCommandEvent &event);

   void SetWindowTitle();

   // PrefsListener implementation
   void UpdatePrefs() override;

   AudMonkeyProject *mProject;
   LyricsPanel *mLyricsPanel;

 public:
   DECLARE_EVENT_TABLE()
};

#endif
