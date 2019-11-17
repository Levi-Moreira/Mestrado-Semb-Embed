//
// Created by Levi Albuquerque on 04/11/19.
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <numeric>
#include <cmath>

using namespace std;

typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;

#ifndef SEMB_CONVOLUTION_H
#define SEMB_CONVOLUTION_H
vector_4d convolution(
        vector_4d &A_prev,
        int m,
        int n_H_prev,
        int n_W_prev,
        int n_C_prev,
        vector_4d &weight,
        vector_4d &bias,
        int f_h,
        int f_w,
        int n_C,
        int stride,
        int padding);
vector_3d create_slice(vector_2d &v, int vert_start, int vert_end, int hor_start, int hor_end);
#endif //SEMB_CONVOLUTION_H
