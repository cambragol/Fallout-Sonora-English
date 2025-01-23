#ifndef CRITTERS_H
#define CRITTERS_H

// -----------------------------------------------------------------------
// map_enter_p_proc
// -----------------------------------------------------------------------

#define set_start_home                       if (map_first_run == true) then begin                 \
                                             set_local_var(LVAR_Home_Tile,self_tile);              \
                                             set_local_var(LVAR_Home_Rotat,self_cur_rot);          \
                                             end                                                   \
                                             if ((self_TEAM != TEAM_PLAYER) or (map_first_run == true)) then begin \
                                             if (NUM_TEAM>=0) then begin                           \
                                             critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,NUM_TEAM); \
                                             end                                                   \
                                             end                                                   \
                                             if ((NUM_AI>0) and (self_TEAM != TEAM_PLAYER) and (partyPidSelf<=0)) then begin \
                                             critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_AI_PACKET,NUM_AI); \
                                             end                                                   \
                                             if ((HomeTile>0) and (self_TEAM != TEAM_PLAYER)) then begin \
                                             move_to(self_obj, HomeTile, self_elevation);          \
                                             anim(self_obj, ANIMATE_ROTATION, HomeRotat);          \
                                             end                                                   \
                                             if (self_cur_hits < self_max_hits) then begin         \
                                                if type_kill(KILL_TYPE_ghoul) then begin           \
                                                critter_heal(self_obj, 10);                        \
                                                end else begin                                     \
                                                critter_heal(self_obj, 2);                         \
                                                end                                                \
                                             end                                                   \
                                             set_lvar_bit_off(LVAR_Self_Flags, bit_7);             \
                                             if (critter_is_fleeing(self_obj) != 0) then begin     \
                                             critter_set_flee_state(self_obj, 0);                  \
                                             end                                                   \
                                             if (self_TEAM != TEAM_PLAYER) then begin              \
                                             add_timer_event(self_obj, random(10,30), 1);          \
                                             add_timer_event(self_obj, random(30,120), 2);         \
                                             end                                                   \

// -----------------------------------------------------------------------
// торговые операции
// -----------------------------------------------------------------------

#define selfBarterBoxObj                     tile_contains_pid_obj(BOX_TILE,0,PID_CNTR_BARTER_BOX) \

#define selfBarterBoxGener                   if (selfBarterBoxObj <= 0) then begin                       \
                                             create_object_sid(PID_CNTR_BARTER_BOX, BOX_TILE, 0, -1);    \
                                             end                                                         \

#define set_BarterBoxProc(time)              selfBarterBoxGener                                \
                                             move_obj_inven_to_obj(selfBarterBoxObj,self_obj); \
                                             inven_unwield(self_obj);                          \
                                             if (local_var(LVAR_Barter_Timer) < game_time) then begin \
                                                  call setBarterA;                             \
                                                  if (get_BarterDopusk != 0) then begin        \
                                                  call setBarterB;                             \
                                                  end                                          \
                                                  set_local_var(LVAR_Barter_Timer, time + game_time); \
                                             end                                               \
                                             if ((BOX_TILE>0) and (has_skill(dude_obj, SKILL_STEAL)<FLAG_STEAL)) then begin   \
                                             move_obj_inven_to_obj(self_obj,selfBarterBoxObj); \
                                             end

#define set_BarterDopusk                     set_lvar_bit_on(LVAR_Self_Flags, bit_10) \

#define set_BarterDopusk_B                   set_lvar_bit_on(LVAR_Self_Flags, bit_11) \

#define get_BarterDopusk                     lvar_bit(LVAR_Self_Flags, bit_10) \

#define get_BarterDopusk_B                   lvar_bit(LVAR_Self_Flags, bit_11) \

// -----------------------------------------------------------------------
// блуждание по локации
// -----------------------------------------------------------------------

//патрулирование между двумя точками:
#define timer_float_reply(a,b)               timer_floater(a,b,COLOR_MSG_NORMAL,random(70,320))    \

#define timer_floater(a,b,color,time)        if (combat_is_initialized == false) then begin        \
                                                 if (self_elevation == dude_elevation) then begin  \
                                                     if (self_visible == true) then begin          \
                                                     if ((a>0) and (b>0)) then begin               \
                                                     floater(self_obj, random(a,b), color);        \
                                                     end                                           \
                                                     end                                           \
                                                 end                                               \
                                                 add_timer_event(self_obj, time, 2);               \
                                             end else begin                                        \
                                                 add_timer_event(self_obj, 20, 2);                 \
                                             end                                                   \

#define timer_move_patrol_next(tileNext)     if (tile_distance(self_tile, tileNext) > 1) then begin \
                                                 if (anim_busy(self_obj) == false) then begin      \
                                                 animate_move_to_tile(tileNext);                   \
                                                 end                                               \
                                             end                                                   \
                                             else begin                                            \
                                                 if (lvar_bit(LVAR_Self_Flags, bit_2) == 0) then begin \
                                                 set_lvar_bit_on(LVAR_Self_Flags, bit_2);          \
                                                 end                                               \
                                                 else begin                                        \
                                                 set_lvar_bit_off(LVAR_Self_Flags, bit_2);         \
                                                 end                                               \
                                             end                                                   \

//патрулирование между двумя точками:
#define timer_move_patrol(tileA,tileB)       if (combat_is_initialized == false) then begin        \
                                                 if (lvar_bit(LVAR_Self_Flags, bit_2) == 0) then begin \
                                                 timer_move_patrol_next(tileA)                     \
                                                 end else begin                                    \
                                                 timer_move_patrol_next(tileB)                     \
                                                 end                                               \
                                             end                                                   \
                                             add_timer_event(self_obj, random(30,50), 1);          \

//персонаж всегда возвращается в заданную позицию:
#define move_to_tile(param,tile,rotat)       if (combat_is_initialized == false) then begin        \
                                                 if (self_visible == false) then begin             \
                                                 end                                               \
                                                 else if (self_elevation != dude_elevation) then begin \
                                                 end                                               \
                                                 else if ((anim_busy(self_obj) == false) and ((critter_state(self_obj) bwand DAM_KNOCKED_OUT) == FALSE)) then begin \
                                                    if (tile > 0) then begin                       \
                                                        if (self_tile != tile) then begin          \
                                                           if (param == 0) then begin              \
                                                           animate_move_to_tile(tile);             \
                                                           end else begin                          \
                                                           animate_run_to_tile(tile);              \
                                                           end                                     \
                                                        end else begin                             \
                                                           if (rotat>=0) then begin                \
                                                           anim(self_obj, ANIMATE_ROTATION, rotat); \
                                                           end                                     \
                                                        end                                        \
                                                    end                                            \
                                                    else if (tile == 0) then begin                 \
                                                        animate_run_to_tile(tile_num_in_direction(self_tile, random(0,5), random(1,2))); \
                                                    end                                            \
                                                 end                                               \
                                             end                                                   \

#define timer_move_to_tile(param,tile,rotat) move_to_tile(param,tile,rotat)                        \
                                             add_timer_event(self_obj, random(40,80), 1);          \

#define timer_move_to_home                   timer_move_to_tile(0,HomeTile,HomeRotat)

#define timer_run_to_home                    timer_move_to_tile(1,HomeTile,HomeRotat)

#define timer_run_random_tile(tile,dst)      timer_move_to_tile(1,tile_num_in_direction(tile,random(0,5),random(1,dst)),random(0,5))

//персонаж перемещается по рэндому:
#define timer_move_random                    timer_move_to_tile(0,tile_num_in_direction(self_tile, random(0,5), random(1,5)),random(0,5))

#define timer_move_random_home(dist)         timer_move_to_tile(0,tile_num_in_direction(HomeTile, random(0,5), random(1,dist)),random(0,5))

#define timer_move_random_tile(tile,dst)     timer_move_to_tile(0,tile_num_in_direction(tile,random(0,5),random(1,dst)),random(0,5))

//персонаж бегает по рэндому:
#define timer_run_random                     timer_move_to_tile(1,tile_num_in_direction(self_tile, random(0,5), random(1,5)),random(0,5))

#define timer_run_random_home(dist)          timer_move_to_tile(1,tile_num_in_direction(HomeTile, random(0,5), random(1,dist)),random(0,5))

//Опция толкания персонажа:
//   Можно толкать всегда, но не дальше расстояния dist от точки xtile
//   Если указать dist=0, то проверка расстояния будет прогнорирована
//   Если указать msg=0, то никаких реплик в момент толкания персонаж не сообщит
#define push_options(xtile,dist,msg)         if (self_TEAM == TEAM_PLAYER) then begin \
                                             end                                \
                                             else if self_enemy_dude then begin \
                                                 script_overrides;              \
                                                 if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children)) then begin \
                                                 g_display_mstr(108);           \
                                                 end else begin                 \
                                                 g_display_mstr(109);           \
                                                 end                            \
                                             end                                \
                                             else begin                         \
                                                 if ((tile_distance(self_tile, xtile) > dist) and (xtile>0) and (dist>0)) then begin \
                                                    script_overrides;           \
                                                    if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children)) then begin \
                                                    g_display_mstr(106);        \
                                                    end else begin              \
                                                    g_display_mstr(107);        \
                                                    end                         \
                                                    animate_move_to_tile(tile_num_in_direction(self_tile, rotation_to_tile(self_tile, xtile), 1)); \
                                                 end else begin                 \
                                                    if (msg>0) then begin       \
                                                    floater(self_obj,msg,COLOR_MSG_LIGHT_GREY); \
                                                    end                         \
                                                 end                            \
                                             end                                \

