#ifndef XHATSWITCH_H
#define XHATSWITCH_H

#include "XPLMUtilities.h"

#define COMMAND_UP "sim/general/rot_up"
#define COMMAND_DOWN "sim/general/rot_down"
#define COMMAND_LEFT "sim/general/rot_left"
#define COMMAND_RIGHT "sim/general/rot_right"

#define COMMAND_UP_LEFT "strosser/general/rot_up_left"
#define COMMAND_UP_RIGHT "strosser/general/rot_up_right"
#define COMMAND_DOWN_LEFT "strosser/general/rot_down_left"
#define COMMAND_DOWN_RIGHT "strosser/general/rot_down_right"

extern XPLMCommandRef commandUp;
extern XPLMCommandRef commandDown;
extern XPLMCommandRef commandLeft;
extern XPLMCommandRef commandRight;

int XHatSwitch_CommandHandler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void * inRefCon);

#endif // XHATSWITCH_H
