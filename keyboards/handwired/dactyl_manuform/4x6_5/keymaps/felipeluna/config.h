#pragma once

#include "quantum.h"

#define XXX KC_NO

#define LAYOUT( \
    k00, k01, k02, k03, k04, k05,                          k11, k10, k09, k08, k07, k06, \
    k12, k13, k14, k15, k16, k17,                          k23, k22, k21, k20, k19, k18, \
    k24, k25, k26, k27, k28, k29,                          k35, k34, k33, k32, k31, k30, \
              k36, k37,                                              k40, k39,    \
                        k38, k45, k44,                k48, k49, k41, \
                             k43, k42,                k46, k47 \
) { \
    { k00, k01, k02, k03, k04, k05 }, \
    { k12, k13, k14, k15, k16, k17 }, \
    { k24, k25, k26, k27, k28, k29 }, \
    { XXX, XXX, k36, k37, k38 , XXX }, \
    { XXX, XXX, k42, k43, k44, k45 }, \
\
    { k06, k07, k08, k09, k10, k11 }, \
    { k18, k19, k20, k21, k22, k23 }, \
    { k30, k31, k32, k33, k34, k35 }, \
    { XXX, XXX, k39, k40, k41, XXX }, \
    { XXX, XXX, k46, k47, k48, k49 } \
}
