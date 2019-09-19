//
// Created by Administrator on 2019/9/18.
//

#ifndef TASKOK_BASECALLBACK_H
#define TASKOK_BASECALLBACK_H

#include <string>
//#include <jni.h>
#include "../../task/task.h"
#include "../../task/JNIThreadPool.h"

class JNIEnv;
class JNIThreadPool;

/***
 * 自定义回调基类
 * 每一个自定义回调类 对应了，上层的JAVA的RequestCallback
******/
class BaseCallback :public Task {
protected:
    JNIEnv *env;
    JNIThreadPool *pool;
protected:
    virtual std::string getResultType();
    virtual int onPreDo();
    virtual void onInPool(ThreadPool *threadPool);
    virtual int onDo();
    virtual int onPostDo();
    void setEnv(JNIEnv *env);
    virtual int process();
    virtual int onRelease();
private:
    void release();
public:
    virtual ~BaseCallback();

};


#endif //TASKOK_BASECALLBACK_H
