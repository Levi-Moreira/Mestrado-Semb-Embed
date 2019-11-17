//
// Created by Levi Albuquerque on 03/11/19.
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
#ifndef SEMB_FILE_LOADING_H
#define SEMB_FILE_LOADING_H
vector_2d read_data_from_file_with_comma(const string &filename, int channels);
vector_1d read_data_from_file_with_new_line(const string &filename, int size);
vector_1d scale(vector_1d v);
vector_1d min_max_scale(vector_1d &v, float desired_min, float desired_max);
vector_2d scale_matrix(vector_2d &m);
vector_2d min_max_scale_matrix(vector_2d &m, float desired_min, float desired_max);
vector_4d read_4d_matrix(vector<float> weights, int d1, int d2, int d3, int d4, int size);
vector_4d init_zero_4d_matrix(int d1, int d2, int d3, int d4);
vector_2d read_2d_matrix(vector<float> weights, int d1, int d2, int size);
vector_2d init_zero_2d_matrix(int d1, int d2);
vector<string> read_data_test_files(const string &filename);
vector<vector<int>> init_int_zero_2d_matrix(int d1, int d2);
float find_max(vector_1d &v);
float find_min(vector_1d &v);
#endif //SEMB_FILE_LOADING_H
