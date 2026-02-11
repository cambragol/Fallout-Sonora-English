#ifndef DEFINE_H
#define DEFINE_H

#include "..\headers\itempid.h"
#include "..\headers\command.h"
#include "..\headers\SCRIPTS.h"
#include "..\headers\GLOBAL.h"
#include "..\headers\MAPVAR.h"
#include "..\headers\REPPOINT.h"
#include "..\headers\maps.h"
#include "..\headers\teams.h"
#include "..\headers\ANIMCOMD.h"
#include "..\headers\Aipacket.h"
#include "..\headers\scenepid.h"
#include "..\headers\CRITRPID.h"
#include "..\headers\critters.h"

// ----------------------------------------------------------------------- //

// Map-Enter Proc subdefines
#define METARULE_TEST_FIRSTRUN    14
#define map_first_run metarule(METARULE_TEST_FIRSTRUN, 0)
#define METARULE_IS_LOADGAME      22
#define is_loading_game metarule(METARULE_IS_LOADGAME, 0)

// Тип действий в боевом режиме
#define COMBAT_SUBTYPE_WEAPON_USED    (1) // было использовано оружие (в скриптах F2 не используется)
#define COMBAT_SUBTYPE_HIT_SUCCEEDED  (2) // успешное попадание
#define COMBAT_SUBTYPE_SEQUENCING     (3) // проверяется боевая последовательность (в скриптах F2 не используется)
#define COMBAT_SUBTYPE_TURN           (4) // начало хода
#define COMBAT_SUBTYPE_NONCOM_TURN    (5) // в F2 используется только у любимцев Мельхиора

// ----------------------------------------------------------------------- //

// Видеоролики (описание см в файле cut_naming.txt в папке cut)
#define MOVIE_LOGO_STUDIO           0 // iplogo.mve
#define MOVIE_INTRO                 1 // intro.mve
#define MOVIE_ELDER                 2 // elder.mve
#define MOVIE_PLAZA                 3 // vsuit.mve
#define MOVIE_AFAILED               4 // afailed.mve
#define MOVIE_ADESTROY              5 // adestroy.mve
#define MOVIE_CAR                   6 // car.mve
#define MOVIE_PHOENIX_VISITED       7 // cartucci.mve
#define MOVIE_TIME_OUT              8 // timeout.mve
#define MOVIE_PHOENIX_DSTROY        9 // tanker.mve
#define MOVIE_ENCLAVE              10 // enclave.mve
#define MOVIE_PUERTO_DSTROY        11 // derrick.mve
#define MOVIE_ARTIMER_1            12 // artimer1.mve
#define MOVIE_ARTIMER_2            13 // artimer2.mve
#define MOVIE_ARTIMER_3            14 // artimer3.mve
#define MOVIE_ARTIMER_4            15 // artimer4.mve
#define MOVIE_CREDITS              16 // credits.mve

// ----------------------------------------------------------------------- //

/*
Примечание: некоторые цвета скрыты слэшем для того, чтобы не перегружали выпадающий список в программе SSE. К тому же эти цвета просто не нужны.
*/

//#define COLOR_MSG_WARNING         (-2) // подпись крупным шрифтом
//#define COLOR_MSG_SEQUENTIAL      (-1)
#define COLOR_MSG_NORMAL           (0)
//#define COLOR_MSG_BLACK            (1)
#define COLOR_MSG_RED              (2)
#define COLOR_MSG_GREEN            (3)
//#define COLOR_MSG_BLUE             (4)
#define COLOR_MSG_PURPLE           (5)
#define COLOR_MSG_NEAR_WHITE       (6)
#define COLOR_MSG_LIGHT_RED        (7)
#define COLOR_MSG_YELLOW           (8)
//#define COLOR_MSG_WHITE            (9)
#define COLOR_MSG_GREY            (10)
//#define COLOR_MSG_DARK_GREY       (11)
#define COLOR_MSG_LIGHT_GREY      (12)

#define mstr(x)                    message_str(NAME,x)
#define g_mstr(x)                  message_str(SCRIPT_INFO,x)
#define display_mstr(x)            display_msg(mstr(x))
#define g_display_mstr(x)          display_msg(g_mstr(x))
#define floater(who,x,color)       float_msg(who, mstr(x), color)
#define g_floater(who,x,color)     float_msg(who, g_mstr(x), color)
#define dude_floater_OK            g_floater(dude_obj, random(340,349), COLOR_MSG_NORMAL)
#define dude_floater_NON           g_floater(dude_obj, random(330,339), COLOR_MSG_NORMAL)

#define z_floater(who,x,color)           if dude_is_female then begin \
                                         floater(who, x+1000, color); \
                                         end else                     \
                                         floater(who, x, color)       \

#define x_display_mstr(msg,amnt)         if DudePerkHas(PERK_hint_look) then begin            \
                                         display_msg(mstr(msg+1)+amnt+mstr(msg+2)+mstr(msg)); \
                                         end else begin               \
                                         display_mstr(msg);           \
                                         end                          \

