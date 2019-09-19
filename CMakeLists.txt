cmake_minimum_required(VERSION 3.12)
project(clion_project)

set(CMAKE_CXX_STANDARD 14)

set (TASK  task/job.h task/job.c task/Task.cpp task/Task.h task/JNIThreadPool.cpp task/JNIThreadPool.h)

set (CALLBACKS  app/callbacks/BaseCallback.cpp app/callbacks/BaseCallback.h
        app/callbacks/TeamCallback.cpp app/callbacks/TeamCallback.h
        )



add_executable(clion_project main.cpp ${TASK} ${CALLBACKS})