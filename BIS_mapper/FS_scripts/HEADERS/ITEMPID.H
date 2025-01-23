#ifndef _ITEMPID_H_DEFINED
#define _ITEMPID_H_DEFINED

/********************************

--- Содержание:

SONORA Ammo
SONORA Weapon
SONORA Armor
SONORA Medical and Food
SONORA Books
SONORA Keys
SONORA Documents
SONORA Quest Items
SONORA Misc Items
SONORA Conteiners
SONORA Tools
SONORA Active Items

*********************************/

/*****************************************************************
***************        SONORA Ammo     ***************************
******************************************************************/

#define PID_AMMO_ENERGY_CELL                (1) // не используется в геймплее
#define PID_AMMO_MICRO_FUSION_CELL          (2)
#define PID_AMMO_22_LR                      (3) // в пачке 5 патронов!
#define PID_AMMO_9_MM                       (4)
#define PID_AMMO_10_MM                      (5)
#define PID_AMMO_10_MM_NSP                  (6)
#define PID_AMMO_44_MAGNUM                  (7)
#define PID_AMMO_50_AE                      (8)
#define PID_AMMO_5_MM                       (9) // в пачке 5 патронов!
#define PID_AMMO_308                        (10)
#define PID_AMMO_SHOTGUN_SHELLS             (11)
#define PID_AMMO_SHOTGUN_SHELLS_BULLET      (12)
#define PID_AMMO_40_MM                      (13)
#define PID_AMMO_SIGNAL_A                   (14)
#define PID_AMMO_SIGNAL_B                   (15)
#define PID_AMMO_SIGNAL_C                   (16)
#define PID_AMMO_TANK                       (185)

/*****************************************************************
***************        SONORA Weapon     *************************
******************************************************************/

//Метательное
#define PID_W_BROCK                         (18)
#define PID_W_THROWING_KNIFE                (19)
#define PID_W_GRENADE_FRAG                  (20)
#define PID_W_GRENADE_PLASMA                (21)
#define PID_W_GRENADE_PULSE                 (22)
#define PID_W_GRENADE_NUKE                  (23)
#define PID_W_GRENADE_MOLOTOV               (159)

//Рукопашное
#define PID_W_KNUCKLES_SPORE_PLANT          (55) // невидимое оружие хищных растений
#define PID_W_KNUCKLES_BRASS                (126)
#define PID_W_KNUCKLES_SPIKED               (127)
#define PID_W_KNUCKLES_THORNS               (128)
#define PID_W_KNUCKLES_PNEUMATIC            (129)
#define PID_W_KNUCKLES_SHOCKER              (130)
#define PID_W_POWER_FIST                    (131)
#define PID_W_IMPULSE_FIST                  (460)

//Холодное
#define PID_W_KNIFE                         (132)
#define PID_W_COMBAT_KNIFE                  (133)
#define PID_W_MACHETE                       (134)
#define PID_W_RIPPER                        (135)
#define PID_W_ATOMIC_CUTTER                 (136)
#define PID_W_SPEAR                         (137)
#define PID_W_SPEAR_PNEUMATIC               (138)
#define PID_W_SPEAR_SHOCKER                 (139)
#define PID_W_SPEAR_COA                     (174)
#define PID_W_SPEAR_MOP                     (180)
#define PID_W_CLUB                          (140)
#define PID_W_CROWBAR                       (141)
#define PID_W_CATTLE_PROD_A                 (142)
#define PID_W_CATTLE_PROD_B                 (143)
#define PID_W_SLEDGEHAMMER                  (145)
#define PID_W_HAMMER                        (146)
#define PID_W_SUPER_SLEDGE                  (147)
#define PID_W_HIKING_HATCHET                (190)

//Огнестрельное легкое
#define PID_W_REVOLVER_OLD                  (148)
#define PID_W_REVOLVER_POLICE               (149)
#define PID_W_REVOLVER_COMBAT               (150)
#define PID_W_SIGNAL_PISTOL                 (151)
#define PID_W_SIGNAL_PISTOL_UP              (497)
#define PID_W_SMG_22                        (152)
#define PID_W_SMG_22_UPGD                   (177)
#define PID_W_PISTOL_22                     (181)
#define PID_W_PISTOL_10                     (153)
#define PID_W_SMG_10                        (154)
#define PID_W_SMG_UZI                       (155)
#define PID_W_PISTOL_50                     (156)
#define PID_W_PISTOL_ZIP                    (175)