// -----------------------------------------------------------------------
// боевые опции и процедуры
// -----------------------------------------------------------------------

/*
Макросы Fallout 2 (устарели), расшифровка:

#define herebefore_bit              bit_1 // знакомство с ГГ, фиксируется на 1 в конце talk_p_proc
#define hostile_bit                 bit_2 // отвечает за враждебность к ГГ, устанавливается при нанесении урона ГГ и в процедуре Node999, но сбрасывается на ноль в начале каждого раунда и при перезаходе на карту
#define examined_bit                bit_3 // используется в description_p_proc для смены описания после первого осмотра
#define personal_enemy_bit          bit_4 // становится персональным врагом ГГ, однако на практике бит бездействует, так вместе с ним в макросе также фиксируется hostile_bit и именно через hostile обычно проверяется враждебность. Впрочем, это не всегда может быть так - оценить все скрипты не могу, их 111 шт.
#define initialized_bit             bit_5 // инициализация какого-либо процесса в скриптах (где вызывается и что включается - прописывается вручную); используется у рабов и атакующих во время порабощения в Дыре, а также у Майрона
#define is_float_bit                bit_7 // используется у нескольких нпс в Рино для появления плавающих предупреждений при виде ГГ, например, если тот вооружен
#define destroy_me_bit              bit_8 // используется только у Красавчика Ллойда (видимо, указание "удали меня" с карты)
#define heard_call_bit              bit_9 // персонаж услышал призыв, используется у Рамиреса в Конюшнях и людей Мордино, когда кто-то призывает охрану

Важно: Если ГГ атакует персонажа, то LVAR принудительно устанавливается движком на -3.

*/

#define enemy_bit                   bit_1

#define self_enemy_dude             (lvar_bit(LVAR_Self_Flags, enemy_bit) != 0)

#define set_enemy_dude              set_lvar_bit_on(LVAR_Self_Flags, enemy_bit)

#define off_enemy_dude              set_lvar_bit_off(LVAR_Self_Flags, enemy_bit)

/*
Устаревший код:

#define set_hostile                 if (self_TEAM == TEAM_PLAYER) then begin    \
                                        off_enemy_dude;                         \
                                    end                                         \
                                    else begin                                  \
                                        if (NUM_TEAM>0) then begin              \
                                        critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,NUM_TEAM); \
                                        end                                     \
                                        set_enemy_dude;                         \
                                    end                                         \
*/

variable damage_amnt;

#define set_damage_dude             if (source_obj == dude_obj) then begin      \
                                        if (self_TEAM == TEAM_PLAYER) then begin \
                                            off_enemy_dude;                     \
                                        end                                     \
                                        else if (fixed_param>0) then begin      \
                                            set_enemy_dude;                     \
                                            set_damage_check                    \
                                            if (damage_amnt > 0) then begin     \
                                            inc_global_var_amt(GVAR_EXPOINT_COMBAT_CHECK,damage_amnt); \
                                            set_damage_fire                     \
                                            end                                 \
                                        end                                     \
                                        damage_amnt := 0;                       \
                                    end                                         \
                                    //display_msg(" "+damage_amnt);               \

//опыт = (урон*3) + ((урон*сопротивляемость) / 100)*3
#define set_damage_check            damage_amnt := fixed_param;                 \
                                        if (self_cur_hits <= 0) then begin      \
                                        damage_amnt += self_cur_hits;           \
                                        end                                     \
                                        damage_amnt := damage_amnt*3;           \
                                        if (damage_amnt>0) then begin           \
                                            if (weapon_dmg_type(target_obj)>0) then begin \
                                            damage_amnt += ((damage_amnt * get_critter_stat(self_obj, STAT_dmg_resist + weapon_dmg_type(target_obj))) / 100); \
                                            end else begin                      \
                                            damage_amnt += ((damage_amnt * get_critter_stat(self_obj, STAT_dmg_resist)) / 100); \
                                            end                                 \
                                        end                                     \
                                        if (self_TEAM == TEAM_PLAYER) then begin \
                                        damage_amnt := 0;                       \
                                        end                                     \

/*
До версии 1.08 было так:

#define set_damage_check            damage_amnt := fixed_param;                 \
                                        if (self_cur_hits <= 0) then begin      \
                                        damage_amnt += self_cur_hits;           \
                                        end                                     \
                                        damage_amnt := damage_amnt*3;           \
                                        if (weapon_dmg_type(target_obj)>0) then begin \
                                            if ((get_critter_stat(self_obj, STAT_dmg_resist+weapon_dmg_type(target_obj))/10)>0) then begin \
                                            damage_amnt *= get_critter_stat(self_obj, STAT_dmg_resist+weapon_dmg_type(target_obj))/10;     \
                                            end                                 \
                                        end else begin                          \
                                            if ((get_critter_stat(self_obj, STAT_dmg_resist)/10)>0) then begin \
                                            damage_amnt *= get_critter_stat(self_obj, STAT_dmg_resist)/10;     \
                                            end                                 \
                                        end                                     \
                                        if (self_TEAM == TEAM_PLAYER) then begin \
                                        damage_amnt := 0;                       \
                                        end                                     \

*/

#define set_damage_fire             if (weapon_dmg_type(target_obj) == DMG_fire) then begin \
                                        if ((critter_is_fleeing(self_obj) == false) and (self_cur_hits>0)) then begin \
                                           if (type_kill(KILL_TYPE_brahmin) or type_kill(KILL_TYPE_radscorpion) or type_kill(KILL_TYPE_scolopendra) or type_kill(KILL_TYPE_rat) or type_kill(KILL_TYPE_giant_ant) or type_kill(KILL_TYPE_dog) or type_kill(KILL_TYPE_centaur)) then begin \
                                                if (is_success(do_check(dude_obj, STAT_lu, -1)) == true) then begin \
                                                display_msg(g_mstr(323)+self_name+g_mstr(324)); \
                                                critter_set_flee_state(self_obj, 1); \
                                                end                             \
                                           end                                  \
                                        end                                     \
                                    end                                         \

/*
Увы, set_damage_EMP не работает.
   Во-первых, функция set_critter_stat действует только в отношении ГГ и не действует в отношении нпс.
   Во-вторых, функция не срабатывает, если урон оказался без потери хотя бы 1 ОЗ, но ЭМИ не действует на живых нпс.
*/
#define set_damage_EMP              if (weapon_dmg_type(target_obj) == DMG_emp) then begin   \
                                       if (lvar_bit(LVAR_Self_Flags, bit_8) == 0) then begin \
                                          display_msg(self_name+g_mstr(326));    \
                                          g_floater(self_obj,325,COLOR_MSG_RED); \
                                          set_critter_stat(self_obj, STAT_pe, -1); \
                                          set_critter_stat(self_obj, STAT_st, -1); \
                                          set_lvar_bit_on(LVAR_Self_Flags, bit_8); \
                                       end                                      \
                                    end                                         \
                                    /*
                                    display_msg(get_critter_stat(self_obj, STAT_pe)+" PE do");   \
                                    display_msg(get_critter_stat(self_obj, STAT_st)+" ST do");   \
                                    display_msg(get_critter_stat(self_obj, STAT_pe)+" PE re");   \
                                    display_msg(get_critter_stat(self_obj, STAT_st)+" ST re");   \
                                    */

#define attack(WHO)                 attack_complex(WHO,0,1,0,0,30000,0,0)       \

#define self_attack_dude            if (critter_is_fleeing(self_obj) == true) then begin \
                                        Flee_From_Dude                          \
                                    end else attack(dude_obj)

//pois - мин величина отравления (макс величина = мин*2)
//rad - мин величина облучения (макс величина = мин*2)
//travm1 - возможна ли травма ног при атаке (указывается вероятность от 0 до 100)
//travm2 - возможна ли травма рук при атаке (указывается вероятность от 0 до 100)
//travm3 - возможна ли травма глаз при атаке (указывается вероятность от 0 до 100)
#define effectAttak(pois,rad,travmA,travmB,travmC)                              \
                                    if (fixed_param == COMBAT_SUBTYPE_HIT_SUCCEEDED) then begin \
                                        if (target_obj == dude_obj) then begin  \
                                            if (random(1,100)>(50+dude_luck)) then begin \
                                               if (pois >0) then begin          \
                                                  if (type_kill(KILL_TYPE_radscorpion) and (critter_state(self_obj) bwand DAM_CRIP_ARM_LEFT)) then begin \
                                                  end                           \
                                                  else if (armor_pid_dude_var == PID_ARMOR_POWER_A) then begin \
                                                  end                           \
                                                  else if (armor_pid_dude_var == PID_ARMOR_POWER_B) then begin \
                                                  end                           \
                                                  else if (armor_pid_dude_var == PID_ARMOR_POWER_C) then begin \
                                                  end                           \
                                                  else begin                    \
                                                  poison(dude_obj,random(pois,pois*2)); \
                                                  end                           \
                                               end                              \
                                            end                                 \
                                            if (rad >0) then begin              \
                                               if (random(1,100)>(50+dude_luck)) then begin \
                                               radiation_inc(dude_obj, random(rad,rad*2)); \
                                               end                              \
                                            end                                 \
                                            if (armor_pid_dude_var == PID_ARMOR_POWER_A) then begin \
                                            end                                 \
                                            else if (armor_pid_dude_var == PID_ARMOR_POWER_B) then begin \
                                            end                                 \
                                            else if (armor_pid_dude_var == PID_ARMOR_POWER_C) then begin \
                                            end                                 \
                                            else if (combat_difficulty == 0) then begin \
                                            end                                 \
                                            else begin                          \
                                               if (travmA>0) then begin         \
                                                   if (random(0,300) <= travmA) then begin \
                                                   dam_to_dude_LEG              \
                                                   end                          \
                                               end                              \
                                               if (travmB>0) then begin         \
                                                   if (random(0,300) <= travmB) then begin \
                                                   dam_to_dude_ARM              \
                                                   end                          \
                                               end                              \
                                               if (travmC>0) then begin         \
                                                   if (random(0,300) <= travmC) then begin \
                                                   dam_to_dude_BLIND            \
                                                   end                          \
                                               end                              \
                                            end                                 \
                                        end                                     \
                                    end                                         \

