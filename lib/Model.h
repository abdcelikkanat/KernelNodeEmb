//
//
//

#ifndef FAST_BERN_MODEL_H
#define FAST_BERN_MODEL_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <random>
#include <iomanip>
#include "math.h"
#include "Unigram.h"
#include "Vocabulary.h"
#include <algorithm>

using namespace std;

class Model {

private:
    string method_name;
    string file_path;
    vector <double> optionalParams;
    int window_size, negative_sample_size, dim_size;
    unsigned long vocab_size;
    unordered_map <string, int> node2Id;
    vector <Node> vocab_items;
    int total_nodes;

    double starting_alpha, decay_rate, min_alpha;
    int num_of_iters;

    double **emb0, **emb1;

    default_random_engine generator;

    Unigram uni;

public:

    Model(string f_path, string method_name, vector <double> optionalParams, double s_alpha, double m_alpha, double d_rate, int dim, int neg, int w_size, int num_iters);
    ~Model();
    double sigmoid(double z);
    void gaussian_kernel(double alpha, vector <double> labels, int centerId, vector <int> contextIds);
    void exponential(double alpha, vector <double> labels, int centerId, vector <int> contextIds);
    void inf_poly_kernel(double alpha, vector <double> labels, int centerId, vector <int> contextIds);
    void run();
    void save_embeddings(string file_path);


};



#endif //FAST_BERN_MODEL_H
