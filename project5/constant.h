// This header file is for collection of the constant value appear in main.cpp.

// Event type, since there are two event type, use 0 and 1 to represent events.
int const Arrived = 1;
int const Served = 0;

// Random Seed value, arbitrary value, chose 2017
int SEED = 2017;
// The amount of time between customers should be drawn from a uniform
// distribution, which has specified min and max values. The min and max value
// are represented by the following values, the unit is minutes.
int MIN = 2;
int MAX = 20;

// The amount of time it takes for the server to wait on the customer will be
// drawn from a normal distribution with a specified mean and standard
// deviation. The mean and standard deviation are represented by the following
// values, the unit is also minutes.
int MEAN = 10;
int STD = 3;

// The simulation time is 1 day, so the whole time unites should be 24*60*60 =
// 86400.

int TIME = 200;

// Used in the error checking function
int const IGNORE = 200;