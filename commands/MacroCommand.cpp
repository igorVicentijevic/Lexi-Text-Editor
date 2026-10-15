//
// Created by Igor on 16.10.26..
//

#include "MacroCommand.h"

namespace commands {

    MacroCommand::~MacroCommand() {
        for(Command* c: commands){
            delete c;
        }
    }

    void MacroCommand::Add(Command* c) {
        commands.push_back(c);
    }

    void MacroCommand::Execute() {
        for(Command* c: commands){
            c->Execute();
        }
    }

} // commands
