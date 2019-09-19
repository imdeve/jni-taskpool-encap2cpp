//
// Created by Administrator on 2019/9/19.
//

#include "JNIThreadPool.h"
#include <stdlib.h>
#include <pthread.h>
JNIThreadPool::JNIThreadPool() {

}

void JNIThreadPool::init(int numWorkers) {
     ThreadPool::init(numWorkers);
}

/*JNIEnv *env;
jvm->AttachCurrentThread(&env, 0);

jstring jmsg = env->NewStringUTF(msg);
env->CallVoidMethod(jobj, jmid, code, jmsg);
env->DeleteLocalRef(jmsg);

jvm->DetachCurrentThread();*/


void JNIThreadPool::onWorkThreadEnter(workqueue_t *wq, int wid) {
    int threadId = pthread_self();
//    jvm->AttachCurrentThread(&(envMap[threadId]), 0);//now for test so zhushi
    JNIEnv *env =0;
    jvm->AttachCurrentThread(&env, 0);
    worker_t *worker= this->queryWorker(wid);
    worker->userData = env;
    ThreadPool::onWorkThreadEnter(wq,wid);
}

void JNIThreadPool::deleteEnv() {
    //no delete
    int threadId = pthread_self();
    std::map<int, JNIEnv *>::iterator iter = this->envMap.find(threadId);
       // pthread_mutex_lock(&this->mapmutex);
      //  this->envMap.erase(iter);
        this->envMap[threadId]=0;
       // pthread_mutex_unlock(&this->mapmutex);

}

void JNIThreadPool::onWorkThreadExit(workqueue_t *wq, int wid) {
   // this->deleteEnv();
    ThreadPool::onWorkThreadExit(wq,wid);
  //  jvm->DetachCurrentThread();
}

JNIEnv* JNIThreadPool::findEnv(int wid) {
   worker_t *w= queryWorker(wid);
   if (w!=0)
   {
       return (JNIEnv*)w->userData;
   }
    return 0;
}

JNIThreadPool::~JNIThreadPool() {

}