#define effectIntimidationPerk      if (fixed_param == COMBAT_SUBTYPE_TURN) then begin \
                                        if DudePerkHas(PERK_intimidation) then begin   \
                                           if (self_TEAM == TEAM_PLAYER) then begin    \
                                           end                                         \
                                           else if (type_kill(KILL_TYPE_robot) or type_kill(KILL_TYPE_big_boss)) then begin \
                                           end                                         \
                                           else if (self_cur_hits >= (90+dude_charisma)) then begin \
                                           end                                         \
                                           else if self_enemy_dude then begin          \
                                              if (tile_distance_objs(self_obj,dude_obj) <= 10) then begin \
                                                 if (random (0,(11-dude_charisma)) == 0) then begin \
                                                 script_overrides;                     \
                                                 display_msg(self_name+g_mstr(320));   \
                                                 g_floater(self_obj,327,COLOR_MSG_RED); \
                                                 end                                   \
                                              end                                      \
                                           end                                         \
                                        end                                            \
                                    end                                                \

#define effectRegeratHP             if (fixed_param == COMBAT_SUBTYPE_TURN) then begin          \
                                       if (dude_elevation == self_elevation) then begin         \
                                              if (self_cur_hits <= (self_max_hits/2)) then begin \
                                                 if (random(0,3) != 0) then begin               \
                                                 display_msg(self_name+g_mstr(321));            \
                                                 g_floater(self_obj,322,COLOR_MSG_RED);         \
                                                 play_sfx("HMXXXXCH");                          \
                                                 critter_heal(self_obj,self_max_hits/15);       \
                                                 critter_uninjure(self_obj, (DAM_CRIP_LEG_LEFT bwor DAM_CRIP_LEG_RIGHT bwor DAM_CRIP_ARM_LEFT bwor DAM_CRIP_ARM_RIGHT)); \
                                                 reg_anim_clear(self_obj);                      \
                                                 reg_anim_begin();                              \
                                                     anim(self_obj, ANIM_hit_from_back, -1);    \
                                                 reg_anim_end();                \
                                                 end                            \
                                              end                               \
                                       end                                      \
                                    end                                         \

// -----------------------------------------------------------------------
// Общие опции криттеров
// -----------------------------------------------------------------------

#define self_can_see_dude           ((obj_can_see_obj(self_obj,dude_obj) == true) and (self_visible == true) and (dude_elevation == self_elevation)) \

#define self_can_see_dude_bit       (lvar_bit(LVAR_Self_Flags,bit_3) != 0)      \

#define setting_self_see_dude       set_lvar_bit_off(LVAR_Self_Flags,bit_3);    \
                                    if self_can_see_dude then begin             \
                                       if dude_is_sneaking then begin           \
                                               if ((self_cur_rot == 0) and (rotation_to_tile(self_tile, dude_tile) == 3)) then begin \
                                          end                                   \
                                          else if ((self_cur_rot == 1) and (rotation_to_tile(self_tile, dude_tile) == 4)) then begin \
                                          end                                   \
                                          else if ((self_cur_rot == 2) and (rotation_to_tile(self_tile, dude_tile) == 5)) then begin \
                                          end                                   \
                                          else if ((self_cur_rot == 3) and (rotation_to_tile(self_tile, dude_tile) == 0)) then begin \
                                          end                                   \
                                          else if ((self_cur_rot == 4) and (rotation_to_tile(self_tile, dude_tile) == 1)) then begin \
                                          end                                   \
                                          else if ((self_cur_rot == 5) and (rotation_to_tile(self_tile, dude_tile) == 2)) then begin \
                                          end                                   \
                                          else if (tile_distance_objs(self_obj,dude_obj) <= ((self_perception*10)-has_skill(dude_obj, SKILL_SNEAK)) ) then begin \
                                          set_lvar_bit_on(LVAR_Self_Flags,bit_3); \
                                          end                                   \
                                          else if (tile_distance_objs(self_obj,dude_obj) <= (self_perception/2)) then begin \
                                          set_lvar_bit_on(LVAR_Self_Flags,bit_3); \
                                          end                                   \
                                       end                                      \
                                       else begin                               \
                                          if (tile_distance_objs(self_obj,dude_obj) <= (self_perception*3)) then begin \
                                          set_lvar_bit_on(LVAR_Self_Flags,bit_3); \
                                          end                                   \
                                       end                                      \
                                    end                                         \

#define Flee_From_Dude              if (combat_is_initialized == false) then begin \
                                        if (anim_busy(self_obj) == false) then begin \
                                            if self_can_see_dude then begin     \
                                            reg_anim_begin();                   \
                                            animate_run_to_tile(tile_num_in_direction(self_tile,rotation_to_tile(dude_tile, self_tile),random(3,8))); \
                                            reg_anim_end();                     \
                                            end                                 \
                                        end                                     \
                                    end                                         \

//Отличие Flee_From_Dude_NoSee от Flee_From_Dude в отстутствии проверки на зрительный контакт между нпс.
#define Flee_From_Dude_NoSee        if (combat_is_initialized == false) then begin \
                                        if (anim_busy(self_obj) == false) then begin \
                                        animate_run_to_tile(tile_num_in_direction(self_tile, rotation_to_tile(dude_tile,self_tile), 5)); \
                                        end                                     \
                                    end                                         \

// -----------------------------------------------------------------------
// critter_p_proc
// -----------------------------------------------------------------------

//param = -1 - персонаж никогда не нападет на ГГ самостоятельно
//      = 0 - персонаж нападает на ГГ только при личной враждебности
//      = 1 - персонаж нападает на ГГ при личной враждебности ИЛИ низкой репутации (<=-30)
//      = 2 - персонаж нападает на ГГ всегда
//      = 3 - персонаж нападает на ГГ при личной враждебности ИЛИ предельно низкой репутации (<=-100) - используется для Виллы
//dist      - максимальное расстояние, на котором сработает проверка
//rot       - постоянный поворот в сторону ГГ (0 - нет, иначе - да)

#define set_critter_options(param,rot)   setting_self_see_dude                  \
                                         if (rot != 0) then begin               \
                                         rotat_critter_to_dude                  \
                                         end                                    \
                                         set_critter_attak(param,15)            \

#define set_critter_attak(param,dist)    if (self_can_see_dude_bit and (tile_distance_objs(self_obj,dude_obj) <= dist)) then begin \
                                             if (game_ui_is_disabled == true) then begin \
                                             end                                \
                                             else if (self_TEAM == TEAM_PLAYER) then begin \
                                             end                                \
                                             else if (type_kill(KILL_TYPE_ghoul) and DudePerkHas(PERK_ghouling_charisma) and (tile_distance_objs(self_obj,dude_obj) >= 5)) then begin \
                                             end                                \
                                             else begin                         \
                                                if self_enemy_dude then begin   \
                                                self_attack_dude;               \
                                                end                             \
                                                else if (param == 2) then begin \
                                                self_attack_dude;               \
                                                end                             \
                                                else if (param == 1) then begin \
                                                    if (TOWN_REP_VAR > 0) then begin \
                                                       if town_rep_is_vilified then begin \
                                                       self_attack_dude;        \
                                                       end                      \
                                                    end                         \
                                                end                             \
                                                else if (param == 3) then begin \
                                                    if (TOWN_REP_VAR > 0) then begin \
                                                       if town_rep_is_critical then begin \
                                                       self_attack_dude;        \
                                                       end                      \
                                                    end                         \
                                                end                             \
                                             end                                \
                                         end                                    \

#define rotat_critter_to_dude            if (combat_is_initialized == false) then begin \
                                            if self_can_see_dude_bit then begin \
                                                if (tile_distance_objs(self_obj,dude_obj) < self_perception) then begin \
                                                   if (anim_busy(self_obj) == false) then begin \
                                                   reg_anim_begin();            \
                                                   animate_rotation(rotation_to_tile(self_tile, dude_tile)); \
                                                   reg_anim_end();              \
                                                   end                          \
                                                end                             \
                                            end                                 \
                                         end                                    \

