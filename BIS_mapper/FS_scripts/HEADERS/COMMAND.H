#ifndef COMMAND_H
#define COMMAND_H

/***************************************************************
****************  Local Variable commands *********************
***************************************************************/

#define LVAR_Flags                      (0) // отвечает за враждебность к ГГ (у криттеров в бою движок ставит эту переменную на -3, поэтому её проще игнорировать)
#define LVAR_Self_Flags                 (1) // по аналогии с LVAR_Flags фиксирует разные параметры:
                                               /*
                                               bit_1  - фиксирует личную враждебность
                                               bit_2  - переключатель патрулирования двух точек
                                               bit_3  - фиксирует что персонаж видит ГГ
                                               bit_4  - фиксирует что персонаж на уровне 0 (см partyRunToDude)
                                               bit_5  - фиксирует что персонаж на уровне 1 (см partyRunToDude)
                                               bit_6  - фиксирует что персонаж на уровне 2 (см partyRunToDude)
                                               bit_7  - факт отравления ядом скорпиона
                                               bit_8  - разовое снижение Восприятия и Силы при уроне ЭМИ по силовой броне
                                               bit_9  - факт лечения травмы по миниквесту
                                               bit_10 - допуск к ограниченному товару торговцев
                                               bit_11 - допуск к эксклюзивному товару торговцев
                                               bit_12 - используется у гулей на Платформе для их подсчета
                                               */
#define LVAR_Home_Tile                  (2) // стартовый тайл
#define LVAR_Home_Rotat                 (3) // стартовый поворот
#define LVAR_Vakero_Status              (4) // переменная животных и мутантов для подсчета перка Вакеро
//! LVAR_Vakero_Status и LVAR_Dialog_Status совпадают, так как используются для криттеров разных типов, то есть не могут оказаться в одном скрипте
#define LVAR_Dialog_Status              (4) // битовые флажки диалога (bit_1 фиксирует первый диалог)
#define LVAR_Personal_Reaction_Bonus    (5) // поправка персонального отношения к ГГ (от -100 до 100)

#define LVAR_Barter_Timer               (6) // время следующего обновления товара
#define LVAR_Barter_Mod                 (7) // модификатор бартера: <0 - скидка, >0 - штраф

#define LVAR_Status                     (0) // состояние системы (только для объектов, не для криттеров)
#define LVAR_SkillBonus                 (1) // бонус к навыку при расчете требуемого уровня у объектов окружения

/***************************************************************
****************  Global Variable commands *********************
***************************************************************/

#define inc_global_var_amt(x,y)     set_global_var(x,global_var(x)+(y))
#define inc_global_var(x)           inc_global_var_amt(x,1)
#define dec_global_var_amt(x,y)     set_global_var(x,global_var(x)-(y))
#define dec_global_var(x)           dec_global_var_amt(x,1)

/***************************************************************
****************  map Variable commands ************************
***************************************************************/

#define inc_map_var_amt(x,y)        set_map_var(x,map_var(x)+y)
#define inc_map_var(x)              inc_map_var_amt(x,1)
#define dec_map_var_amt(x,y)        set_map_var(x,map_var(x)-y)
#define dec_map_var(x)              dec_map_var_amt(x,1)

/***************************************************************
****************  Local Variable commands **********************
***************************************************************/

#define inc_local_var_amt(x,y)      set_local_var(x,local_var(x)+y)
#define inc_local_var(x)            inc_local_var_amt(x,1)
#define dec_local_var_amt(x,y)      set_local_var(x,local_var(x)-y)
#define dec_local_var(x)            dec_local_var_amt(x,1)

/***************************************************************
**************** Bit Manipulation Macros ***********************
***************************************************************/

#define MAXINT                                        4294967295          //Max int
#define INV(x)                                        (MAXINT - x)        //An inverse function

// get bit state
#define gvar_bit(x, the_bit)                          ((global_var(x) bwand the_bit) != 0)
#define mvar_bit(x, the_bit)                          ((map_var(x) bwand the_bit) != 0)
#define lvar_bit(x, the_bit)                          ((local_var(x) bwand the_bit) != 0)

// switch bit on
#define set_gvar_bit_on(x, the_bit)                   set_global_var(x, global_var(x) bwor the_bit)
#define set_mvar_bit_on(x, the_bit)                   set_map_var(x, map_var(x) bwor the_bit)
#define set_lvar_bit_on(x, the_bit)                   set_local_var(x, local_var(x) bwor the_bit)

