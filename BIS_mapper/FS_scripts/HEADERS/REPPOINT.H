#ifndef REPPOINT_H
#define REPPOINT_H

/*****************************************************************
**************    СЛАВА ПЕРСОНАЖА В ПУСТОШАХ   *******************
******************************************************************/

#define get_SLAVA                               (global_var(GVAR_REPUTATION_PLAYER))   \

#define set_SLAVA(x)                            if (x>0) then begin                                                           \
                                                   if DudePerkHas(PERK_karma_hollywood) then begin                            \
                                                   set_global_var(GVAR_REPUTATION_GOOD,global_var(GVAR_REPUTATION_GOOD)+(x*2)); \
                                                   end else begin                                                             \
                                                   set_global_var(GVAR_REPUTATION_GOOD,global_var(GVAR_REPUTATION_GOOD)+(x)); \
                                                   end                                                                        \
                                                   debug_msg(message_str(SCRIPT_OBJ_DUDE, 200));                              \
                                                end                                                                           \
                                                if (x<0) then begin                                                           \
                                                   if DudePerkHas(PERK_karma_hollywood) then begin                            \
                                                   set_global_var(GVAR_REPUTATION_BAD,global_var(GVAR_REPUTATION_BAD)+(x*2)); \
                                                   end else begin                                                             \
                                                   set_global_var(GVAR_REPUTATION_BAD,global_var(GVAR_REPUTATION_BAD)+(x));   \
                                                   end                                                                        \
                                                   debug_msg(message_str(SCRIPT_OBJ_DUDE, 201));                              \
                                                end                                                                           \
                                                if (x!=0) then begin                                                          \
                                                   set_global_var(GVAR_REPUTATION_PLAYER,(global_var(GVAR_REPUTATION_GOOD))+(global_var(GVAR_REPUTATION_BAD))); \
                                                end                                                                           \
                                                if (get_SLAVA <= -500) then begin                                             \
                                                   dont_rep_Ranger                                                            \
                                                end                                                                           \

#define SLAVA_KILL_GOOD                         -5
#define SLAVA_KILL_NEITRAL                      0
#define SLAVA_KILL_BAD                          5
#define SLAVA_KILL_CHILD                        SLAVA_KILL_GOOD*10
#define SLAVA_KILL_GHOUL                        2
#define SLAVA_KILL_DWCLW                        SLAVA_KILL_BAD*2

/*****************************************************************
****************     Репутация в поселениях     ******************
******************************************************************/

//репутация в городах
#define town_rep_is_idolized                    (get_REP >= 30)
#define town_rep_is_liked                       (get_REP >= 15)
#define town_rep_is_accepted                    (get_REP >= 1)
#define town_rep_is_like(x)                     (get_REP >= x)
#define town_rep_is_neutral                     (get_REP == 0)
#define town_rep_is_anti(x)                     (get_REP <= x)
#define town_rep_is_antipaty                    (get_REP <= -1)
#define town_rep_is_hated                       (get_REP <= -15)
#define town_rep_is_vilified                    (get_REP <= -30)
#define town_rep_is_critical                    (get_REP <= -100)

#define get_REP                                 (global_var(TOWN_REP_VAR))    \

#define set_REP(rep)                            set_CITY_REP(TOWN_REP_VAR,rep) \

#define set_CITY_REP(gvar,rep)                  if ((rep!=0) and (gvar>0)) then begin    \
                                                   inc_global_var_amt(gvar,rep);         \
                                                   if (global_var(gvar)<-100) then begin \
                                                   set_global_var(gvar,-100);            \
                                                   end                                   \
                                                   if (global_var(gvar)>100) then begin  \
                                                   set_global_var(gvar,100);             \
                                                   end                                   \
                                                end                                      \

#define REP_KILL_GOOD                           -3
#define REP_KILL_NEITRAL                        0
#define REP_KILL_BAD                            3
#define REP_KILL_CHILD                          REP_KILL_GOOD*10
#define REP_KILL_CRITICAL                       -100

//репутация и слава при убийстве нпс
#define kill_critter_reput                      if (source_obj == dude_obj) then begin       \
                                                   if (KILL_TOWN_REP!=0) then begin          \
                                                   set_REP(KILL_TOWN_REP)                    \
                                                   end                                       \
                                                   if (KILL_SLAVA!=0) then begin             \
                                                   set_SLAVA(KILL_SLAVA)                     \
                                                   end                                       \
                                                   kill_critter_titul                        \
                                                   kill_critter_dont_rep                     \
                                                end                                          \

#define kill_critter_reput_norep                if (source_obj == dude_obj) then begin       \
                                                   kill_critter_titul                        \
                                                end                                          \

