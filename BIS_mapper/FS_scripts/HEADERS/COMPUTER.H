#ifndef COMPUTER_H
#define COMPUTER_H

#define CompProcUsing                           script_overrides;               \
                                                if (local_var(LVAR_Status) == 0) then begin \
                                                g_display_mstr(550);            \
                                                end else if (combat_is_initialized == true) then begin \
                                                g_display_mstr(551);            \
                                                end else begin                  \
                                                call talk_p_proc;               \
                                                end                             \

#define CompProcSience(exp)                     CompProcSienceOK                \
                                                exp_add(exp);                   \
                                                g_display_mstr(553);            \

#define CompProcSienceOK                        set_local_var(LVAR_Status,1);   \
                                                play_sfx("SLDOORSA");           \
                                                dude_floater_OK;                \
                                                if ((self_PID == 33555109) or (self_PID == 33555103)) then begin \
                                                CompCreatMonic(33555097,self_tile) \
                                                CompCreatMonic(33555098,self_tile) \
                                                CompCreatMonic(33555099,self_tile) \
                                                end                             \
                                                if ((self_PID == 33555110) or (self_PID == 33555104)) then begin \
                                                CompCreatMonic(33555100,tile_num_in_direction(self_tile,1,1))    \
                                                CompCreatMonic(33555101,tile_num_in_direction(self_tile,1,1))    \
                                                CompCreatMonic(33555102,tile_num_in_direction(self_tile,1,1))    \
                                                end                             \
                                                if ((self_PID == 33555122) or (self_PID == 33555123)) then begin \
                                                CompCreatMonic(33555119,self_tile) \
                                                end                             \

#define CompCreatMonic(pid,tile)                if (tile_contains_obj_pid(tile, self_elevation, pid) == false) then begin \
                                                create_object_sid(pid,tile,self_elevation,-1); \
                                                end                             \

#define CompUsedLockpic                         if (objUsedPid == PID_TOOL_LOCKPICKS_EL) then begin \
                                                   script_overrides;            \
                                                   if (local_var(LVAR_Status) != 0) then begin \
                                                   g_display_mstr(552);         \
                                                   end                          \
                                                   else if (local_var(LVAR_SkillBonus) >= 100) then begin \
                                                   g_display_mstr(558);         \
                                                   end                          \
                                                   else if (combat_is_initialized == true) then begin \
                                                   g_display_mstr(551);         \
                                                   end                          \
                                                   else begin                   \
                                                   inc_local_var_amt(LVAR_SkillBonus,40); \
                                                   dude_floater_OK;             \
                                                   g_display_mstr(557);         \
                                                   item_remove(dude_obj, objUsedPid, 1) \
                                                   end                          \
                                                end                             \
                                                else CompUsedKey(PID_TEST,0)    \

#define CompUsedKey(pid,del)                    if (objUsedPid == pid) then begin \
                                                   script_overrides;            \
                                                   if (local_var(LVAR_Status) != 0) then begin \
                                                   g_display_mstr(552);         \
                                                   end                          \
                                                   else begin                   \
                                                   CompProcSienceOK             \
                                                   g_display_mstr(554);         \
                                                   end                          \
                                                   if (del>0) then begin        \
                                                   item_remove(dude_obj, objUsedPid, 1) \
                                                   end                          \
                                                end                             \

#define CompUsedRelict                    if (objUsedPid == PID_RELICT_GAMEDISK) then begin \
                                                   script_overrides;            \
                                                   if (combat_is_initialized == true) then begin \
                                                   g_display_mstr(551);         \
                                                   end                          \
                                                   else if (local_var(LVAR_Status) == 0) then begin \
                                                   g_display_mstr(550);         \
                                                   end                          \
                                                   else begin                   \
                                                   g_display_mstr(555);         \
                                                   PLAY_FADE                    \
                                                   game_time_advance(ONE_GAME_HOUR*12); \
                                                   skill_up(SKILL_GAMBLING,10); \
                                                   item_remove(dude_obj, objUsedPid, 1) \
                                                   end                          \
                                                end                             \

#define CompVarCheck(lvl)                       variable skillcheck;            \
                                                skillcheck := lvl;              \
                                                if (local_var(LVAR_SkillBonus) != 0) then begin \
                                                skillcheck -= local_var(LVAR_SkillBonus); \
                                                end                             \

#define CompSkillScience                        if (action_being_used == SKILL_SCIENCE) then begin \
                                                   script_overrides;            \
                                                   CompSkillScienceOptn         \
                                                end                             \

#define CompSkillScienceOptn                    if (local_var(LVAR_Status) != 0) then begin \
                                                g_display_mstr(552);            \
                                                end                             \
                                                else if (has_skill(source_obj, SKILL_SCIENCE) < skillcheck) then begin \
                                                g_skill_display_mstr(556,SKILL_SCIENCE,skillcheck) \
                                                end                             \
                                                else if (random(0,100)<(12-dude_luck)) then begin \
                                                critter_dmg(source_obj, random(1,5), DMG_electrical); \
                                                g_display_mstr(575);            \
                                                end                             \
                                                else begin                      \
                                                call sience_proc;               \
                                                end                             \

#endif