// switch bit off
#define set_gvar_bit_off(x, the_bit)                  set_global_var(x, global_var(x) bwand INV(the_bit))
#define set_mvar_bit_off(x, the_bit)                  set_map_var(x, map_var(x) bwand INV(the_bit))
#define set_lvar_bit_off(x, the_bit)                  set_local_var(x, local_var(x) bwand INV(the_bit))

/***************************************************************
**************** Макросы личного транспорта ********************
***************************************************************/

#define dude_has_car                                  global_var(GVAR_CAR_GOT_PLAYER)

/***************************************************************
******************** Фазы квестов ******************************
***************************************************************/

#define qStop                                        -1 //Провал квеста
#define qZero                                         0 //Обнуление квеста
#define qStart                                        1 //Начало квеста
#define qEnd                                          2 //Завершение квеста

#define setQuest(gvar,fasa)                           set_global_var(gvar,fasa)

#define getQuest(gvar)                                global_var(gvar)

/***************************************************************
******************** Старт диалогового окна    *****************
***************************************************************/

#define dialogue_system_forcing(distn)                if (combat_is_initialized == true) then begin \
                                                      end                                  \
                                                      else if (dude_elevation != self_elevation) then begin \
                                                      end                                  \
                                                      else if (self_visible == false) then begin \
                                                      end                                  \
                                                      else if self_enemy_dude then begin   \
                                                      end                                  \
                                                      else if (tile_distance_objs(self_obj, dude_obj) > distn) then begin \
                                                      end                                  \
                                                      else begin                           \
                                                      dialogue_system_enter;               \
                                                      end                                  \

#define StartDialog(node,crit,head,fon)               set_global_var(GVAR_RADIOACTIV_STOP,1); \
                                                      set_global_var(GVAR_RADIOACTIV_GLOBAL,0); \
                                                      set_global_var(GVAR_DIALOG_BIT_EXP,0); \
                                                      start_gdialog(NAME,crit,HEAD_REACTION_NEUTRAL,head,fon); \
                                                      gSay_Start;                          \
                                                           call node;                      \
                                                      gSay_End;                            \
                                                      end_dialogue;                        \
                                                      if (global_var(GVAR_DIALOG_BIT_EXP)>0) then begin \
                                                      exp_add_answr(global_var(GVAR_DIALOG_BIT_EXP)); \
                                                      end                                  \
                                                      set_global_var(GVAR_DIALOG_BIT_EXP,0); \
                                                      set_global_var(GVAR_PERSONAL_REACTION,0); \
                                                      set_global_var(GVAR_RADIOACTIV_STOP,0); \

#define dialog_proc_obj(node)                         if (combat_is_initialized == false) then begin \
                                                         StartDialog(node,dude_obj,-1,-1)  \
                                                      end                                  \
                                                      else begin                           \
                                                         g_display_mstr(328);              \
                                                      end                                  \

#define dialog_proc(wpn,arm,node,head,fon)            ScorpPoisonFlt                       \
                                                      else if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin        \
                                                         g_display_mstr(500);              \
                                                      end                                  \
                                                      else if ((arm>0) and (armor_pid_dude_var == PID_ARMOR_POWER_A)) then begin \
                                                         g_display_mstr(516);              \
                                                         if (arm == 1) then begin          \
                                                         g_floater(self_obj,517,COLOR_MSG_RED); \
                                                         end else begin                    \
                                                         floater(self_obj,arm,COLOR_MSG_RED); \
                                                         end                               \
                                                      end                                  \
                                                      else if ((arm>0) and (armor_pid_dude_var == PID_ARMOR_POWER_B)) then begin \
                                                         g_display_mstr(516);              \
                                                         if (arm == 1) then begin          \
                                                         g_floater(self_obj,517,COLOR_MSG_RED); \
                                                         end else begin                    \
                                                         floater(self_obj,arm,COLOR_MSG_RED); \
                                                         end                               \
                                                      end                                  \
                                                      else if ((arm>0) and (armor_pid_dude_var == PID_ARMOR_POWER_C)) then begin \
                                                         g_display_mstr(516);              \
                                                         if (arm == 1) then begin          \
                                                         g_floater(self_obj,517,COLOR_MSG_RED); \
                                                         end else begin                    \
                                                         floater(self_obj,arm,COLOR_MSG_RED); \
                                                         end                               \
                                                      end                                  \
                                                      else if ((wpn>0) and weapon_invn_dude and (getReaction<90)) then begin \
                                                         if (wpn >= 100) then begin          \
                                                         floater(self_obj,wpn,COLOR_MSG_RED); \
                                                         end                               \
                                                         else begin                        \
                                                         if (KILL_SLAVA > 0) then begin    \
                                                         g_floater(self_obj,515,COLOR_MSG_RED); \
                                                         end else begin                    \
                                                         g_floater(self_obj,514,COLOR_MSG_RED); \
                                                         end                               \
                                                         end                               \
                                                         g_display_mstr(506);              \
                                                      end                                  \
                                                      else begin                           \
                                                         anim(self_obj, ANIMATE_ROTATION, rotation_to_tile(self_tile, dude_tile)); \
                                                         anim(dude_obj, ANIMATE_ROTATION, rotation_to_tile(dude_tile, self_tile)); \
                                                         StartDialog(node,self_obj,head,fon) \
                                                      end                                  \

