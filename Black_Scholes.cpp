// balck scholes

#include<bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793238462643 
#define E 2.71828182845904523536

class BlackScholesModel{
    private:

    long double current_Price;
    long double strike_Price;
    long double interest_rate;
    long double time;
    long double volatility;


    public:
    BlackScholesModel(){
        current_Price= 0.0;
        strike_Price=0.0;
        interest_rate=0.0;
        time=0;
        volatility=0;
    }

    BlackScholesModel(long double current_Price, long double strike_Price, long double interest_rate, long double time, long double volatility){
        this->current_Price= current_Price;
        this->strike_Price= strike_Price;
        this->interest_rate= interest_rate;
        this->time= time;
        this->volatility=volatility;
    }

    long double calculate_d1(long double current_Price, long double strike_Price, long double interest_rate, long double time, long double volatility){
        return (log(current_Price/strike_Price) + (interest_rate+ (volatility*volatility)/2)* time)/ (volatility*sqrt(time));
    }

    long double calculate_d2(long double d1, long double volatility, long double time){
        return d1-volatility*(sqrt(time));
    }

    long double normalCDF(long double x)
    {
        long double L, K, w ;
        long double const a1 = 0.31938153, a2 = -0.356563782, a3 = 1.781477937;
        long double const a4 = -1.821255978, a5 = 1.330274429;

        L = fabs(x);
        K = 1.0 / (1.0 + 0.2316419 * L);
        w = 1.0 - 1.0 / sqrt(2 * Pi) * exp(-L *L / 2) * (a1 * K + a2 * K *K + a3 * pow(K,3) + a4 * pow(K,4) + a5 * pow(K,5));

        if (x < 0 ){
            w= 1.0 - w;
        }
        return w;
    }

    long double call_option_price() {
        long double d1 = calculate_d1(current_Price, strike_Price, interest_rate, time, volatility);
        long double d2 = calculate_d2(d1, volatility, time);

        long double call_option = current_Price * normalCDF(d1) - strike_Price * exp(-interest_rate * time) * normalCDF(d2);
        return call_option;
    }

    long double put_option_price() {
        long double d1 = calculate_d1(current_Price, strike_Price, interest_rate, time, volatility);
        long double d2 = calculate_d2(d1, volatility, time);

        long double put_option = strike_Price * exp(-interest_rate * time) * normalCDF(-d2) - current_Price * normalCDF(-d1);
        return put_option;
    }
};


int main() {
    long double current_Price = 100.0;
    long double strike_Price = 105.0;
    long double interest_rate = 0.05;
    long double time = 1.0;
    long double volatility = 0.2;

    BlackScholesModel bsm(current_Price, strike_Price, interest_rate, time, volatility);
    cout << "Call Option Price: " << bsm.call_option_price() << endl;
    cout << "Put Option Price: " << bsm.put_option_price() << endl;

    return 0;
}