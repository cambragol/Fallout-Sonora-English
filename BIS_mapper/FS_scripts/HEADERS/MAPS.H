#ifndef MAPS_H
#define MAPS_H

//------------------------------------------------------
//---------------------- Локации
//------------------------------------------------------

#define AREA_VILLA                  (0)
#define AREA_FLAGSTAFF              (1)
#define AREA_GARAGE                 (2)
#define AREA_SAN_BRAHMIN            (3)
#define AREA_TWO_SUN                (4)
#define AREA_PUERTO_STEEL           (5)
#define AREA_RANGERS                (6)
#define AREA_PHOENIX                (7)
#define AREA_OIL_PLATFORM           (8)
#define AREA_CASA_GRANDE            (9)
#define AREA_HERMOSILLO             (10)
#define AREA_SAN_FELIPE             (11)
#define AREA_INFIERNO               (12)
#define AREA_CASA_NUEVA             (13)
#define AREA_reserv_14              (14)
#define AREA_OLD_MOTEL              (15)
#define AREA_DAYGLOW                (16) // DLC
#define AREA_reserv_17              (17)
#define AREA_SANTA_ANA              (18)
#define AREA_reserv_19              (19)
#define AREA_JACKALS                (20)
#define AREA_CAR_PIT_STOP           (21)
#define AREA_VILLA_DSTR             (22) // не использовать! (Разрушенный Арройо)
#define AREA_VAULT_27               (23)
#define AREA_BOS_CAMPS              (24)
#define AREA_RAIDERS                (25)
#define AREA_RND_DESERT             (26)
#define AREA_RND_MOUNTAIN           (27)
#define AREA_RND_CITY               (28)
#define AREA_RND_COAST              (29)
#define AREA_PUERTO_DESTROY         (30)
#define AREA_SPECIAL_GOLD           (31)
#define AREA_SPECIAL_BIBL           (32)
#define AREA_SPECIAL_CAFE           (33)
#define AREA_SPECIAL_BOMBER         (34)
#define AREA_SPECIAL_PETRO          (35)
#define AREA_SPECIAL_CRY            (36)
#define AREA_SPECIAL_DRIVE_IN       (37)
#define AREA_SPECIAL_PADRE          (38)
#define AREA_SPECIAL_BARON          (39)
#define AREA_SPECIAL_SNOW           (40)
#define AREA_SPECIAL_VAULT          (41)
#define AREA_SPECIAL_ARMY           (42)
#define AREA_SPECIAL_LEGENDCITY     (43)
#define AREA_reserv_44              (44)
#define AREA_reserv_45              (45)
#define AREA_QUARTZ                 (46)
#define AREA_SHADOW_WORLDS          (47)
#define AREA_WINON                  (48)

//------------------------------------------------------
//---------------------- Карты локаций
//------------------------------------------------------

//--- Случайные встречи
#define MAP_RND_DESERT_1            (0)
#define MAP_RND_DESERT_2            (1)
#define MAP_RND_DESERT_3            (2)
#define MAP_RND_DESERT_4            (3)
#define MAP_RND_DESERT_9            (144)
#define MAP_RND_ROAD_1              (4)
#define MAP_RND_ROAD_2              (5)
#define MAP_RND_ROAD_3              (6)
#define MAP_RND_ROAD_4              (7)
#define MAP_RND_ROAD_5              (146)
#define MAP_RND_CITY_1              (8)
#define MAP_RND_CITY_2              (9)
#define MAP_RND_CITY_3              (10)
#define MAP_RND_CITY_4              (11)
#define MAP_RND_CITY_9              (148)
#define MAP_RND_MOUNTAIN_1          (12)
#define MAP_RND_MOUNTAIN_2          (13)
#define MAP_RND_MOUNTAIN_3          (14)
#define MAP_RND_MOUNTAIN_4          (15)
#define MAP_RND_MOUNTAIN_5          (16)
#define MAP_RND_MOUNTAIN_6          (17)
#define MAP_RND_MOUNTAIN_7          (147)
#define MAP_RND_MOUNTAIN_8          (143)
#define MAP_RND_MOUNTAIN_9          (142)
#define MAP_RND_COAST_1             (18)
#define MAP_RND_COAST_2             (19)
#define MAP_RND_COAST_3             (20)
#define MAP_RND_COAST_4             (145)

//--- Специальные встречи
#define MAP_CAR_PIT_STOP            (53)
#define MAP_IN_GAME_MOVIE           (149)
#define MAP_SPECIAL_GOLD            (96)
#define MAP_SPECIAL_BIBL            (97)
#define MAP_SPECIAL_CAFE            (98)
#define MAP_SPECIAL_BOMBER          (99)
#define MAP_SPECIAL_PETRO           (100)
#define MAP_SPECIAL_CRY             (101)
#define MAP_SPECIAL_DRIVE_IN        (102)
#define MAP_SPECIAL_PADRE           (103)
#define MAP_SPECIAL_BARON           (104)
#define MAP_SPECIAL_SNOW            (105)
#define MAP_SPECIAL_VAULT           (106)
#define MAP_SPECIAL_ARMY            (107)
#define MAP_SPECIAL_LEGENDCITY      (108)

