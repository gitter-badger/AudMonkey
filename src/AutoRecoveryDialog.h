/**********************************************************************

AudMonkey: A Digital Audio Editor

AutoRecoveryDialog.h

Paul Licameli split from AutoRecovery.h

**********************************************************************/

#ifndef __AUDMONKEY_AUTO_RECOVERY_DIALOG__
#define __AUDMONKEY_AUTO_RECOVERY_DIALOG__

class AudMonkeyProject;

//
// Show auto recovery dialog if there are projects to recover. Should be
// called once at AudMonkey startup.
//
// This function possibly opens NEW project windows while it recovers all
// projects. If so, it will re-use *pproj, if != NULL and set it to NULL.
//
// Returns: True, if the start of AudMonkey should continue as normal
//          False if AudMonkey should be quit immediately
//
// The didRecoverAnything param is strictly for a return value.
// Any value passed in is ignored.
//
bool ShowAutoRecoveryDialogIfNeeded(AudMonkeyProject*& pproj,
                                    bool *didRecoverAnything);

#endif
