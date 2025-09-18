#include "Five.h"
#include <stdexcept>  
#include <iostream>

Five::Five(){
    data = new unsigned char[1];
    data[0] = 0;
    n = 1;  
};


Five::Five(const std::string &num) {
    n = num.size();
    data = new unsigned char[n];
    for (size_t i = 0; i < n; i++) {
        data[n - 1 - i] = num[i] - '0';
    }
    
}

Five::Five(const Five &o) {
    n = o.n;
    data = new unsigned char[n];
    for(size_t i = 0; i < n; i++) {
        data[i] = o.data[i];
    }
    

}

Five::~Five() {
    delete[] data;
}

Five Five::sum(const Five &o) const {
    Five res;
    delete []res.data;

    res.n = std::max(n, o.n)+1;
    res.data = new unsigned char[res.n]();

    int per = 0;//перенос
    for(size_t i = 0; i < res.n; i++) {
        int s = per;//сумма
        if (i < n) {
            s += data[i];
        };
        if (i < o.n) {
            s += o.data[i];
        };
        res.data[i] = s % 5;
        per = s / 5;
    };

    return res;

}

Five Five::sub(const Five &o) const {

    if(this->lt(o)){
    throw std::underflow_error("neg res");
    }
    Five res;
    delete[] res.data;
    res.n = std::max(n, o.n);
    res.data = new unsigned char[res.n]();

    int per = 0;
    for (size_t i = 0; i < res.n; i++){
        std::cout << per <<std::endl;
        int d = data[i] - per;
        if (i < o.n) {
            d -= o.data[i];

        }
        if (d < 0) {
            d += 5;
            per = 1;
        } else {
            per = 0;
        }

        res.data[i] = d;

       
    }

    

    return res;
}

void Five::sumAs(const Five &o) {
    Five res = this->sum(o);
    delete []data;
    n = res.n;
    data = res.data;

    res.data = nullptr;
    res.n = 0;
}

void Five::subAs(const Five &o) {
    Five res = this->sub(o);
    delete[] data;
    n = res.n;

    data = res.data;
    res.data = nullptr;
    res.n = 0;
}

bool Five::lt(const Five &o) const {
    if (n!= o.n) {
        return n < o.n;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (data[i]!= o.data[i]){
            return data[i] < o.data[i];
        }
    }
return false;
}

bool Five::eq(const Five &o) const {
    if (n != o.n) {
        return false;
    }
    for (size_t i = 0; i < n; i++) {
       
        if (data[i] != o.data[i]) {
            return false;
        }
    }

    return true;
}

bool Five::mt(const Five &o) const {
    if (n != o.n) {
         return n > o.n;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (data[i]!= o.data[i]) {
        return data[i] > o.data[i];
        }
    }
     
     return false;
}

