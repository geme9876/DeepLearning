#include "Neuron.h"
#include <iostream>
#include <math.h>
using namespace std;

bool AreDoubleSame(double dFirstVal, double dSecondVal)
{
	return std::fabs(dFirstVal - dSecondVal) < std::numeric_limits<float>::epsilon();
}
void main()
{
	Neuron n(2.0, 1.0);
	
	while(!AreDoubleSame(n.GetOutput(), 4.0))
	{
		n.feedForward(1.0);
		n.propBackward(4.0);
	}

}