//Огнестрельное тяжелое
#define PID_W_RIFLE_HUNTING                 (157)
#define PID_W_RIFLE_HUNTING_UNERTL          (176)
#define PID_W_RIFLE_COMBAT                  (158)
#define PID_W_RIFLE_SNIPER                  (160)
#define PID_W_RIFLE_ASSAULT                 (161)
#define PID_W_RIFLE_ASSAULT_UPD             (182)
#define PID_W_LIGHT_AUTOGUN                 (162)
#define PID_W_MINIGUN                       (163)
#define PID_W_SHOTGUN_DUBLET                (164)
#define PID_W_SHOTGUN_COMBAT                (165)
#define PID_W_SHOTGUN_ASSAULT               (166)
#define PID_W_LAUNCHER                      (167)
#define PID_W_LAUNCHER_UPD                  (178)
#define PID_W_RIFLE_CARABINA                (179)

//Энергетическое
#define PID_W_LASER_ZIPGUN                  (168)
#define PID_W_LASER_ZIPGUN_UP               (498)
#define PID_W_LASER_PISTOL                  (169)
#define PID_W_LASER_RIFLE                   (170)
#define PID_W_LASER_GATLING                 (188)
#define PID_W_PLASMA_PISTOL                 (171)
#define PID_W_PLASMA_RIFLE                  (172)
#define PID_W_MICROWAVE_PISTOL              (173)
#define PID_W_RAILGUN                       (183)
#define PID_W_FLAMER                        (184)
#define PID_W_ELECTRO_PISTOL                (187)
#define PID_W_PLASMA_TURREL                 (189)
#define PID_W_PLASMA_RIFLE_TURBO            (191)
#define PID_W_PLASMA_PISTOL_DETALS          (453)
#define PID_W_LASER_PISTOL_UPGRD            (454)

#define PID_W_SCOLOPENDRA_ACID              (116)

/*****************************************************************
***************        SONORA Armor     **************************
******************************************************************/

#define PID_ARMOR_VAULT                     (24)
#define PID_ARMOR_JACKET_A                  (25)
#define PID_ARMOR_JACKET_B                  (26)
#define PID_ARMOR_LEATHER                   (27)
#define PID_ARMOR_PURPLE_ROBE_A             (28)
#define PID_ARMOR_PURPLE_ROBE_B             (29)
#define PID_ARMOR_METALIC_A                 (30)
#define PID_ARMOR_TESLA                     (31)
#define PID_ARMOR_COMBAT                    (32)
#define PID_ARMOR_COMBAT_BOS                (33)
#define PID_ARMOR_COMBAT_MEX                (104)
#define PID_ARMOR_COMBAT_GHOUL              (117)
#define PID_ARMOR_POWER_A                   (34)
#define PID_ARMOR_POWER_B                   (35)
#define PID_ARMOR_POWER_C                   (115)
#define PID_ARMOR_ROAD                      (36)
#define PID_ARMOR_LEATHER_RANGER            (37)
#define PID_ARMOR_CHEST_SHIELD              (57)
#define PID_ARMOR_JACKET_C                  (72)
#define PID_ARMOR_INDIAN_PROTEGER           (103)

/*****************************************************************
***************      SONORA Medical and Food     *****************
******************************************************************/

//Медикаменты и наркотики
#define PID_M_STIMPAK                       (40)
#define PID_M_SUPER_STIMPAK                 (144)
#define PID_M_RAD_X                         (109)
#define PID_M_RADAWAY                       (48)
#define PID_M_ANTIDOTE                      (49)
#define PID_M_MENTATS                       (53)
#define PID_M_BUFFOUT                       (87)
#define PID_M_PSYCHO                        (110)
#define PID_M_ASH                           (111)

//Еда
#define PID_M_IGUANA                        (60) // игуана
#define PID_M_FRUIT                         (61) // мутафрукт
#define PID_M_MEAT_JERKY                    (62) // вяленое мясо
#define PID_M_NOODLES                       (63) // лапша
#define PID_M_TV_DINNER                     (64) // телеужин
#define PID_M_SLUGS                         (65) // личинки
#define PID_M_BRAHMIN_POTROH                (66) // блюдо из браминьих отрубей
#define PID_M_SOUP_RAT                      (67) // суп из крысы
#define PID_M_IRP                           (68) // ИРП Братства Стали
#define PID_M_MEAT_FOUL                     (69) // протухшее блюдо
#define PID_M_ROACH                         (70) // таракан
#define PID_M_FRITOS_BANDITOS               (71) // мексиканские чипсы

