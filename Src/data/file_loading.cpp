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

vector_2d read_data_from_file_with_comma(const string &filename, int channels) {

    ifstream file(filename);
    string content;
    vector<vector<float>> final_vect;
    int current_line = 0;

    while (file >> content && current_line < channels) {
        istringstream ss(content);
        string token;
        vector<float> vect;

        while (std::getline(ss, token, ',')) {
            float value = stof(token);
            vect.push_back(value);
        }
        final_vect.push_back(vect);
        current_line++;
    }

    return final_vect;
}

vector_1d read_data_from_file_with_new_line(const string &filename, int size) {

    ifstream file(filename);
    string content;
    vector_1d final_vect(size,0);

    int index = 0;
    while (getline(file, content)) {
        float value = stof(content);
        final_vect[index] = value;
        index++;
    }

    return final_vect;
}

vector<string> read_data_test_files(const string &filename) {
    ifstream file(filename);
    string content;
    vector<string> final_vect;

    while (getline(file, content)) {
        final_vect.push_back(content);
    }
    return final_vect;
}

vector_1d scale(vector_1d v) {
    double sum = accumulate(v.begin(), v.end(), 0.0);
    double mean = sum / v.size();
    double sq_sum = inner_product(v.begin(), v.end(), v.begin(), 0.0);
    double stdev = sqrt(sq_sum / v.size() - mean * mean);

    for (int i = 0; i < v.size(); i++) {
        v[i] = (v[i] - mean) / stdev;
    }
    return v;
}

float find_max(vector_1d &v){

	float max = 0;
	for(int i = 0; i< v.size();i++){
		if(v[i] > max){
			max = v[i];
		}
	}

	return max;
}

float find_min(vector_1d &v){

	float min = 10000000;
	for(int i = 0; i< v.size();i++){
		if(v[i] < min){
			min = v[i];
		}
	}

	return min;
}

vector_1d min_max_scale(vector_1d &v, float desired_min, float desired_max) {

    float min = find_max(v);
    float max = find_min(v);

    for (int i = 0; i < v.size(); i++) {
        v[i] = (v[i] - min) / (max - min);
    }

    for (int i = 0; i < v.size(); i++) {
        v[i] = v[i] * (desired_max - desired_min) + desired_min;
    }
    return v;
}



vector_2d scale_matrix(vector_2d &m) {

    for (int i = 0; i < m[0].size(); i++) {
        vector<float> axis;
        for (int j = 0; j < m.size(); j++) {
            axis.push_back(m[j][i]);
        }
        axis = scale(axis);

        for (int a = 0; a < m.size(); a++) {
            m[a][i] = axis[a];
        }
    }
    return m;
}

vector_2d min_max_scale_matrix(vector_2d &m, float desired_min, float desired_max) {

    for (int i = 0; i < m[0].size(); i++) {
        vector<float> axis;
        for (int j = 0; j < m.size(); j++) {
            axis.push_back(m[j][i]);
        }
        axis = min_max_scale(axis, desired_min, desired_max);

        for (int a = 0; a < m.size(); a++) {
            m[a][i] = axis[a];
        }
    }
    return m;
}

vector_4d read_4d_matrix(vector<float> weights, int d1, int d2, int d3, int d4, int size) {
//    vector<float> weights = read_data_from_file_with_new_line(filename,  size);

    vector_4d final(d1, vector_3d(d2,vector_2d(d3,vector_1d(d4,0))));

    int index = 0;
    for (int a = 0; a < d1; a++) {
        for (int j = 0; j < d2; j++) {
            for (int i = 0; i < d3; i++) {
                for (int b = 0; b < d4; b++) {
                    final[a][j][i][b] = weights[index];
                    index++;
                }
            }
        }
    }
    return final;
}

vector_2d read_2d_matrix(vector<float> weights, int d1, int d2, int size) {
//    vector<float> weights = read_data_from_file_with_new_line(filename, size);
    vector_2d final(d1, vector_1d(d2,0));
    int index = 0;
    for (int a = 0; a < d1; a++) {
        for (int j = 0; j < d2; j++) {
            final[a][j] = weights[index];
            index++;
        }
    }
    return final;
}

vector_4d init_zero_4d_matrix(int d1, int d2, int d3, int d4) {
    vector_4d final;
    for (int a = 0; a < d1; a++) {
        vector<vector<vector<float>>> _dimension_2;
        for (int j = 0; j < d2; j++) {
            vector<vector<float>> _dimension_3;
            for (int i = 0; i < d3; i++) {
                vector<float> _dimension_4(d4, 0);
                _dimension_3.push_back(_dimension_4);
            }
            _dimension_2.push_back(_dimension_3);
        }
        final.push_back(_dimension_2);
    }
    return final;
}

vector_2d init_zero_2d_matrix(int d1, int d2) {
    vector_2d final;
    for (int i = 0; i < d1; i++) {
        vector<float> _dimension_4(d2, 0);
        final.push_back(_dimension_4);
    }
    return final;
}

vector<vector<int>> init_int_zero_2d_matrix(int d1, int d2) {
    vector<vector<int>> final;
    for (int i = 0; i < d1; i++) {
        vector<int> _dimension_4(d2, 0);
        final.push_back(_dimension_4);
    }
    return final;
}