#define skill_display_mstr(msg,skill,x)  if DudePerkHas(PERK_hint_look) then begin      \
                                         display_msg(g_mstr(133)+g_mstr(110+skill)+" "+x+g_mstr(134)+mstr(msg)); \
                                         end else begin               \
                                         display_mstr(msg);           \
                                         end                          \

#define g_skill_display_mstr(msg,skill,x)  if DudePerkHas(PERK_hint_look) then begin      \
                                         display_msg(g_mstr(133)+g_mstr(110+skill)+" "+x+g_mstr(134)+g_mstr(msg)); \
                                         end else begin               \
                                         g_display_mstr(msg);         \
                                         end                          \

#define stat_display_mstr(msg,stat,x)    if DudePerkHas(PERK_hint_look) then begin      \
                                         display_msg(g_mstr(133)+g_mstr(150+stat)+" "+x+g_mstr(134)+mstr(msg)); \
                                         end else begin               \
                                         display_mstr(msg);           \
                                         end                          \

// Опции диалога
//#define start_dialogue(X,Y)        start_gdialog(-1,X,Y,-1,-1)

#define good_fidget                (1)
#define neutral_fidget             (4)
#define bad_fidget                 (7)

// Объемные головы
#define HEAD_VILLA_BABL            (1)  // Вилла: бабуля Адонсия
#define HEAD_RANGER_GENERAL        (2)  // Рейнджеры: верховный командир рейнджеров
#define HEAD_PHENIX_CULTBOSS       (3)  // Феникс: Властелин Феника
#define HEAD_TWO_SUN_BOSS          (4)  // ТуСан: лидер жестянщиков
#define HEAD_BOSS_DIXON            (5)  // Пуэрто: генерал Диксон, Братство Стали
#define HEAD_BOSS_POST             (6)  // Пуэрто: часовой на корабле Братства Стали
#define HEAD_BOSS_COMMANDER_A      (7)  // Пуэрто: полевой командир Братства Стали (фоном стена дома)
#define HEAD_BOSS_COMMANDER_B      (8)  // Пуэрто: полевой командир Братства Стали (фоном дневная пустошь)
#define HEAD_BOSS_COMMANDER_C      (9)  // Пуэрто: полевой командир Братства Стали (фоном ночная пустошь)
#define HEAD_BOSS_COMMANDER_D     (10)  // Пуэрто: полевой командир Братства Стали (фоном пещера)
#define HEAD_INIFERNO_GATE        (11)  // Инферно: супермутант-охранник в церкви
#define HEAD_JACALS_BOSS          (12)  // Шакалы: Бешенная Сука
#define HEAD_GARAGE_BOSS          (13)  // ГаражСити: мистер Коган начальник картеля старателей в Гараже (карта гаража)
#define HEAD_HERMO_POST_DAY       (14)  // Эрмосильо: постовой днем
#define HEAD_HERMO_POST_NIGHT     (15)  // Эрмосильо: постовой ночью
#define HEAD_GARAGE_BOSS_B        (16)  // ГаражСити: мистер Коган начальник картеля старателей в Гараже (карта сделки с караванов)
#define HEAD_FLAGSTAFF_BOSS       (17)  // Флагпул: начальник гарнизона
#define HEAD_GARAGE_LUCAS         (18)  // ГаражСити: Лукас на Заводе
#define HEAD_ENCOUNTER_PAUL       (19)  // заключенный на платформе супермутантов
#define HEAD_VILLA_BANDITS        (20)  // Вилла: бандит в подвале
#define HEAD_SANBRAHMIN_HEAD      (21)  // СанБрамин: верховный вождь
#define HEAD_RAIDERS_BOSS         (22)  // Рейдеры: главарь банды
#define HEAD_BOSS_MAURA           (23)  // Пуэрто: Маура

// Фон объемной головы
#define BACKGROUND_WASTELND        (1)    // WASTELND.FRM

// Реакция объемной головы
#define HEAD_REACTION_GOOD         (49)
#define HEAD_REACTION_NEUTRAL      (50)
#define HEAD_REACTION_BAD          (51)

// ----------------------------------------------------------------------- //

#define STAT_st                    (0) // Сила
#define STAT_pe                    (1) // Восприятие
#define STAT_en                    (2) // Выносливость
#define STAT_ch                    (3) // Харизма
#define STAT_iq                    (4) // Интеллект
#define STAT_ag                    (5) // Ловкость
#define STAT_lu                    (6) // Удача

#define dude_strength              (get_critter_stat(dude_obj,STAT_st))
#define dude_perception            (get_critter_stat(dude_obj,STAT_pe))
#define dude_endurance             (get_critter_stat(dude_obj,STAT_en))
#define dude_charisma              (get_critter_stat(dude_obj,STAT_ch))
#define dude_iq                    (get_critter_stat(dude_obj,STAT_iq))
#define dude_agility               (get_critter_stat(dude_obj,STAT_ag))
#define dude_luck                  (get_critter_stat(dude_obj,STAT_lu))

#define self_strength              (get_critter_stat(self_obj,STAT_st))
#define self_perception            (get_critter_stat(self_obj,STAT_pe))
#define self_endurance             (get_critter_stat(self_obj,STAT_en))
#define self_charisma              (get_critter_stat(self_obj,STAT_ch))
#define self_iq                    (get_critter_stat(self_obj,STAT_iq))
#define self_agility               (get_critter_stat(self_obj,STAT_ag))
#define self_luck                  (get_critter_stat(self_obj,STAT_lu))