#define kill_critter_titul                      if type_kill(KILL_TYPE_children) then begin     \
                                                   inc_global_var(GVAR_REPUTATION_CHILDKILLER); \
                                                end                                             \
                                                else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women)) then begin \
                                                   inc_global_var(GVAR_REPUTATION_KILLER_CK);   \
                                                end                                             \
                                                else if (type_kill(KILL_TYPE_brahmin) or type_kill(KILL_TYPE_rat) or type_kill(KILL_TYPE_dog) or type_kill(KILL_TYPE_giant_ant) or type_kill(KILL_TYPE_radscorpion) or type_kill(KILL_TYPE_scolopendra) or type_kill(KILL_TYPE_manti)) then begin \
                                                   inc_global_var(GVAR_REPUTATION_HUNTER_CK);   \
                                                end                                             \
                                                else if (type_kill(KILL_TYPE_super_mutant) or type_kill(KILL_TYPE_ghoul) or type_kill(KILL_TYPE_floater) or type_kill(KILL_TYPE_centaur) or type_kill(KILL_TYPE_deathclaw) or type_kill(KILL_TYPE_plant) or type_kill(KILL_TYPE_alien)) then begin \
                                                   inc_global_var(GVAR_REPUTATION_MUTAKILLER_CK); \
                                                end                                             \
                                                if (dude_level>=3) then begin                   \
                                                   if (global_var(GVAR_REPUTATION_KILLER_CK)>=20) then begin \
                                                   set_global_var(GVAR_REPUTATION_KILLER,1);    \
                                                   end                                          \
                                                   if (global_var(GVAR_REPUTATION_HUNTER_CK)>=50) then begin \
                                                   set_global_var(GVAR_REPUTATION_HUNTER,1);    \
                                                   end                                          \
                                                   if (global_var(GVAR_REPUTATION_MUTAKILLER_CK)>=15) then begin \
                                                   set_global_var(GVAR_REPUTATION_MUTAKILLER,1); \
                                                   end                                          \
                                                end                                             \

//убийственные статусы
#define has_rep_childkiller                     (global_var(GVAR_REPUTATION_CHILDKILLER) >1)

#define has_rep_killer                          (global_var(GVAR_REPUTATION_KILLER) >0)

#define has_rep_hunter                          (global_var(GVAR_REPUTATION_HUNTER) >0)

#define has_rep_mutakiller                      (global_var(GVAR_REPUTATION_MUTAKILLER) >0)

#define has_rep_pelgrim                         (global_var(GVAR_REPUTATION_PELGRIM) >0)

//принадлежность криттера к фракции (задается в KILL_FRAC_REP)
#define FRAC_NON                                -1
#define FRAC_BOS                                GVAR_TITUL_BOS
#define FRAC_RANGER                             GVAR_TITUL_ARIZONA_RANGER
#define FRAC_WARROAD                            GVAR_TITUL_WARRIOR_ROAD
#define FRAC_PNXCULT                            GVAR_TITUL_PHENIX_CULT
#define FRAC_CASINO                             GVAR_TITUL_PHENIX_CASINO

#define kill_critter_dont_rep                   if (KILL_FRAC_REP == FRAC_BOS) then begin    \
                                                dont_rep_BoS                                 \
                                                end                                          \
                                                else if (KILL_FRAC_REP == FRAC_RANGER) then begin  \
                                                dont_rep_Ranger                              \
                                                end                                          \
                                                else if (KILL_FRAC_REP == FRAC_WARROAD) then begin \
                                                dont_rep_WarRoad                             \
                                                end                                          \
                                                else if (KILL_FRAC_REP == FRAC_PNXCULT) then begin \
                                                dont_rep_PnxCult                             \
                                                end                                          \

//удаление фракционных званий
#define dont_rep_BoS                            if ((global_var(GVAR_TITUL_BOS) >0) or (global_var(GVAR_TITUL_BOS_SCRIBE) >0) or (global_var(GVAR_TITUL_BOS_CAVALER) >0) or (global_var(GVAR_TITUL_BOS_PALADIN) >0) or (global_var(GVAR_TITUL_BOS_SCOUT) >0)) then begin \
                                                   set_global_var(GVAR_TITUL_BOS_TRAITOR,1); \
                                                   set_global_var(GVAR_TITUL_BOS,0);         \
                                                   set_global_var(GVAR_TITUL_BOS_SCRIBE,0);  \
                                                   set_global_var(GVAR_TITUL_BOS_CAVALER,0); \
                                                   set_global_var(GVAR_TITUL_BOS_PALADIN,0); \
                                                   set_global_var(GVAR_TITUL_BOS_SCOUT,0);   \
                                                   play_sfx("IISXXXX1");                     \
                                                   display_msg(message_str(SCRIPT_OBJ_DUDE, 208)); \
                                                end                                          \

#define dont_rep_Ranger                         if (global_var(GVAR_TITUL_ARIZONA_RANGER) >0) then begin \
                                                   set_global_var(GVAR_TITUL_ARIZONA_RANGER,0);  \
                                                   play_sfx("IISXXXX1");                     \
                                                   display_msg(message_str(SCRIPT_OBJ_DUDE, 209)); \
                                                end                                          \

#define dont_rep_WarRoad                        if (global_var(GVAR_TITUL_WARRIOR_ROAD) >0) then begin \
                                                   set_global_var(GVAR_TITUL_WARRIOR_ROAD,0);    \
                                                   play_sfx("IISXXXX1");                     \
                                                   display_msg(message_str(SCRIPT_OBJ_DUDE, 210)); \
                                                end                                          \

#define dont_rep_PnxCult                        if (global_var(GVAR_TITUL_PHENIX_CULT) >0) then begin \
                                                   set_global_var(GVAR_TITUL_PHENIX_CULT,0); \
                                                   play_sfx("IISXXXX1");                     \
                                                   display_msg(message_str(SCRIPT_OBJ_DUDE, 211)); \
                                                end                                          \

#endif
