#ifndef RANGERS_H
#define RANGERS_H

//--- Переменные по квесту кадета Пресли

#define MILTON_ENEMY_TO_DUDE         (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_1) != 0) \

#define DEAD_MILTON_CHILD            (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_3) != 0) \

#define DEAD_MILTON_MSTR             (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_4) != 0) \

#define DEAD_MILTON_MISS             (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_5) != 0) \

#define RATKING_LIFE                 (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_6) == 0) \

#define RATKING_DEAD                 (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_6) != 0) \

#define MISSIA_STOP                  (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_7) == 0) \

#define MISSIA_START                 (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_7) != 0) \

#define BANDIT_INVISIBLE             (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_8) == 0) \

#define BANDIT_VISIBLE               (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_8) != 0) \

#define BANDIT_LIFE                  (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_2) == 0) \

#define BANDIT_DEAD                  (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_2) != 0) \

#define BANDIT_RUN                   (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_2) != 0) \

#define DUDE_ESCAPED                 (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_13) != 0) \

#define MILTON_ESCAPED               (gvar_bit(GVAR_RANGERS_QST_CADET_MASK, bit_14) != 0) \

//--- Переменные по квесту торговца Флика

#define Flick_Visible                set_obj_visibility(self_obj, 0);           \
                                     if (cur_map_index == MAP_RANGERS_ROAD) then begin \
                                        if (global_var(GVAR_RANGERS_QST_MOR_STATUS) != 2) then begin \
                                        set_obj_visibility(self_obj, 1);        \
                                        end                                     \
                                     end                                        \
                                     else if (cur_map_index == MAP_RANGERS_BASA) then begin \
                                        if (global_var(GVAR_RANGERS_QST_MOR_STATUS) > 0) then begin \
                                        set_obj_visibility(self_obj, 1);        \
                                        end                                     \
                                     end                                        \
                                     if (global_var(GVAR_STATUS_RANGERS_FLICK) > 0) then begin \
                                        set_obj_visibility(self_obj, 1);        \
                                     end                                        \
                                     else if (getQuest(GVAR_RANGERS_QST_MOR) >= qEnd) then begin \
                                        set_obj_visibility(self_obj, 1);        \
                                     end                                        \

#endif
