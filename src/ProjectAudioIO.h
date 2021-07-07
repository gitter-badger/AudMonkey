/**********************************************************************

AudMonkey: A Digital Audio Editor

ProjectAudioIO.h

Paul Licameli split from AudMonkeyProject.h

**********************************************************************/

#ifndef __PROJECT_AUDIO_IO__
#define __PROJECT_AUDIO_IO__

#include "ClientData.h" // to inherit
#include <wx/weakref.h>

class AudMonkeyProject;

// Windows build needs complete type for parameter of wxWeakRef
// class MeterPanelBase;
#include "widgets/MeterPanelBase.h"

///\ brief Holds per-project state needed for interaction with AudioIO,
/// including the audio stream token and pointers to meters
class AUDACITY_DLL_API ProjectAudioIO final
   : public ClientData::Base
{
public:
   static ProjectAudioIO &Get( AudMonkeyProject &project );
   static const ProjectAudioIO &Get( const AudMonkeyProject &project );

   explicit ProjectAudioIO( AudMonkeyProject &project );
   ProjectAudioIO( const ProjectAudioIO & ) PROHIBITED;
   ProjectAudioIO &operator=( const ProjectAudioIO & ) PROHIBITED;
   ~ProjectAudioIO();

   int GetAudioIOToken() const;
   bool IsAudioActive() const;
   void SetAudioIOToken(int token);

   MeterPanelBase *GetPlaybackMeter();
   void SetPlaybackMeter(MeterPanelBase *playback);
   MeterPanelBase *GetCaptureMeter();
   void SetCaptureMeter(MeterPanelBase *capture);

private:
   AudMonkeyProject &mProject;

   // Project owned meters
   wxWeakRef<MeterPanelBase> mPlaybackMeter{};
   wxWeakRef<MeterPanelBase> mCaptureMeter{};

   int  mAudioIOToken{ -1 };
};

#endif