//--- Локации
#define MAP_VILLA_HOME              (21)
#define MAP_VILLA_PLAZA             (22)
#define MAP_VILLA_CAVE              (23)
#define MAP_VILLA_GARD              (24)
#define MAP_VILLA_RUINS             (79)
#define MAP_VILLA_CRYPT             (109)
#define MAP_FLAGSTAFF_CITY          (25)
#define MAP_FLAGSTAFF_SLAVE         (26)
#define MAP_FLAGSTAFF_MINE          (27)
#define MAP_FLAGSTAFF_MUSEUM        (28)
#define MAP_FLAGSTAFF_CAVE          (70)
#define MAP_FLAGSTAFF_FARM          (87)
#define MAP_GARAGE_SIGN             (29)
#define MAP_GARAGE_HOMES            (30)
#define MAP_GARAGE_FACTORY          (31)
#define MAP_GARAGE_HISTORY          (85)
#define MAP_GARAGE_BRAHMIN          (86)
#define MAP_GARAGE_TRILER           (117)
#define MAP_SAN_BRAHMIN_SIGN        (32)
#define MAP_SAN_BRAHMIN_CITY        (33)
#define MAP_SAN_BRAHMIN_GARD        (34)
#define MAP_SAN_BRAHMIN_CAVE        (114)
#define MAP_SAN_BRAHMIN_OASIS       (119)
#define MAP_TWO_SUN_CITY            (35)
#define MAP_TWO_SUN_WORKSHOP        (36)
#define MAP_TWO_SUN_DSTR            (37)
#define MAP_TWO_SUN_ZAX             (38)
#define MAP_TWO_SUN_GRAVE           (77)
#define MAP_TWO_SUN_INN             (78)
#define MAP_PUERTO_SIGN             (39)
#define MAP_PUERTO_DOCS             (40)
#define MAP_PUERTO_BASA             (41)
#define MAP_PUERTO_DESTROY          (69)
#define MAP_BOS_CAMP_A              (73)
#define MAP_BOS_CAMP_B              (74)
#define MAP_BOS_CAMP_C              (75)
#define MAP_RANGERS_ROAD            (42)
#define MAP_RANGERS_BASA            (43)
#define MAP_RANGERS_RADIO           (44)
#define MAP_RANGERS_DAMBA           (45)
#define MAP_RANGERS_PAROM           (80)
#define MAP_RANGERS_RETRANSL        (81)
#define MAP_RANGERS_QUARTZ          (82)
#define MAP_RANGERS_CAVE            (83)
#define MAP_RANGERS_CITY            (84)
#define MAP_RANGERS_MOHAVE          (94)
#define MAP_HERMO_RANCHO            (88)
#define MAP_HERMO_CASA              (89)
#define MAP_HERMO_FUERTE            (90)
#define MAP_PHOENIX_SIGN            (46)
#define MAP_PHOENIX_CENTER          (47)
#define MAP_PHOENIX_BNDCS           (48)
#define MAP_PHOENIX_PLAZA           (49)
#define MAP_PHOENIX_VAULT           (50)
#define MAP_PHOENIX_ANAL            (51)
#define MAP_PHOENIX_DSTROY          (52)
#define MAP_PHOENIX_ELECTR          (54)
#define MAP_PHOENIX_CHURCH          (76)
#define MAP_PHOENIX_COLA            (110)
#define MAP_VAULT_27_EXTERIER       (55)
#define MAP_VAULT_27_INTERIER       (56)
#define MAP_CASA_GRANDE_WATER       (57)
#define MAP_CASA_GRANDE_CITY        (58)
#define MAP_CASA_GRANDE_GRAVE       (59)
#define MAP_CASA_GRANDE_SCHOOL      (91)
#define MAP_CASA_GRANDE_BAR         (92)
#define MAP_CASA_GRANDE_STANTION    (93)
#define MAP_INFIERNO_ROAD           (60)
#define MAP_INFIERNO_CITY           (61)
#define MAP_INFIERNO_SHOP           (62)
#define MAP_INFIERNO_POLICE         (63)
#define MAP_INFIERNO_CHURCH         (95)
#define MAP_INFIERNO_MONUMENT       (111)
#define MAP_CASA_NUEVA_CITY         (64)
#define MAP_CASA_NUEVA_PLANT        (65)
#define MAP_CASA_NUEVA_LAB          (66)
#define MAP_CASA_NUEVA_CEMENT       (112)
#define MAP_CASA_NUEVA_GIDROPONIC   (113)
#define MAP_RAIDERS_BASA            (67)
#define MAP_JACKALS                 (68)
#define MAP_OLD_MOTEL               (71)
#define MAP_SAN_FELIPE_CITY         (72)
#define MAP_SAN_FELIPE_COAST        (115)
#define MAP_SAN_FELIPE_CAVE         (116)
#define MAP_FLAGSTAFF_WINON         (118)
#define MAP_SANTA_ANA_PLAZA         (120)
#define MAP_SANTA_ANA_MONUMENT      (121)
#define MAP_SANTA_ANA_GRAVE         (122)
#define MAP_SB_CARAVAN_A            (123)
#define MAP_SB_CARAVAN_B            (124)
#define MAP_SB_CARAVAN_C            (125)
#define MAP_OIL_CITY                (126)
#define MAP_OIL_PLATFORM            (127)
#define MAP_OIL_PLATFORMROOMS       (128)
#define MAP_OIL_PLATFORMDRILL       (129)
#define MAP_OIL_COAST               (130)

