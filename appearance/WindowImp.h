//
// Created by Igor on 16.10.26..
//

#ifndef LEXI_WINDOWIMP_H
#define LEXI_WINDOWIMP_H

namespace appearance {

    //Implementor part of the Bridge: platform specific drawing.
    //Coordinates are in document units (one character = one cell),
    //each implementation maps them to its own device.
    class WindowImp {
        public:
            virtual ~WindowImp() = default;

            virtual void DeviceText(char c, int x, int y) = 0;
            virtual void DeviceRect(int x0, int y0, int x1, int y1) = 0;
            //horizontal or vertical line from (x0,y0) to (x1,y1), the end is exclusive
            virtual void DeviceLine(int x0, int y0, int x1, int y1) = 0;

            //shows everything drawn since the last flush and starts a new frame
            virtual void DeviceFlush() = 0;
    };

} // appearance

#endif //LEXI_WINDOWIMP_H
