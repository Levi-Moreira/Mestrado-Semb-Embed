//
// Created by Levi Albuquerque on 04/11/19.
//
#include <vector>
#include <numeric>
using namespace std;
typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;


#ifndef SEMB_POOLING_H
#define SEMB_POOLING_H
vector_4d maxpool(vector_4d &input,
                  int m,
                  int n_H_prev,
                  int n_W_prev,
                  int n_C_prev,
                  int f_h,
                  int f_w,
                  int stride_h,
                  int stride_w);
#endif //SEMB_POOLING_H
