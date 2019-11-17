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


vector_4d relu(vector_4d &input,
               int m,
               int n_H,
               int n_W,
               int n_C) {

    for (int i = 0; i < m; i++) {
        for (int h = 0; h < n_H; h++) {
            for (int w = 0; w < n_W; w++) {
                for (int c = 0; c < n_C; c++) {

                    if (input[i][h][w][c] < 0) {
                        input[i][h][w][c] = 0;
                    }

                }
            }
        }
    }

    return input;
}

vector_2d relu_2d(vector_2d &input,
                  int H,
                  int W) {


    for (int i = 0; i < H; i++) {
        for (int h = 0; h < W; h++) {
            if (input[i][h] < 0) {
                input[i][h] = 0;
            }
        }
    }

    return input;
}

float apply_sigmoid(float value) {
    return 1 / (1 + exp(-value));
}

float sigmoid(float input) {
    return apply_sigmoid(input);
}