#include "XPLMPlugin.h"
#include "xhatswitch.h"

#ifdef _WIN32
    // Thanks Microsoft, but I know how to use strncpy().
    #pragma warning(disable:4996)
#endif

XPLMCommandRef commandUp;
XPLMCommandRef commandDown;
XPLMCommandRef commandLeft;
XPLMCommandRef commandRight;

XPLMCommandRef commandUpLeft;
XPLMCommandRef commandUpRight;
XPLMCommandRef commandDownLeft;
XPLMCommandRef commandDownRight;

enum {
    CMD_UP_LEFT,
    CMD_UP_RIGHT,
    CMD_DOWN_LEFT,
    CMD_DOWN_RIGHT
};

PLUGIN_API int XPluginStart(char * outName, char * outSig, char * outDesc)
{
    strcpy(outName, "XHatSwitch 1.0");
    strcpy(outSig, "strosser.tools.xhatswitch");
    strcpy(outDesc, "Provides commands for 8-way hat switch");

    commandUp = XPLMFindCommand(COMMAND_UP);
    commandDown = XPLMFindCommand(COMMAND_DOWN);
    commandLeft = XPLMFindCommand(COMMAND_LEFT);
    commandRight = XPLMFindCommand(COMMAND_RIGHT);

    commandUpLeft = XPLMCreateCommand(COMMAND_UP_LEFT, "rot_up_left");
    commandUpRight = XPLMCreateCommand(COMMAND_UP_RIGHT, "rot_up_right");
    commandDownLeft = XPLMCreateCommand(COMMAND_DOWN_LEFT, "rot_down_left");
    commandDownRight = XPLMCreateCommand(COMMAND_DOWN_RIGHT, "rot_down_right");

    return 1;
}

PLUGIN_API void	XPluginStop(void)
{
}

PLUGIN_API void XPluginDisable(void)
{
    XPLMUnregisterCommandHandler(commandUpLeft, XHatSwitch_CommandHandler, 0, (void *) CMD_UP_LEFT);
    XPLMUnregisterCommandHandler(commandUpRight, XHatSwitch_CommandHandler, 0, (void *) CMD_UP_RIGHT);
    XPLMUnregisterCommandHandler(commandDownLeft, XHatSwitch_CommandHandler, 0, (void *) CMD_DOWN_LEFT);
    XPLMUnregisterCommandHandler(commandDownRight, XHatSwitch_CommandHandler, 0, (void *) CMD_DOWN_RIGHT);
}

PLUGIN_API int XPluginEnable(void)
{
    XPLMRegisterCommandHandler(commandUpLeft, XHatSwitch_CommandHandler, 0, (void *) CMD_UP_LEFT);
    XPLMRegisterCommandHandler(commandUpRight, XHatSwitch_CommandHandler, 0, (void *) CMD_UP_RIGHT);
    XPLMRegisterCommandHandler(commandDownLeft, XHatSwitch_CommandHandler, 0, (void *) CMD_DOWN_LEFT);
    XPLMRegisterCommandHandler(commandDownRight, XHatSwitch_CommandHandler, 0, (void *) CMD_DOWN_RIGHT);

    return 1;
}

PLUGIN_API void XPluginReceiveMessage(XPLMPluginID inFromWho, long inMessage, void * inParam)
{
    // Kill warnings about unused variables
    (void) inFromWho;
    (void) inMessage;
    (void) inParam;
}

int XHatSwitch_CommandHandler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void * inRefCon)
{
    (void) inCommand;
    (void) inPhase;

    switch ((int) inRefCon) {
        case CMD_UP_LEFT:
            XPLMCommandOnce(commandUp);
            XPLMCommandOnce(commandLeft);
            break;

        case CMD_UP_RIGHT:
            XPLMCommandOnce(commandUp);
            XPLMCommandOnce(commandRight);
            break;

        case CMD_DOWN_LEFT:
            XPLMCommandOnce(commandDown);
            XPLMCommandOnce(commandLeft);
            break;

        case CMD_DOWN_RIGHT:
            XPLMCommandOnce(commandDown);
            XPLMCommandOnce(commandRight);
            break;

        default:
            break;
    }

    return 0;
}
