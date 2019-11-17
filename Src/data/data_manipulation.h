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

#ifndef SEMB_DATA_MANIPULATION_H
#define SEMB_DATA_MANIPULATION_H
void copy_on_4_dimension(vector_3d &sliced_weight, vector_4d &v, int dimension1, int dimension2, int dimension3, int c);
vector_4d convert_to_4d(const vector_2d& input);
vector_2d transpose(vector<vector<float>> input, int w, int h);
vector_2d convert_to_2d(const vector_4d &input, int d1, int d2, int d3, int d4, int finalh, int finalw);
#endif //SEMB_DATA_MANIPULATION_H
