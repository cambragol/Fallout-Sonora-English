#ifndef DAYGLOW_H
#define DAYGLOW_H


/***************************************************************
************************ SCRIPTS.H *****************************
***************************************************************/

#define SCRIPT_YSVltDor        (820)
#define SCRIPT_YSVltGen        (821)
#define SCRIPT_YTVltLft        (822)
#define SCRIPT_YTVltWtr        (823)
#define SCRIPT_YTExp           (824)
#define SCRIPT_YSEnd           (825)

#define SCRIPT_YCBossA         (826) // лидер южного лагеря
#define SCRIPT_YCBossB         (827) // лидер северного лагеря
#define SCRIPT_YCDumBos        (828)

#define SCRIPT_YCCafeA         (829) // кафе - южный лагерь
#define SCRIPT_YCCafeB         (830) // кафе - северный лагерь
#define SCRIPT_YCShopA         (831) // магазин - южный лагерь
#define SCRIPT_YCShopB         (832) // магазин - северный лагерь
#define SCRIPT_YCCrvBos        (833) // лидер каравана после спасения
#define SCRIPT_YCBandA         (834)
#define SCRIPT_YCBandB         (835)
#define SCRIPT_YCBandC         (836)

#define SCRIPT_YCPtrlA         (838)
#define SCRIPT_YCPtrlB         (839)
#define SCRIPT_YCTunel         (840)
#define SCRIPT_YSTunel         (842)
#define SCRIPT_YSRolBar        (843)
#define SCRIPT_YCMrdr          (841)
#define SCRIPT_YCBarTlk        (844)
#define SCRIPT_YCCtzn          (845)
#define SCRIPT_YSJunk          (846)
#define SCRIPT_YCRalf          (847)
#define SCRIPT_YCTalius        (848)
#define SCRIPT_YCGopStp        (849)
#define SCRIPT_YSArena         (852)
#define SCRIPT_YCRbtArn        (853)
#define SCRIPT_YSFodMch        (854)
#define SCRIPT_YSRprMch        (855)
#define SCRIPT_YSTunl2         (856)
#define SCRIPT_YCTalGhl        (857)
#define SCRIPT_YSFonars        (858)
#define SCRIPT_YSDumCnA        (859)
#define SCRIPT_YSDumCnB        (860)
#define SCRIPT_YSDumCnC        (861)
#define SCRIPT_YSDumTrs        (862)
#define SCRIPT_YSDumbaA        (863) // турбина - гидравлический клапан #1 (закрытый)
#define SCRIPT_YSDumbaB        (864) // турбина - провода
#define SCRIPT_YSDumbaC        (865) // турбина - переключатель
#define SCRIPT_YSDumbaD        (872) // турбина - гидравлический клапан #2 (открытый)
#define SCRIPT_YSDorBlc        (866)
#define SCRIPT_YSDumCmp        (867)
#define SCRIPT_YSRadio         (868)
#define SCRIPT_YCGomer         (869)
#define SCRIPT_YCFungs         (870)
#define SCRIPT_YSChlRop        (871)
#define SCRIPT_YSRadPtl        (873)
#define SCRIPT_YSChlGen        (875)
#define SCRIPT_YCChlGhl        (876) // обезумевший гуль, сбежавший в Чула-Виста
#define SCRIPT_YTChlMsg        (877)
#define SCRIPT_YSMonoDr        (878)
#define SCRIPT_YSMonoJk        (879)
#define SCRIPT_YSMonoGh        (880)
#define SCRIPT_YSMonoAp        (881)
#define SCRIPT_YSMonoMv        (882)
#define SCRIPT_YSRadIsd        (883)
#define SCRIPT_YSMusic         (884)
#define SCRIPT_YSGuitar        (887)
#define SCRIPT_YSChlHlg        (888)
#define SCRIPT_YCCtzZzz        (889)
#define SCRIPT_YCHsptlA        (890)
#define SCRIPT_YCHsptlB        (891)
#define SCRIPT_YCHsptlC        (892)
#define SCRIPT_YCHsptlD        (893)
#define SCRIPT_YSAutdoc        (894)
#define SCRIPT_YSHspCps        (895)
#define SCRIPT_YSHspGhl        (896)
#define SCRIPT_YSHspRbt        (897)
#define SCRIPT_YCCrvGrd        (898)
#define SCRIPT_YCCrvLed        (899)
#define SCRIPT_YCCrvRun        (900)
#define SCRIPT_YSCrvBag        (901)
#define SCRIPT_YCCrvMtn        (902)
#define SCRIPT_YCRbtCrr        (903)
#define SCRIPT_YCIsdMtA        (904)
#define SCRIPT_YCIsdMtB        (905)
#define SCRIPT_YTHolLvl        (906)
#define SCRIPT_YSPress         (907)
#define SCRIPT_YSHrtVnt        (908)
#define SCRIPT_YSHrtCmp        (909)
#define SCRIPT_YSHrtCmB        (910)
#define SCRIPT_YTAzot          (911)
#define SCRIPT_YSTrgmat        (912)
#define SCRIPT_YSVltCmp        (913)
#define SCRIPT_YSVltCmB        (914)
#define SCRIPT_YCGhlMat        (915)
#define SCRIPT_YCIsdOil        (916)
#define SCRIPT_YCCrazyA        (922)
#define SCRIPT_YCCrazyB        (918)
#define SCRIPT_YCBosGrd        (919)
#define SCRIPT_YIBook          (920)
#define SCRIPT_YCBarMrd        (921)
#define SCRIPT_YCNslBos        (923)
#define SCRIPT_YCNslMtn        (924)
#define SCRIPT_YSNslCaf        (925)
#define SCRIPT_YCNslCaf        (926)
#define SCRIPT_YSHrtStr        (927)
#define SCRIPT_YCCnvBos        (928)
#define SCRIPT_YCCnvGrd        (929)
#define SCRIPT_YCCnvGhl        (930)
#define SCRIPT_YINslBns        (931)
#define SCRIPT_YCDnvnA         (932)
#define SCRIPT_YCDnvnB         (933)
#define SCRIPT_YCDnvnC         (934)
#define SCRIPT_YCCnvCrz        (935)
#define SCRIPT_YSRndmCr        (936)
#define SCRIPT_YCBandit        (937)
#define SCRIPT_YSPoster        (938)
#define SCRIPT_YTWave          (939)
#define SCRIPT_YSMonoPw        (940)
#define SCRIPT_YSArcada        (941)
#define SCRIPT_YCMessag        (942)
#define SCRIPT_YTDumScn        (943)
#define SCRIPT_YCDeSant        (944)
#define SCRIPT_YCLiveA         (945)
#define SCRIPT_YCLiveB         (946)
#define SCRIPT_YCIsdCrh        (947)
#define SCRIPT_YSMonStr        (948)
#define SCRIPT_YCFinal         (949)
#define SCRIPT_YCPirTlk        (950)
#define SCRIPT_YCPirGrd        (951)
#define SCRIPT_YSPirBrt        (952)
#define SCRIPT_YCMtnSld        (953)
#define SCRIPT_YIPwrArm        (954)
#define SCRIPT_YCCrazyC        (955)
#define SCRIPT_YCCrazyD        (956)
#define SCRIPT_YSSantRb        (957)
#define SCRIPT_YCSantRb        (958)
#define SCRIPT_YCSantGd        (959)
#define SCRIPT_YCSantEn        (960)
#define SCRIPT_YCSantPs        (961)
#define SCRIPT_YCCrazyE        (962)
#define SCRIPT_YCSantRt        (963)
#define SCRIPT_YCSantBn        (964)
#define SCRIPT_YSSantCr        (965)
#define SCRIPT_YCSantDg        (966)
#define SCRIPT_YCSantVt        (967)
#define SCRIPT_YSSantVt        (968)
#define SCRIPT_YCOldTlk        (969)
#define SCRIPT_YCSantSt        (970)
#define SCRIPT_YCTitr          (971)
#define SCRIPT_YCSantBl        (972)
#define SCRIPT_YCSantMt        (973)
#define SCRIPT_YCMrcSnt        (974)
#define SCRIPT_YSTorped        (975)
#define SCRIPT_YSGaubi         (976)
#define SCRIPT_YSGaubDt        (977)
#define SCRIPT_YSCompSp        (978)
#define SCRIPT_YTElectr        (979)
#define SCRIPT_YSElectr        (980)
#define SCRIPT_YCIsdMor        (981)
#define SCRIPT_YCIsdTlk        (982)
#define SCRIPT_YIDwlBox        (983)
#define SCRIPT_YCMutCap        (984)
#define SCRIPT_YCMutBos        (985)
#define SCRIPT_YSIsdFir        (986)
#define SCRIPT_YSHole          (987)
#define SCRIPT_YCSprMtn        (988)
#define SCRIPT_YSDumInf        (989)


