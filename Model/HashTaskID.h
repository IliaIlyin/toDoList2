//
// Created by Ilya on 5/20/2020.
//

#ifndef TODOLIST_HASHTASKENTITY_H
#define TODOLIST_HASHTASKENTITY_H

#include"TaskEntity.h"

class HashTaskID {
public:
    // id is returned as hash function
    size_t operator()(const TaskID task_id) const;

};


#endif //TODOLIST_HASHTASKENTITY_H
