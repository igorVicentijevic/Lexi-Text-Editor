//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_CONSOLEWINDOWIMP_H
#define LEXI_CONSOLEWINDOWIMP_H

#include "WindowImp.h"

#include <string>
#include <vector>

namespace appearance {

    //drawing goes into a character buffer, DeviceFlush prints it to stdout
    class ConsoleWindowImp: public WindowImp {
        private:
            std::vector<std::string> buffer;

        public:
            void DeviceText(char c, int x, int y) override;
            void DeviceRect(int x0, int y0, int x1, int y1) override;
            void DeviceFlush() override;
    };

} // appearance

#endif //LEXI_CONSOLEWINDOWIMP_H
