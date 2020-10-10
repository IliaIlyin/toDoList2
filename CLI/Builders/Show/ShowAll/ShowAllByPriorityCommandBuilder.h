//
// Created by Ilya on 9/15/2020.
//

#ifndef TODOLIST_CLI_BUILDERS_SHOW_SHOWALL_SHOWALLBYPRIORITYCOMMANDBUILDER_H_
#define TODOLIST_CLI_BUILDERS_SHOW_SHOWALL_SHOWALLBYPRIORITYCOMMANDBUILDER_H_

#include "Builder.h"
#include "InputStateMachine.h"
#include "Validators/InputValidators/TaskIdValidator.h"
#include "States/InputDataStates/TaskIdState.h"
#include "Commands/Show/ShowAll/ShowAllByPriorityCommand.h"

class ShowAllByPriorityCommandBuilder: public Builder {
  std::shared_ptr<Command> buildCommand(std::shared_ptr<CoreAPIInterface> service) override;
};

#endif //TODOLIST_CLI_BUILDERS_SHOW_SHOWALL_SHOWALLBYPRIORITYCOMMANDBUILDER_H_
