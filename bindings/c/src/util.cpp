// Copyright (c) 2018 Shapelets.io
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <arrayfire.h>
#include <khiva_c/util.h>

void check_and_retain_arrays(khiva_array *a, khiva_array *b, af::array &var_a, af::array &var_b) {
    if (a == b) {
        var_a = af::array(*a);
        af_retain_array(a, var_a.get());
        var_b = var_a;
    } else {
        var_a = af::array(*a);
        af_retain_array(a, var_a.get());
        var_b = af::array(*b);
        af_retain_array(b, var_b.get());
    }
}