// ----------------------------------------------------------------------- //

#define GENDER_MALE                (0)
#define GENDER_FEMALE              (1)

#define STAT_max_hp                (7)
#define STAT_max_hit_points        (7)
#define STAT_max_move_points       (8)
#define STAT_ac                    (9)
#define STAT_unused                (10)
#define STAT_melee_dmg             (11)
#define STAT_carry_amt             (12)
#define STAT_sequence              (13)
#define STAT_heal_rate             (14)
#define STAT_crit_chance           (15)
#define STAT_better_crit           (16)
#define STAT_dmg_thresh            (17)
#define STAT_dmg_thresh_laser      (18)
#define STAT_dmg_thresh_fire       (19)
#define STAT_dmg_thresh_plasma     (20)
#define STAT_dmg_thresh_electrical (21)
#define STAT_dmg_thresh_emp        (22)
#define STAT_dmg_thresh_explosion  (23)
#define STAT_dmg_resist            (24)
#define STAT_dmg_resist_laser      (25)
#define STAT_dmg_resist_fire       (26)
#define STAT_dmg_resist_plasma     (27)
#define STAT_dmg_resist_electrical (28)
#define STAT_dmg_resist_emp        (29)
#define STAT_dmg_resist_explosion  (30)
#define STAT_rad_resist            (31)
#define STAT_poison_resist         (32)
#define STAT_age                   (33)
#define STAT_gender                (34)
#define STAT_current_hp            (35)
#define STAT_current_poison        (36)
#define STAT_current_rad           (37)
#define STAT_real_max_stat         (38)

#define dude_name                  obj_name(dude_obj)
#define dude_is_male               (get_critter_stat(dude_obj,STAT_gender) == GENDER_MALE)
#define dude_is_female             (get_critter_stat(dude_obj,STAT_gender) == GENDER_FEMALE)
#define dude_cur_hits              get_critter_stat(dude_obj,STAT_current_hp)
#define dude_max_hits              get_critter_stat(dude_obj,STAT_max_hp)
#define dude_age                   get_critter_stat(dude_obj,STAT_age)
#define dude_weight                critter_weight(dude_obj)

#define self_name                  obj_name(self_obj)
#define self_is_male               (get_critter_stat(self_obj,STAT_gender) == GENDER_MALE)
#define self_is_female             (get_critter_stat(self_obj,STAT_gender) == GENDER_FEMALE)
#define self_cur_hits              get_critter_stat(self_obj,STAT_current_hp)
#define self_max_hits              get_critter_stat(self_obj,STAT_max_hp)

// Состояние криттера
#define CRITTER_IS_NORMAL          (0)
#define CRITTER_IS_DEAD            (1)
#define CRITTER_IS_PRONE           (2)

#define is_critter_normal(who)     (critter_state(who) bwand CRITTER_IS_NORMAL)
#define is_critter_dead(who)       (critter_state(who) bwand CRITTER_IS_DEAD)
#define is_critter_prone(who)      (critter_state(who) bwand CRITTER_IS_PRONE)

// Слоты инвентаря
#define INVEN_TYPE_INV_COUNT       (-2)
#define INVEN_TYPE_WORN            (0)
#define INVEN_TYPE_RIGHT_HAND      (1)
#define INVEN_TYPE_LEFT_HAND       (2)

#define inven_count(who)           critter_inven_obj(who,INVEN_TYPE_INV_COUNT)

#define inven_armor(who)           critter_inven_obj(who,INVEN_TYPE_WORN)

#define inven_hand_R(who)          critter_inven_obj(who,INVEN_TYPE_RIGHT_HAND)

#define inven_hand_L(who)          critter_inven_obj(who,INVEN_TYPE_LEFT_HAND)

// ----------------------------------------------------------------------- //

#define PCSTAT_unspent_skill_points         (0)
#define PCSTAT_level                        (1)
#define PCSTAT_experience                   (2)
#define PCSTAT_reputation                   (3)
#define PCSTAT_karma                        (4)
#define PCSTAT_max_pc_stat                  (5)

#define dude_level                          (get_pc_stat(PCSTAT_level))

// ----------------------------------------------------------------------- //

#define SKILL_SMALL_GUNS                    (0)  // легкое
#define SKILL_BIG_GUNS                      (1)  // тяжелое
#define SKILL_ENERGY_WEAPONS                (2)  // энерго
#define SKILL_UNARMED_COMBAT                (3)  // без оружия
#define SKILL_MELEE                         (4)  // холодное
#define SKILL_THROWING                      (5)  // метание
#define SKILL_FIRST_AID                     (6)  // 1я помощь
#define SKILL_DOCTOR                        (7)  // доктор
#define SKILL_SNEAK                         (8)  // скрытность
#define SKILL_LOCKPICK                      (9)  // взлом
#define SKILL_STEAL                         (10) // кража
#define SKILL_TRAPS                         (11) // ловушки
#define SKILL_SCIENCE                       (12) // наука
#define SKILL_REPAIR                        (13) // ремонт
#define SKILL_CONVERSANT                    (14) // красноречие
#define SKILL_BARTER                        (15) // торговля
#define SKILL_GAMBLING                      (16) // игры
#define SKILL_SCOUT                         (17) // выживание

