#include "scenario.h"
#include "common.h"

extern volatile s32* D_801C77D8_1C8398;
static s16 scenario_text_0000[] = { CTR_BEGIN, CTR_ENDLINE };
static s16 scenario_text_0004[] = { PCT_SPACE, CTR_NEWLINE, CTR_ENDLINE };
static s16 scenario_text_0074[] = { CTR_NEWWINDOW, CTR_ENDLINE };

// ma yoeru ko hitsujitachiyo
static s16 scenario_text_000C[] = {
    PCT_SPACE,CTR_EM_BLUE,
    PCT_SPACE,
    CHR_M,CHR_a,
    PCT_SPACE,
    CHR_y,CHR_o,CHR_e,CHR_r,CHR_u,
    PCT_SPACE,
    CHR_k,CHR_o,
    PCT_SPACE,
    CHR_h,CHR_i,CHR_t,CHR_s,CHR_u,CHR_j,CHR_i,CHR_t,CHR_a,CHR_c,CHR_h,CHR_i,CHR_y,CHR_o,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};

// sa miruga i
static s16 scenario_text_0018[] = {
    PCT_SPACE,CTR_EM_RED,PCT_SPACE,
    CHR_S,CHR_a,PCT_SPACE,
    CHR_m,CHR_i,CHR_r,CHR_u,CHR_g,CHR_a,PCT_SPACE,
    CHR_i,CTR_CLOSE_EM,
    CTR_ENDLINE
};

// mai suteji Just Dancin
static s16 scenario_text_0024[] = {
    PCT_SPACE,PCT_SPACE,CTR_EM_BLUE,
    PCT_SPACE,PCT_SPACE,
    CHR_M,CHR_a,CHR_i,PCT_SPACE,
    CHR_S,CHR_u,CHR_t,CHR_e,CHR_j,CHR_i,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};


// mai suteji Just lily
static s16 scenario_text_0028[] = {
    PCT_SPACE,CTR_EM_RED,
    PCT_SPACE,
    CHR_M,CHR_a,CHR_i,
    PCT_SPACE,
    CHR_S,CHR_u,CHR_t,CHR_e,CHR_j,CHR_i,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};

// gojasu
static s16 scenario_text_0038[] = {
    PCT_SPACE,PCT_SPACE,PCT_SPACE,
    CTR_EM_RED,
    PCT_SPACE,PCT_SPACE,PCT_SPACE,
    CHR_G,CHR_o,CHR_j,CHR_a,CHR_s,CHR_u,
    CTR_CLOSE_EM,
    PCT_SPACE,PCT_SPACE,
    CTR_EM_BLUE,
    PCT_SPACE,CHR_G,CHR_o,CHR_j,CHR_a,CHR_s,CHR_u,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};

// no ni saku bara lily
static s16 scenario_text_0048[] = {
    PCT_SPACE,CTR_EM_RED,
    CHR_N,CHR_o,PCT_SPACE,
    CHR_n,CHR_i,PCT_SPACE,
    CHR_s,CHR_a,CHR_k,CHR_u,PCT_SPACE,
    CHR_b,CHR_a,CHR_r,CHR_a,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};

// no ni saku bara Dancin
static s16 scenario_text_0044[] = {
    PCT_SPACE,CTR_EM_BLUE,
    PCT_SPACE,CHR_N,CHR_o,PCT_SPACE,
    CHR_n,CHR_i,PCT_SPACE,
    CHR_s,CHR_a,CHR_k,CHR_u,PCT_SPACE,
    CHR_b,CHR_a,CHR_r,CHR_a,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};

// amai kaori Lily
static s16 scenario_text_0060[] = {
    PCT_SPACE,CTR_EM_RED,
    PCT_SPACE,
    CHR_a,CHR_m,CHR_a,CHR_i,
    PCT_SPACE,
    CHR_k,CHR_a,CHR_o,CHR_r,CHR_i,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};


// amai kaori Dancin
static s16 scenario_text_0062[] = {
    PCT_SPACE,CTR_EM_BLUE,
    PCT_SPACE,PCT_SPACE,CHR_a,CHR_m,CHR_a,CHR_i,PCT_SPACE,
    CHR_k,CHR_a,CHR_o,CHR_r,CHR_i,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};