#define var_using_stop(the_var)          if ((self_visible == true) and (self_elevation == dude_elevation) and (tile_distance_objs(self_obj,dude_obj) < 15) and (global_var(GVAR_DUDE_STEALTH_TO_HAND) <= 0)) then begin \
                                            if (the_var == 0) then begin   \
                                                the_var := self_obj;            \
                                            end                                 \
                                            else if (is_critter_dead(the_var)) then begin \
                                                the_var := self_obj;            \
                                            end                                 \
                                            else if (obj_can_see_obj(the_var, dude_obj) == false) then begin \
                                                the_var := self_obj;            \
                                            end                                 \
                                         end                                    \

#define set_using_stop                   var_using_stop(box_stop_use)           \

#define invisToDude(hexBns,msg)          variable ItemDudeHend;                 \
                                         if (self_elevation == dude_elevation) then begin \
                                           ItemDudeHend := 5+dude_perception;     \
                                           if (hexBns!=0) then begin              \
                                           ItemDudeHend += hexBns;                \
                                           end                                    \
                                           if (self_visible == false) then begin  \
                                            if (inven_hand_R(dude_obj) > 0) then begin \
                                               if (obj_pid(inven_hand_R(dude_obj)) == PID_TOOL_MOTION_SENSOR) then begin \
                                               ItemDudeHend += 10;                \
                                               end                                \
                                            end                                   \
                                            if (inven_hand_L(dude_obj) > 0) then begin \
                                               if (obj_pid(inven_hand_L(dude_obj)) == PID_TOOL_MOTION_SENSOR) then begin \
                                               ItemDudeHend += 10;                \
                                               end                                \
                                            end                                   \
                                            if (tile_distance_objs(self_obj,dude_obj) <= ItemDudeHend) then begin \
                                               set_obj_visibility(self_obj, 0);   \
                                               if (msg>0) then begin              \
                                               display_mstr(msg);                 \
                                               end                                \
                                            end                                   \
                                           end                                    \
                                         end                                      \

/*
Замечание:
   Пришлось немного усложнить макрос partyRunToDude введением битовых проверок.
   Причина в недоработке движка по части напарников. Напарники переносятся вслед за ГГ на другой уровень автоматически,
   но при этом сохраняют анимацию ходьбы/бега. Соответственно ее нужно обрывать в момент перехода.
   Самый очевидный способ (проверка уровня) не работает, так как движок моментально переносит персонажа и проверка срабатывает уже на актуальном уровне.
   Затем я ввел отдельную переменную stepElevation, это самый простой вариант. Но каждый раз эту переменную нужно объявлять в скрипте, что избыточно.
   Ведь она не актуальна для тех нпс, которые с точки зрения движка не являются напарниками и все равно бегают за ГГ благодаря partyRunToDude.
   В итоге заменил stepElevation на биты стандартной переменной LVAR_Self_Flags. Это более трудоемко в плане записи макроса, но проще в использовании в будущем.
*/

#define partyRunToDude              if ((combat_is_initialized == false) and (self_visible == true)) then begin \
                                        if ((lvar_bit(LVAR_Self_Flags, bit_4) == 0) and (self_elevation == 0)) then begin \
                                            reg_anim_clear(self_obj);           \
                                            set_lvar_bit_on(LVAR_Self_Flags, bit_4);  \
                                            set_lvar_bit_off(LVAR_Self_Flags, bit_5); \
                                            set_lvar_bit_off(LVAR_Self_Flags, bit_6); \
                                            end                                 \
                                        else if ((lvar_bit(LVAR_Self_Flags, bit_5) == 0) and (self_elevation == 1)) then begin \
                                            reg_anim_clear(self_obj);           \
                                            set_lvar_bit_off(LVAR_Self_Flags, bit_4); \
                                            set_lvar_bit_on(LVAR_Self_Flags, bit_5);  \
                                            set_lvar_bit_off(LVAR_Self_Flags, bit_6); \
                                        end                                     \
                                        else if ((lvar_bit(LVAR_Self_Flags, bit_6) == 0) and (self_elevation == 2)) then begin \
                                            reg_anim_clear(self_obj);           \
                                            set_lvar_bit_off(LVAR_Self_Flags, bit_4); \
                                            set_lvar_bit_off(LVAR_Self_Flags, bit_5); \
                                            set_lvar_bit_on(LVAR_Self_Flags, bit_6);  \
                                        end                                     \
                                        if (dude_elevation != self_elevation) then begin \
                                            reg_anim_clear(self_obj);           \
                                            move_to(self_obj, tile_num_in_direction(dude_tile,random(0,5),1), dude_elevation); \
                                        end                                     \
                                        else begin                              \
                                            partyRunToDudeAnim                  \
                                        end                                     \
                                    end                                         \

#define partyRunToDudeAnim          if (anim_busy(self_obj) == false) then begin \
                                        if (tile_distance(self_tile, dude_tile) > 5) then begin \
                                        reg_anim_begin();                       \
                                        animate_run_to_tile_force(tile_num_in_direction(dude_tile,random(0,5),2)); \
                                        reg_anim_end();                         \
                                        end                                      \
                                        else if (tile_distance(self_tile, dude_tile) > 3) then begin \
                                        reg_anim_begin();                       \
                                        animate_move_to_tile_force(tile_num_in_direction(dude_tile,random(0,5),2)); \
                                        reg_anim_end();                         \
                                        end                                     \
                                    end                                         \

// -----------------------------------------------------------------------
// look_at_p_proc и description_p_proc
// -----------------------------------------------------------------------

#define lookProcMsg                 if (mstr(100) != "") then begin             \
                                    script_overrides;                           \
                                    display_mstr(100); end                      \

#define dsrptProcMsg                if (mstr(101) != "") then begin             \
                                    script_overrides;                           \
                                    display_mstr(101); end                      \

// -----------------------------------------------------------------------
// pickup_p_proc
// -----------------------------------------------------------------------

#define pickupProcCritter           if (source_obj == dude_obj) then begin      \
                                        if (self_TEAM == TEAM_PLAYER) then begin \
                                        end                                     \
                                        else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children)) then begin \
                                           if (DudePerkHas(PERK_harmless) and (random(0,100) >= 50)) then begin \
                                           script_overrides;                    \
                                           g_display_mstr(143);                 \
                                           end                                  \
                                           else begin                           \
                                           anim(self_obj, ANIMATE_ROTATION, rotation_to_tile(self_tile, dude_tile)); \
                                           set_enemy_dude;                      \
                                           self_attack_dude;                    \
                                           end                                  \
                                        end                                     \
                                        else begin                              \
                                           anim(self_obj, ANIMATE_ROTATION, rotation_to_tile(self_tile, dude_tile)); \
                                           set_enemy_dude;                      \
                                           self_attack_dude;                    \
                                        end                                     \
                                    end                                         \

// -----------------------------------------------------------------------
// use_skill_on_p_proc
// -----------------------------------------------------------------------

#define skillUseSteal               if (action_being_used == SKILL_STEAL) then begin                      \
                                        if (FLAG_STEAL <= -99) then begin                                 \
                                            script_overrides;                                             \
                                            g_display_mstr(149);                                          \
                                        end                                                               \
                                        else if type_kill(KILL_TYPE_robot) then begin                     \
                                            script_overrides;                                             \
                                            g_display_mstr(145);                                          \
                                        end                                                               \
                                        else if ((armor_pid_dude_var == PID_ARMOR_POWER_A) or (armor_pid_dude_var == PID_ARMOR_POWER_B) or (armor_pid_dude_var == PID_ARMOR_POWER_C)) then begin \
                                            script_overrides;                                             \
                                            g_display_mstr(148);                                          \
                                        end                                                               \
                                        else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children) or type_kill(KILL_TYPE_super_mutant) or type_kill(KILL_TYPE_ghoul)) then begin \
                                            if (has_skill(dude_obj, SKILL_STEAL) < FLAG_STEAL) then begin \
                                                if (party_member_obj(self_PID) == 0) then begin           \
                                                script_overrides;                                         \
                                                g_skill_display_mstr(141,SKILL_STEAL,FLAG_STEAL)          \
                                                end                                                       \
                                            end                                                           \
                                        end                                                               \
                                        else begin                                                        \
                                            script_overrides;                                             \
                                            g_display_mstr(142);                                          \
                                        end                                                               \
                                    end                                                                   \

#define skillUseFAid                if (action_being_used == SKILL_FIRST_AID) then begin                  \
                                    end                                                                   \
                                        //script_overrides;                                             \
                                        //display_msg(g_mstr(105));                                     \
                                    //end                                                               \

#define skillUseFAidx(x)            if (action_being_used == SKILL_FIRST_AID) then begin                  \
                                        if (has_skill(dude_obj, SKILL_FIRST_AID) < x) then begin          \
                                        script_overrides;                                                 \
                                        g_skill_display_mstr(147,SKILL_FIRST_AID,x)                       \
                                        end                                                               \
                                    end                                                                   \

#define skillUseDoctor(x)           if (action_being_used == SKILL_DOCTOR) then begin                     \
                                        if (has_skill(dude_obj, SKILL_DOCTOR) < x) then begin             \
                                        script_overrides;                                                 \
                                        g_skill_display_mstr(147,SKILL_DOCTOR,x)                          \
                                        end                                                               \
                                    end                                                                   \

