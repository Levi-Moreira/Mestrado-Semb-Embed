//
// Created by Levi Albuquerque on 04/11/19.
//
#include <vector>
#include <numeric>
#include "../data/file_loading.h"

using namespace std;
typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;


void create_pool_slice(vector_1d &slice, vector_4d &input, int horiz_start, int horiz_end, int vert_start, int vert_end, int c) {
    int index = 0;
    for (int i = horiz_start; i < horiz_end; i++) {
        for (int j = vert_start; j < vert_end; j++) {
            slice[index] = input[0][i][j][c];
            index++;
        }
    }
}


vector_4d maxpool(vector_4d &input,
                  int m,
                  int n_H_prev,
                  int n_W_prev,
                  int n_C_prev,
                  int f_h,
                  int f_w,
                  int stride_h,
                  int stride_w) {

    int n_H = int(1 + (n_H_prev - f_h) / stride_h);
    int n_W = int(1 + (n_W_prev - f_w) / stride_w);
    int n_C = n_C_prev;

    vector_4d A(m, vector_3d(n_H, vector_2d(n_W, vector_1d(n_C, 0))));
    vector_1d slice(2, 0);


        for (int h = 0; h < n_H; h++) {
            for (int w = 0; w < n_W; w++) {
                for (int c = 0; c < n_C; c++) {

                    int vert_start = stride_w * w;
                    int vert_end = vert_start + f_w;

                    int horiz_start = stride_h * h;
                    int horiz_end = horiz_start + f_h;
                    create_pool_slice(slice, input, horiz_start, horiz_end, vert_start, vert_end, c);
                    float max_pool_result = find_max(slice);
                    A[0][h][w][c] = max_pool_result;
                }
            }
        }


    return A;

}
