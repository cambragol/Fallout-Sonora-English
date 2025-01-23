#ifndef COMPUTER_H
#define COMPUTER_H

#define RepairProcUsing(a,b)                    script_overrides;               \
                                                if (local_var(LVAR_Status) == 0) then begin \
                                                display_mstr(a);                \
                                                end else begin                  \
                                                display_mstr(b);                \
                                                end                             \

#define RepairUsedJunk(pid,bonus)               if (objUsedPid == pid) then begin \
                                                   script_overrides;            \
                                                   if (local_var(LVAR_Status) != 0) then begin \
                                                   display_msg(self_name+g_mstr(570)); \
                                                   end                          \
                                                   else if (combat_is_initialized == true) then begin \
                                                   g_display_mstr(571);         \
                                                   end                          \
                                                   else if ((SKILL_LIMIT-local_var(LVAR_SkillBonus)) <= -15) then begin \
                                                   g_display_mstr(578);         \
                                                   end                          \
                                                   else begin                   \
                                                   inc_local_var_amt(LVAR_SkillBonus,bonus); \
                                                   dude_floater_OK;             \
                                                   if (bonus > 20) then begin   \
                                                   g_display_mstr(577);         \
                                                   end else begin               \
                                                   g_display_mstr(576);         \
                                                   end                          \
                                                   play_sfx("WOR1XXX1");        \
                                                   item_remove(dude_obj, objUsedPid, 1) \
                                                   end                          \
                                                end                             \

#define RepairVarCheck                          variable skillcheck;            \
                                                skillcheck := SKILL_LIMIT;      \
                                                if (global_var(GVAR_GARAGE_EUGENE_STATUS) == 1) then begin \
                                                skillcheck -= 20;               \
                                                end                             \
                                                if (local_var(LVAR_SkillBonus) != 0) then begin \
                                                skillcheck -= local_var(LVAR_SkillBonus); \
                                                end                             \

#define RepairSkillRepair                       if (action_being_used == SKILL_REPAIR) then begin \
                                                   script_overrides;            \
                                                   RepairSkillRepairOptn(573)   \
                                                end                             \
                                                if (action_being_used == SKILL_SCIENCE) then begin \
                                                   script_overrides;            \
                                                   call use_p_proc;             \
                                                end                             \

#define RepairSkillRepairB                      if (action_being_used == SKILL_REPAIR) then begin \
                                                   script_overrides;            \
                                                   RepairSkillRepairOptn(574)   \
                                                end                             \
                                                if (action_being_used == SKILL_SCIENCE) then begin \
                                                   script_overrides;            \
                                                   call use_p_proc;             \
                                                end                             \

#define RepairSkillRepairOptn(num)              if (local_var(LVAR_Status) != 0) then begin \
                                                display_msg(self_name+g_mstr(570)); \
                                                end                             \
                                                else if (has_skill(source_obj, SKILL_REPAIR) < skillcheck) then begin \
                                                g_skill_display_mstr(num,SKILL_REPAIR,skillcheck) \
                                                end                             \
                                                else begin                      \
                                                call repair_proc;               \
                                                end                             \

#define RepairProcRepair(msg,exp,sfx)           set_local_var(LVAR_Status,1);   \
                                                play_sfx(sfx);                  \
                                                if (exp >0) then begin          \
                                                exp_add(exp);                   \
                                                end                             \
                                                dude_floater_OK;                \
                                                if (msg>0) then begin           \
                                                display_mstr(msg);              \
                                                end                             \

#define RepairProcUsingMexTorpedos              if (objUsedPid == PID_MEX_TORPEDOS) then begin \
                                                script_overrides; \
                                                item_add(dude_obj,PID_AMMO_SIGNAL_A,20) \
                                                item_remove(dude_obj, objUsedPid, 1) \
                                                play_sfx("TANKS"); \
                                                dude_floater_OK; \
                                                g_display_mstr(435); \
                                                end \

#endif
