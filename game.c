// Copyright (c) 2020 Marcus A. Mosley All rights reserved.
//
// Created by Marcus A. Mosley
// Created on January 2020
// This program shows a Start Screen

#include <gb/gb.h>
#include <stdio.h>
#include "logo_data.c"
#include "logo_map.c"
#include "titlescreen_data.c"
#include "titlescreen_map.c"
UINT8 i;

void performantdelay(UINT8 numloops) {
    UINT8 ii;
    for (ii = 0; ii < numloops; ii++) {
        wait_vbl_done();
    }
}

void fadeout() {
    for (i=0; i < 4; i++) {
        switch (i) {
            case 0:
                BGP_REG = 0xE4;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xFE;
                break;
            case 3:
                BGP_REG = 0xFF;
                break;
        }
        performantdelay(5);
    }
}

void fadein() {
    for (i=0; i < 3; i++) {
        switch (i) {
            case 0:
                BGP_REG = 0xFE;
                break;
            case 1:
                BGP_REG = 0xF9;
                break;
            case 2:
                BGP_REG = 0xE4;
                break;
        }
        performantdelay(5);
    }
}

void main() {
    set_bkg_data(0, 114, logo_data);
    set_bkg_tiles(0, 0, 20, 18, logo_map);

    SHOW_BKG;
    DISPLAY_ON;

    performantdelay(30);

    fadeout();

    set_bkg_data(0, 114, titlescreen_data);
    set_bkg_tiles(0, 0, 20, 18, titlescreen_map);

    fadein();

    waitpad(J_START);

    printf("START OF MY GAME");
}
