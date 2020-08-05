//
// Created by Ilya on 7/26/2020.
//

#include<gtest/gtest.h>

#include "Model/TaskEntity.h"
using testing::Eq;

class TaskEntityTest : public ::testing::Test {

};

TEST_F(TaskEntityTest,shouldCreateTaskEntity){
    Task task = Task::createTask("Lol",200,Task::Priority::FIRST,"label");
    IdGenerator idGenerator;
    std::vector<std::shared_ptr<TaskEntity>> vec;
    TaskID taskId(0);
    TaskEntity taskEntity=TaskEntity::createTaskEntity(task,idGenerator);
    ASSERT_TRUE(taskEntity.getTask().getName()== task.getName());
    ASSERT_TRUE(taskEntity.getTask().getLabel()==task.getLabel());
    ASSERT_EQ(taskEntity.getTask().getDate(),task.getDate());
    ASSERT_EQ(taskEntity.getTask().getPriority(),task.getPriority());
    ASSERT_EQ((taskId.getId()),(taskEntity.getTaskId().getId()));
    ASSERT_EQ(false,taskEntity.checkStatus());
    ASSERT_EQ(vec,taskEntity.getSubtasks());
}
TEST_F(TaskEntityTest,shouldAddSubTasks){
  Task task = Task::createTask("Lol",200,Task::Priority::FIRST,"label");
  IdGenerator idGenerator;
  TaskEntity taskEntity=TaskEntity::createTaskEntity(task,idGenerator);
  Task task2 = Task::createTask("fsdfds",200,Task::Priority::THIRD,"label");
  Task task3 = Task::createTask("Lgdfgdfgsdf",200,Task::Priority::SECOND,"label");
  std::shared_ptr<TaskEntity> ptr=std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2,idGenerator));
  taskEntity.addsubtask(ptr);
  std::shared_ptr<TaskEntity> ptr2=std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3,idGenerator));
  ptr->addsubtask(ptr2);
  ASSERT_EQ(1,taskEntity.getSubtasks().size());
  ASSERT_EQ(ptr.operator*(),taskEntity.getSubtasks().begin().operator*().operator*());
  ASSERT_EQ(ptr2.operator*(),taskEntity.getSubtasks().begin()->operator*().getSubtasks().begin()->operator*());
}
TEST_F(TaskEntityTest,shouldCompleteTask){
  Task task = Task::createTask("Lol",200,Task::Priority::FIRST,"label");
  IdGenerator idGenerator;
  TaskEntity taskEntity=TaskEntity::createTaskEntity(task,idGenerator);
  Task task2 = Task::createTask("fsdfds",200,Task::Priority::THIRD,"label");
  Task task3 = Task::createTask("Lgdfgdfgsdf",200,Task::Priority::SECOND,"label");
  std::shared_ptr<TaskEntity> ptr=std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task2,idGenerator));
  taskEntity.addsubtask(ptr);
  std::shared_ptr<TaskEntity> ptr2=std::make_shared<TaskEntity>(TaskEntity::createTaskEntity(task3,idGenerator));
  ptr->addsubtask(ptr2);
  taskEntity.completeTask();
  ASSERT_EQ(true,taskEntity.checkStatus());
  ASSERT_EQ(true,taskEntity.getSubtasks().begin()->operator*().checkStatus());
  ASSERT_EQ(true,taskEntity.getSubtasks().begin()->operator*().getSubtasks().begin()->operator*().checkStatus());
}