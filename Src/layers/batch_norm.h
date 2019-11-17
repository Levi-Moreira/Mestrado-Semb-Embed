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


#ifndef SEMB_BATCH_NORM_H
#define SEMB_BATCH_NORM_H

vector_4d batch_norm_4d(vector_4d &input, vector_1d &gamma, vector_1d &beta, vector_1d &mean, vector_1d &variance, float eps, int d1, int d2, int d3, int d4);

vector_2d batch_norm_2d(vector_2d &input, vector_1d &gamma, vector_1d &beta, vector_1d &mean, vector_1d &variance, float eps, int d1, int d2);

#endif //SEMB_BATCH_NORM_H