#define skill_up(skill,x)                   display_msg(g_mstr(130)+g_mstr(110+skill)+g_mstr(131)+x+g_mstr(132)); \
                                            critter_mod_skill(dude_obj, skill, x) \

#define dude_is_sneaking                    (using_skill(dude_obj,SKILL_SNEAK) == true) \

#define dude_skill(skill,lvl)               (has_skill(dude_obj, skill) >= lvl) \

// ----------------------------------------------------------------------- //

// Трейт или перк:
#define TRAIT_PERK                           (0)
#define TRAIT_OBJECT                         (1)
#define TRAIT_TRAIT                          (2)

// Перки
#define PERK_bonus_awareness                 (0)
#define PERK_bonus_hth_attacks               (1)
#define PERK_bonus_hth_damage                (2)
#define PERK_bonus_move                      (3)
#define PERK_bonus_ranged_damage             (4)
#define PERK_bonus_rate_of_fire              (5)
#define PERK_earlier_sequence                (6)
#define PERK_faster_healing                  (7)
#define PERK_more_criticals                  (8)
#define PERK_night_vision                    (9)
#define PERK_vaquero                        (10)
#define PERK_rad_resistance                 (11)
#define PERK_toughness                      (12)
#define PERK_strong_back                    (13)
#define PERK_sharpshooter                   (14)
#define PERK_silent_running                 (15)
#define PERK_survivalist                    (16)
#define PERK_master_trader                  (17)
#define PERK_educated                       (18)
#define PERK_healer                         (19)
#define PERK_marauder                       (20)
#define PERK_better_criticals               (21)
#define PERK_empathy                        (22)
#define PERK_slayer                         (23)
#define PERK_sniper                         (24)
#define PERK_silent_death                   (25)
#define PERK_action_boy                     (26)
#define PERK_RESERV_27                      (27)
#define PERK_lifegiver                      (28)
#define PERK_dodger                         (29)
#define PERK_snakeater                      (30)
#define PERK_master_computer                (31)
#define PERK_medic                          (32)
#define PERK_master_thief                   (33)
#define PERK_speaker                        (34)
#define PERK_heave_ho                       (35)
#define PERK_baiker                         (36)
#define PERK_pickpocket                     (37)
#define PERK_ghost                          (38)
#define PERK_forgotten_hero                 (39)
#define PERK_RESERV_40                      (40)
#define PERK_game_dont_finish               (41)
#define PERK_flower_child                   (42)
#define PERK_pathfinder                     (43)
#define PERK_ghouling_start                 (44) // В Fallout 2 это PERK_animal_friend
#define PERK_scout                          (45)
#define PERK_mysterious_stranger            (46)
#define PERK_ranger                         (47)
#define PERK_quick_pockets                  (48)
#define PERK_smooth_talker                  (49)
#define PERK_swift_learner                  (50)
#define PERK_tag                            (51)
#define PERK_mutate                         (52)
//!!! Perks 53-72 are for engine use and not available to the player
#define PERK_RESERV_73                      (73)
#define PERK_dermal_armor                   (74)
#define PERK_dermal_enhancement             (75)
#define PERK_phoenix_armor                  (76)
#define PERK_ghouling_charisma              (77) // В Fallout 2 это PERK_phoenix_enhancement_perk
#define PERK_ghouling_fiziology             (78) // В Fallout 2 это PERK_adrenaline_rush_perk
#define PERK_adrenaline_rush                (79)
#define PERK_wasteland_school               (80)
#define PERK_hint_look                      (81)
#define PERK_demolition_expert              (82)
#define PERK_gambler                        (83)
#define PERK_gain_strength                  (84)
#define PERK_gain_perception                (85)
#define PERK_gain_endurance                 (86)
#define PERK_gain_charisma                  (87)
#define PERK_gain_intelligence              (88)
#define PERK_gain_agility                   (89)
#define PERK_gain_luck                      (90)
#define PERK_harmless                       (91)
#define PERK_here_and_now                   (92)
#define PERK_hth_evade                      (93)
#define PERK_Sonora_expert                  (94)
#define PERK_karma_hollywood                (95)
#define PERK_light_step                     (96)
#define PERK_living_anatomy                 (97)
#define PERK_intimidation                   (98)
#define PERK_negotiator                     (99)
#define PERK_pack_rat                      (100)
#define PERK_pyromaniac                    (101)
#define PERK_quick_recovery                (102)
#define PERK_salesman                      (103)
#define PERK_stonewall                     (104)
#define PERK_thief                         (105)
#define PERK_weapon_handling               (106)
#define PERK_old_medical_training          (107)
#define PERK_alcohol_hp_bonus1             (108)
#define PERK_alcohol_hp_bonus2             (109)
#define PERK_alcohol_hp_neg1               (110)
#define PERK_alcohol_hp_neg2               (111)
#define PERK_autodoc_hp_bonus1             (112)
#define PERK_autodoc_hp_bonus2             (113)
#define PERK_radiactiv_hp_I                (114)
#define PERK_radiactiv_hp_II               (115)
#define PERK_RESERV_116                    (116)
#define PERK_weapon_knockout               (117)
#define PERK_RESERV_118                    (118)

