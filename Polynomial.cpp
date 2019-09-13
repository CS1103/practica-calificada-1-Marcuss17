#include <stdexcept>
#include <iostream>
#include "Polynomial.h"

Polynomial::Polynomial() {
    top = nullptr;
    polCounter = 0;
}

void Polynomial::add(double coeficiente, int grado) {
    //El try y catch se utiliza aquí para validar que no se repitan terminos del mismo grado.
    try{
        indivPol* aux1 = top;
        while(aux1 != nullptr){
            if(coeficiente == aux1->coef){
                throw 1;
            }
            aux1 = aux1->next;
        }
        auto* new_Pol = new indivPol();
        new_Pol->coef = coeficiente;
        new_Pol->grado = grado;
        new_Pol->next = top;
        top = new_Pol;
        polCounter++;
    }catch (int e){
        std::cout<<"Term exist in the polynomial";
    }
}

int Polynomial::degree() {
    int mayor = 0;
    indivPol* aux1 = top;
    while(aux1 != nullptr){
        if(aux1->grado > mayor){
            mayor = aux1->grado;
        }
        aux1 = aux1->next;
    }
    return mayor;
}
ostream& operator<<(ostream& os, const Polynomial& P){
    indivPol* aux = P.top;
    string polButStr;
    string mystr;
    stringstream ss;
    while(aux != nullptr){
        if(aux->grado == 0){
            ss.clear();
            ss << noshowpos << aux->coef;
            ss >> mystr;
            polButStr+=mystr;
        }

        if(aux->grado != 0){
            ss.clear();
            ss << showpos << aux->coef;
            ss >> mystr;
            polButStr +=mystr;
            ss.clear();
            polButStr +="x^";
            ss<<noshowpos << aux->grado;
            ss>> mystr;
            polButStr +=mystr;
        }
        aux = aux->next;
    }
    os << polButStr;
    return os;
}

Polynomial operator+( Polynomial& P1,Polynomial& P2){
    indivPol* auxmenor; int menorexponente = 999;
    indivPol* auxmayor;
    bool mayor;
    if(P1.polCounter < P2.polCounter){
        menorexponente = P1.polCounter;
        auxmenor = P1.top;
        auxmayor = P2.top;
        mayor = true;
    }
    else{
        menorexponente = P2.polCounter;
        auxmenor = P2.top;
        auxmayor = P1.top;
        mayor = false;
    }
    for(int i = 0; i < menorexponente; i++){
        while(auxmenor != nullptr){
            if(auxmenor->grado == auxmayor->grado){
                auxmayor->coef += auxmenor->coef;
            }
            auxmenor = auxmenor->next;
            auxmayor = auxmayor->next;
        }
    }
    if(mayor == true){
        return P2;
    }
    else{
        return P1;
    }
}

Polynomial Polynomial::operator+(double val) {
    Polynomial P1;
    P1.top = top;
    auto* newPol = new indivPol();
    indivPol* aux1 = top;
    bool existeGradoCero;
    while(aux1 != nullptr){
        if(aux1->grado == 0){
            existeGradoCero = true;
            if(existeGradoCero == true){
                aux1->coef +=val;
            }
        }
        aux1 = aux1->next;
    }
    if(existeGradoCero == false){
        newPol->coef = val;
        newPol->grado = 0;
        newPol->next = P1.top;
        P1.top = newPol;
    }
    return P1;
}

Polynomial Polynomial::operator*(int val) {
    Polynomial P1;
    P1.top = top;
    indivPol* aux1;
    aux1 = top;
    while(aux1 != nullptr){
        aux1->coef *= val;
        aux1 = aux1->next;
    }
    return P1;
}

Polynomial operator*(double val, Polynomial& P){
    Polynomial P1;
    P1.top = P.top;
    indivPol* aux1;
    while(aux1 != nullptr){
        aux1->coef *= val;
        aux1 = aux1->next;
    }
    return P1;
}

Polynomial operator+(double val, Polynomial P1){
    auto* newPol = new indivPol();
    indivPol* aux1 = P1.top;
    bool existeGradoCero;
    while(aux1 != nullptr){
        if(aux1->grado == 0){
            existeGradoCero = true;
            if(existeGradoCero == true){
                aux1->coef +=val;
            }
        }
        aux1 = aux1->next;
    }
    if(existeGradoCero == false){
        newPol->coef = val;
        newPol->grado = 0;
        newPol->next = P1.top;
        P1.top = newPol;
    }
    return P1;
}

Polynomial operator+=(Polynomial P1,double val){
    auto* newPol = new indivPol();
    indivPol* aux1 = P1.top;
    bool existeGradoCero;
    while(aux1 != nullptr){
        if(aux1->grado == 0){
            existeGradoCero = true;
            if(existeGradoCero == true){
                aux1->coef +=val;
            }
        }
        aux1 = aux1->next;
    }
    if(existeGradoCero == false){
        newPol->coef = val;
        newPol->grado = 0;
        newPol->next = P1.top;
        P1.top = newPol;
    }
    return P1;
}

Polynomial operator+=(Polynomial& P1, Polynomial& P2){
    indivPol* auxmenor; int menorexponente = 999;
    indivPol* auxmayor;
    bool mayor;
    if(P1.polCounter < P2.polCounter){
        menorexponente = P1.polCounter;
        auxmenor = P1.top;
        auxmayor = P2.top;
        mayor = true;
    }
    else{
        menorexponente = P2.polCounter;
        auxmenor = P2.top;
        auxmayor = P1.top;
        mayor = false;
    }
    for(int i = 0; i < menorexponente; i++){
        while(auxmenor != nullptr){
            if(auxmenor->grado == auxmayor->grado){
                auxmayor->coef += auxmenor->coef;
            }
            auxmenor = auxmenor->next;
        }
    }
    if(mayor == true){
        return P2;
    }
    else{
        return P1;
    }
}

Polynomial operator*(Polynomial& P1, Polynomial& P2){
    indivPol* auxmenor; int menorexponente = 999;
    indivPol* auxmayor;
    bool mayor;
    if(P1.polCounter < P2.polCounter){
        menorexponente = P1.polCounter;
        auxmenor = P1.top;
        auxmayor = P2.top;
        mayor = true;
    }
    else{
        menorexponente = P2.polCounter;
        auxmenor = P2.top;
        auxmayor = P1.top;
        mayor = false;
    }
    for(int i = 0; i < menorexponente; i++){
        while(auxmenor != nullptr){
            auxmayor->coef *= auxmenor->coef;
            auxmayor->grado += auxmenor->grado;
            auxmenor = auxmenor->next;
        }
    }
    if(mayor == true){
        return P2;
    }
    else{
        return P1;
    }
}

Polynomial operator^(Polynomial& P1, int exponente){
    indivPol* aux = P1.top;
    for(int i= 0; i < exponente; i++){
        while(aux != nullptr){
            aux->grado += aux->grado;
            aux->coef *= aux->coef;
            aux = aux->next;
        }
    }
    return P1;
}

void Polynomial::showP() {
    indivPol* aux = top;
    while(aux != nullptr){
        std::cout<<aux->coef << endl;
        aux = aux->next;
    }
}





