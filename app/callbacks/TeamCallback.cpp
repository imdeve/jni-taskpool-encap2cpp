//
// Created by Administrator on 2019/9/18.
//

#include "TeamCallback.h"
#include <iostream>

using  namespace std;

std::string TeamCallback::getResultType() {

    return "LTeamCallbackclaspath";
}

int TeamCallback::onPreDo() {
    BaseCallback::onPreDo();
    //自己的事情
   // cout <<"TeamCallback::onPreDo...."<<endl;

    return 0;
}
int TeamCallback::onDo() {

 //   cout <<"TeamCallback::onDo...."<<endl;
    return 0;
}

static int atomic_int_inc(int* addr,int delta){
    //based on asm : xaddl delta,[ptr]
    int ret = 0;
// input output sys arch
    __asm__ __volatile__(
    "lock; xaddl %2,%1;"
    :"=a"(ret)
    :"m"(*addr) ,"a"(delta)
    :"memory","cc"

    );
    return ret;

}

static int c=0;
int TeamCallback::onRelease() {
    BaseCallback::onRelease();
    atomic_int_inc(&c,1);
    cout << "TeamCallback::onRelease"<<  this->id << " wid:" << this->getWid() << "  selfcount:" << c <<endl;
    return 0;
}

TeamCallback::~TeamCallback() {
  //  cout <<"TeamCallback::~TeamCallback..~~~~~~~~.."<<endl;
}