//Напитки
#define PID_M_NUKA_COLA                     (106)
#define PID_M_NUKA_COLA_RAD                 (107)
#define PID_M_WATER_FLASK                   (108)
#define PID_M_MEX_BEER                      (120)
#define PID_M_BOOZE                         (122)
#define PID_M_VISKI                         (123)
#define PID_M_BEER                          (124)
#define PID_M_TEQUILA                       (125)

/*****************************************************************
***************        SONORA Books     **************************
******************************************************************/

#define PID_BOOK_SCIENCE                    (73)
#define PID_BOOK_REPAIR                     (76)
#define PID_BOOK_FIRST_AID                  (80)
#define PID_BOOK_OUTDOORSMAN                (86)
#define PID_BOOK_SMALL_WEAPON               (102)

#define PID_BOOK_COMIX                      (499)

/*****************************************************************
***************        SONORA Keys      **************************
******************************************************************/

#define PID_KEY_ARMY_SUPERMUTANT            (363)
#define PID_KEY_FABER_PASSWORD              (391)
#define PID_KEY_DESTROYER                   (412)
#define PID_KEY_TORPED                      (413)
#define PID_KEY_PHENIX_CASINO_LUX           (414)
#define PID_KEY_PHENIX_RADIO_COD            (415)
#define PID_KEY_DUMBA                       (416)
#define PID_KEY_ZAX                         (417)
#define PID_KEY_VAULT25_YLW                 (418)
#define PID_KEY_VAULT25_RED                 (419)
#define PID_KEY_VAULT27                     (420)
#define PID_KEY_PHENIX_CULT                 (421)
#define PID_KEY_OLD_MOTEL                   (422)
#define PID_KEY_JACKALS                     (423)
#define PID_KEY_FLAGSTAFF_MINE              (425)
#define PID_KEY_VILLA_ANGAR                 (427)
#define PID_KEY_QUARTZ                      (424)
#define PID_KEY_OILPLATFORM                 (446)

/*****************************************************************
***************        SONORA Documents     **********************
******************************************************************/

#define PID_HOLODSK_VILLA                   (350)
#define PID_HOLODSK_VAULT_27_DIARY          (351)
#define PID_HOLODSK_VAULT_27_REPORT         (352)
#define PID_HOLODSK_QUARTZ                  (353)
#define PID_HOLODSK_TWOSUN_ZAX              (354)
#define PID_HOLODSK_CASA_GRANDE             (355)
#define PID_HOLODSK_SAN_BRAHMIN             (356)
#define PID_HOLODSK_VAULT_TEC               (357)
#define PID_HOLODSK_OIL_PLATFORM            (358)
#define PID_HOLODSK_VAULT_SANDIEGO          (359)

#define PID_HOLODSK_ULISS                   (394)
#define PID_LETTER_CULT_FLAGSTAFF           (393)
#define PID_MAP_PHIENIX                     (444)

/*****************************************************************
***************        SONORA Quest Items    *********************
******************************************************************/

#define PID_MOTO_KEY                        (430)
#define PID_MOTO_LUMP                       (432)
#define PID_MOTO_BAG                        (456)

#define PID_BOS_ARMY_TAG                    (44)
#define PID_BOS_ARMYTAG_A                   (113)
#define PID_BOS_ARMYTAG_B                   (114)
#define PID_Q_SANTAANA_CORONA               (361)
#define PID_Q_BRAHMIN_BARTER                (362)
#define PID_Q_RADIO_HERMOSILLO              (364)
#define PID_Q_PORTMONE                      (365)
#define PID_Q_CASE_CURIER                   (366)
#define PID_Q_MADRE_CULON                   (367)
#define PID_Q_INSECT_A                      (368)
#define PID_Q_INSECT_B                      (369)
#define PID_Q_INSECT_C                      (370)
#define PID_Q_BOOKS_PUERTO                  (371)
#define PID_Q_INSECT_WHITE                  (372)
#define PID_Q_INSECT_DOCS                   (373)
#define PID_Q_INSECTICIDES                  (374)
#define PID_Q_BOS_MAP                       (375)
#define PID_Q_BOS_RELICT                    (376)
#define PID_Q_DIANA_MUTAGEN                 (377)
#define PID_Q_DIANA_PACKET                  (378)
#define PID_Q_PWR_HEAD                      (379)
#define PID_Q_PWR_PROC                      (380)
#define PID_Q_COLA_BOX                      (381)
#define PID_Q_HORSE                         (382)
#define PID_Q_PISTOL_LOST                   (384)
#define PID_Q_GLASS_BIBL                    (385)
#define PID_Q_NEIRO_CHIP                    (386)
#define PID_Q_RANGER_STAR_QST               (387)
#define PID_Q_LETTERS                       (395)
#define PID_Q_DRUGBOX_A                     (388)
#define PID_Q_DRUGBOX_B                     (389)
#define PID_Q_EUGENE_CONTRACT               (392)
#define PID_Q_SCORP_SPEAR                   (401)
#define PID_Q_FUNGUS                        (402)
#define PID_Q_GARAGE_DETALS                 (403)
#define PID_Q_LEBEDKA                       (404)
#define PID_Q_RADIO_LUMP                    (405)
#define PID_Q_WELDING_MACHINE               (406)
#define PID_ZAX_UPGRADE                     (407)
#define PID_GENERATOR_ENERGY                (410)
#define PID_NUKE_BOMB_DETONATOR             (411)
#define PID_TOOTHS_RAT_KING                 (426)
#define PID_SCULL_DEATHCLAW                 (429)
#define PID_GLASSES                         (433)
#define PID_Q_ARMYTAG_PESCADOR              (445)
#define PID_Q_GOLD_MAP                      (447)
#define PID_Q_HERMO_INFO_DISK               (475)

