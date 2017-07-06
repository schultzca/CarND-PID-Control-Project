#include "PID.h"
#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	// initialize gains
	gains = {Kp, Ki, Kd};

	first_step = true;
}

void PID::UpdateError(double cte) {
	// handle first step
	if (first_step) {
		prev_cte = cte;
		first_step = false;
	}
	
	// compute errors
	p_error = cte;
	d_error = cte - prev_cte;
	i_error += cte;

	// store current error
	prev_cte = cte;
}

double PID::TotalError() {
	return -gains[Kp] * p_error - gains[Kd] * d_error - gains[Ki] * i_error;
}



