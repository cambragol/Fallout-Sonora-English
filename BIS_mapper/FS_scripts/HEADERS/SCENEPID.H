#ifndef SCENEPID_H
#define SCENEPID_H

#define PID_ZERO_NUMBER                     33554432 // стартовый нулевой объект (после него 1й объект - горящая бочка)
#define PID_HEX_MAPEXIT                     33554481
#define PID_HEX_BLOCKING                    33554499
#define PID_HEX_SOLAR                       33554573
#define PID_HEX_NOT_GOO                     PID_ZERO_NUMBER+1082

// Транспорт ГГ
#define PID_CAR_GENERATOR                   33554434
#define PID_CAR_OBJ                         33555441
#define PID_CAR_TRUNK                       455

// Двери убежища
#define PID_DOOR_VLT_AA                     33554932  // чистая дверь С-Ю
#define PID_DOOR_VLT_AB                     33554933  // чистая дверь З-В
#define PID_DOOR_VLT_BA                     33554936  // ржавая дверь С-Ю
#define PID_DOOR_VLT_BB                     33554937  // ржавая дверь З-В

// Двери корабля в Пуэрто
#define PID_DOOR_PRT_A                      33556278  //
#define PID_DOOR_PRT_B                      33556279  //
#define PID_DOOR_PRT_C                      33556280  //
#define PID_DOOR_PRT_D                      33556281  //
#define PID_DOOR_PRT_E                      33556282  //
#define PID_DOOR_PRT_F                      33556283  //
#define PID_DOOR_PRT_G                      33556284  //
#define PID_DOOR_PRT_H                      33556285  //

// Силовые поля
#define PID_POWER_POLE_AA                   33555168  // обычное желтое поле З-В
#define PID_POWER_POLE_AB                   33555169  // обычное желтое поле С-Ю
#define PID_POWER_POLE_BA                   33555170  // красное поле З-В
#define PID_POWER_POLE_BB                   33555171  // красное поле С-Ю
#define PID_POWER_POLE_CA                   33555172  // желтое поле Анклава З-В
#define PID_POWER_POLE_CB                   33555173  // желтое поле Анклава С-Ю
#define PID_POWER_POLE_DA                   33555174  // линии З-В
#define PID_POWER_POLE_DB                   33555175  // линии С-Ю

// Ловушки
#define PID_TRAP_Aa                         33554435   // каменная плита вкл
#define PID_TRAP_Ab                         33554436   // каменная плита выкл
#define PID_TRAP_Ba                         33554437   // напольная плита вкл
#define PID_TRAP_Bb                         33554438   // напольная плита выкл
#define PID_TRAP_Ca                         33554439   // крысоловка вкл
#define PID_TRAP_Cb                         33554440   // крысоловка выкл
#define PID_TRAP_Da                         33554441   // растяжка вкл
#define PID_TRAP_Db                         33554442   // растяжка выкл
#define PID_TRAP_Ea                         33554443   // растяжка вкл
#define PID_TRAP_Eb                         33554444   // растяжка выкл
#define PID_TRAP_Fa                         33556573   // газовый баллон вкл
#define PID_TRAP_Fb                         33556572   // газовый баллон выкл

#define trapObj(pid)                        (tile_contains_obj_pid(self_tile,self_elevation,pid) == true) \

// Генераторы случайного окружения
#define PID_GENERATOR_POSTER_A              33554561
#define PID_GENERATOR_POSTER_B              33554562
#define PID_GENERATOR_ROADSIGN_A            33554563
#define PID_GENERATOR_ROADSIGN_B            33554564
#define PID_GENERATOR_COAST_JUNK            33554565
#define PID_GENERATOR_ROAD_JUNK             33554566
#define PID_GENERATOR_DESERT_OBJ            33554567
#define PID_GENERATOR_CRITTERS_CAVE         33554568
#define PID_GENERATOR_RESERV_a              33554569
#define PID_GENERATOR_RESERV_b              33554570
#define PID_GENERATOR_RESERV_c              33554571
#define PID_GENERATOR_RESERV_d              33554572

// Кровь
#define PID_BLOOD_1                         33554874   // без костей
#define PID_BLOOD_2                         33554875
#define PID_BLOOD_3                         33554876
#define PID_BLOOD_4                         33554877
#define PID_BLOOD_5                         33554878
#define PID_BLOOD_6                         33554879
#define PID_BLOOD_7                         33554880   //с костями
#define PID_BLOOD_8                         33554881
#define PID_BLOOD_9                         33554882

// Игральные автомат
#define PID_GAME_SLOT_A                    33555542
#define PID_GAME_SLOT_B                    33555543
#define PID_GAME_SLOT_DSTR_A               33555544
#define PID_GAME_SLOT_DSTR_B               33555545

#endif
