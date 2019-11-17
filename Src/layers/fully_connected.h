//
// Created by Levi Albuquerque on 05/11/19.
//
#include <vector>
#include <numeric>

using namespace std;
typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;

#ifndef SEMB_FULLY_CONNECTED_H
#define SEMB_FULLY_CONNECTED_H

vector_2d fc_forward(vector_2d &input, vector_2d &weights, vector_2d &bias, int d1, int d2, int d3);

#endif //SEMB_FULLY_CONNECTED_H
