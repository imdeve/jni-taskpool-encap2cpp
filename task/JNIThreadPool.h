//
// Created by Administrator on 2019/9/19.
//

#ifndef TASKOK_JNITHREADPOOL_H
#define TASKOK_JNITHREADPOOL_H

//#include <jni.h>
#include <map>
#include "Task.h"
class JNIEnv;
class JavaVM;

class JNIEnv
{

};
class JavaVM{

}
;
class JNIThreadPool :public ThreadPool {
public:
    JNIThreadPool();
    void init(int numWorkers);
    ~JNIThreadPool();
    JNIEnv* findEnv(int threadId);
protected:
    virtual  void  onWorkThreadEnter(workqueue_t *wq, int wid);
    virtual  void  onWorkThreadExit(workqueue_t *wq, int wid);
    void           deleteEnv();
protected:
    JavaVM *jvm;
};


#endif //TASKOK_JNITHREADPOOL_H
