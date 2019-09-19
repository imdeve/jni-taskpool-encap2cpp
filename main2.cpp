
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "task/JNIThreadPool.h"
#include "app/callbacks/TeamCallback.h"

static bool  flag =true;

static Task* newTask(){
    Task *add = new  TeamCallback();
    return  add;
}

int main() {

  JNIThreadPool pool;
    pool.init(0,2);

    while(flag)
    {
        pool.addTask(newTask());
        usleep(500);
    }


 BaseCallback* t= (BaseCallback*) newTask();
    delete t;


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