// futari tsumu merodi Lily
static s16 scenario_text_0078[] = {
    PCT_SPACE,CTR_EM_RED,CHR_f,CHR_u,CHR_t,CHR_a,CHR_r,CHR_i,PCT_SPACE,
    CHR_t,CHR_s,CHR_u,CHR_t,CHR_s,CHR_u,CHR_m,CHR_u,PCT_SPACE,
    CHR_m,CHR_e,CHR_r,CHR_o,CHR_d,CHR_i,CTR_CLOSE_EM,
    CTR_ENDLINE
};


// futari tsumu merodi Dancin
static s16 scenario_text_0080[] = {
    PCT_SPACE,CTR_EM_BLUE,
    PCT_SPACE,PCT_SPACE,PCT_SPACE,
    CHR_f,CHR_u,CHR_t,CHR_a,CHR_r,CHR_i,PCT_SPACE,
    CHR_t,CHR_s,CHR_u,CHR_t,CHR_s,CHR_u,CHR_m,CHR_u,PCT_SPACE,
    CHR_m,CHR_e,CHR_r,CHR_o,CHR_d,CHR_i,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};


// (suwito memori) 1
static s16 scenario_text_0092[] = {
    PCT_SPACE,CTR_EM_BLUE,PCT_LBRACKET,
    CHR_S,CHR_u,CHR_w,CHR_i,CHR_t,CHR_o,PCT_SPACE,
    CHR_m,CHR_e,CHR_m,CHR_o,CHR_r,CHR_i,
    PCT_RBRACKET,CTR_CLOSE_EM,
    CTR_ENDLINE
};

// (suwito memori) 2
static s16 scenario_text_0094[] = {
    PCT_SPACE,CTR_EM_RED,PCT_LBRACKET,
    CHR_S,CHR_u,CHR_w,CHR_i,CHR_t,CHR_o,PCT_SPACE,
    CHR_m,CHR_e,CHR_m,CHR_o,CHR_r,CHR_i,
    PCT_RBRACKET,CTR_CLOSE_EM,
    CTR_ENDLINE
};

// (suwito memori) 3
static s16 scenario_text_0096[] = {
    PCT_SPACE,PCT_LBRACKET,
    CHR_S,CHR_u,CHR_w,CHR_i,CHR_t,CHR_o,PCT_SPACE,
    CHR_m,CHR_e,CHR_m,CHR_o,CHR_r,CHR_i,
    PCT_RBRACKET,
    CTR_ENDLINE
};

// (suwito memori) 4
static s16 scenario_text_0098[] = {
    PCT_SPACE,CTR_EM_GREEN,PCT_LBRACKET,
    CHR_S,CHR_u,CHR_w,CHR_i,CHR_t,CHR_o,PCT_SPACE,
    CHR_m,CHR_e,CHR_m,CHR_o,CHR_r,CHR_i,
    PCT_RBRACKET,CTR_CLOSE_EM,
    CTR_ENDLINE
};

// yume no tsuzuki Lily
static s16 scenario_text_00C0[] = {
    PCT_SPACE,CTR_EM_RED,
    CHR_Y,CHR_u,CHR_m,CHR_e,PCT_SPACE,
    CHR_n,CHR_o,PCT_SPACE,
    CHR_t,CHR_s,CHR_u,CHR_z,CHR_u,CHR_k,CHR_i,CTR_CLOSE_EM,
    CTR_ENDLINE
};

// yume no tsuzuki Dancin
static s16 scenario_text_00C2[] = {
    PCT_SPACE,PCT_SPACE,CTR_EM_BLUE,
    CHR_Y,CHR_u,CHR_m,CHR_e,PCT_SPACE,
    CHR_n,CHR_o,PCT_SPACE,
    CHR_t,CHR_s,CHR_u,CHR_z,CHR_u,CHR_k,CHR_i,CTR_CLOSE_EM,
    CTR_ENDLINE
};

// konya wa Lily
static s16 scenario_text_00D6[] = {
    PCT_SPACE,CTR_EM_RED,
    PCT_SPACE,
    CHR_k,CHR_o,CHR_n,CHR_y,CHR_a,PCT_SPACE,
    CHR_w,CHR_a,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};

// konya wa Dancin
static s16 scenario_text_00D8[] = {
    PCT_SPACE,PCT_SPACE,CTR_EM_BLUE,
    PCT_SPACE,PCT_SPACE,PCT_SPACE,
    CHR_k,CHR_o, CHR_n,CHR_y,CHR_a,
    PCT_SPACE,
    CHR_w,CHR_a,CTR_CLOSE_EM,
    CTR_ENDLINE
};

