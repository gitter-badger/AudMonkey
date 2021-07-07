/**********************************************************************

AudMonkey: A Digital Audio Editor

CommonCommandFlags.h

Paul Licameli split from Menus.cpp

**********************************************************************/

#ifndef __AUDMONKEY_COMMON_COMMAND_FLAGS__
#define __AUDMONKEY_COMMON_COMMAND_FLAGS__



#include "commands/CommandFlag.h"

AUDMONKEY_DLL_API
bool EditableTracksSelectedPred( const AudMonkeyProject &project );

AUDMONKEY_DLL_API
bool AudioIOBusyPred( const AudMonkeyProject &project );

AUDMONKEY_DLL_API
bool TimeSelectedPred( const AudMonkeyProject &project );

AUDMONKEY_DLL_API
const CommandFlagOptions &cutCopyOptions();

extern AUDMONKEY_DLL_API const ReservedCommandFlag
   &AudioIONotBusyFlag(),
   &StereoRequiredFlag(),  //lda
   &NoiseReductionTimeSelectedFlag(),
   &TimeSelectedFlag(), // This is equivalent to check if there is a valid selection, so it's used for Zoom to Selection too
   &WaveTracksSelectedFlag(),
   &TracksExistFlag(),
   &EditableTracksSelectedFlag(),
   &AnyTracksSelectedFlag(),
   &TrackPanelHasFocus();  //lll

extern AUDMONKEY_DLL_API const ReservedCommandFlag
   &AudioIOBusyFlag(), // lll
   &CaptureNotBusyFlag();

extern AUDMONKEY_DLL_API const ReservedCommandFlag
   &LabelTracksExistFlag(),
   &UnsavedChangesFlag(),
   &UndoAvailableFlag(),
   &RedoAvailableFlag(),
   &ZoomInAvailableFlag(),
   &ZoomOutAvailableFlag(),
   &PlayRegionLockedFlag(),  //msmeyer
   &PlayRegionNotLockedFlag(),  //msmeyer
   &WaveTracksExistFlag(),
   &NoteTracksExistFlag(),  //gsw
   &NoteTracksSelectedFlag(),  //gsw
   &IsNotSyncLockedFlag(),  //awd
   &IsSyncLockedFlag(),  //awd
   &NotMinimizedFlag(), // prl
   &PausedFlag(), // jkc
   &PlayableTracksExistFlag(),
   &AudioTracksSelectedFlag(),
   &NoAutoSelect() // jkc
;

#endif