#define PID_HEAD_ROAD                       (396)
#define PID_HEAD_A                          (397)
#define PID_HEAD_B                          (398)
#define PID_HEAD_C                          (399)
#define PID_HEAD_D                          (400)

#define PID_RELICT_VILLA_FAMILY             (428)
#define PID_RELICT_MUSIC_BOX                (434)
#define PID_RELICT_WATCH                    (435)
#define PID_RELICT_SNOWGLOBE                (436)
#define PID_RELICT_MEDAL                    (437)
#define PID_RELICT_STAR_RANGER              (438)
#define PID_RELICT_BIBLE                    (439)
#define PID_RELICT_FOTO                     (440)
#define PID_RELICT_DAYGLOW                  (441)
#define PID_RELICT_FLAG                     (442)
#define PID_RELICT_GAMEDISK                 (443)

//DLC


/*****************************************************************
***************        SONORA Misc Items     *********************
******************************************************************/

#define PID_BOOTLE_CAPS                     (41)
#define PID_MANY                            (42)
#define PID_POKER_FISH                      (43)
#define PID_TEST                            (46)

#define PID_POCKET_TRASH                    (45)
#define PID_OIL                             (90)
#define PID_SCORPION_TAIL                   (92)
#define PID_RAD_ITEM                        (93)
#define PID_BOOK_OLD                        (94)
#define PID_CORN_FLOUR                      (95)
#define PID_CLEAR                           (96)
#define PID_WAT_WIPES                       (97)
#define PID_TABACO                          (98)
#define PID_COFFEE                          (99)
#define PID_SANDALS                         (100)
#define PID_KERAMIC                         (101)
#define PID_HYPO                            (112)
#define PID_AGAVE_JUICE                     (121)
#define PID_AMMO_CULON                      (431)
#define PID_MEX_TORPEDOS                    (360)
#define PID_KATOD_LUMP                      (463)

#define dude_caps                           (item_caps_total(dude_obj))

/*****************************************************************
***************        SONORA Conteiners     *********************
******************************************************************/

#define PID_CNTR_BARTER_BOX                 (193) // Универсальный торговый ящик для торговцев (размещается за пределами карты)
#define PID_CNTR_UNIVERSAL_BOX              (17)  // Универсальный вспомогательный бокс с огромной вместимостью (для отладки, для использования вне видимости игрока)
#define PID_CNTR_EXPRESSBOX_F               (200) // Посылка в Флагпул
#define PID_CNTR_EXPRESSBOX_P               (201) // Посылка в Феникс
#define PID_CNTR_EXPRESSBOX_T               (202) // Посылка в ТуСан
#define PID_CNTR_SOILJUNK                   (197) // Мусорная куча
#define PID_CNTR_SOIL                       (203) // Свежевскопанная земля
#define PID_CNTR_VAULT_AA                   (289) // Убежище: шкафчик серый запад-восток
#define PID_CNTR_VAULT_AB                   (290) // Убежище: шкафчик серый север-юг
#define PID_CNTR_VAULT_BA                   (291) // Убежище: шкафчик новый запад-восток
#define PID_CNTR_VAULT_BB                   (292) // Убежище: шкафчик новый север-юг
#define PID_CNTR_VAULT_CA                   (293) // Убежище: шкафчик ржавый запад-восток
#define PID_CNTR_VAULT_CB                   (294) // Убежище: шкафчик ржавый север-юг
#define PID_CNTR_TOTEM                      (318) // Разрушенный тотем Шакалов