// oh gojasu mai lily
static s16 scenario_text_00E6[] = {
    PCT_SPACE,CTR_EM_RED,CHR_O,CHR_H,PCT_EXCLAMATION,PCT_SPACE,
    CHR_G,CHR_o,CHR_j,CHR_a,CHR_s,CHR_u,PCT_SPACE,
    CHR_M,CHR_a,CHR_i,CTR_CLOSE_EM,
    CTR_ENDLINE
};

// oh gojasu mai dancin
static s16 scenario_text_00E8[] = {
    PCT_SPACE,CTR_EM_BLUE,PCT_SPACE,PCT_SPACE,CHR_O,CHR_H,PCT_EXCLAMATION,PCT_SPACE,
    CHR_G,CHR_o,CHR_j,CHR_a,CHR_s,CHR_u,PCT_SPACE,
    CHR_M,CHR_a,CHR_i,CTR_CLOSE_EM,
    CTR_ENDLINE
};

// mai suteji !! lily
static s16 scenario_text_0106[] = {
    PCT_SPACE,CTR_EM_RED,
    CHR_M,CHR_a,CHR_i,PCT_SPACE,
    CHR_S,CHR_u,CHR_t,CHR_e,CHR_j,CHR_i,
    PCT_EXCLAMATION,PCT_EXCLAMATION,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};


// mai suteji !! dancin
static s16 scenario_text_0108[] = {
    PCT_SPACE,CTR_EM_BLUE,
    PCT_SPACE,PCT_SPACE,
    CHR_M,CHR_a,CHR_i,PCT_SPACE,
    CHR_S,CHR_u,CHR_t,CHR_e,CHR_j,CHR_i,
    PCT_EXCLAMATION,PCT_EXCLAMATION,
    CTR_CLOSE_EM,
    CTR_ENDLINE
};

// LAUGH  waraigoe no rokuon
static s16 scenario_text_0112[] = {
    PCT_SPACE,
    CTR_EM_YELLOW,
    CTR_BLINK,
    CHR_W,CHR_A,CHR_R,
    CHR_A,CHR_I,CHR_G,CHR_O,CHR_E,PCT_SPACE,CHR_N,CHR_O,PCT_SPACE,CHR_R,CHR_O,CHR_K,CHR_U,CHR_O,CHR_N,
    PCT_EXCLAMATION,PCT_EXCLAMATION,
    CTR_CLOSE_EM,
    CTR_CLOSE_BLINK,
    CTR_ENDLINE
};


static s16 scenario_text_0180[] = { CTR_END, CTR_ENDLINE };

// ===== Scenario Code =====
s32 scenario_code_gms_og[];

    // ===== Scenario Code =====
