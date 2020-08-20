#pragma once
#include <math.h>
class Neuron
{
public:
	Neuron() : weight_(2.0), bias_(1.0) {}
	Neuron(const double& w_input, const double& b_input) : weight_(w_input), bias_(b_input) {}
public:
	double feedForward(const double& _input)
	{
		SetInput(_input);
		const double sigma = GetWeight() * GetInput() + GetBias();
		SetOutput(GetActivation(sigma));
		return output_;
	}
	double GetActivation(const double& x)
	{
		//return x; // Linear
		return fmax(0.0, x); // ReLu
	}
	double getActivationGradiant(const double& x)
	{
		//return 1.0;
		//ReLu
		return x > 0.0 ? 1.0 : 0.0;
	}

	void propBackward(const double& target)
	{
		const double alpha = 0.1; // learning rate
		const double grad = (output_ - target) * getActivationGradiant(output_);
		weight_ -= alpha * grad * input_; // ЙЬКа   d(sigma) / d(w) = x
		bias_ -= alpha * grad * 1.0;  // d(sigma) / d(b) = 1
	}


	void SetWeight(const double& _weight) { weight_ = _weight; }
	void SetBias(const double& _bias) { bias_ = _bias; }
	void SetInput(const double& _input) { input_ = _input; }
	void SetOutput(const double& _output) { output_ = _output; }
	const double GetWeight() const { return weight_; }
	const double GetBias() const { return bias_; }
	const double GetInput() const { return input_; }
	const double GetOutput() const { return output_; }
private:
	double weight_;
	double bias_;
	double input_, output_; 


};