/*****************************************************************
***************        SONORA Tools     **************************
******************************************************************/

#define PID_TOOL_CAR_GAZ                    (38)
#define PID_TOOL_CAR_GAZ_SUPER              (39)  // Не использовать!
#define PID_TOOL_RADIO                      (55)
#define PID_TOOL_IGUANA_TRACK               (56)
#define PID_TOOL_LOCKPICKS_MH               (74)
#define PID_TOOL_LOCKPICKS_EL               (75)
#define PID_TOOL_GAS_MASK                   (77)
#define PID_TOOL_NV_GLASSES                 (78)
#define PID_TOOL_BOOTS                      (81)
#define PID_TOOL_SHOVEL                     (82)
#define PID_TOOL_ROPE                       (83)
#define PID_TOOL_ZIPPER                     (84)
#define PID_TOOL_PARTS_MECHANICAL           (88)
#define PID_TOOL_PARTS_ELECTRONIC           (89)
#define PID_TOOL_DOCTORS_BAG                (50) // Не путать с Докторским чемоданом в F1 и F2!
#define PID_TOOL_PIPBOY_LINK                (516)
#define PID_TOOL_WATER_FLASK_VB             (105)

#define PID_TOOL_FLARE                      (79)
#define PID_TOOL_DYNAMITE                   (51)  // Не использовать!
#define PID_TOOL_GEIGER_COUNTER             (52)
#define PID_TOOL_STEALTH_BOY                (54)
#define PID_TOOL_MOTION_SENSOR              (59)
#define PID_TOOL_PLASTIC_EXPLOSIVES         (85)

#define PID_TOOL_FIRST_AID_KIT_A            (47)  // Не использовать!
#define PID_TOOL_FIRST_AID_KIT_B            (408) // Не использовать!
#define PID_TOOL_DOCTORS_BAG_A              (91)  // Не использовать!
#define PID_TOOL_DOCTORS_BAG_B              (409) // Не использовать!

#define stopUseCarGaz                       if (objUsedPid == PID_TOOL_CAR_GAZ) then begin \
                                               script_overrides;                \
                                               if (global_var(GVAR_CAR_GOT_PLAYER) == 0) then begin\
                                               g_display_mstr(490);             \
                                               end                              \
                                               else begin                       \
                                               g_display_mstr(489);             \
                                               end                              \
                                            end                                 \

/*
#define destroyUseShovel                    inc_global_var(GVAR_SHOVEL_STATUS);  \
                                            if (global_var(GVAR_SHOVEL_STATUS)>=(dude_strength+4)) then begin \
                                            item_remove(dude_obj, objUsedPid, 1) \
                                            g_display_mstr(492);                 \
                                            set_global_var(GVAR_SHOVEL_STATUS,0); \
                                            end                                  \
*/

#define destroyUseShovel                    if (random(0,100) <= (10-dude_strength)) then begin \
                                            item_remove(dude_obj, objUsedPid, 1) \
                                            g_display_mstr(492);                 \
                                            end                                  \


/*****************************************************************
***************       Active Items                  **************
******************************************************************/

#define PID_ACTIVE_FLARE                    (205)
#define PID_ACTIVE_DYNAMITE                 (206)
#define PID_ACTIVE_GEIGER_COUNTER           (207)
#define PID_ACTIVE_MOTION_SENSOR            (208)
#define PID_ACTIVE_PLASTIC_EXPLOSIVE        (209)
#define PID_ACTIVE_STEALTH_BOY              (210)

/*

Не актуально.
Этот макрос использовался по умолчанию в каждом set_start_home.
Но баги, которые он исправляет, слишком редкие.
Лишнее нагромждение скриптовых функций - это тоже не есть хорошо.

#define deleteActiveItem                    if (item_amnt(self_obj,PID_ACTIVE_FLARE) >0) then begin \
                                            item_remove(self_obj, PID_ACTIVE_FLARE, item_amnt(self_obj,PID_ACTIVE_FLARE)) \
                                            end                                                   \
                                            if (item_amnt(self_obj,PID_ACTIVE_DYNAMITE) >0) then begin \
                                            item_remove(self_obj, PID_ACTIVE_DYNAMITE, item_amnt(self_obj,PID_ACTIVE_DYNAMITE)) \
                                            end                                                   \
                                            if (item_amnt(self_obj,PID_ACTIVE_PLASTIC_EXPLOSIVE) >0) then begin \
                                            item_remove(self_obj, PID_ACTIVE_PLASTIC_EXPLOSIVE, item_amnt(self_obj,PID_ACTIVE_PLASTIC_EXPLOSIVE)) \
                                            end                                                   \

*/

