/**********************************************************************
 
 AudMonkey: A Digital Audio Editor
 
 QualitySettings.h
 
 Paul Licameli split from QualityPrefs.h
 
 **********************************************************************/

#ifndef __AUDMONKEY_QUALITY_SETTINGS__
#define __AUDMONKEY_QUALITY_SETTINGS__

#include "Prefs.h" // for EnumSetting

class IntSetting;

namespace QualitySettings {
extern AUDMONKEY_DLL_API IntSetting DefaultSampleRate;
extern AUDMONKEY_DLL_API EnumSetting< sampleFormat > SampleFormatSetting;
extern AUDMONKEY_DLL_API sampleFormat SampleFormatChoice();
}

#endif
