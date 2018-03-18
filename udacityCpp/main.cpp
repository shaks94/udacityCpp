//
//  main.cpp
//  udacityCpp
//
//  Created by Admin on 17/03/18.
//  Copyright © 2018 Admin. All rights reserved.
//
#include <tuple>
#include <iostream>
#include "Eigen"
#include "Dense"
using namespace std;
using namespace Eigen;
struct Osm update(float mean1,float mean2,float var1,float var2);
struct Osm predict(float mean1,float mean2,float var1,float var2);
struct Osm{
    float mean;
    float variance;
};
int main(int argc, const char * argv[]) {
    float measurements[5] = {5., 6., 7., 9., 10.};
    float motion[5] = {1., 1., 2., 1., 1.};
    int measurement_sig = 4;
    int motion_sig = 2;
    int mu = 0;
    int sig =.0000000001;
    
    
    for (int i=0;i<5;i++){
        Osm r= update(mu,sig,measurements[i],measurement_sig);
        cout<<"update "<<r.mean<<"\t"<<r.variance<<endl;
        r = predict(mu,sig,motion[i],motion_sig);
        cout<<"predict "<<r.mean<<"\t"<<r.variance<<endl;
    }
    std::cout << "Hello, osm World!\n";
    return 0;
}

struct Osm update(float mean1,float mean2,float var1,float var2) {
    float a =  (float)(mean1*var1+mean2*var2)/(float)(var1+var2);
    float b = (float)(1)/(float)((1/var1)+(1/var2));
    Osm r ={a , b};
    return r;
}
struct Osm predict(float mean1,float mean2,float var1,float var2) {
    return Osm{ mean1+mean2,var1+var2 };
}
