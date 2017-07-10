#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */
    VectorXd rmse(4);
    rmse << 0,0,0,0;
    
    if(estimations.size() == 0 || estimations.size() != ground_truth.size())
    {
        cout << "Error - Wrong input sizes" << endl;
        return rmse;
    }
    
    //accumulate squared residuals
    VectorXd sqr_res;
    for(int i=0; i < estimations.size(); ++i){
        // ... your code here
        VectorXd r = estimations[i] - ground_truth[i];
        VectorXd sqr_r = r.array() * r.array();
        rmse += sqr_r;
        
    }
    
    //calculate the mean
    // ... your code here
    VectorXd mean = rmse/ estimations.size();
    
    //calculate the squared root
    // ... your code here
    rmse = mean.array().sqrt();
    
    
    //return the result
    return rmse;
}
