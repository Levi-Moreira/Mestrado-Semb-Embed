//
// Created by Levi Albuquerque on 05/11/19.
//
#include <vector>
#include <numeric>
#include "../data/file_loading.h"
#include "convolution.h"
#include "../data/data_manipulation.h"
#include "pooling.h"
#include "activation.h"
#include "batch_norm.h"
#include "fully_connected.h"
#include "../constants.h"

#ifndef SEMB_FORWARD_PASS_H
#define SEMB_FORWARD_PASS_H

int forward_pass(const string &filename);

#endif //SEMB_FORWARD_PASS_H