/***************************************************************
************************ GLOBAL.H ******************************
***************************************************************/

#define GVAR_DAYGLOW_VISITED                 (508) // путешествие ГГ в Сияние Дня: 0 - еще не посетил, 1 - отправился, 2 - вернулся
#define GVAR_DAYGLOW_PASS                    (521) // пропуск ГГ через границу: -1 пропуск обнулен, 0 - еще не получен, 1 - в процессе получения, 2 - ГГ прошел мимо пограничников, 10 - ГГ получил пропуск легально.
#define GVAR_VAULT24_VISITED                 (518) // квест посетить убежище 24: 0 - не взят, 1 - взят, 2 - завершен (ГГ посетил в убежище)
#define GVAR_DAYGLOW_QST_ROBOT               (519) // квест устранить робота на корриде: <0 - провален, 0 - не взят, 1 - взят, 2 - завершен
#define GVAR_DAYGLOW_STATUS_ROBOT            (520) // статус робота на корриде: <0 - уничтожен, 0 - активен и враждебен, 1 - перепрограммирован на мирный режим
#define GVAR_DAYGLOW_CONTRACT_VISKI          (550) // контракт на доставку виски: <0 - разорван, 0 - не заключен, 1 - заключен, >=2 - доставлена минимум одна бутылка
#define GVAR_DAYGLOW_CONTRACT_COFFE          (551) // контракт на доставку кофе: <0 - разорван, 0 - не заключен, 1 - заключен, >=2 - доставлена минимум одна банка
#define GVAR_DAYGLOW_TUNEL_KNOW              (523) // даёт сигнал для появления секретного спуска через туннельный дом
#define GVAR_DAYGLOW_A_GHOST                 (524) // убийство враждебного гуля в часовне: 0 - не взят, 1 - взят, >=2 - завершен любым способом
#define GVAR_DAYGLOW_MAIN_A                  (525) // главквест Сан-Исидро 1 (электростанция): <0 - провален, 0 - не взят, 1 - взят, > 1 - завершен
#define GVAR_DAYGLOW_MAIN_B                  (526) // главквест Сан-Исидро 2 (радиостанция): <0 - провален, 0 - не взят, 1 - взят, > 1 - завершен
#define GVAR_DAYGLOW_MAIN_C                  (527) // главквест Старого Города 1 (спасение каравана): <0 - провален, 0 - не взят, 1 - взят, > 1 - завершен
#define GVAR_DAYGLOW_MAIN_D                  (528) // главквест Старого Города 2 (сокровища Коронадо): < 0 - провален, 0 - не взят, 1 - взят, >= 100 - завершен полностью (100 взрывом, 101 в угоду Густаво, 102 в угоду Батлера, 103 в угоду Братства Стали, 104 анархия после смерти лидеров)
#define GVAR_DAYGLOW_TURBINA                 (529) // состояние ГЭС Бонита: <0 - разрушена, 0 - ничего, 1 - открыт клапан гидроагрегата, 2 - провода починены, 3 - рычаг опущен, 4 - ток направлен на подстанцию, 5 - включена подстанция (квест завершен), 6 - ГГ отчитался перед гулем на дамбе
#define GVAR_DAYGLOW_RADIO                   (530) // состояние радиостанции СанИсидро: <= 0 - не работает, 1 - восстановлена, 2 - ГГ несёт голодиск в Старый Город, 3 - ГГ отнёс голодиск в Старый Город
#define GVAR_DAYGLOW_STATUS_GONZO            (531) // статус безумца Гонзо: < 0 - убит, 0 - не определен, 1 - изолирован от общества
#define GVAR_DAYGLOW_STATUS_MONORAIL         (532) // статус монорельсовой дороги: 0 - не определен, 1 - ГГ получил задание на починку, 2 - линия работает
#define GVAR_DAYGLOW_MONORAIL_APPARAT        (533) // состояние аппаратуры на станции монорельса: 0 - не работает, 1 - изъята на починку, 2 - работает
#define GVAR_DAYGLOW_MONORAIL_ENERGY         (534) // энергообеспечение станций монорельса: 0 - нет энергии, 2 - энергия подаётся
#define GVAR_DAYGLOW_MONORAIL_MOVETO         (535) // тригер для перемещения ГГ на новую станцию монорельса
#define GVAR_DAYGLOW_PATRUL_SIGNAL_NON       (536) // сигнал отбоя роботам-пограничникам Сан-Исидро
#define GVAR_DAYGLOW_QST_MARIACHI            (537) // квест мариачи: 0 - не взят, 1 - взят (починка гитары), 2 - в процессе (собрать коллектив), 3 - завершен
#define GVAR_DAYGLOW_MARIACHI_A              (538) // статус 2го мариачи: -1 - погиб, 0 - не определен, 1 - в пути с ГГ, 2 - стоит на сцене
#define GVAR_DAYGLOW_MARIACHI_B              (539) // статус 3го мариачи: -1 - погиб, 0 - не определен, 1 - в пути с ГГ, 2 - стоит на сцене
#define GVAR_DAYGLOW_CHULA_ROPE              (540) // даёт сигнал для появления веревочного спуска в Чула-Виста Отей
#define GVAR_DAYGLOW_QST_CARAVAN             (541) // квест каравана по поиску вещей: <0 - провален, 0 - не взят, 1 - взят, >=2 - завершен частично или полностью
#define GVAR_DAYGLOW_STATUS_RUTGER           (542) // статус начальника каравана: < 0 - мертв, 0 - не определен, 1 - спасен из засады и появляется в лагере гулей
#define GVAR_DAYGLOW_STATUS_CARAVAN          (543) // выжившие караванщики после засады + поиск артефактов:
                                                    /*
                                                    - bit_1  охранник 1 мужик выжил
                                                    - bit_2  охранник 2 женщина выжила
                                                    - bit_3  охранник 3 в металле выжил
                                                    - bit_4  брамин 1
                                                    - bit_5  брамин 2
                                                    - bit_6  артефакт 1 найден и передан заказчику
                                                    - bit_7  артефакт 2 найден и передан заказчику
                                                    - bit_8  артефакт 3 найден и передан заказчику
                                                    - bit_9  артефакт 4 найден и передан заказчику
                                                    - bit_10 артефакт 5 найден и передан заказчику
                                                    - bit_11 ГГ прочитал книгу о Сан-Диего
                                                    - bit_12  охранник 1 мужик мертв
                                                    - bit_13  охранник 2 женщина мертва
                                                    - bit_14  охранник 3 в металле мертв
                                                    - bit_15  ГГ получил сигнал от осажденного БС
                                                    - bit_16  ГГ обнаружил люк из Сердца к Кафе
                                                    - bit_17  ГГ обнаружил люк из Сердца к Италии
                                                    - bit_18  ГГ узнать местоположение тайника БС на пирсе
                                                    - bit_19  осажденный БС на карте кафе погиб
                                                    - bit_20  ГГ получил сообщение от робоглаза с приглашением
                                                    - bit_21  ГГ обнаружил люк из ЧулаВиста к пирсам
                                                    - bit_22  ГГ обнаружил люк из пирса в ЧулаВиста
                                                    - bit_23  Руперт (муж Джуди) погиб
                                                    - bit_24  ГГ узнал, что Руперт мог направиться в отель
                                                    - bit_25  Джуди (жена Руперта) погибла
                                                    - bit_26  ГГ получил минизадание раздобыть программу для робота-админа
                                                    - bit_27  ГГ получил минизадание раздобыть старое кино
                                                    - bit_28  ГГ посетил дамбу Бонита
                                                    - bit_29  ГГ посетил Старый Город
                                                    - bit_30  ДеСанти заказал ГГ
                                                    - bit_31  ГГ узнал о тайнике Выходца в парке Бальбоа
                                                    */
