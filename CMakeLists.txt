cmake_minimum_required(VERSION 3.12)
project(clion_project)

set(CMAKE_CXX_STANDARD 14)

#set (TASK  task/job.h task/job.c task/Task.cpp task/Task.h task/JNIThreadPool.cpp task/JNIThreadPool.h)

aux_source_directory(task TASK)
aux_source_directory(app/callbacks  CALLBACKS)

#set (CALLBACKS  app/callbacks/BaseCallback.cpp app/callbacks/BaseCallback.h
#        app/callbacks/TeamCallback.cpp app/callbacks/TeamCallback.h
#        )



add_executable(clion_project main2.cpp ${TASK} ${CALLBACKS})