// ----------------------------------------------------------------------- //

#define TRAIT_fast_metabolism              (0) // Ускор. метаболизм
#define TRAIT_bruiser                      (1) // Хулиган
#define TRAIT_small_frame                  (2) // Миниатюрный
#define TRAIT_one_hander                   (3) // Однорукий
#define TRAIT_finesse                      (4) // Точность
#define TRAIT_kamikaze                     (5) // Камикадзе
#define TRAIT_heavy_handed                 (6) // Тяжелая рука
#define TRAIT_fast_shot                    (7) // Стрельба навскидку
#define TRAIT_espanol                      (8) // Горячая кровь
#define TRAIT_jinxed                       (9) // Порченый
#define TRAIT_good_natured                (10) // Добрая душа
#define TRAIT_drug_addict                 (11) // Чувств. к химии
#define TRAIT_drug_resistant              (12) // Сопрот. химии
#define TRAIT_Villa_tradition             (13) // Традиции Виллы
#define TRAIT_skilled                     (14) // Тренированный
#define TRAIT_gifted                      (15) // Одаренный

// Свойства объектов
#define OBJECT_AI_PACKET                   (5)
#define OBJECT_TEAM_NUM                    (6)
#define OBJECT_CUR_ROT                    (10)
#define OBJECT_VISIBILITY                (666)
#define OBJECT_CUR_WEIGHT                (669)

#define source_PID                obj_pid(source_obj)

#define self_PID                  obj_pid(self_obj)

#define self_TEAM                 has_trait(TRAIT_OBJECT, self_obj, OBJECT_TEAM_NUM)

#define self_AI                   has_trait(TRAIT_OBJECT, self_obj, OBJECT_AI_PACKET)

#define self_visible              visible(self_obj)

#define visible(WHO)              obj_is_visible_flag(WHO)

#define obj_is_visible_flag(WHO)  has_trait(TRAIT_OBJECT, WHO, OBJECT_VISIBILITY)

#define obj_get_rot(obj)          has_trait(TRAIT_OBJECT, obj, OBJECT_CUR_ROT)

#define who_carry_amount(x)       has_trait(TRAIT_OBJECT, x, OBJECT_CUR_WEIGHT)

#define DudeTraitHas(x)           (has_trait(TRAIT_TRAIT, dude_obj, x) > 0)

#define DudePerkHas(x)            (has_trait(TRAIT_PERK, dude_obj, x) > 0)

// ----------------------------------------------------------------------- //

/* Данные прототипов */

//--- Инвентарь
#define item_type_armor        (0)
#define item_type_container    (1)
#define item_type_drug         (2)
#define item_type_weapon       (3)
#define item_type_ammo         (4)
#define item_type_misc_item    (5)
#define item_type_key_item     (6)

//--- общее
#define it_pid                 (0)
#define it_name                (1)
#define it_description         (2)
#define it_fid                 (3)
#define it_light_distance      (4)
#define it_light_intensity     (5)
#define it_flags               (6)
#define it_flags_ext           (7)
#define it_sid                 (8)
#define it_type                (9)
#define it_data               (10)
#define it_material           (11)
#define it_size               (12)
#define it_weight             (13)
#define it_cost               (14)
#define it_inv_fid            (15)
#define it_weapon_range      (555)

//--- криттер
#define cr_pid                 (0)
#define cr_name                (1)
#define cr_description         (2)
#define cr_fid                 (3)
#define cr_light_distance      (4)
#define cr_light_intensity     (5)
#define cr_flags               (6)
#define cr_flags_ext           (7)
#define cr_sid                 (8)
#define cr_data                (9)
#define cr_head_fid           (10)
#define cr_body_type          (11)

//--- тип тела криттера
#define CR_BODY_BIPED           0
#define CR_BODY_QUADRUPED       1
#define CR_BODY_ROBOTIC         2

//--- окружение
#define sc_pid                 (0)
#define sc_name                (1)
#define sc_description         (2)
#define sc_fid                 (3)
#define sc_light_distance      (4)
#define sc_light_intensity     (5)
#define sc_flags               (6)
#define sc_flags_ext           (7)
#define sc_sid                 (8)
#define sc_type                (9)
#define sc_data               (10)
#define sc_material           (11)

//--- стена
#define wa_pid                 (0)
#define wa_name                (1)
#define wa_description         (2)
#define wa_fid                 (3)
#define wa_light_distance      (4)
#define wa_light_intensity     (5)
#define wa_flags               (6)
#define wa_flags_ext           (7)
#define wa_sid                 (8)
#define wa_material            (9)

//--- misc
#define mi_pid                 (0)
#define mi_name                (1)
#define mi_description         (2)
#define mi_fid                 (3)
#define mi_light_distance      (4)
#define mi_light_intensity     (5)
#define mi_flags               (6)
#define mi_flags_ext           (7)

