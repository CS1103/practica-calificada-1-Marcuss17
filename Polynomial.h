#ifndef POLINOMIO_POLINOMIO_H
#define POLINOMIO_POLINOMIO_H

#include <sstream>
using std::showpos;
//using std::showpos pone el signo delante;
#include <vector>
using namespace std;

struct indivPol{
    double coef;
    int grado;
    indivPol* next;
};

//Coeficiente y grado
class Polynomial {
private:
    indivPol* top;

public:
    int polCounter;
    void showP();
    Polynomial();
    Polynomial(const Polynomial&) = default;
    void add(double, int);
    int degree();
    friend ostream& operator<<(ostream& os, const Polynomial&);
    Polynomial operator+(double);
    friend Polynomial operator+(double, Polynomial);
    friend Polynomial operator+=(Polynomial,double);
    Polynomial operator*(int);
    friend Polynomial operator+(Polynomial&, Polynomial&);
    friend Polynomial operator+=(Polynomial&, Polynomial&);
    friend Polynomial operator*(double, Polynomial&);
    friend Polynomial operator*(Polynomial&, Polynomial&);
    friend Polynomial operator^(Polynomial&, int);

};




#endif //POLINOMIO_POLINOMIO_H