s32 scenario_code_gms_og[] = {

    // Window setup
    STW,     TEXT_SPEED,          WTS, 0x01, //text speed. Sets to max. zoooooooom
    STW, (s32)&D_801C7758_1C8358, WTS, 0x20,
    STW, (s32)&D_801C775C_1C835C, WTS, 0xAA,
    STW, (s32)&D_801C7768_1C8368, WTS, 0xB,

    TXT, (s32)&scenario_text_0000,  

    // Initial wait (match 1D4 timing)
    STW, (s32)&D_801C7740_1C8340, WTS, 0x1C0,
    ESR, (s32)&func_8003F460_40060,

    STW, (s32)&D_801C77D8_1C8398, WTS, 0x64,
    STW, (s32)&D_801C7798_1C8398, WTS, 0x1,

    // Opening line: "ma yoeru ko hitsujitachiyo  sa miruga i"
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_000C,  
    STW, (s32)&D_801C7740_1C8340, WTS, 0x65,
    ESR, (s32)&func_8003F460_40060,

    // Window 1: sa miruga i
    TXT, (s32)&scenario_text_0074,  // window marker
    TXT, (s32)&scenario_text_0004,  // spacer/padding
    TXT, (s32)&scenario_text_0018,  
    STW, (s32)&D_801C7740_1C8340, WTS, 0x48,  
    ESR, (s32)&func_8003F460_40060,

    // Window 2: my stage
    TXT, (s32)&scenario_text_0024,  
    STW, (s32)&D_801C7740_1C8340, WTS, 0x30,
    ESR, (s32)&func_8003F460_40060,


    // Window 3: "gorgeous
    STW,     TEXT_SPEED,          WTS, 0x64, //text speed. Sets to max. zoooooooom
    TXT, (s32)&scenario_text_0074,
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_0038,  
    STW, (s32)&D_801C7740_1C8340, WTS, 0x5E,
    ESR, (s32)&func_8003F460_40060,
   
    // Window 2: my stage
  TXT, (s32)&scenario_text_0074,
  TXT, (s32)&scenario_text_0004,
  TXT, (s32)&scenario_text_0028,
  TXT, (s32)&scenario_text_0024,
  STW, (s32)&D_801C7740_1C8340, WTS, 0x1E,
  ESR, (s32)&func_8003F460_40060,

  //  BLANK
   STW,     TEXT_SPEED,          WTS, 0x01, //text speed. Sets to max. zoooooooom
   TXT, (s32)&scenario_text_0074,
   STW, (s32)&D_801C7740_1C8340, WTS, 0xBA,
   ESR, (s32)&func_8003F460_40060,

    //  no ni saku bara
    STW,     TEXT_SPEED,          WTS, 0x64, //text speed. Sets to max. zoooooooom
    TXT, (s32)&scenario_text_0074,
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_0048,  
    TXT, (s32)&scenario_text_0044,
    STW, (s32)&D_801C7740_1C8340, WTS, 0x62,
    ESR, (s32)&func_8003F460_40060,

    // amai kaori
    TXT, (s32)&scenario_text_0074,
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_0060,  
    TXT, (s32)&scenario_text_0062,
    STW, (s32)&D_801C7740_1C8340, WTS, 0x68,
    ESR, (s32)&func_8003F460_40060,

    // futari tsumu merodi
    TXT, (s32)&scenario_text_0074,
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_0078,  
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_0080,
    STW, (s32)&D_801C7740_1C8340, WTS, 0x78,
    ESR, (s32)&func_8003F460_40060,

    // (suwito memori)
 
    TXT, (s32)&scenario_text_0074,
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_0092,
    TXT, (s32)&scenario_text_0094,
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_0098,
    TXT, (s32)&scenario_text_0096,
    STW, (s32)&D_801C7740_1C8340, WTS, 0x4A,
    ESR, (s32)&func_8003F460_40060,


    //  yume no tsuzuki
   
    TXT, (s32)&scenario_text_0074,
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_00C0,
    TXT, (s32)&scenario_text_00C2,
    STW, (s32)&D_801C7740_1C8340, WTS, 0x55,
    ESR, (s32)&func_8003F460_40060,

    //  konya wa
   TXT, (s32)&scenario_text_0074,
   TXT, (s32)&scenario_text_0004,
   TXT, (s32)&scenario_text_00D6,
   TXT, (s32)&scenario_text_00D8,
   STW, (s32)&D_801C7740_1C8340, WTS, 0x55,
   ESR, (s32)&func_8003F460_40060,

    // oh gojasu mai
    TXT, (s32)&scenario_text_0074,
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_00E6,
    TXT, (s32)&scenario_text_00E8,
    STW, (s32)&D_801C7740_1C8340, WTS, 0x65,
    ESR, (s32)&func_8003F460_40060,

  // mai suteji !!
    STW, TEXT_SPEED, WTS, 0x64, //text speed. Sets to max. zoooooooom
    TXT, (s32)&scenario_text_0074,
    TXT, (s32)&scenario_text_0004,
    TXT, (s32)&scenario_text_0106,
    TXT, (s32)&scenario_text_0108,  
    STW, (s32)&D_801C7740_1C8340, WTS, 0xA0,
    ESR, (s32)&func_8003F460_40060,

      //  BLANK
    STW, TEXT_SPEED, WTS, 0x01, //text speed. Sets to max. zoooooooom
    TXT, (s32)&scenario_text_0074,
    STW, (s32)&D_801C7740_1C8340, WTS, 0x98,
    ESR, (s32)&func_8003F460_40060,


   //  laughing
        TXT, (s32)&scenario_text_0074,
        TXT, (s32)&scenario_text_0004,
        TXT, (s32)&scenario_text_0112,
        STW, (s32)&D_801C7740_1C8340, WTS, 0x70,
        ESR, (s32)&func_8003F460_40060,


    // End
    TXT, (s32)&scenario_text_0180,
    END,
};