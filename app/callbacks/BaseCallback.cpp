//
// Created by Administrator on 2019/9/18.
//
#include <iostream>
#include "BaseCallback.h"
#include  "../../task/JNIThreadPool.h"
std::string BaseCallback::getResultType() {

   // this->env->GetObjectClass("");
    return "";
}

void BaseCallback::setEnv(JNIEnv *env) {
     this->env =  env;
}

void BaseCallback::onInPool(ThreadPool *threadPool) {
     this->pool = (JNIThreadPool*)threadPool;
}

int BaseCallback::onPreDo() {
    Task::onPreDo();
    int currThreadId = pthread_self();
    JNIEnv* e= this->pool->findEnv(currThreadId);
    this->env= e;

    return 0;
}

int BaseCallback::onDo() {
    Task::onDo();

    return 0;
}

int BaseCallback::process() {
    Task::process();
    this->release();
    return 0;
}

void BaseCallback::release() {
    this->onRelease();
    delete this;
}

int BaseCallback::onRelease() {
    std::cout << "BaseCallback::~onRelease()   delete (Task*)this; delete (Task*)this; delete (Task*)this;" << std::endl;
    return 0;
}

int BaseCallback::onPostDo() {
    Task::onPostDo();


    return 0;
}

BaseCallback::~BaseCallback() {

     std::cout << "BaseCallback::~BaseCallback() " << std::endl;
}
