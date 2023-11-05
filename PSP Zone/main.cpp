#include <pspkernel.h>
#include <pspdebug.h>
#include <pspdisplay.h>
#include <pspctrl.h>
#include "gfx.h"
#include "player.h"
#include <pspgu.h>
#include <pspgum.h>

PSP_MODULE_INFO("PSPHome", 0,1,0);

bool running = true;
bool menu =  true;
bool inGame = true;

//#define PSP_BUF_WIDTH (512)
//#define PSP_SCR_WIDTH (480)
//#define PSP_SCR_HEIGHT (272)

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
    GFX::init();
    //pspDebugScreenInit();
    player spaceship(207);
    //Main Loop
    while(running){
        while(menu){
            sceCtrlSetSamplingCycle(0);
            sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

            SceCtrlData ctrlData0;
            sceCtrlReadBufferPositive(&ctrlData0, 1);

            GFX::clear(0xFFFFFFF);
            GFX::swapBuffers();
            sceDisplayWaitVblankStart();
            //Display start screen somehow
            switch(ctrlData0.Buttons){
            // Important buttons
            case PSP_CTRL_START:
                pspDebugScreenPrintf("START PRESSED\n");
                menu = false;
                break;
            }
        }

        while(inGame){

            sceCtrlSetSamplingCycle(0);
            sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

            SceCtrlData ctrlData;
            sceCtrlReadBufferPositive(&ctrlData, 1);
        

            GFX::clear(0xFF000000); //82CAFFFF RGB in HEX 0xFFFFCA82
            
            spaceship.draw();
            GFX::swapBuffers();
            //sceDisplayWaitVblankStart();

            
            switch (ctrlData.Buttons){
            // Important buttons
            case PSP_CTRL_START:
                //pspDebugScreenPrintf("START PRESSED\n");
                break;
            case PSP_CTRL_SELECT:
                //pspDebugScreenPrintf("SELECT PRESSED\n");
                break;

            // Right Buttons
            case PSP_CTRL_TRIANGLE:
                //pspDebugScreenPrintf("TRIANGLE PRESSED\n");
                break;
            case PSP_CTRL_CIRCLE:
                // pspDebugScreenPrintf("CIRCLE PRESSED\n");
                break;
            case PSP_CTRL_CROSS:
                //pspDebugScreenPrintf("CROSS PRESSED\n");
                break;
            case PSP_CTRL_SQUARE:
                //pspDebugScreenPrintf("SQUARE PRESSED\n");
                break;

            // D-Pad
            case PSP_CTRL_UP:
                //pspDebugScreenPrintf("UP PRESSED\n");
                break;
            case PSP_CTRL_RIGHT:
                spaceship.move(10);
                spaceship.draw();
                GFX::swapBuffers();
                //sceDisplayWaitVblankStart();
                break;
            case PSP_CTRL_DOWN:
                //pspDebugScreenPrintf("DOWN PRESSED\n");
                break;
            case PSP_CTRL_LEFT:
                spaceship.move(-10);
                spaceship.draw();
                GFX::swapBuffers();
                //sceDisplayWaitVblankStart();
                break;

            // TRIGGERRRREDDD!!?!?!?!?!??!
            case PSP_CTRL_RTRIGGER:
                //pspDebugScreenPrintf("Right pew pew\n");
                break;
            case PSP_CTRL_LTRIGGER:
                //pspDebugScreenPrintf("Left pew pew\n");
                break;
            }
        }

        sceKernelExitGame();

    }
}