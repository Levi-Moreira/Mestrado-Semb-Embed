//
// Created by Levi Albuquerque on 04/11/19.
//
#include <vector>
#include "../data/file_loading.h"
#include "../data/data_manipulation.h"
#include <chrono>
using namespace std;

typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;

float conv_single_step(vector_3d &slice, vector_3d &weights, float bias, int d1, int d2, int d3) {
    float sum = 0;
//    for (int i = 0; i < d1; i++) {
        for (int j = 0; j < d2; j++) {
            for (int a = 0; a < d3; a++) {
                slice[0][j][a] = slice[0][j][a] * weights[0][j][a];
                sum = sum + slice[0][j][a];
            }
        }
//    }

    return sum + bias;


}

void create_slice(vector_3d &final_vector, vector_3d &v, int vert_start, int vert_end, int hor_start, int hor_end, int n_c) {

    int c = 0;
    for (int i = vert_start; i < vert_end; i++) {
        int d = 0;
        for (int j = hor_start; j < hor_end; j++) {
//            final_vector[c][d].swap(v[i][j]);

            final_vector[c][d] = v[i][j];
//            int e = 0;
//            for (int a = 0; a < n_c; a++) {
//                float value = v[i][j][a];
//                final_vector[c][d][e] = value;
//                e++;
//            }
            d++;
        }
        c++;
    }


}

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
        int padding) {

    int n_H = int((n_H_prev - f_h + 2 * padding) / stride) + 1;
    int n_W = int((n_W_prev - f_w + 2 * padding) / stride) + 1;

    vector_4d Z(m, vector_3d(n_H, vector_2d(n_W, vector_1d(n_C, 0))));
    vector_3d sliced_weight(f_h, vector_2d(f_w, vector_1d(n_C_prev, 0)));
    vector_3d sliced(f_h, vector_2d(f_w, vector_1d(n_C_prev, 0)));

//    for (int i = 0; i < m; i++) {
//        for (int h = 0; h < n_H; h++) {

    for (int w = 0; w < n_W; w++) {

                for (int c = 0; c < n_C; c++) {
                    int vert_start = 0 * stride;
                    int vert_end = vert_start + f_h;
                    int horiz_start = w * stride;
                    int horiz_end = horiz_start + f_w;
                    create_slice(sliced, A_prev[0], vert_start, vert_end, horiz_start, horiz_end, n_C_prev);
                    copy_on_4_dimension(sliced_weight, weight, f_h, f_w, n_C_prev, c);
                    float sliced_bias = bias[0][0][0][c];
                    float conv_result = conv_single_step(sliced, sliced_weight, sliced_bias, f_h, f_w, n_C_prev);
                    Z[0][0][w][c] = conv_result;
                }

            }

//        }
//    }

    return Z;

}