#define GVAR_DAYGLOW_STATUS_GOMER            (544) // статус рядового Кучи: <= -99 - убит, -1 - стал врагом ГГ, 0 - не определен, 1 - стоит в ожидании ГГ, 2 - следует в партии ГГ
#define GVAR_DAYGLOW_MUTGOPSTROP             (545) // гопстоп гуля супермутантами на карте моста: <0 - событие отменено, 0 - не инициировано, 1 - инициировано, 2 - завершено любым способом
#define GVAR_DAYGLOW_STATUS_EL_TEMOR_ROJO    (546) // статус когтя смерти в Сиянии: < 0 - убит, 0 - жив
#define GVAR_DAYGLOW_STATUS_BOSS_A           (548) // статус южного лидера: < 0 - мертв, 0 - жив, 1 - выиграл в финале
#define GVAR_DAYGLOW_STATUS_BOSS_B           (549) // статус северного лидера: < 0 - мертв, 0 - жив, 1 - выиграл в финале
#define GVAR_DAYGLOW_QST_DONOVAN             (553) // квест найти Донована: < 0 - провален, 0 - не взят, 1 - взят, 2 - ГГ нашел Донована и несет его к медику, 3 - ГГ отнес к медику, медик просит инвентарь, 4 - квест завершен
#define GVAR_DAYGLOW_QST_MORODERS            (554) // допквест Старого Города (старатели на заводе): <0 - провален, 0 - не взят, 1 - взят, > 1 - завершен любым способом
#define GVAR_DAYGLOW_FABRICA_STATUS          (555) // квест старателей на Заводе: <0 - ГГ перебил всех старателей, 1 - ГГ взял квест старателей на чипы, 2 - ГГ выполнил условия старателей или уговорил их уйти
#define GVAR_DAYGLOW_FABRICA_GHOULLIFE       (556) // число погибших на заводе гулей
#define GVAR_DAYGLOW_PROPAGANDA_POSTERS      (557) // число изученных агиток
#define GVAR_DAYGLOW_QST_LIVE                (558) // любовная история: < 0 - провален, 0 - не взят, 1 - взят, >= 2 - завершен (при 10 муж перемещается в СанИсидро)
#define GVAR_DAYGLOW_STATUS_ZERAF            (559) // статус Зераха в госпитале: <0 - погиб, 0 в заложниках, 1 в процессе освобождения, 2 свободен (сбежал), 3 свободен (выкуплен)
#define GVAR_DAYGLOW_CONTRACT_CAFE_CURIER    (560) // подработка курьером в кафе: <0 - провален, 0 - не взят, 1 - взят, >=(1 + 5) - завершен (5 предметов нужно отдать 5 нпс) >=10 завершен успешно
#define GVAR_DAYGLOW_CORONADO_CODE_SIGNAL    (561) // допуск на базу Коронадо: 0 не получен, 1 получен
#define GVAR_DAYGLOW_QST_BUTLEGER            (562) // квест ДеСанти на поиск детали: -1 провален, 0 не получен, 1 получен, 2 - деталь у ГГ, 10 - ГГ сдал деталь ДеСанти, 20 - ГГ сдал деталь в Сан-Исидро
#define GVAR_DAYGLOW_QST_CREDITS             (563) // квест ДеСанти собрать долги: -1 провален, 0 не получен, 1 получен, 2 - ГГ отдал долг
#define GVAR_DAYGLOW_QST_BANDITS             (564) // квест ДеСанти собрать дань со старателей: -1 провален, 0 не получен, 1 получен, 10 гг отказался, 20 - квест завершен успешно
#define GVAR_DAYGLOW_QST_SUPERMUT            (565) // квест ДеСанти нанять супермутанта: -1 провален, 0 не получен, 1 получен, 2 завершен
#define GVAR_DAYGLOW_DESTROY_TIMER           (566) // таймер до взрыва торпед
#define GVAR_DAYGLOW_CORONADO_STATUS         (567) // статус военной базы: -1 уничтожена, 0 в боевой готовности, 1 неактивна
#define GVAR_DAYGLOW_QST_GOMER               (568) // личный квест Кучи:
                                                     /*
                                                     -1  провален
                                                     0   разговор с Кучей еще не состоялся
                                                     1   ГГ получил у Кучи наводку на отряд
                                                     2   ГГ узнал местонахождения отряда
                                                     3   ГГ нашел отряд и поговорил с ним получив квест
                                                     4   ГГ обсудил квест отряда с Кучей
                                                     10  ГГ спас капитана Кучи
                                                     11  ГГ не спас или заложил отряд
                                                     100 Куча решил остаться с гулями
                                                     200 Куча решил отправиться с отрядом
                                                     */
