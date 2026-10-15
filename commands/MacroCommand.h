//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_MACROCOMMAND_H
#define LEXI_MACROCOMMAND_H

#include "Command.h"

#include <vector>

namespace commands {

    //Sequence of commands executed as one. Owns its commands.
    class MacroCommand: public Command {
        private:
            std::vector<Command*> commands;

        public:
            MacroCommand() = default;
            ~MacroCommand() override;

            MacroCommand(const MacroCommand&) = delete;
            MacroCommand& operator=(const MacroCommand&) = delete;

            void Add(Command* c);

            void Execute() override;
    };

} // commands

#endif //LEXI_MACROCOMMAND_H