#define skillUseScience(x)          if (action_being_used == SKILL_SCIENCE) then begin                    \
                                        if type_kill(KILL_TYPE_robot) then begin                          \
                                            script_overrides;                                             \
                                            if (self_TEAM == TEAM_PLAYER) then begin                      \
                                            g_display_mstr(501);                                          \
                                            end                                                           \
                                            else if (has_skill(source_obj, SKILL_SCIENCE) >= x) then begin  \
                                            critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_PLAYER); \
                                            set_local_var(LVAR_Flags,0);                                  \
                                            off_enemy_dude;                                               \
                                            exp_add(3*x);                                                 \
                                            g_display_mstr(502);                                          \
                                            dude_floater_OK;                                              \
                                            end                                                           \
                                            else begin                                                    \
                                            g_skill_display_mstr(504,SKILL_SCIENCE,x)                     \
                                            end                                                           \
                                        end                                                               \
                                    end                                                                   \

// -----------------------------------------------------------------------
// use_obj_on_p_proc
// -----------------------------------------------------------------------

/*
itemTypeUseDude фиксирует успех применения предметов определенного типа со стороны ГГ.
По умолчанию успех означает, что нпс невраждебен ГГ, успешно принял предмет и что предмет применен именно ГГ, а не кем-то еще.
Использовать для проверки ПОСЛЕ макроса UsedItemToCrit_Proc и только в процедуре use_obj_on_p_proc
Значения:
   0 - безуспешное применение
   1 - стимуляторы
   2 - алкоголь
   3 - еда
   4 - безвредный напиток (вода, необлученная кола)
*/

#define UsedItemToCrit_Proc         variable itemTypeUseDude;                   \
                                    itemTypeUseDude := 0;                       \
                                    if (obj_item_subtype(obj_being_used_with) == item_type_drug) then begin \
                                       if type_kill(KILL_TYPE_robot) then begin \
                                       script_overrides;                        \
                                       g_display_mstr(404);                     \
                                       end                                      \
                                       else if type_kill(KILL_TYPE_plant) then begin \
                                       script_overrides;                        \
                                       g_display_mstr(406);                     \
                                       end                                      \
                                       else begin                               \
                                       UsedToCrit_Cola                          \
                                       UsedToCrit_Water                         \
                                       UsedToCrit_Alcohol                       \
                                       UsedToCrit_Stimpak                       \
                                       UsedToCrit_Foods                         \
                                       UsedToCrit_MeatFoul                      \
                                       UsedToCrit_IRP                           \
                                       UsedToCrit_Ash                           \
                                       end                                      \
                                    end                                         \
                                    else if (obj_item_subtype(obj_being_used_with) == item_type_misc_item) then begin \
                                       UsedToCrit_Boots                         \
                                       UsedToCrit_Shovel                        \
                                       UsedToCrit_Decoder                       \
                                       UsedToCrit_DoctorsBag                    \
                                       UsedToCrit_Scull                         \
                                    end                                         \
                                    else if (obj_item_subtype(obj_being_used_with) == item_type_armor) then begin \
                                    end                                         \
                                    else if (obj_item_subtype(obj_being_used_with) == item_type_ammo) then begin \
                                       stopUseCarGaz                            \
                                    end                                         \
                                    else if (obj_item_subtype(obj_being_used_with) == item_type_weapon) then begin \
                                       g_display_mstr(482);                     \
                                    end                                         \
                                    else if (obj_item_subtype(obj_being_used_with) == item_type_key_item) then begin \
                                       g_display_mstr(480);                     \
                                    end                                         \
                                    else if (obj_item_subtype(obj_being_used_with) == item_type_container) then begin \
                                       g_display_mstr(481);                     \
                                    end                                         \

/*
   Учитывать:
      на ком применим предмет, а на ком нет
      применим ли предмет в бою
      применим ли предмет при враждебности криттера
*/

#define UsedToCrit_Alcohol                  if ((objUsedPid == PID_M_BOOZE) or (objUsedPid == PID_M_VISKI) or (objUsedPid == PID_M_BEER) or (objUsedPid == PID_M_TEQUILA) or (objUsedPid == PID_M_MEX_BEER)) then begin \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children) or type_kill(KILL_TYPE_ghoul) or type_kill(KILL_TYPE_big_boss)) then begin \
                                                  if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(403));       \
                                                  end                                       \
                                                  else if (combat_is_initialized == true) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(402));       \
                                                  end                                       \
                                                  else if (FLAG_ALCOHOL == 1) then begin    \
                                                  script_overrides;                         \
                                                  g_floater(self_obj,413,COLOR_MSG_NORMAL); \
                                                  display_msg(self_name+g_mstr(407));       \
                                                  end                                       \
                                                  else begin                                \
                                                  itemTypeUseDude := 2;                     \
                                                  g_floater(self_obj,414,COLOR_MSG_GREEN);  \
                                                  end                                       \
                                               end                                          \
                                               else begin                                   \
                                                  script_overrides;                         \
                                                  g_display_mstr(410);                      \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_Stimpak                  if ((objUsedPid == PID_M_STIMPAK) or (objUsedPid == PID_M_SUPER_STIMPAK)) then begin \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children) or type_kill(KILL_TYPE_ghoul) or type_kill(KILL_TYPE_big_boss)) then begin \
                                                  if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin \
                                                     script_overrides;                      \
                                                     display_msg(self_name+g_mstr(403));    \
                                                     itemTypeUseDude := 0;                  \
                                                  end                                       \
                                                  else begin                                \
                                                     itemTypeUseDude := 1;                  \
                                                  end                                       \
                                               end                                          \
                                               else begin                                   \
                                                  script_overrides;                         \
                                                  g_display_mstr(409);                      \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_Stimpak_Doctor           if (itemTypeUseDude == 1) then begin            \
                                               critter_uninjure_full(self_obj);             \
                                            end                                             \

#define UsedToCrit_Cola                     if (objUsedPid == PID_M_NUKA_COLA_RAD) then begin \
                                               item_add(self_obj,PID_BOOTLE_CAPS,1)         \
                                               display_msg(obj_name(self_obj)+g_mstr(102)); \
                                            end                                             \
                                            else if (objUsedPid == PID_M_NUKA_COLA) then begin   \
                                               if (source_obj != dude_obj) then begin       \
                                                  item_add(self_obj,PID_BOOTLE_CAPS,1)      \
                                                  display_msg(obj_name(self_obj)+g_mstr(102)); \
                                               end                                          \
                                               else if (FLAG_FOOD >0) then begin            \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(407));       \
                                               end                                          \
                                               else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children) or type_kill(KILL_TYPE_ghoul)) then begin \
                                                  if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(403));       \
                                                  end                                       \
                                                  else if ((combat_is_initialized == true) and (self_TEAM != TEAM_PLAYER)) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(402));       \
                                                  end                                       \
                                                  else begin                                \
                                                  itemTypeUseDude := 4;                     \
                                                  set_SLAVA(1)                              \
                                                  exp_add(10);                              \
                                                  item_add(self_obj,PID_BOOTLE_CAPS,1)      \
                                                  display_msg(obj_name(self_obj)+g_mstr(102)); \
                                                  g_display_mstr(419);                      \
                                                  g_floater(self_obj,417,COLOR_MSG_GREEN);  \
                                                  end                                       \
                                               end                                          \
                                               else begin                                   \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(407));       \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_Water                    if (objUsedPid == PID_M_WATER_FLASK) then begin \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if (FLAG_FOOD >0) then begin            \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(407));       \
                                               end                                          \
                                               else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children) or type_kill(KILL_TYPE_ghoul)) then begin \
                                                  if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(403));       \
                                                  end                                       \
                                                  else if (combat_is_initialized == true) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(402));       \
                                                  end                                       \
                                                  else begin                                \
                                                  itemTypeUseDude := 4;                     \
                                                  set_SLAVA(1)                              \
                                                  exp_add(10);                              \
                                                  g_display_mstr(419);                      \
                                                  g_floater(self_obj,417,COLOR_MSG_GREEN);  \
                                                  end                                       \
                                               end                                          \
                                               else begin                                   \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(407));       \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_Foods                    if ((objUsedPid == PID_M_IGUANA) or (objUsedPid == PID_M_FRUIT) or (objUsedPid == PID_M_MEAT_JERKY) or (objUsedPid == PID_M_NOODLES) or (objUsedPid == PID_M_TV_DINNER) or (objUsedPid == PID_M_SOUP_RAT) or (objUsedPid == PID_M_BRAHMIN_POTROH) or (objUsedPid == PID_M_FRITOS_BANDITOS)) then begin \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if (FLAG_FOOD >0) then begin            \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(407));       \
                                               end                                          \
                                               else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children) or type_kill(KILL_TYPE_ghoul) or type_kill(KILL_TYPE_super_mutant)) then begin \
                                                  if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(403));       \
                                                  end                                       \
                                                  else if (combat_is_initialized == true) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(402));       \
                                                  end                                       \
                                                  else begin                                \
                                                  itemTypeUseDude := 3;                     \
                                                  set_SLAVA(1)                              \
                                                  exp_add(10);                              \
                                                  g_display_mstr(405);                      \
                                                  g_floater(self_obj,417,COLOR_MSG_GREEN);  \
                                                  end                                       \
                                               end                                          \
                                               else if (type_kill(KILL_TYPE_big_boss) or type_kill(KILL_TYPE_super_mutant)) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(407));       \
                                               end                                          \
                                               else begin                                   \
                                                  if DudePerkHas(PERK_vaquero) then begin   \
                                                  if (self_TEAM != TEAM_PLAYER) then begin  \
                                                     if (random(0,100+self_max_hits) <= (20+(20*has_trait(TRAIT_PERK, dude_obj, PERK_vaquero)))) then begin \
                                                     critter_stop_attacking(self_obj);      \
                                                     critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_PLAYER); \
                                                     off_enemy_dude;                        \
                                                     set_local_var(LVAR_Flags,0);           \
                                                     g_display_mstr(408);                   \
                                                     g_floater(self_obj,322,COLOR_MSG_GREEN); \
                                                     end                                    \
                                                  end                                       \
                                                  end                                       \
                                               end                                          \
                                            end                                             \