#define SELF_IS_UNLOCKED       (obj_is_locked(self_obj) == 0)

#define SELF_IS_LOCKED         (obj_is_locked(self_obj) != 0)

#define SELF_IS_CLOSED         (obj_is_open(self_obj) == 0)

#define SELF_IS_OPEN           (obj_is_open(self_obj) != 0)

// ----------------------------------------------------------------------- //

/* Combat Flags */

#define DAM_KNOCKED_OUT                      1
#define DAM_KNOCKED_DOWN                     2
#define DAM_CRIP_LEG_LEFT                    4
#define DAM_CRIP_LEG_RIGHT                   8
#define DAM_CRIP_ARM_LEFT                   16
#define DAM_CRIP_ARM_RIGHT                  32
#define DAM_BLIND                           64
#define DAM_DEAD                           128
#define DAM_HIT                            256
#define DAM_CRITICAL                       512
#define DAM_ON_FIRE                       1024
#define DAM_BYPASS                        2048
#define DAM_EXPLODE                       4096
#define DAM_DESTROY                       8192
#define DAM_DROP                         16384
#define DAM_LOSE_TURN                    32768
#define DAM_HIT_SELF                     65536
#define DAM_LOSE_AMMO                   131072
#define DAM_DUD                         262144
#define DAM_HURT_SELF                   524288
#define DAM_RANDOM_HIT                 1048576
#define DAM_CRIP_RANDOM                2097152
#define DAM_BACKWASH                   4194304
#define DAM_PERFORM_REVERSE            8388608

#define critter_uninjure(WHO, FLAGS)   critter_injure(WHO, (FLAGS bwor DAM_PERFORM_REVERSE))

#define dude_is_crippled               ((critter_state(dude_obj) bwand DAM_CRIP_LEG_LEFT) or \
                                        (critter_state(dude_obj) bwand DAM_CRIP_LEG_RIGHT) or \
                                        (critter_state(dude_obj) bwand DAM_CRIP_ARM_LEFT) or \
                                        (critter_state(dude_obj) bwand DAM_CRIP_ARM_RIGHT) or \
                                        (critter_state(dude_obj) bwand DAM_BLIND))

#define party_is_crippled(crit)        ((critter_state(crit) bwand DAM_CRIP_LEG_LEFT) or \
                                        (critter_state(crit) bwand DAM_CRIP_LEG_RIGHT) or \
                                        (critter_state(crit) bwand DAM_CRIP_ARM_LEFT) or \
                                        (critter_state(crit) bwand DAM_CRIP_ARM_RIGHT) or \
                                        (critter_state(crit) bwand DAM_BLIND))

#define DMG_normal_dam                 0
#define DMG_laser                      1
#define DMG_fire                       2
#define DMG_plasma                     3
#define DMG_electrical                 4
#define DMG_emp                        5
#define DMG_explosion                  6

#define DMG_BYPASS_ARMOR              (256)
#define DMG_NOANIMATE                 (512)

#define critter_damage(WHO,AMT)       critter_dmg(WHO,AMT,DMG_normal_dam)

/* Kill Critter Equates */
#define KILL_DONT_LEAVE_BODY          (0)
#define KILL_LEAVE_BODY               (1)
#define KILL_LEAVE_NV_BODY            (2)

/* Kill Types names */
#define KILL_TYPE_men                  0
#define KILL_TYPE_women                1
#define KILL_TYPE_children             2
#define KILL_TYPE_super_mutant         3
#define KILL_TYPE_ghoul                4
#define KILL_TYPE_brahmin              5
#define KILL_TYPE_radscorpion          6
#define KILL_TYPE_rat                  7
#define KILL_TYPE_floater              8
#define KILL_TYPE_centaur              9
#define KILL_TYPE_robot               10
#define KILL_TYPE_dog                 11
#define KILL_TYPE_manti               12
#define KILL_TYPE_deathclaw           13
#define KILL_TYPE_plant               14
#define KILL_TYPE_scolopendra         15
#define KILL_TYPE_alien               16
#define KILL_TYPE_giant_ant           17
#define KILL_TYPE_big_boss            18

#define type_kill(body)               (critter_kill_type(self_obj) == body) \

#define type_kill_source(body)        (critter_kill_type(source_obj) == body) \

// ----------------------------------------------------------------------- //

/* Метаданные */

//Сигнал для завершения игры
#define signal_end_game               metarule(13, 0)

//Вызов лифта:
#define elevator(X)                   metarule(15, X)

#define ELEV_BOS1                (0)  // Brotherhood of Steel main elevator
#define ELEV_BOS2                (1)  // Brotherhood of Steel surface elevator
#define ELEV_MASTR1              (2)  // Master's upper-level elevator
#define ELEV_MASTR2              (3)  // Master's lower-level elevator
#define ELEV_MILB1               (4)  // Military Base upper-level elevator
#define ELEV_MILB2               (5)  // Military Base lower-level elevator
#define ELEV_GLOW1               (6)  // Glow Elevator upper
#define ELEV_GLOW2               (7)  // Glow elevator lower
#define ELEV_VAULT               (8)  // Vault13 elevator
#define ELEV_NECVLT              (9)  // Necropolis elevator
#define ELEV_SIERRA1             (10) // Sierra Elev 1 (1-2-3)
#define ELEV_SIERRA2             (11) // Sierra Elev 2 (3-4)
#define ELEV_SIERRAS             (12) // Sierra Service Elev (1-2-3-4)

