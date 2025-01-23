#ifndef ANIMCOMD_H
#define ANIMCOMD_H

//------------------------------------------------------
//---------------------- Анимационные опции
//------------------------------------------------------
#define ANIMATE_WALK                (0)
#define ANIMATE_RUN                 (1)
#define ANIMATE_INTERRUPT           (16)

#define ANIMATE_FORWARD             (0)
#define ANIMATE_REVERSE             (1)

#define animate_move_to_tile(X)         animate_move_obj_to_tile(self_obj, X, ANIMATE_WALK)
#define animate_run_to_tile(X)          animate_move_obj_to_tile(self_obj, X, ANIMATE_RUN)
#define animate_stand                   animate_stand_obj(self_obj)
#define animate_stand_reverse           animate_stand_reverse_obj(self_obj)
#define animate_move_to_tile_force(X)   animate_move_obj_to_tile(self_obj, X, (ANIMATE_WALK bwor ANIMATE_INTERRUPT))
#define animate_run_to_tile_force(X)    animate_move_obj_to_tile(self_obj, X, (ANIMATE_RUN bwor ANIMATE_INTERRUPT))
#define ANIMATE_ROTATION                (1000)
#define ANIMATE_SET_FRAME               (1010)
#define MAX_ROTATIONS                   (6)
#define animate_rotation(X)             anim(self_obj, ANIMATE_ROTATION, X)
#define animate_set_frame(FRAME)        anim(self_obj, ANIMATE_SET_FRAME, FRAME)

//------------------------------------------------------
//---------------------- Коды анимаций
//------------------------------------------------------
//--- базовые 0-19
#define ANIM_stand                    (0)
#define ANIM_walk                     (1)
#define ANIM_jump_begin               (2)
#define ANIM_jump_end                 (3)
#define ANIM_climb_ladder             (4)
#define ANIM_falling                  (5)
#define ANIM_up_stairs_right          (6)
#define ANIM_up_stairs_left           (7)
#define ANIM_down_stairs_right        (8)
#define ANIM_down_stairs_left         (9)
#define ANIM_magic_hands_ground      (10)
#define ANIM_magic_hands_middle      (11)
#define ANIM_magic_hands_up          (12)
#define ANIM_dodge_anim              (13)
#define ANIM_hit_from_front          (14)
#define ANIM_hit_from_back           (15)
#define ANIM_throw_punch             (16) // удар рукой
#define ANIM_kick_leg                (17)
#define ANIM_throw_anim              (18)
#define ANIM_running                 (19)
//--- падение и смерть   20-35
#define ANIM_fall_back               (20)
#define ANIM_fall_front              (21)
#define ANIM_bad_landing             (22)
#define ANIM_big_hole                (23)
#define ANIM_charred_body            (24)
#define ANIM_chunks_of_flesh         (25)
#define ANIM_dancing_autofire        (26)
#define ANIM_electrify               (27)
#define ANIM_sliced_in_half          (28)
#define ANIM_burned_to_nothing       (29)
#define ANIM_electrified_to_nothing  (30)
#define ANIM_exploded_to_nothing     (31)
#define ANIM_melted_to_nothing       (32)
#define ANIM_fire_dance              (33) // огненный танец
#define ANIM_fall_back_blood         (34)
#define ANIM_fall_front_blood        (35)
//--- поднимается  36-37
#define ANIM_prone_to_standing       (36)
#define ANIM_back_to_standing        (37)
//--- использование оружия 38-47
#define ANIM_take_out                (38)
#define ANIM_put_away                (39)
#define ANIM_parry_anim              (40) // парирует удар
#define ANIM_thrust_anim             (41) // удар копьем
#define ANIM_swing_anim              (42) // удар ножом свингом
#define ANIM_point                   (43)
#define ANIM_unpoint                 (44)
#define ANIM_fire_single             (45) // одиночный выстрел
#define ANIM_fire_burst              (46) // очередь
#define ANIM_fire_continuous         (47)
//--- однокадровые анимации  48-63
#define ANIM_fall_back_sf            (48)
#define ANIM_fall_front_sf           (49)
#define ANIM_bad_landing_sf          (50)
#define ANIM_big_hole_sf             (51)
#define ANIM_charred_body_sf         (52)
#define ANIM_chunks_of_flesh_sf      (53)
#define ANIM_dancing_autofire_sf     (54)
#define ANIM_electrify_sf            (55)
#define ANIM_sliced_in_half_sf       (56)
#define ANIM_burned_to_nothing_sf    (57)
#define ANIM_electrified_to_nothing_sf  (58)
#define ANIM_exploded_to_nothing_sf  (59)
#define ANIM_melted_to_nothing_sf    (60)
#define ANIM_fire_dance_sf           (61)
#define ANIM_fall_back_blood_sf      (61)
#define ANIM_fall_front_blood_sf     (62)
#define ANIM_called_shot_pic         (63)
#define ANIM_max_anim                (65)

//------------------------------------------------------
//---------------------- Команды для анимации
//------------------------------------------------------
#define RB_UNRESERVED                 1    // unreserved animation sequence, may fail if no available slots
#define RB_RESERVED                   2    // reserved animation sequence, should never fail

#define REG_ANIM_BEGIN                1
#define REG_ANIM_CLEAR                2
#define REG_ANIM_END                  3

#define reg_anim_begin()              reg_anim_func(REG_ANIM_BEGIN, RB_UNRESERVED)
#define reg_anim_clear(who)           reg_anim_func(REG_ANIM_CLEAR, who)
#define reg_anim_end()                reg_anim_func(REG_ANIM_END, 0)

#endif