/*
Старая версия:
                                                  if DudePerkHas(PERK_vaquero) then begin   \
                                                     inc_local_var_amt(LVAR_Vakero_Status,20*has_trait(TRAIT_PERK, dude_obj, PERK_vaquero)); \
                                                     if (random(0,100+self_max_hits) <= (20*has_trait(TRAIT_PERK, dude_obj, PERK_vaquero))) then begin        \
                                                     if (local_var(LVAR_Vakero_Status) >= self_max_hits) then begin        \
                                                     critter_stop_attacking(self_obj);      \
                                                     critter_add_trait(self_obj,TRAIT_OBJECT,OBJECT_TEAM_NUM,TEAM_PLAYER); \
                                                     set_local_var(LVAR_Flags,0);           \
                                                     off_enemy_dude;                        \
                                                     g_display_mstr(408);                   \
                                                     end                                    \
                                                  end                                       \
*/

#define UsedToCrit_MeatFoul                 if (objUsedPid == PID_M_MEAT_FOUL) then begin   \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if type_kill(KILL_TYPE_brahmin) then begin \
                                                  if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(403));       \
                                                  end                                       \
                                                  else if (combat_is_initialized == true) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(402));       \
                                                  end                                       \
                                                  else begin                                \
                                                  script_overrides;                         \
                                                  exp_add(100);                             \
                                                  g_display_mstr(401);                      \
                                                  item_remove(dude_obj, objUsedPid, 1)      \
                                                  end                                       \
                                               end                                          \
                                               else begin                                   \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(400));       \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_IRP                      if (objUsedPid == PID_M_IRP) then begin         \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if (FLAG_FOOD >0) then begin            \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(407));       \
                                               end                                          \
                                               else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children) or type_kill(KILL_TYPE_ghoul)) then begin \
                                                  if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(403));       \
                                                  end                                       \
                                                  else if (combat_is_initialized == true) then begin \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(402));       \
                                                  end                                       \
                                                  else if (NUM_TEAM == TEAM_BROTHERS_STEEL) then begin \
                                                  script_overrides;                         \
                                                  g_display_mstr(415);                      \
                                                  end                                       \
                                                  else begin                                \
                                                  itemTypeUseDude := 3;                     \
                                                  set_SLAVA(5)                              \
                                                  exp_add(50);                              \
                                                  g_floater(self_obj,416,COLOR_MSG_GREEN);  \
                                                  g_display_mstr(405);                      \
                                                  end                                       \
                                               end                                          \
                                               else begin                                   \
                                                  script_overrides;                         \
                                                  display_msg(self_name+g_mstr(400));       \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_Ash                      if (objUsedPid == PID_M_ASH) then begin         \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if type_kill(KILL_TYPE_floater) then begin \
                                                  script_overrides;                         \
                                                  g_display_mstr(411);                      \
                                               end                                          \
                                               else if ((self_PID == PID_BOS_PALADIN_LEADER) or (self_PID == PID_BOS_PALADIN)) then begin \
                                                  script_overrides;                         \
                                                  g_display_mstr(418);                      \
                                               end                                          \
                                               else begin                                   \
                                                  display_msg(self_name+g_mstr(412));       \
                                                  set_enemy_dude;                           \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_Boots                    if (objUsedPid == PID_TOOL_BOOTS) then begin    \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if (type_kill(KILL_TYPE_men) or type_kill(KILL_TYPE_women) or type_kill(KILL_TYPE_children) or type_kill(KILL_TYPE_ghoul)) then begin \
                                                  if (self_enemy_dude and (self_TEAM != TEAM_PLAYER)) then begin \
                                                  end                                       \
                                                  else begin                                \
                                                  script_overrides;                         \
                                                  item_remove(dude_obj, objUsedPid, 1)      \
                                                  item_add(self_obj,objUsedPid,1)           \
                                                  g_floater(self_obj,420,COLOR_MSG_NORMAL); \
                                                  end                                       \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_Shovel                   if (objUsedPid == PID_TOOL_SHOVEL) then begin   \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else begin                                   \
                                                  script_overrides;                         \
                                                  g_display_mstr(424);                      \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_Decoder                  if (objUsedPid == PID_TOOL_LOCKPICKS_EL) then begin \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if type_kill(KILL_TYPE_robot) then begin \
                                                  script_overrides;                         \
                                                  g_display_mstr(425);                      \
                                               end                                          \
                                            end                                             \

/*
#define UsedToCrit_Toy                      if (objUsedPid == PID_RELICT_TOY) then begin    \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if type_kill(KILL_TYPE_children) then begin \
                                                  script_overrides;                         \
                                                  if (self_enemy_dude or has_rep_childkiller) then begin \
                                                  g_display_mstr(423);                      \
                                                  end                                       \
                                                  else begin                                \
                                                  item_remove(dude_obj, objUsedPid, 1)      \
                                                  set_SLAVA(1)                              \
                                                  exp_add(50);                              \
                                                  g_display_mstr(422);                      \
                                                  g_floater(self_obj,421,COLOR_MSG_GREEN);  \
                                                  end                                       \
                                               end                                          \
                                            end                                             \
*/

#define UsedToCrit_Scull                    if (objUsedPid == PID_SCULL_DEATHCLAW) then begin \
                                               if (source_obj != dude_obj) then begin       \
                                               end                                          \
                                               else if type_kill(KILL_TYPE_children) then begin \
                                                  script_overrides;                         \
                                                  g_display_mstr(434);                      \
                                                  g_floater(dude_obj,433,COLOR_MSG_NORMAL); \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_DoctorsBag               if (objUsedPid == PID_TOOL_DOCTORS_BAG) then begin \
                                               script_overrides;                            \
                                               if (combat_is_initialized == true) then begin \
                                                  g_display_mstr(431);                      \
                                               end                                          \
                                               else if type_kill(KILL_TYPE_robot) then begin \
                                                  g_display_mstr(486);                      \
                                               end                                          \
                                               else if (self_enemy_dude and (self_obj != dude_obj)) then begin \
                                                  display_msg(self_name+g_mstr(487));       \
                                               end                                          \
                                               else if (item_amnt(dude_obj,objUsedPid) < 1) then begin \
                                                  g_display_mstr(485);                      \
                                               end                                          \
                                               else if ((critter_state(self_obj) bwand DAM_CRIP_ARM_LEFT) or (critter_state(self_obj) bwand DAM_CRIP_ARM_RIGHT) or (critter_state(self_obj) bwand DAM_CRIP_LEG_LEFT) or (critter_state(self_obj) bwand DAM_CRIP_LEG_RIGHT) or (critter_state(self_obj) bwand DAM_BLIND)) then begin \
                                                  critter_uninjure_full(self_obj);          \
                                                  if (self_obj == dude_obj) then begin      \
                                                  g_display_mstr(483);                      \
                                                  end                                       \
                                                  else begin                                \
                                                  g_display_mstr(484);                      \
                                                  end                                       \
                                                  itemTypeUseDude := 1;                     \
                                                  item_remove(dude_obj, objUsedPid, 1)      \
                                               end                                          \
                                               else begin                                   \
                                                  g_display_mstr(493);                      \
                                               end                                          \
                                            end                                             \

#define UsedToCrit_Scorp(msg,timer)         UsedToCrit_Poison(PID_SCORPION_TAIL,msg,timer)  \

#define UsedToCrit_Poison(pid,msg,timer)    if (objUsedPid == pid) then begin               \
                                               script_overrides;                            \
                                               if (combat_is_initialized == true) then begin \
                                               g_display_mstr(431);                         \
                                               end                                          \
                                               else if (self_TEAM == TEAM_PLAYER) then begin \
                                               g_display_mstr(432);                         \
                                               end                                          \
                                               else begin                                   \
                                               ScorpUsedOpt(msg,timer)                      \
                                               end                                          \
                                            end                                             \

// -----------------------------------------------------------------------
// destroy_p_proc
// -----------------------------------------------------------------------

#define kill_critter_opt            kill_critter_reput                              \
                                    destroy_critter_inventar                        \

#define kill_critter_opt_norep      kill_critter_reput_norep                        \
                                    destroy_critter_inventar                        \

#define kill_critter_box            if (selfBarterBoxObj>0) then begin              \
                                    move_obj_inven_to_obj(selfBarterBoxObj,self_obj); \
                                    end                                             \