#define dialog_proc_barter(wpn,arm,node,head,fon)     ScorpPoisonFlt                       \
                                                      else if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin        \
                                                         g_display_mstr(500);              \
                                                      end                                  \
                                                      else if ((arm>0) and (armor_pid_dude_var == PID_ARMOR_POWER_A)) then begin \
                                                         g_display_mstr(516);              \
                                                         if (arm == 1) then begin          \
                                                         g_floater(self_obj,517,COLOR_MSG_RED); \
                                                         end else begin                    \
                                                         floater(self_obj,arm,COLOR_MSG_RED); \
                                                         end                               \
                                                      end                                  \
                                                      else if ((arm>0) and (armor_pid_dude_var == PID_ARMOR_POWER_B)) then begin \
                                                         g_display_mstr(516);              \
                                                         if (arm == 1) then begin          \
                                                         g_floater(self_obj,517,COLOR_MSG_RED); \
                                                         end else begin                    \
                                                         floater(self_obj,arm,COLOR_MSG_RED); \
                                                         end                               \
                                                      end                                  \
                                                      else if ((arm>0) and (armor_pid_dude_var == PID_ARMOR_POWER_C)) then begin \
                                                         g_display_mstr(516);              \
                                                         if (arm == 1) then begin          \
                                                         g_floater(self_obj,517,COLOR_MSG_RED); \
                                                         end else begin                    \
                                                         floater(self_obj,arm,COLOR_MSG_RED); \
                                                         end                               \
                                                      end                                  \
                                                      else if ((wpn>0) and weapon_invn_dude and (getReaction<90)) then begin \
                                                         if (wpn >= 100) then begin          \
                                                         floater(self_obj,wpn,COLOR_MSG_RED); \
                                                         end                               \
                                                         else begin                        \
                                                         if (KILL_SLAVA > 0) then begin    \
                                                         g_floater(self_obj,515,COLOR_MSG_RED); \
                                                         end else begin                    \
                                                         g_floater(self_obj,514,COLOR_MSG_RED); \
                                                         end                               \
                                                         end                               \
                                                         g_display_mstr(506);              \
                                                      end                                  \
                                                      else begin                           \
                                                         if (BOX_TILE>0) then begin        \
                                                         inven_unwield(self_obj);          \
                                                         move_obj_inven_to_obj(selfBarterBoxObj,self_obj); \
                                                         end                               \
                                                         setBarterMod;                     \
                                                         anim(self_obj, ANIMATE_ROTATION, rotation_to_tile(self_tile, dude_tile)); \
                                                         anim(dude_obj, ANIMATE_ROTATION, rotation_to_tile(dude_tile, self_tile)); \
                                                         StartDialog(node,self_obj,head,fon) \
                                                         if ((BOX_TILE>0) and (has_skill(dude_obj, SKILL_STEAL)<FLAG_STEAL)) then begin   \
                                                         move_obj_inven_to_obj(self_obj,selfBarterBoxObj); \
                                                         end                               \
                                                      end                                  \

#define setNodeCombat                                 set_enemy_dude;                      \
                                                      g_display_mstr(509)                  \

/* Диалог - стандарт */

#define Reply(msg)                                    gSay_Reply(NAME,msg);                \

#define Answer(msg,intl,node,react)                   giQ_Option(intl,NAME,msg,node,react); \

#define NAnswer(msg,intl,node)                        Answer(msg,intl,node,HEAD_REACTION_NEUTRAL) \

#define GAnswer(msg,intl,node)                        Answer(msg,intl,node,HEAD_REACTION_GOOD) \

#define BAnswer(msg,intl,node)                        Answer(msg,intl,node,HEAD_REACTION_BAD) \

/* Диалог - гендер */

#define zReply(msg)                                   if dude_is_female then begin         \
                                                      Reply(msg+1000)                      \
                                                      end else begin                       \
                                                      Reply(msg)                           \
                                                      end                                  \

