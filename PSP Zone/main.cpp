#include <pspkernel.h>
#include <pspdebug.h>
#include <pspctrl.h>

PSP_MODULE_INFO("PSPHome", 0,1,0);

// This code basically enables exiting via home
int exit_callback(int agr1,int arg2, void* common){
    sceKernelExitGame();
    return 0;
}

int callbackThread(SceSize args, void* argp){
    int cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
    sceKernelRegisterExitCallback(cbid);

    sceKernelSleepThreadCB();
    return 0;
}

void setupCallbacks(){
    int thid = sceKernelCreateThread("update_thread", callbackThread, 0x11, 0xFA0, 0, NULL);
    if(thid >= 0){
        sceKernelStartThread(thid,0,NULL);
    }
}

auto main() -> int{
    setupCallbacks();
    pspDebugScreenInit();

    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    SceCtrlData ctrlData;

    pspDebugScreenPrintf("Hello from C++!");
    while(true){
        sceCtrlReadBufferPositive(&ctrlData, 1);

        switch (ctrlData.Buttons)
        {

        // Important buttons
        case PSP_CTRL_START:
            pspDebugScreenPrintf("START PRESSED\n");
            break;
        case PSP_CTRL_SELECT:
            pspDebugScreenPrintf("SELECT PRESSED\n");
            break;

        // Right Buttons
        case PSP_CTRL_TRIANGLE:
            pspDebugScreenPrintf("TRIANGLE PRESSED\n");
            break;
        case PSP_CTRL_CIRCLE:
            pspDebugScreenPrintf("CIRCLE PRESSED\n");
            break;
        case PSP_CTRL_CROSS:
            pspDebugScreenPrintf("CROSS PRESSED\n");
            break;
        case PSP_CTRL_SQUARE:
            pspDebugScreenPrintf("SQUARE PRESSED\n");
            break;

        // D-Pad
        case PSP_CTRL_UP:
            pspDebugScreenPrintf("UP PRESSED\n");
            break;
        case PSP_CTRL_RIGHT:
            pspDebugScreenPrintf("RIGHT PRESSED\n");
            break;
        case PSP_CTRL_DOWN:
            pspDebugScreenPrintf("DOWN PRESSED\n");
            break;
        case PSP_CTRL_LEFT:
            pspDebugScreenPrintf("LEFT PRESSED\n");
            break;

        // TRIGGERRRREDDD!!?!?!?!?!??!
        case PSP_CTRL_RTRIGGER:
            pspDebugScreenPrintf("Right pew pew\n");
            break;
        case PSP_CTRL_LTRIGGER:
            pspDebugScreenPrintf("Left pew pew\n");
            break;
        }
    }
}