#define destroy_critter_inventar         if type_kill(KILL_TYPE_super_mutant) then begin \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_ghoul) then begin   \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_robot) then begin   \
                                        if ((random(0,2) == 1) or (self_PID == PID_ROBOT_ARMY)) then begin      \
                                        item_add(self_obj,PID_TOOL_PARTS_ELECTRONIC,1) \
                                        end                                         \
                                        item_add(self_obj,PID_AMMO_MICRO_FUSION_CELL,1+random(1,dude_luck)) \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_brahmin) then begin \
                                        item_add(self_obj,PID_M_MEAT_JERKY,random(3,6)) \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_radscorpion) then begin \
                                        if (self_PID == PID_SCORPION_SMALL) then begin \
                                           if (random(0,100)>=75) then begin        \
                                           item_add(self_obj,PID_SCORPION_TAIL,1)   \
                                           end                                      \
                                        end else begin                              \
                                           item_add(self_obj,PID_SCORPION_TAIL,1)   \
                                        end                                         \
                                        if (random(0,100) <= dude_luck) then begin  \
                                            if (random(0,2) == 1) then begin        \
                                            item_add(self_obj,PID_M_FRUIT,1)        \
                                            end                                     \
                                            else if (random(0,1) == 1) then begin   \
                                            item_add(self_obj,PID_M_SLUGS,1)        \
                                            end                                     \
                                            else if (random(0,1) == 1) then begin   \
                                            item_add(self_obj,PID_M_IGUANA,1)       \
                                            end                                     \
                                            else begin                              \
                                            item_add(self_obj,PID_W_BROCK,1)        \
                                            end                                     \
                                        end                                         \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_floater) then begin \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_centaur) then begin \
                                        item_add(self_obj,PID_M_BUFFOUT,1)          \
                                        item_add(self_obj,PID_HYPO,random(1,3))     \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_rat) then begin     \
                                        if (cur_map_index == MAP_VILLA_CAVE) then begin \
                                        end                                         \
                                        else if (cur_map_index == MAP_VILLA_PLAZA) then begin \
                                        end                                         \
                                        else if (cur_map_index == MAP_VILLA_HOME) then begin \
                                        end                                         \
                                        else begin                                  \
                                           if (random(0,100) <= dude_luck) then begin \
                                           item_add(self_obj,PID_BOOTLE_CAPS,1)     \
                                           end                                      \
                                        end                                         \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_dog) then begin     \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_manti) then begin   \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_deathclaw) then begin \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_plant) then begin   \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_scolopendra) then begin \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_alien) then begin   \
                                    end                                             \
                                    else if type_kill(KILL_TYPE_giant_ant) then begin \
                                       if (random(0,100) <= dude_luck) then begin   \
                                       kill_critter_Ant_items                       \
                                       end                                          \
                                    end                                             \

#define kill_critter_Ant_items      if (random(0,2) == 0) then begin                \
                                       if (random(0,1) == 0) then begin             \
                                       item_add(self_obj,PID_AMMO_308,1)            \
                                       end else begin                               \
                                       item_add(self_obj,PID_AMMO_SHOTGUN_SHELLS,1) \
                                       end                                          \
                                    end                                             \
                                    else if (random(0,1) == 0) then begin           \
                                       if (random(0,1) == 0) then begin             \
                                       item_add(self_obj,PID_AMMO_44_MAGNUM,1)      \
                                       end else begin                               \
                                       item_add(self_obj,PID_AMMO_10_MM,1)          \
                                       end                                          \
                                    end                                             \
                                    else begin                                      \
                                       if (random(0,1) == 0) then begin             \
                                       item_add(self_obj,PID_BOOTLE_CAPS,1)         \
                                       end else begin                               \
                                       item_add(self_obj,PID_W_BROCK,1)             \
                                       end                                          \
                                    end                                             \

#define kill_critter_BoS_item       item_add(self_obj,PID_BOS_ARMY_TAG,1)           \

#define kill_critter_dude_reply(a,b) if (source_obj == dude_obj) then begin         \
                                       if (get_SLAVA < 0) then begin                \
                                           if (a >0) then begin                     \
                                           floater(dude_obj,a,COLOR_MSG_RED);       \
                                           end                                      \
                                       end                                          \
                                       else begin                                   \
                                           if (b >0) then begin                     \
                                           floater(dude_obj,b,COLOR_MSG_RED);       \
                                           end                                      \
                                       end                                          \
                                    end                                             \

// -----------------------------------------------------------------------
// Миниквест на лечение травм
// -----------------------------------------------------------------------

/*
Пояснение: Лечение персонажей от травм в качестве миниквеста.
Для реализации необходимо в скрипте персонажа:
   + добавить set_injure_start (травмирование) в процедуру map_enter_p_proc
   + добавить set_injure_update в процедуру map_update_p_proc
   + добавить процедуру uninjure_proc (даже если она останется пустой) и наполнить опциями успешного лечения по необходимости
   + добавить блокировку на использование Хирурга skillUseDoctor(x) в use_skill_on_p_proc - по необходимости
   + добавить UsedToCrit_Stimpak_Doctor (лечение стимуляторами) в use_obj_on_p_proc - по необходимости
*/

#define get_Medic_Quest              lvar_bit(LVAR_Self_Flags, bit_9) \

#define set_Medic_Quest              set_lvar_bit_on(LVAR_Self_Flags, bit_9) \

#define set_injure_start(a,b,c,d,e)  if (get_Medic_Quest == 0) then begin             \
                                        if (a>0) then begin                           \
                                        critter_injure(self_obj, DAM_CRIP_ARM_LEFT);  \
                                        end                                           \
                                        if (b>0) then begin                           \
                                        critter_injure(self_obj, DAM_CRIP_ARM_RIGHT); \
                                        end                                           \
                                        if (c>0) then begin                           \
                                        critter_injure(self_obj, DAM_CRIP_LEG_LEFT);  \
                                        end                                           \
                                        if (d>0) then begin                           \
                                        critter_injure(self_obj, DAM_CRIP_LEG_RIGHT); \
                                        end                                           \
                                        if (e>0) then begin                           \
                                        critter_injure(self_obj, DAM_BLIND);          \
                                        end                                           \
                                     end                                              \

#define set_injure_update(exp,msg)   if (is_loading_game == false) then begin         \
                                     if (get_Medic_Quest == 0) then begin             \
                                             if (critter_state(self_obj) bwand DAM_CRIP_ARM_LEFT) then begin \
                                        end                                           \
                                        else if (critter_state(self_obj) bwand DAM_CRIP_ARM_RIGHT) then begin \
                                        end                                           \
                                        else if (critter_state(self_obj) bwand DAM_CRIP_LEG_LEFT) then begin \
                                        end                                           \
                                        else if (critter_state(self_obj) bwand DAM_CRIP_LEG_RIGHT) then begin \
                                        end                                           \
                                        else if (critter_state(self_obj) bwand DAM_BLIND) then begin \
                                        end                                           \
                                        else begin                                    \
                                           if (exp>0) then begin                      \
                                           exp_add(exp);                              \
                                           end                                        \
                                           if (msg>0) then begin                      \
                                           floater(self_obj,msg,COLOR_MSG_GREEN);     \
                                           end                                        \
                                           call uninjure_proc;                        \
                                           set_Medic_Quest;                           \
                                        end                                           \
                                     end                                              \
                                     end                                              \

// -----------------------------------------------------------------------
// Отравление персонажа хвостом радскорпиона
// -----------------------------------------------------------------------

/*
Опция отравления хвостом радскорпиона приводит к смерти персонажа через 3 секунды.
Для реализации необходимо в скрипте жертвы:
   + добавить таймер с записью: KillScorpTail(x);
   + добавить макрос UsedToCrit_Scorp в процедуру use_obj_on_p_proc;
   + добавить по необходимости блокировку диалога ScorpPoisonFlt (! эта опция есть в стандартном макросе диалога !)
*/

/*
   Комментарий: Рассматривались разные варианты тихого устранения персонажей:
      + отравление ядом радскорпиона или ядом, который нужно из него готовить на костре/верстаке
      + подлог специального сильно облученного предмета (урановая руда, отработанный уран, облученная монета)
      + применение отравленного пойла
      + подрыв штанов гранатой как сделано в Fallout 3
   При любомраскладе необходима унификация подхода. Чтобы принцип отравления был всюду одиннаков.
*/

#define ScorpUsedOpt(msg,timer)     display_msg(self_name+g_mstr(426));             \
                                    if (msg>0) then begin                           \
                                    floater(self_obj,msg,COLOR_MSG_RED);            \
                                    end                                             \
                                    item_remove(dude_obj, objUsedPid, 1)            \
                                    if (lvar_bit(LVAR_Self_Flags, bit_7) == 0) then begin \
                                    rm_timer_event(self_obj);                       \
                                    add_timer_event(self_obj, 30, timer);           \
                                    set_lvar_bit_on(LVAR_Self_Flags, bit_7);        \
                                    end                                             \

#define KillScorpTail(msg)          display_msg(self_name+g_mstr(random(427,430))); \
                                    if (msg>0) then begin                           \
                                    floater(self_obj,msg,COLOR_MSG_RED);            \
                                    end                                             \
                                    exp_add(100);                                   \
                                    set_lvar_bit_off(LVAR_Self_Flags, bit_7);       \
                                    set_SLAVA(-5)                                   \
                                    call destroy_p_proc;                            \
                                    kill_critter(self_obj,ANIM_fall_back_sf);       \

#define ScorpPoisonFlt              if (lvar_bit(LVAR_Self_Flags, bit_7) != 0) then begin \
                                    g_display_mstr(507);                        \
                                    g_floater(self_obj,508,COLOR_MSG_RED);      \
                                    end                                         \

// -----------------------------------------------------------------------
// Команда
// -----------------------------------------------------------------------

#define partyPidSelf                party_member_obj(self_PID)

