//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_COMMAND_H
#define LEXI_COMMAND_H

namespace commands {

    class Command {
        public:
            virtual ~Command() = default;

            virtual void Execute() = 0;
    };

} // commands

#endif //LEXI_COMMAND_H
