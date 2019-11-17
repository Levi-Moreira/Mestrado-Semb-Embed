//
// Created by Levi Albuquerque on 04/11/19.
//
#include <vector>
#include <cmath>

using namespace std;
typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;


vector_4d batch_norm_4d(vector_4d &input, vector_1d &gamma, vector_1d &beta, vector_1d &mean, vector_1d &variance, float eps, int d1, int d2, int d3, int d4) {



            for (int a = 0; a < d3; a++) {
                for (int c = 0; c < d4; c++) {
                    float x_hat = (input[0][0][a][c] - mean[c]) * 1.0 / sqrt(variance[c] + eps);
                    input[0][0][a][c] = x_hat * gamma[c] + beta[c];
                }
            }


    return input;
}

vector_2d batch_norm_2d(vector_2d &input, vector_1d &gamma, vector_1d &beta, vector_1d &mean, vector_1d &variance, float eps, int d1, int d2) {



        for (int j = 0; j < d2; j++) {
            float x_hat = (input[0][j] - mean[j]) * 1.0 / sqrt(variance[j] + eps);
            input[0][j] = x_hat * gamma[j] + beta[j];
        }


    return input;
}