#define partyPidSnc                 party_member_obj(PID_PARTY_ARTUR) // ученый в убежище 27
#define partyPidUdj                 party_member_obj(16777341) // юный техник из Гараж-Сити (ранее 16777261)
#define partyPidHrm                 party_member_obj(16777340) // узник в Эрмосильо
#define partyPidApc                 party_member_obj(16777342) // Последователь Апокалипсиса в Инферно (ранее 16777302)
#define partyPidBos                 party_member_obj(PID_PARTY_PALADIN_BIRKLY) // паладин Баркли в Инферно
#define partyPidAss                 party_member_obj(PID_PARTY_EL_ASSISTENTE) // робот на Вилле во фриплее
#define partyPidTsn                 party_member_obj(PID_PARTY_GHOUL_TWOSUN) // гуль - выживальщик в Тусоне
#define partyPidBnd                 party_member_obj(16777370) // бандит из погребов Виллы

#define partyPidMtn                 party_member_obj(PID_PARTY_GOMER) // Сияние: супермутант
#define partyPidMr1                 party_member_obj(PID_PARTY_GHOUL_FERNANDO) // Сияние: гуль мариачи 1
#define partyPidMr2                 party_member_obj(PID_PARTY_GHOUL_BEATRIS) // Сияние: гуль мариачи 2

#define partyRemoveAll              if (partyPidUdj!=0) then begin \
                                    party_remove(partyPidUdj);     \
                                    end                            \
                                    if (partyPidSnc!=0) then begin \
                                    party_remove(partyPidSnc);     \
                                    end                            \
                                    if (partyPidHrm!=0) then begin \
                                    party_remove(partyPidHrm);     \
                                    end                            \
                                    if (partyPidApc!=0) then begin \
                                    party_remove(partyPidApc);     \
                                    end                            \
                                    if (partyPidBos!=0) then begin \
                                    party_remove(partyPidBos);     \
                                    end                            \
                                    if (partyPidAss!=0) then begin \
                                    party_remove(partyPidAss);     \
                                    end                            \
                                    if (partyPidTsn!=0) then begin \
                                    party_remove(partyPidTsn);     \
                                    end                            \
                                    if (partyPidMtn!=0) then begin \
                                    party_remove(partyPidMtn);     \
                                    end                            \
                                    if (partyPidMr1!=0) then begin \
                                    party_remove(partyPidMr1);     \
                                    end                            \
                                    if (partyPidMr2!=0) then begin \
                                    party_remove(partyPidMr2);     \
                                    end                            \
                                    if (partyPidBnd!=0) then begin \
                                    party_remove(partyPidBnd);     \
                                    end                            \

//#define party_size                  (party_member_count(0) - global_var(GVAR_CAR_GOT_PLAYER))
#define party_size                  (party_member_count(0) - 1)

#define party_limit                 ((party_size >= (dude_charisma/2)) and (party_size>0))

// -----------------------------------------------------------------------
// talk_p_proc
// -----------------------------------------------------------------------

#define goBarter(x)                 gdialog_mod_barter(x)                           \

#define goBarterMod                 goBarter(local_var(LVAR_Barter_Mod))            \

#define setBarterMod                gdialog_set_barter_mod(local_var(LVAR_Barter_Mod)) \

//поднимает цены:
#define incBarterMod(x)             inc_local_var_amt(LVAR_Barter_Mod,x);           \
                                    setBarterMod                                    \

//снижает цены:
#define decBarterMod(x)             dec_local_var_amt(LVAR_Barter_Mod,x);           \
                                    setBarterMod                                    \

#define REACTION_CHARISMA           ((dude_charisma - self_charisma)*2)             \

#define getReaction                 (global_var(GVAR_PERSONAL_REACTION)+local_var(LVAR_Personal_Reaction_Bonus))           \

#define setReaction(x)              set_global_var(GVAR_PERSONAL_REACTION,0);                                              \
                                    set_global_var(GVAR_PERSONAL_REACTION,REACTION_CHARISMA);                              \
                                    if (TOWN_REP_VAR >0) then begin                                                        \
                                        if (KILL_TOWN_REP >0) then begin                                                   \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,global_var(TOWN_REP_VAR));               \
                                        end                                                                                \
                                        if (KILL_TOWN_REP <0) then begin                                                   \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,global_var(TOWN_REP_VAR));               \
                                        end                                                                                \
                                    end                                                                                    \
                                    if (x > 0) then begin                                                                  \
                                        if (get_SLAVA>=250) then begin                                                     \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                        if (get_SLAVA<=-250) then begin                                                    \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                        if has_rep_pelgrim then begin                                                      \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                        if has_rep_killer then begin                                                       \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                    end                                                                                    \
                                    else if (x < 0) then begin                                                             \
                                        if (get_SLAVA>=250) then begin                                                     \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                        if (get_SLAVA<=-250) then begin                                                    \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                        if has_rep_pelgrim then begin                                                      \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                        if has_rep_killer then begin                                                       \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                    end                                                                                    \
                                    if has_rep_childkiller then begin                                                      \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,20);                                     \
                                    end                                                                                    \
                                    if DudePerkHas(PERK_ghouling_charisma) then begin                                      \
                                        if type_kill(KILL_TYPE_ghoul) then begin                                           \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,80);                                     \
                                        end else begin                                                                     \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,20);                                     \
                                        end                                                                                \
                                    end                                                                                    \
                                    if DudePerkHas(PERK_karma_hollywood) then begin                                        \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                    end                                                                                    \
                                    if DudeTraitHas(TRAIT_espanol) then begin                                              \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,5);                                      \
                                    end                                                                                    \
                                    if (global_var(GVAR_PERSONAL_REACTION)>100) then begin                                 \
                                    set_global_var(GVAR_PERSONAL_REACTION,100);                                            \
                                    end                                                                                    \
                                    if (global_var(GVAR_PERSONAL_REACTION)<-100) then begin                                \
                                    set_global_var(GVAR_PERSONAL_REACTION,-100);                                           \
                                    end                                                                                    \
                                    set_local_var(LVAR_Flags,0);                                                           \
                                    if (global_var(GVAR_PERSONAL_REACTION)>=50) then begin                                 \
                                    set_local_var(LVAR_Flags,11);                                                          \
                                    end                                                                                    \
                                    if (global_var(GVAR_PERSONAL_REACTION)<=-25) then begin                                \
                                    set_local_var(LVAR_Flags,-11);                                                         \
                                    end                                                                                    \

/*
Прежний вариант:

#define setReaction(x)              set_global_var(GVAR_PERSONAL_REACTION,0);                                              \
                                    set_global_var(GVAR_PERSONAL_REACTION,REACTION_CHARISMA);                              \
                                    if (TOWN_REP_VAR >0) then begin                                                        \
                                        if (KILL_TOWN_REP >0) then begin                                                   \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,global_var(TOWN_REP_VAR));               \
                                        end                                                                                \
                                        if (KILL_TOWN_REP <0) then begin                                                   \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,global_var(TOWN_REP_VAR));               \
                                        end                                                                                \
                                    end                                                                                    \
                                    if (x > 0) then begin                                                                  \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,(get_SLAVA/20));                         \
                                        if has_rep_pelgrim then begin                                                      \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                        if has_rep_killer then begin                                                       \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                    end                                                                                    \
                                    else if (x < 0) then begin                                                             \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,(get_SLAVA/20));                         \
                                        if has_rep_pelgrim then begin                                                      \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                        if has_rep_killer then begin                                                       \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                        end                                                                                \
                                    end                                                                                    \
                                    if has_rep_childkiller then begin                                                      \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,20);                                     \
                                    end                                                                                    \
                                    if DudePerkHas(PERK_ghouling_charisma) then begin                                      \
                                        if type_kill(KILL_TYPE_ghoul) then begin                                           \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,80);                                     \
                                        end else begin                                                                     \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,20);                                     \
                                        end                                                                                \
                                    end                                                                                    \
                                    if DudePerkHas(PERK_karma_hollywood) then begin                                        \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,10);                                     \
                                    end                                                                                    \
                                    if (global_var(GVAR_PERSONAL_REACTION)>100) then begin                                                        \
                                    set_global_var(GVAR_PERSONAL_REACTION,100);                                            \
                                    end                                                                                    \
                                    if (global_var(GVAR_PERSONAL_REACTION)<-100) then begin                                                       \
                                    set_global_var(GVAR_PERSONAL_REACTION,-100);                                           \
                                    end                                                                                    \
*/

/*
Такая запись для setReaction проще, но Sfall Script Editor отказывается его компилировать, когда x=0.
                                    if (x != 0) then begin                                                                 \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,((get_SLAVA/20)*x));                     \
                                        if has_rep_pelgrim then begin                                                      \
                                        inc_global_var_amt(GVAR_PERSONAL_REACTION,(10*x));                                 \
                                        end                                                                                \
                                        if has_rep_killer then begin                                                       \
                                        dec_global_var_amt(GVAR_PERSONAL_REACTION,(10*x));                                 \
                                        end                                                                                \
                                    end                                                                                    \
*/

#define fracReaction(gvar,x)        if (global_var(gvar) > 0) then begin                                                   \
                                    inc_global_var_amt(GVAR_PERSONAL_REACTION,x);                                          \
                                    end                                                                                    \

#define setBonusReaction(x)         set_local_var(LVAR_Personal_Reaction_Bonus,local_var(LVAR_Personal_Reaction_Bonus)+(x)); \

#endif
