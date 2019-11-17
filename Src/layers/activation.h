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


#ifndef SEMB_ACTIVATION_H
#define SEMB_ACTIVATION_H
vector_4d relu(vector_4d &input,
               int m,
               int n_H,
               int n_W,
               int n_C);

vector_2d relu_2d(vector_2d &input,
                  int H,
                  int W);
float sigmoid(float input);
#endif //SEMB_ACTIVATION_H