//--- Резерв
#define MAP_reserv_131              (131)
#define MAP_reserv_132              (132)
#define MAP_reserv_133              (133)
#define MAP_reserv_134              (134)
#define MAP_reserv_135              (135)
#define MAP_reserv_136              (136)
#define MAP_reserv_137              (137)
#define MAP_reserv_138              (138)
#define MAP_reserv_139              (139)
#define MAP_reserv_140              (140)
#define MAP_reserv_141              (141)
#define MAP_reserv_150              (150)

//------------------------------------------------------
//---------------------- Ящики Сонора Экспресс
//------------------------------------------------------

#define TILE_EXPRESS_BOX            (9)  // тайл размещения ящков Сонора Экспресс (номер должен быть >=2 и не может быть достижим для игрока)

#define express_box_obj(pid)        tile_contains_pid_obj(TILE_EXPRESS_BOX, 0, pid)

#define addExpressBoxToDude         if (express_box_obj(PID_CNTR_EXPRESSBOX_F) > 0) then begin \
                                    add_mult_objs_to_inven(dude_obj,express_box_obj(PID_CNTR_EXPRESSBOX_F),1); \
                                    end                                         \
                                    if (express_box_obj(PID_CNTR_EXPRESSBOX_P) > 0) then begin \
                                    add_mult_objs_to_inven(dude_obj,express_box_obj(PID_CNTR_EXPRESSBOX_P),1); \
                                    end                                         \
                                    if (express_box_obj(PID_CNTR_EXPRESSBOX_T) > 0) then begin \
                                    add_mult_objs_to_inven(dude_obj,express_box_obj(PID_CNTR_EXPRESSBOX_T),1); \
                                    end                                         \

//------------------------------------------------------
//---------------------- Опции карт
//------------------------------------------------------

#define HomeTile                    local_var(LVAR_Home_Tile)
#define HomeRotat                   local_var(LVAR_Home_Rotat)

#define self_cur_rot                (has_trait(TRAIT_OBJECT,self_obj,OBJECT_CUR_ROT))
#define self_inv_rot                ((self_cur_rot + 3)%6)
#define self_tile                   tile_num(self_obj)
#define self_elevation              elevation(self_obj)
#define source_tile                 tile_num(source_obj)

#define dude_cur_rot                (has_trait(TRAIT_OBJECT,dude_obj,OBJECT_CUR_ROT))
#define dude_inv_rot                ((dude_cur_rot + 3)%6)
#define dude_tile                   (tile_num(dude_obj))
#define dude_elevation              (elevation(dude_obj))

/*
Телепортация ГГ на другую карту:
   fa   - затухание (при <=0 игнорируется)
   fb   - восстановление экрана (при <=0 игнорируется)
   map  - индекс загружаемой карты
   hour - число часов, которое нужно промотать (при <= 0 игнорируется)
*/
#define dude_teleport_map(fa,fb,map,hour)                                       \
                                    if (fa >0) then begin                       \
                                    gfade_out(ONE_GAME_SECOND);                 \
                                    end                                         \
                                     play_sfx("GUSTWIND");                      \
                                     if (hour >0) then begin                    \
                                     game_time_advance(ONE_GAME_HOUR*(hour));   \
                                     end                                        \
                                    if (fb >0) then begin                       \
                                    gfade_in(ONE_GAME_SECOND);                  \
                                    end                                         \
                                    load_map(map, -1)                           \

//                                   !! addExpressBoxToDude                         \

#define override_map_start_hex(x,y,z)   override_map_start(x%200,x/200,y,z)

// Used with mark_area_known
#define MARK_TYPE_TOWN              (0)
#define MARK_TYPE_MAP               (1)
// wmAreaVisitStateInfo
#define MARK_STATE_UNKNOWN          (0)
#define MARK_STATE_KNOWN            (1)
#define MARK_STATE_VISITED          (2)
#define MARK_STATE_INVISIBLE        (-66)

#define mark_on_map(x)              if (town_known(x) == MARK_STATE_UNKNOWN) then begin          \
                                       if (g_mstr(1500+x) != "") then begin                      \
                                       display_msg(g_mstr(1400)+g_mstr(1401)+g_mstr(1500+x)+g_mstr(1402)); \
                                       end else begin                                            \
                                       display_msg(g_mstr(1400)+g_mstr(1402));                   \
                                       end                                                       \
                                       mark_area_known(MARK_TYPE_TOWN, x, MARK_STATE_KNOWN);     \
                                    end

#define unmark_on_map(x)            if (town_known(x) != MARK_STATE_UNKNOWN) then begin          \
                                       mark_area_known(MARK_TYPE_TOWN, x, MARK_STATE_UNKNOWN);   \
                                    end

#endif
