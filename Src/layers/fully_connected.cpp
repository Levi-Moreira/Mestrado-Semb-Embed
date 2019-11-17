//
// Created by Levi Albuquerque on 05/11/19.
//
#include <vector>
#include "../data/file_loading.h"

using namespace std;
typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;


vector_2d fc_forward(vector_2d &input, vector_2d &weights, vector_2d &bias, int d1, int d2, int d3) {

    vector_2d res(d1, vector_1d(d2, 0));
    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < d3; k++)
                res[i][j] += input[i][k] *
                             weights[k][j];
        }
    }

    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            res[i][j] = res[i][j] + bias[j][0];
        }
    }

    return res;

}