#include "scenario.h"
#include "common.h"
#include "recomputils.h"
#include "modding.h"
#include "recompconfig.h"

extern s32 scenario_code_gms_og[];
extern s32 scenario_code_gms_song[];
extern s32 scenario_code_gms_removed[];
extern s32 scenario_code_gms_rama[];
extern s32 scenario_code_gms_goi[];
#define GMS_SCENARIO_ID 777  // scenario being replaced

// Helper function to choose which C file pointer to use
s32* get_selected_gms_lyrics(void) {
    unsigned long version = recomp_get_config_u32("gms_lyrics_version");


    switch (version)
    {
    case 0: return scenario_code_gms_og;
    case 1: return scenario_code_gms_rama;
    case 2: return scenario_code_gms_goi;
    case 3: return scenario_code_gms_removed;
    default: return scenario_code_gms_og;
    }
}

// ---------------------------
// Replace scenario function
// ---------------------------
void replace_scenario(s32 scenario_id, s32* scenario_code, s16 scenario_file_id) {
    D_800779A0_785A0[scenario_id] = scenario_code;
    D_80078608_79208[scenario_id] = scenario_file_id;
}

// ---------------------------
// Hook to Replace Scenario 775
// ---------------------------
RECOMP_HOOK("func_8003F1D8_3FDD8")
void main_hook() {
    s32* selected_lyrics = get_selected_gms_lyrics();
    replace_scenario(GMS_SCENARIO_ID, selected_lyrics, 0);



}