#define GVAR_DAYGLOW_QST_GOMERSUPERMUT       (569) // квест отряда Кучи: -1 провален, 0 не взят, 1 начат, 2 завершен успешно
#define GVAR_DAYGLOW_STATUS_GOMER_CAP        (570) // статус главы отряда Кучи: -1 умер, 0 в плену, 1 освобожден


/***************************************************************
************************ DEFINE.H ******************************
***************************************************************/

#define MOVIE_SAN_DIEGO_VISID      MOVIE_ENCLAVE

#define HEAD_DAYGLOW_BOSS_A       (24)  // Сияние: лидер южного лагеря
#define HEAD_DAYGLOW_BOSS_B       (25)  // Сияние: лидер северного лагеря

#define GomerAttakDude                   if (partyPidMtn!=0) then begin \
                                         add_timer_event(partyPidMtn, 0, 666); \
                                         end                            \


/***************************************************************
************************ MAPS.H ********************************
***************************************************************/

#define MAP_DAYGLOW_START           (131) // руины Тихуаны
#define MAP_DAYGLOW_CAMP_SAN_ISIDRO (132) // южный лагерь (Сан-Исидро)
#define MAP_DAYGLOW_BONITA_DUM      (133) // восточный лагерь (дамба)
#define MAP_DAYGLOW_CAMP_OLD_TOWN   (134) // северный лагерь (Старый Город)
#define MAP_DAYGLOW_PATRUL          (135)
#define MAP_DAYGLOW_CHULAVISTA      (136)
#define MAP_DAYGLOW_NATIONALCITY    (137)
#define MAP_DAYGLOW_CITYHEART       (138)
#define MAP_DAYGLOW_PIRS            (139)
#define MAP_DAYGLOW_VAULT           (140)
#define MAP_DAYGLOW_CORONADO        (141) // база ВМС США