//Число партийцев в партии
#define party_member_count(X)    metarule(16, X)
#define DONT_LIST_HIDDEN_MEMBERS (0)
#define LIST_HIDDEN_MEMBERS      (1)

//Находится ли криттер под действием наркотиков
#define drug_influence(WHO)      metarule(18, WHO)

//Выбран ли навык как основной
#define is_skill_tagged(SKILL)   metarule(40, SKILL)

//Команда криттеру бросить вещи под ноги
#define obj_drop_everything(WHO) metarule(42, WHO)

//Команда криттеру убрать вещи из рук
#define inven_unwield(WHO)       metarule(43, WHO)

//Проверка фильтра мата
#define language_filter_is_on    metarule(47, 0)

//Проверка уровня насилия
#define violence_filter_setting  metarule(48, 0)
#define VLNCLVL_NONE    0
#define VLNCLVL_MIN     1
#define VLNCLVL_NORMAL  2
#define VLNCLVL_MAX     3

//Возврат типа повреждений, нанесенных указанным оружием
#define weapon_dmg_type(WEAP)    metarule(49, WEAP)

//Проверка возможности торговать с криттером
#define critter_can_barter(WHO) metarule(50, WHO)

//Возвращает тип криттера по видам убитых
#define critter_kill_type(WHO)  metarule(51, WHO)

//Очистка событий подвешанных на таймер
#define rm_fixed_timer_event(WHO,FIXED_VAL) metarule3(100,WHO,FIXED_VAL,0)

//Число убитых игроком криттеров
#define player_kill_count(TYPE)    metarule3(103,TYPE,0,0)
// Off/On states for mark_map_entrance_state
#define OFFSTATE  0
#define ONSTATE   1

#define mark_map_entrance_state(MAPIDX,STATE)            metarule3(104,MAPIDX,STATE,-1)
#define mark_map_entrance_elev_state(MAPIDX,ELEV,STATE)  metarule3(104,MAPIDX,STATE,ELEV)
// wmSubTileVisitInfo Types:
#define UNKNOWNTILETYPE       0
#define KNOWNTILETYPE         1
#define VISITEDTILETYPE       2

//Указатель на следующего криттера на заданном гексе
#define tile_get_next_critter(tile, elevation, lastCritter)   metarule3(106, tile, elevation, lastCritter)

//Изменить базовый FID
#define art_change_fid_num(WHO, NUM)         metarule3(107,WHO,NUM,0)

//Центрировать экран
#define tile_set_center(tileNum)             metarule3(108,tileNum,0,0)

//?
#define chem_use_level(WHO)                  metarule3(109,WHO,0,0)

//?
#define map_get_load_area                    metarule3(111,0,0,0)

//-------------------------
//--- Метаданные по машине:

//Возвращение номера города с текущим местоположением автомобиля
#define car_current_town                     metarule(30, 0)

//Посадить команду ГГ в машину и выйти на карту мира
#define car_give_to_party                    metarule(31, 0)

//Заправить машину топливом
#define car_give_gas(AMOUNT)                 metarule(32, AMOUNT)

//Изменить максимальный объем груза для машины
#define set_car_carry_amount(VALUE)          metarule(52, VALUE)

//Показывает максимальный объем груза для машины
#define car_carry_amount                     metarule(53, 0)

//Машина без топлива (0 - машина заряжена >0, 1 - машина без топлива)
#define car_out_of_fuel                      metarule3(110,0,0,0)

//-------------------------
//--- Метаданные по карте мира:

//Статус локации
#define town_known(X)                        metarule(17, X)

//Статус карты
#define map_is_known(X)                      metarule(19, X)

//Помечает тайл карты мира как посещенный
#define mark_world_subtile_visited(XPOS,YPOS,RADIUS) metarule3(101,XPOS,YPOS,RADIUS)

//Состояние тайла карты мира
#define wm_get_subtile_state(XPOS,YPOS)      metarule3(105,XPOS,YPOS,0)

//Текущая координата по х на карте мира
#define worldmap_xpos                        metarule(44, 0)

//Текущая координата по y на карте мира
#define worldmap_ypos                        metarule(45, 0)

//Текущий город
#define cur_town                             metarule(46, 0)

//-------------------------

#define INVEN_CMD_INDEX_PTR                  (13)

#define inven_ptr(WHO,WHERE)                 inven_cmds(WHO,INVEN_CMD_INDEX_PTR,WHERE)

#define wield_obj(itemObj)                   wield_obj_critter(self_obj,itemObj)

// ----------------------------------------------------------------------- //

/* Системные настройки */

// gsound_character_types
#define snd_human                  (0)
#define snd_monster                (1)

// gsound_character_extra
#define snd_unused                 (0)
#define snd_knock_down             (1)
#define snd_pass_out               (2)
#define snd_die                    (3)
#define snd_contact                (4)

// gsound_sfx_action
#define snd_active                 (0)
#define snd_passive                (1)

