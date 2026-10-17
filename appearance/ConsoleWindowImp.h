//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_CONSOLEWINDOWIMP_H
#define LEXI_CONSOLEWINDOWIMP_H

#include "WindowImp.h"

#include <string>
#include <vector>

namespace appearance {

    //Drawing goes into a character buffer, DeviceFlush prints it to stdout.
    //Everything is shown on the terminal's alternate screen (like vim or less),
    //each flush redraws it from the top left corner.
    class ConsoleWindowImp: public WindowImp {
        private:
            std::vector<std::string> buffer;

            //console can't draw between cells, so the caret is shown by inverting cell x
            bool hasCaret = false;
            int caretX = 0, caretY0 = 0, caretY1 = 0;

            bool isCaret(int x, int y) const;

        public:
            //switches to the alternate screen
            ConsoleWindowImp();
            //back to the normal screen, as it was before the program started
            ~ConsoleWindowImp() override;

            ConsoleWindowImp(const ConsoleWindowImp&) = delete;
            ConsoleWindowImp& operator=(const ConsoleWindowImp&) = delete;

            void DeviceText(char c, int x, int y) override;
            void DeviceRect(int x0, int y0, int x1, int y1) override;
            //'_' for horizontal and '|' for vertical lines, other lines can't be drawn in console
            void DeviceLine(int x0, int y0, int x1, int y1) override;
            void DeviceCaret(int x, int y0, int y1) override;
            void DeviceFlush() override;
    };

} // appearance

#endif //LEXI_CONSOLEWINDOWIMP_H