#define zAnswer(msg,intl,node,react)                  if dude_is_female then begin         \
                                                      Answer(msg+1000,intl,node,react)     \
                                                      end else begin                       \
                                                      Answer(msg,intl,node,react)          \
                                                      end                                  \

#define zNAnswer(msg,intl,node)                      zAnswer(msg,intl,node,HEAD_REACTION_NEUTRAL) \

#define zGAnswer(msg,intl,node)                      zAnswer(msg,intl,node,HEAD_REACTION_GOOD) \

#define zBAnswer(msg,intl,node)                      zAnswer(msg,intl,node,HEAD_REACTION_BAD) \

/* Диалог - подсказка */

/*
#define xAnswer(msg,intl,node,react)                  if DudePerkHas(PERK_hint_look) then begin \
                                                      Answer(mstr(msg+5000)+" "+mstr(msg),intl,node,react) \
                                                      end else begin                       \
                                                      Answer(msg,intl,node,react)          \
                                                      end                                  \

#define xGAnswer(msg,intl,node)                      xAnswer(msg,intl,node,HEAD_REACTION_GOOD) \

#define xBAnswer(msg,intl,node)                      xAnswer(msg,intl,node,HEAD_REACTION_BAD) \

#define xNAnswer(msg,intl,node)                      xAnswer(msg,intl,node,HEAD_REACTION_NEUTRAL) \
*/

/* Диалог - проверка навыка */

#define skillAnswer(msg,intl,node,react,skill,x)      if DudePerkHas(PERK_hint_look) then begin \
                                                      Answer(g_mstr(133)+g_mstr(110+skill)+" "+x+g_mstr(134)+mstr(msg),intl,node,react) \
                                                      end else begin                       \
                                                      Answer(msg,intl,node,react)          \
                                                      end                                  \

#define NAnswerSkill(msg1,intl,node1,skill,x,msg2,node2) if dude_skill(skill,x) then begin \
                                                      skillAnswer(msg1,intl,node1,HEAD_REACTION_NEUTRAL,skill,x) \
                                                      end else begin                       \
                                                      skillAnswer(msg2,intl,node2,HEAD_REACTION_NEUTRAL,skill,x) \
                                                      end                                  \

#define GAnswerSkill(msg1,intl,node1,skill,x,msg2,node2) if dude_skill(skill,x) then begin \
                                                      skillAnswer(msg1,intl,node1,HEAD_REACTION_GOOD,skill,x) \
                                                      end else begin                       \
                                                      skillAnswer(msg2,intl,node2,HEAD_REACTION_GOOD,skill,x) \
                                                      end                                  \

#define BAnswerSkill(msg1,intl,node1,skill,x,msg2,node2) if dude_skill(skill,x) then begin \
                                                      skillAnswer(msg1,intl,node1,HEAD_REACTION_BAD,skill,x) \
                                                      end else begin                       \
                                                      skillAnswer(msg2,intl,node2,HEAD_REACTION_BAD,skill,x) \
                                                      end                                  \

/* Диалог - проверка характеристики ГГ */

#define statAnswer(msg,intl,node,react,stat,x)        if DudePerkHas(PERK_hint_look) then begin \
                                                      Answer(g_mstr(133)+g_mstr(150+stat)+" "+x+g_mstr(134)+mstr(msg),intl,node,react) \
                                                      end else begin                       \
                                                      Answer(msg,intl,node,react)          \
                                                      end                                  \

#define NAnswerStat(msg1,intl,node1,stat,x,msg2,node2) if (get_critter_stat(dude_obj,stat) >= x) then begin \
                                                      statAnswer(msg1,intl,node1,HEAD_REACTION_NEUTRAL,stat,x)  \
                                                      end else begin                       \
                                                      statAnswer(msg2,intl,node2,HEAD_REACTION_NEUTRAL,stat,x)  \
                                                      end                                  \

/* Диалог - проверка Отношения к ГГ */

#define reactionAnswer(msg,intl,node,react,x)         if DudePerkHas(PERK_hint_look) then begin \
                                                      Answer(g_mstr(133)+g_mstr(135)+g_mstr(134)+mstr(msg),intl,node,react) \
                                                      end else begin                       \
                                                      Answer(msg,intl,node,react)          \
                                                      end                                  \

#define NAnswerReaction(msg1,intl,node1,x,msg2,node2) if (getReaction >= x) then begin     \
                                                      reactionAnswer(msg1,intl,node1,HEAD_REACTION_NEUTRAL,x)  \
                                                      end else begin                       \
                                                      reactionAnswer(msg2,intl,node2,HEAD_REACTION_NEUTRAL,x)  \
                                                      end                                  \

