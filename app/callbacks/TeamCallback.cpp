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
    cout <<"TeamCallback::onPreDo...."<<endl;

    return 0;
}
int TeamCallback::onDo() {

    cout <<"TeamCallback::onDo...."<<endl;
    return 0;
}

int TeamCallback::onRelease() {
    BaseCallback::onRelease();
    cout <<"TeamCallback::onRelease...."<<endl;
    return 0;
}

TeamCallback::~TeamCallback() {
    cout <<"TeamCallback::~TeamCallback..~~~~~~~~.."<<endl;
}