/***************************************************************
************************ ITEMPID.H *****************************
***************************************************************/

//Weapon
#define PID_W_SPEAR_ELECTRO                 (119)
#define PID_W_SPEAR_ELECTRO_UPGD            (483)
#define PID_W_TASER                         (484)

//Key
#define PID_KEY_BONITADUM_A                 (457)
#define PID_KEY_BONITADUM_B                 (458)
#define PID_KEY_CORONADO_A                  (490)
#define PID_KEY_CORONADO_B                  (491)

//Quest
#define PID_Q_DAYGLOW_GUITAR                (448)
#define PID_Q_DAYGLOW_TRUBA                 (449)
#define PID_Q_DAYGLOW_GHOULBODY             (450)
#define PID_Q_DAYGLOW_BORDERBADGE_A         (451)
#define PID_Q_DAYGLOW_BORDERBADGE_B         (452)
#define PID_Q_DAYGLOW_DUM_PLAN              (461)
#define PID_Q_DAYGLOW_HOLO_GUSTAVO          (462)
#define PID_Q_DAYGLOW_TRAIL_DETALS_A        (464)
#define PID_Q_DAYGLOW_TRAIL_DETALS_B        (465)
#define PID_Q_DAYGLOW_PATRUL_CODES          (466)
#define PID_Q_DAYGLOW_HOLOMODUL             (468)
#define PID_Q_DAYGLOW_BOOK_SANDIEGO         (476)
#define PID_Q_DAYGLOW_BIOGEL                (480)
#define PID_Q_DAYGLOW_CHIP                  (481)
#define PID_Q_DAYGLOW_CODE_CORONADO         (482)
#define PID_Q_DAYGLOW_CODE_HANDY            (485)
#define PID_Q_DAYGLOW_FILM                  (486)
#define PID_Q_DAYGLOW_FOODPROCESSOR         (487)
#define PID_Q_DAYGLOW_ROCKET                (488)
#define PID_Q_DAYGLOW_GAUBI_DETALS          (489)

