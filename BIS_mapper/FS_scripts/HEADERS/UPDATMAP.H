#ifndef UPDATMAP_H
#define UPDATMAP_H

//------------------------------------------------------
//---------------------- Параметры освещения карт
//------------------------------------------------------

#define BRIGHT_LIGHT                    (100) // максимальное освещение
#define VAULT_LIGHTING                  (80)  // яркое освещение внутри зданий
#define INDOOR_LIGHT                    (60)  // обычное освещение внутри зданий
#define CAVERN_LIGHT                    (40)  // пещера или подвал
#define DUSK_LIGHT                      (20)  // ночная темень
#define BLACK_LIGHT                     (10)  // нулевая видимость

//------------------------------------------------------
//----------- Установка освещения
//------------------------------------------------------

variable lightParam := 0;

#define setGVARlight(x)                 set_global_var(GVAR_LIGHT_MAP_GLOBAL,x)

#define setGlblMapLight                 if (global_var(GVAR_LIGHT_MAP_GLOBAL) < 0) then begin   \
                                        Natura_Lighting;                                        \
                                        end                                                     \
                                        lightParam := global_var(GVAR_LIGHT_MAP_GLOBAL);        \
                                        if (global_var(GVAR_LIGHT_MAP_BONUS) != 0) then begin   \
                                        lightParam += global_var(GVAR_LIGHT_MAP_BONUS);         \
                                        end                                                     \
                                        if (lightParam > BRIGHT_LIGHT) then begin               \
                                        lightParam := BRIGHT_LIGHT;                             \
                                        end                                                     \
                                        if (lightParam <0) then begin                           \
                                        lightParam := 0;                                        \
                                        end                                                     \
                                        set_light_level(lightParam);                            \

//------------------------------------------------------
//----------- Уличное освещение, зависит от времени суток
//------------------------------------------------------

//Замечание: в F2 часы утра и вечера варьировались от сезона к сезону, но на мой взгляд это излишне.

#define LIGHT_MORNING                   (600)  // утро
#define LIGHT_EVENING                   (1800) // вечер

#define season_morning(when)            ((game_time_hour >= (when)) and (game_time_hour < (when + 100)))
#define season_day(sunrise,sunset)      ((game_time_hour >= (sunrise + 100)) and (game_time_hour < sunset))
#define season_evening(when)            ((game_time_hour >= (when)) and (game_time_hour < (when + 100)))

#define Natura_Lighting                 if (season_morning(LIGHT_MORNING)) then                               \
                                            setGVARlight((game_time_hour - LIGHT_MORNING) + DUSK_LIGHT);      \
                                        else if (season_day(LIGHT_MORNING,LIGHT_EVENING)) then                \
                                            setGVARlight(BRIGHT_LIGHT);                                       \
                                        else if (season_evening(LIGHT_EVENING)) then                          \
                                            setGVARlight(BRIGHT_LIGHT - (game_time_hour - LIGHT_EVENING));    \
                                        else                                                                  \
                                            setGVARlight(DUSK_LIGHT)

//------------------------------------------------------
//---------------------- Виды освещений
//------------------------------------------------------

//#define Lighting                        setGVARlight(BLACK_LIGHT)              // уличное освещение

#define Lighting                        setGVARlight(-1)                        // уличное освещение

#define Black_Lighting                  setGVARlight(BLACK_LIGHT)               // нулевая видимость

#define Darkness                        setGVARlight(DUSK_LIGHT)                // ночная темень

#define Cavern_Lighting                 setGVARlight(CAVERN_LIGHT)              // пещера или подвал

#define Indoor_Lighting                 setGVARlight(INDOOR_LIGHT)              // обычное освещение внутри зданий

#define Vault_Lighting                  setGVARlight(VAULT_LIGHTING)            // яркое освещение внутри зданий

#define Full_Light                      setGVARlight(BRIGHT_LIGHT)              // максимальное освещение

//------------------------------------------------------
//----------------- Обобщенный макрос для скрипта карты
//------------------------------------------------------

//Флаги освещения (задаются для каждого уровня карты):
#define L_STREET                        0  // уличное освещение
#define L_BLACK                         1  // тьма промешная
#define L_DARK                          2  // сумрак
#define L_CAVE                          3  // свещение пещер и подвалов
#define L_ROOM                          4  // обычное освещение внутри зданий
#define L_VAULT                         5  // яркое освещение внутри зданий
#define L_FULL                          6  // максимальное освещение

#define MapLight(flag)                  if (flag == L_BLACK) then begin          \
                                            Black_Lighting;                      \
                                        end else if (flag == L_DARK) then begin  \
                                            Darkness;                            \
                                        end else if (flag == L_CAVE) then begin  \
                                            Cavern_Lighting;                     \
                                        end else if (flag == L_ROOM) then begin  \
                                            Indoor_Lighting;                     \
                                        end else if (flag == L_VAULT) then begin \
                                            Vault_Lighting;                      \
                                        end else if (flag == L_FULL) then begin  \
                                            Full_Light;                          \
                                        end else begin                           \
                                            Lighting;                            \
                                        end                                      \

#define lvlMapLight(a,b,c)              if (dude_elevation == 2) then begin     \
                                            MapLight(c)                         \
                                        end                                     \
                                        else if (dude_elevation == 1) then begin \
                                            MapLight(b)                         \
                                        end                                     \
                                        else begin                              \
                                            MapLight(a)                         \
                                        end                                     \

#define setMapLight(map,a,b,c)          if (cur_map_index == map) then begin    \
                                            lvlMapLight(a,b,c)                  \
                                        end                                     \

#endif