/* Диалог - проверка местной репутации */

#define repAnswer(msg,intl,node,react,x)              if DudePerkHas(PERK_hint_look) then begin \
                                                      Answer(g_mstr(133)+g_mstr(136)+g_mstr(134)+mstr(msg),intl,node,react) \
                                                      end else begin                       \
                                                      Answer(msg,intl,node,react)          \
                                                      end                                  \

#define NAnswerRep(msg1,intl,node1,x,msg2,node2)      if (get_REP >= x) then begin         \
                                                      repAnswer(msg1,intl,node1,HEAD_REACTION_NEUTRAL,x)  \
                                                      end else begin                       \
                                                      repAnswer(msg2,intl,node2,HEAD_REACTION_NEUTRAL,x)  \
                                                      end                                  \

/* Диалог - проверка Славы (кармы) */

#define slavaAnswer(msg,intl,node,react,x)            if DudePerkHas(PERK_hint_look) then begin \
                                                      Answer(g_mstr(133)+g_mstr(137)+g_mstr(134)+mstr(msg),intl,node,react) \
                                                      end else begin                       \
                                                      Answer(msg,intl,node,react)          \
                                                      end                                  \

#define NAnswerSlava(msg1,intl,node1,x,msg2,node2)    if (get_SLAVA >= x) then begin       \
                                                      slavaAnswer(msg1,intl,node1,HEAD_REACTION_NEUTRAL,x)  \
                                                      end else begin                       \
                                                      slavaAnswer(msg2,intl,node2,HEAD_REACTION_NEUTRAL,x)  \
                                                      end                                  \

/* Диалог - проверка Уровня ГГ */

#define levelDudeAnswer(msg,intl,node,react,x)        if DudePerkHas(PERK_hint_look) then begin \
                                                      Answer(g_mstr(133)+g_mstr(138)+g_mstr(134)+mstr(msg),intl,node,react) \
                                                      end else begin                       \
                                                      Answer(msg,intl,node,react)          \
                                                      end                                  \

#define NAnswerLevel(msg1,intl,node1,x,msg2,node2)    if (dude_level >= x) then begin      \
                                                      levelDudeAnswer(msg1,intl,node1,HEAD_REACTION_NEUTRAL,x)  \
                                                      end else begin                       \
                                                      levelDudeAnswer(msg2,intl,node2,HEAD_REACTION_NEUTRAL,x)  \
                                                      end                                  \

/* Диалог - опыт за ведение диалога */

#define bitDialogExp(bit,exp)                         if (lvar_bit(LVAR_Dialog_Status, bit) == 0) then begin \
                                                          if (exp != 0) then begin                           \
                                                          inc_global_var_amt(GVAR_DIALOG_BIT_EXP,exp);       \
                                                          end                                                \
                                                          bitDialogInc(bit)          \
                                                      end                                                    \

#define bitDialog(bit)                                lvar_bit(LVAR_Dialog_Status, bit) \

#define bitDialogZero(bit)                            set_lvar_bit_off(LVAR_Dialog_Status, bit); \

#define bitDialogInc(bit)                             set_lvar_bit_on(LVAR_Dialog_Status, bit); \

/***************************************************************
******************** Получение травм при атаке *****************
***************************************************************/

#define dam_to_dude_LEG                               if (random(0,1) == 0) then begin \
                                                      critter_injure(dude_obj, DAM_CRIP_LEG_LEFT); \
                                                      g_display_mstr(300);             \
                                                      end else begin                   \
                                                      critter_injure(dude_obj, DAM_CRIP_LEG_RIGHT); \
                                                      g_display_mstr(301);             \
                                                      end                              \
                                                      float_msg(dude_obj, g_mstr(305), COLOR_MSG_RED); \

#define dam_to_dude_ARM                               if (random(0,1) == 0) then begin \
                                                      critter_injure(dude_obj, DAM_CRIP_ARM_LEFT); \
                                                      g_display_mstr(302);             \
                                                      end else begin                   \
                                                      critter_injure(dude_obj, DAM_CRIP_ARM_RIGHT); \
                                                      g_display_mstr(303);             \
                                                      end                              \
                                                      float_msg(dude_obj, g_mstr(305), COLOR_MSG_RED); \

#define dam_to_dude_BLIND                             critter_injure(dude_obj, DAM_BLIND); \
                                                      g_display_mstr(304);             \
                                                      float_msg(dude_obj, g_mstr(305), COLOR_MSG_RED); \

#define critter_uninjure_full(who)                    critter_uninjure(who, (DAM_BLIND bwor DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT)) \

#endif
