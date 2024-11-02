#include<bits/stdc++.h>

using namespace std;

double binomialTreeOptionPricing(int steps, double spotPrice, double strikePrice, double riskFreeRate,double volatility, double timeToMaturity, bool isCall) {
    double deltaT = timeToMaturity / steps;
    double up = exp(volatility * sqrt(deltaT));
    double down = 1 / up;
    double p = (exp(riskFreeRate * deltaT) - down) / (up - down);
    vector<double> prices(steps + 1);
    vector<double> optionValues(steps + 1);

    for (int i = 0; i <= steps; ++i) {
        prices[i] = spotPrice * pow(up, steps - i) * pow(down, i);
    }

    for (int i = 0; i <= steps; ++i) {
        optionValues[i] = isCall ? max((0.0), prices[i] - strikePrice)
                                 : max((0.0), strikePrice - prices[i]);
    }

    // Work backwards through the tree
    for (int j = steps - 1; j >= 0; --j) {
        for (int i = 0; i <= j; ++i) {
            optionValues[i] = exp(-riskFreeRate * deltaT) * (p * optionValues[i] + (1 - p) * optionValues[i + 1]);
        }
    }
    return optionValues[0];
}