#define PID_Q_DAYGLOW_CARAVAN_1             (469) // Водяной чип
#define PID_Q_DAYGLOW_CARAVAN_2             (470) // Печатная плата
#define PID_Q_DAYGLOW_CARAVAN_3             (471) // Диагностическая плата
#define PID_Q_DAYGLOW_CARAVAN_4             (472) // Топливный контроллер
#define PID_Q_DAYGLOW_CARAVAN_5             (473) // Чертежи винтокрыла


/***************************************************************
************************ MAPVAR.H ******************************
***************************************************************/

//------------------------------- Стартовая карта

#define MVAR_DIEGOSTART_FAIL             (1) // фиксирует гибель гуля-проводника на этой карте
#define MVAR_DIEGOSTART_DUDEMANY         (2) // фиксирует число крышек у ГГ при первом посещении

//------------------------------- Южный лагерь (Сан-Исидро)

#define MVAR_DIEGO_A_GHOST               (1) // состояние обезумевшего гуля в часовне: -1 мертв, - 100 враждебен к ГГ, 1 разместился в часовне впервые после ЧулаВиста
#define MVAR_DIEGO_A_SHOP                (2) // босс разрешил находиться в лагере
#define MVAR_DIEGO_A_CONFESION           (3) // подсчет реплик гуля в исповедальне

