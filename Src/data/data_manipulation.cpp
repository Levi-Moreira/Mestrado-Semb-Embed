//
// Created by Levi Albuquerque on 04/11/19.
//

#include <vector>

using namespace std;

typedef std::vector<float> vector_1d;
typedef std::vector<vector_1d> vector_2d;
typedef std::vector<vector_2d> vector_3d;
typedef std::vector<vector_3d> vector_4d;


void copy_on_4_dimension(vector_3d &sliced_weight, vector_4d &v, int dimension1, int dimension2, int dimension3, int c) {

//    for (int i = 0; i < dimension1; i++) {
        for (int j = 0; j < dimension2; j++) {
            for (int a = 0; a < dimension3; a++) {
                float value = v[0][j][a][c];
                sliced_weight[0][j][a] = value;
            }
        }
//    }

}


vector_4d convert_to_4d(const vector_2d &input) {
    vector_3d intermediate;
    intermediate.push_back(input);
    vector_4d final;
    final.push_back(intermediate);
    return final;
}

vector_2d convert_to_2d(const vector_4d &input, int d1, int d2, int d3, int d4, int finalh, int finalw) {

    vector_1d flatten;

    for (int a = 0; a < d1; a++) {
        for (int b = 0; b < d2; b++) {
            for (int c = 0; c < d3; c++) {
                for (int d = 0; d < d4; d++) {
                    flatten.push_back(input[a][b][c][d]);
                }
            }
        }
    }

    vector_2d final;
    int index = 0;
    for (int a = 0; a < finalh; a++) {
        vector_1d sub_final;
        for (int b = 0; b < finalw; b++) {
            sub_final.push_back(flatten[index]);
            index++;
        }
        final.push_back(sub_final);
    }


    return final;

}

vector_2d transpose(vector<vector<float>> input, int w, int h) {
    vector<vector<float>> output;
    vector_1d temp;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            float value = input[i][j];
            temp.push_back(value);
        }
    }

    int index = 0;
    for (int i = 0; i < w; i++) {
        vector<float> result;
        for (int j = 0; j < h; j++) {
            float value = temp[index];
            result.push_back(value);
            index++;
        }
        output.push_back(result);
    }

    return output;
}