/*****************************************************************
***************       Операции с предметами         **************
******************************************************************/

variable removed_amnt;
variable removed_obj;

#define objUsedPid                          obj_pid(obj_being_used_with)        \

#define item_amnt(who,pid)                  obj_is_carrying_obj_pid(who,pid)    \

#define item_add(who,pid,amnt)              add_mult_objs_to_inven(who,(create_object_sid(pid,0,0,-1)),amnt); \

#define item_remove(who,pid,amnt)           removed_amnt := item_amnt(who,pid);                                   \
                                            if (amnt < removed_amnt) then begin                                   \
                                               removed_amnt := amnt;                                              \
                                            end                                                                   \
                                            if (removed_amnt > 0) then begin                                      \
                                               removed_obj := obj_carrying_pid_obj(who, pid);                     \
                                               debug_msg("removedObj "+removed_obj);                              \
                                               if (obj_type(who) == 1) then begin                                 \
                                                  if (inven_armor(who) == removed_obj) then begin                 \
                                                  item_remove_armor(who)                                          \
                                                  end                                                             \
                                                  if (inven_hand_R(who) == removed_obj) then begin                \
                                                  inven_unwield(who);                                             \
                                                  end                                                             \
                                                  if (inven_hand_L(who) == removed_obj) then begin                \
                                                  inven_unwield(who);                                             \
                                                  end                                                             \
                                               end                                                                \
                                               removed_amnt := rm_mult_objs_from_inven(who, removed_obj, removed_amnt); \
                                               destroy_object(removed_obj);                                       \
                                               debug_msg(removed_obj+" delete");                                  \
                                            end                                                                   \
                                            else begin                                                            \
                                               debug_msg("Deleted Nothing");                                      \
                                            end                                                                   \
                                            removed_obj := 0;                                                     \
                                            removed_amnt := 0;                                                    \

#define item_remove_armor(who)              if (inven_armor(who) > 0) then begin                                  \
                                            removed_obj := inven_armor(who);                                      \
                                            rm_obj_from_inven(who,removed_obj);                                   \
                                            add_mult_objs_to_inven(who, removed_obj, 1);                          \
                                            end                                                                   \

#define check_restock_item(pid,min,max,chince)                                                                    \
                                            removed_amnt := random(min, max);                                     \
                                            if (item_amnt(self_obj, pid) > removed_amnt) then begin               \
                                               item_remove(self_obj, pid, (item_amnt(self_obj,pid) - removed_amnt)) \
                                            end                                                                   \
                                            if (item_amnt(self_obj, pid) < removed_amnt) then begin               \
                                               if (chince >= random(0,100)) then begin                            \
                                               item_add(self_obj, pid, removed_amnt - item_amnt(self_obj, pid))   \
                                               end                                                                \
                                            end                                                                   \
                                            removed_amnt := 0;                                                    \

#define check_restock_many(min, max)        item_remove(self_obj, PID_BOOTLE_CAPS, item_amnt(self_obj,PID_BOOTLE_CAPS)) \
                                            if DudePerkHas(PERK_marauder) then begin                              \
                                            check_restock_item(PID_BOOTLE_CAPS, min+(min/10), max+(max/10), 100)    \
                                            end else begin                                                        \
                                            check_restock_item(PID_BOOTLE_CAPS, min, max, 100)                    \
                                            end                                                                   \

#define weapon_invn_dude                    (global_var(GVAR_DUDE_WPN_TO_HAND) > 0) \

#define weapon_invn_self                   ((obj_item_subtype(inven_hand_R(self_obj)) == item_type_weapon) or (obj_item_subtype(inven_hand_L(self_obj)) == item_type_weapon)) \

#define item_inven_dude(pid)               ((obj_pid(inven_hand_R(dude_obj)) == pid) or (obj_pid(inven_hand_L(dude_obj)) == pid)) \

#define armor_pid_dude                      obj_pid(inven_armor(dude_obj))      \

#define armor_pid_dude_var                  global_var(GVAR_DUDE_PID_ARMOR)     \

#endif