//------------------------------- Офис пограничного патруля

#define MVAR_DIEGOPTRL_CODE              (1) // код от сейфа на автозаправке
#define MVAR_DIEGOPTRL_MUTNTLIFE         (2) // статус супермутантов на карте разрушенного моста: <0 - покинули карту мирно, 1 - убит один, 2 - убит второй
#define MVAR_DIEGOPTRL_ROBOT_BRIDGE      (3) // число уничтоженных роботов на уровне с мостом
#define MVAR_DIEGOPTRL_SIGNAL_ACTIV      (4) // включение сигнализации в тюрьме
#define MVAR_DIEGOPTRL_GOMER_STOP_DIALOG (5) // принудительный диалог Кучи
#define MVAR_DIEGOPTRL_PALADIN_STOP_DIALOG (6) // принудительный диалог паладина: -1 полный допуск к территории, 0 не состоялся, 1 первое предупреждение, 2 последнее предупреждение, 3 атака

//------------------------------- Чула-Виста Торговый центр

#define MVAR_DIEGOCHULA_ELECTR           (1) // 0 - бездействие, 1 - включение электропитания и уличного освещения
#define MVAR_DIEGOCHULA_HOLO             (2) // -1 - изъят модуль из голопроектора, 0 - бездействие, 1 - включение рекламных голограмм, 2 - гуль поддался действию голограммы

//------------------------------- Дамба

#define MVAR_DIEGODUM_ALARMA             (1) // включение сирены
#define MVAR_DIEGODUM_CONSOLCENTER       (2) // взлом панели управления
#define MVAR_DIEGODUM_SOLAR_A            (3) // освещение на ур 1
#define MVAR_DIEGODUM_SOLAR_B            (4) // освещение на ур 2
#define MVAR_DIEGODUM_SOLAR_C            (5) // уличное освещение на ур 0
#define MVAR_DIEGODUM_SOLAR_D            (6) // внутреннее освещение на ур 0
#define MVAR_DIEGODUM_ROBOTS             (7) // боевая готовность роботов: 0 - агрессивные, 1 - мирные
#define MVAR_DIEGODUM_POWERPOLE          (8) // отключено силовое поле к центру управлению
#define MVAR_DIEGODUM_PAS_BIT            (9) // битовые маски для переключателей у подстанции
#define MVAR_DIEGODUM_PAS_NEW           (10) // вводимые значения битовых масок для переключателей у подстанции

//------------------------------- Госпиталь + Кафе + Завод