// gsound_sfx_weapon_action_type
#define snd_weapon_ready           (0)
#define snd_weapon_attack          (1)
#define snd_weapon_out             (2)
#define snd_weapon_ammo_flying     (3)
#define snd_weapon_hitting         (4)

// gsound_sfx_scenery_action
#define snd_open                   (0)
#define snd_close                  (1)
#define snd_locked                 (2)
#define snd_unlocked               (3)
#define snd_used                   (4)

// hit_mode
#define hit_left_weapon_primary    (0)
#define hit_left_weapon_secondary  (1)
#define hit_right_weapon_primary   (2)
#define hit_right_weapon_secondary (3)
#define hit_punch                  (4)
#define hit_kick                   (5)
#define hit_left_weapon_reload     (6)
#define hit_right_weapon_reload    (7)

#define LEVEL_DIFCLTY_MINIMUM      (difficulty_level == 0) \

#define LEVEL_DIFCLTY_NORMAL       (difficulty_level == 1) \

#define LEVEL_DIFCLTY_TOOGH        (difficulty_level == 2) \

#define COMBAT_DIFCLTY_MINIMUM     (combat_difficulty == 0) \

#define COMBAT_DIFCLTY_NORMAL      (combat_difficulty == 1) \

#define COMBAT_DIFCLTY_TOOGH       (combat_difficulty == 2) \

// ----------------------------------------------------------------------- //

/* Затухание экрана */
#define ONE_GAME_SECOND             (10)
#define ONE_GAME_MINUTE             (60*ONE_GAME_SECOND)
#define ONE_GAME_HOUR               (60*ONE_GAME_MINUTE)
#define ONE_GAME_DAY                (24*ONE_GAME_HOUR)
#define ONE_GAME_WEEK               (7*ONE_GAME_DAY)
#define ONE_GAME_MONTH              (30*ONE_GAME_DAY)

#define PLAY_FADE                   gfade_out(ONE_GAME_SECOND); \
                                    gfade_in(ONE_GAME_SECOND);  \

/* Результаты бросков случайных чисел для функции do_check */
#define ROLL_CRITICAL_FAILURE       0
#define ROLL_FAILURE                1
#define ROLL_SUCCESS                2
#define ROLL_CRITICAL_SUCCESS       3

// ----------------------------------------------------------------------- //

/* Битовые маски */
#define bit_1                       (1)
#define bit_2                       (2)
#define bit_3                       (4)
#define bit_4                       (8)
#define bit_5                       (16)
#define bit_6                       (32)
#define bit_7                       (64)
#define bit_8                       (128)
#define bit_9                       (256)
#define bit_10                      (512)
#define bit_11                      (1024)
#define bit_12                      (2048)
#define bit_13                      (4096)
#define bit_14                      (8192)
#define bit_15                      (16384)
#define bit_16                      (32768)
#define bit_17                      (65536)
#define bit_18                      (131072)
#define bit_19                      (262144)
#define bit_20                      (524288)
#define bit_21                      (1048576)
#define bit_22                      (2097152)
#define bit_23                      (4194304)
#define bit_24                      (8388608)
#define bit_25                      (16777216)
#define bit_26                      (33554432)
#define bit_27                      (67108864)
#define bit_28                      (134217728)
#define bit_29                      (268435456)
#define bit_30                      (536870912)
#define bit_31                      (1073741824)
#define bit_32                      (-2147483648)
#define bit_ALL                     (-1)

// ----------------------------------------------------------------------- //

#define exp_add(x)                  exp_add_msg(x,SCRIPT_INFO,200,201) \

#define exp_add_answr(x)            exp_add_msg(x,SCRIPT_INFO,200,202) \

#define exp_add_msg(x,scr,msgA,msgB)    set_global_var(GVAR_EXPOINT_CHECK,global_var(GVAR_EXPOINT_CHECK)+x); \
                                    if (DudeTraitHas(TRAIT_Villa_tradition) and DudePerkHas(PERK_swift_learner)) then begin \
                                    set_global_var(GVAR_EXPOINT_CHECK,x-((x*(20-(5*has_trait(TRAIT_PERK, dude_obj, PERK_swift_learner))))/100)); \
                                    end                                                       \
                                    else if DudeTraitHas(TRAIT_Villa_tradition) then begin    \
                                    set_global_var(GVAR_EXPOINT_CHECK,x-((x*20)/100));        \
                                    end                                                       \
                                    else if DudePerkHas(PERK_swift_learner) then begin        \
                                    inc_global_var_amt(GVAR_EXPOINT_CHECK,(x*(5*has_trait(TRAIT_PERK, dude_obj, PERK_swift_learner)))/100); \
                                    end                                                       \
                                    if (global_var(GVAR_EXPOINT_CHECK)>0) then begin          \
                                    give_exp_points(global_var(GVAR_EXPOINT_CHECK));          \
                                    display_msg(message_str(scr,msgA)+global_var(GVAR_EXPOINT_CHECK)+message_str(scr,msgB)); \
                                    end                                                       \
                                    set_global_var(GVAR_EXPOINT_CHECK,0)


// ----------------------------------------------------------------------- //

#endif
