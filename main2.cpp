
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "task/JNIThreadPool.h"
#include "app/callbacks/TeamCallback.h"

static Task* newTask(int id){
    TeamCallback *add = new  TeamCallback();
    add->id = id;
    return  add;
}


void test(){
    JNIThreadPool pool;
    pool.init(0,100);

    for (int i=0;i<1000000;i++)
    {
        pool.addTask(newTask(i));
    }

    std::cout << "Hello, World!" << std::endl;
    getchar();

}

int main() {
    test();

    sleep(50000);
    return 0;
}
