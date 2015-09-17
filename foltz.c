/*
-------------------------------------------------
THE ART OF EXTERNAL TROLLING - THE FOOTAGE
FOLTZ.C
--------------------------------------------------
*/

#include <stdio.h>
#include <nds.h>
#include <nf_lib.h>
#include <nds/touch.h>
#include <nds/input.h>
#include <stdlib.h>
#include <filesystem.h>
#include <fat.h>
#include <unistd.h>

#include "viDSnips.h"
#include "IceDaddy-Reg.h"

#define RED 1
#define GREEN 2
#define BLUE 3

int HomeRoom();
int MainVideo();
int Credits();

touchPosition touched;

int main(int argc, char **argv) {
    NF_Set2D(0, 0);
    NF_Set2D(1, 0);
    soundEnable();
    consoleDemoInit();
    swiWaitForVBlank();
    NF_SetRootFolder("NITROFS");
    NF_UpdateTextLayers();
    HomeRoom();
    return 0;
}

// TITLE SCREEN
int HomeRoom(void) {
    NF_Set2D(0, 0);
    NF_Set2D(1, 0);
    NF_InitTiledBgBuffers();
    NF_InitTiledBgSys(0);
    NF_InitTiledBgSys(1);
    NF_InitTextSys(0);
    NF_InitTextSys(1);

    // FONT ENGINE
    NF_LoadTextFont("fnt/f","PIXELFONT", 256, 256, 0);
    NF_LoadTextFont("fnt/f","PIXELFONTBOTTOM", 256, 256, 0);
    NF_CreateTextLayer(0, 0, 0, "PIXELFONT");
    NF_CreateTextLayer(1, 3, 0, "PIXELFONTBOTTOM");
    NF_CreateTextLayer(0, 1, 0, "PIXELFONT");
    NF_DefineTextColor(0, 0, 1, 31, 0, 0);
    NF_SetTextColor(0, 1, 1);
    NF_CreateTextLayer(0, 2, 0, "PIXELFONT");
    NF_DefineTextColor(0, 0, 2, 31, 31, 0);
    NF_SetTextColor(0, 2, 2);
    NF_WriteText(0, 0, 2, 8, "the art of external trolling");
    NF_WriteText(0, 1, 10, 14, "the footage");
    NF_WriteText(0, 2, 7, 23, "[c] hakobyte 2012");
    NF_WriteText(0, 1, 0, 23, "V 2.0");

    //  SECOND SCREEN (WITH TOUCH)
    NF_WriteText(1, 3, 12, 12, "go go go!");
    NF_WriteText(1, 3, 1, 23, "hakobaito.co.uk");
    NF_WriteText(1, 3, 20, 23, "x = credits");

    while(1) {
        scanKeys();
        if(keysDown() & KEY_TOUCH) {
            touchRead(&touched);
            MainVideo();
        } else if (keysDown() & KEY_X) {
            Credits();
        }
        NF_UpdateTextLayers();
        swiWaitForVBlank();
    }
    return 0;
}

// CREDITS SCREEN
int Credits(void) {
    NF_Set2D(0, 0);
    NF_Set2D(1, 0);
    NF_InitTiledBgBuffers();
    NF_InitTiledBgSys(0);
    NF_InitTiledBgSys(1);
    NF_InitTextSys(0);
    NF_LoadTextFont("fnt/f","PIXELFONT", 256, 256, 0);
    NF_LoadTextFont("fnt/f","PIXELFONT0", 256, 256, 0);
    NF_LoadTextFont("fnt/f","PIXELFONTx", 256, 256, 0);
    NF_LoadTextFont("fnt/f","PIXELFONT2", 256, 256, 0);
    NF_CreateTextLayer(0, 0, 0, "PIXELFONT0");
    NF_CreateTextLayer(0, 1, 0, "PIXELFONTx");
    NF_CreateTextLayer(1, 1, 0, "PIXELFONTx");
    NF_CreateTextLayer(1, 3, 0, "PIXELFONT");
    NF_CreateTextLayer(0, 2, 0, "PIXELFONT2");
    NF_DefineTextColor(0, 0, 1, 31, 0, 0);
    NF_DefineTextColor(0, 1, 1, 31, 31, 10);
    NF_DefineTextColor(1, 1, 1, 31, 31, 10);
    NF_SetTextColor(0, 1, 1);
    NF_SetTextColor(0, 0, 1);
    NF_SetTextColor(1, 1, 1);

    while(1) {
        NF_WriteText(1, 3, 2, 4, "And thank you for downloading");
        NF_WriteText(1, 3, 10, 6, "the footage!.");
        NF_WriteText(1, 3, 3, 8, "=[],");
        NF_WriteText(1, 3, 7, 21, "Press X to go back");
        NF_WriteText(0, 2, 12, 2, "credits");
        NF_WriteText(0, 2, 2, 5, "frankie jax - tester");
        NF_WriteText(0, 2, 2, 17, "icedaddy - support + video api");
        NF_WriteText(0, 2, 2, 8, "GlassCake - support + friend");
        NF_WriteText(0, 2, 2, 11, "Cameraman99 - support + friend");
        NF_WriteText(0, 2, 2, 14, "lessthannormal01 - voices");
        NF_WriteText(1, 1, 7, 14, "twitter: @hakobyte");
        NF_WriteText(0, 0, 10, 21, "version 2.0");
        scanKeys();
        if(keysDown() & KEY_X) {
            HomeRoom();
        }
        if(keysDown() &  KEY_TOUCH) {
            Credits();
        }
        NF_UpdateTextLayers();
        swiWaitForVBlank();
        swiWaitForVBlank();
    }
    return 0;
}
// MAIN VIDEO
int MainVideo(void) {
    NF_Set2D(0, 0);
    NF_Set2D(1, 0);
    NF_InitTiledBgBuffers();
    NF_InitTiledBgSys(0);
    NF_InitTiledBgSys(1);
    NF_InitTextSys(0);
    // Initalise filesystem.
    nitroFSInit(NULL);
    chdir("nitro:/");
    viDSnips_Init(MAIN_SCREEN , false);
    NF_LoadTextFont("fnt/f","PIXELFONT", 256, 256, 0);

    while (true) {

        NF_InitTextSys(1);
        swiWaitForVBlank();
        NF_CreateTextLayer(1, 3, 0, "PIXELFONT");
        NF_WriteText(1, 3, 1, 10, "TOUCH ANYWHERE TO PLAY FOOTAGE");
        NF_WriteText(1, 3, 12, 16, "X = MENU");
        scanKeys();

        if(keysDown() & KEY_X) {
            HomeRoom();
        }

        // Play the footage.
        if(keysDown() & KEY_TOUCH) {
            NF_ClearTextLayer(1,3);
            NF_UpdateTextLayers();
            touchRead(&touched);
            soundEnable();
            viDSnips_Play("footage.vDS");
        }
    }
    return 0;
}