//#define MVAR_DIEGOHSPTL_GHOULLIFE        (1) // не используется
#define MVAR_DIEGOHSPTL_TIMER            (2) // таймер до исчезновения черных старателей с карты
#define MVAR_DIEGOHSPTL_ALARM            (3) // тревога: 1 - сбегаются в холл, 2 - сбегаются в операционную
#define MVAR_DIEGOHSPTL_CAPS             (4) // знание о тайнике в почтовом ящике
#define MVAR_DIEGOHSPTL_BANDLIFE         (5) // число еще живых черных старателей
#define MVAR_DIEGOHSPTL_ROBOT            (6) // состояние робота-медика: <0 - погиб, 0 - сломан, 1 - починен
#define MVAR_DIEGOCAFE_MUTANT_LIFE       (7) // число погибших или сбежавших супермутантов на карте кафе
#define MVAR_DIEGOCAFE_GHOUL_STATUS      (8) // появление гуля из холодильника
#define MVAR_DIEGOCAFE_MUTANT_QST        (9) // фиксация событий в стычке БС и супермутантов
#define MVAR_DIEGOCAFE_FABRICA_LIFE     (10) // число еще живых старателей
#define MVAR_DIEGOCAFE_FABRICA_ENEMY    (11) // агрессивность старателей по отношению к ГГ
#define MVAR_DIEGOCAFE_GHOUL_BODY       (12) // создание тела гуля возле бандитов

//------------------------------- Северный лагерь (Старый Город)

#define MVAR_DIEGO_C_GUITAR              (1) // состояние гитары: 0 - не определено, 1 - струны заменены, 2 - починка засчитана владельцем
#define MVAR_DIEGO_C_CARREGULATOR        (2) // 4 - появление гуля с топливным регулятором на карте осады
#define MVAR_DIEGO_C_MUTANT_LIFE         (3) // число еще живых супермутантов на карте засады. При <=-100 становятся мирными и уходят с карты.
#define MVAR_DIEGO_C_MUTANT_PARTY        (4) // ГГ поговорил с начальником каравана на месте засады
#define MVAR_DIEGO_C_ROBOT_TIMER         (5) // время до появления робота после всех событий на карте засады
#define MVAR_DIEGO_C_BAR_COMBAT          (6) // драка в баре: <0 прервана, 0 еще не состоялась, 1 началась, 2 закончилась
#define MVAR_DIEGO_C_BAR_MUSIC           (7) // включение музыки в баре

//------------------------------- Сердце Сан-Диего

#define MVAR_DIEGOHEART_MEAT_HEX         (1) // номер гекса где была размещена приманка для когтя смерти
#define MVAR_DIEGOHEART_DWCL_VISBL       (2) // отображение когтя смерти на карте

//------------------------------- Пирс + Италия + Парк Бальбоа

#define MVAR_DIEGOPIRS_CRAZY_AMNT        (1) // число погибших гулей-безумцев в Маленькой Италии
#define MVAR_DIEGOPIRS_DESANTI_ROBOT     (2) // статус робота - администратора Де Санти: <0 уничтожен, 0 не работоспособен, 1 отремонтирован, 2 запрограммирован на работу
#define MVAR_DIEGOPIRS_DESANTI_SID       (3) // статус Сида: <0 мертв, 0 не изменен, 1 стал работать на ДеСанти
#define MVAR_DIEGOPIRS_DESANTI_PUSHER    (4) // квест по устранению Сида: <0 провален, 0 не взят, 1 взят, 2 завершен
#define MVAR_DIEGOPIRS_DESANTI           (5) // статус ДеСанти: <0 мертв, 0 жив
#define MVAR_DIEGOPIRS_DESANTI_RATS      (6) // количество убитых крыс в номере отеля
#define MVAR_DIEGOPIRS_RETARN_HEX        (7) // точка возврата с острова
#define MVAR_DIEGOPIRS_DESANTI_VENTIL    (8) // статус сломанной вентиляции: 0 сломана, 1 починена
#define MVAR_DIEGOPIRS_DESANTI_MRDR_KILL (9) // число погибших черных старателей по квесту ДеСанти

//------------------------------- Убежище

#define MVAR_DIEGOVLT_ENERGY             (1) // включение генератора
#define MVAR_DIEGOVLT_WATER              (2) // откачка воды

//------------------------------- Военная база

#define MVAR_DIEGOCORONADO_GAUBI         (1) // гаубица: 0 не работает, 1 починена, 2 заряжена, 3 выстерлила
#define MVAR_DIEGOCORONADO_ELECTRO       (2) // активность электротригера


#endif
