//
// Created by Igor on 14.10.26..
//

#ifndef LEXI_LINEWIDTHSOURCE_H
#define LEXI_LINEWIDTHSOURCE_H

#include "EnvironmentSource.h"
#include "../../../appearance/Window.h"

namespace formatting{
    class LineWidthSource: public EnvironmentSource {
        private:
            appearance::Window& w;
        public:
            LineWidthSource(appearance::Window& w):w(w){}
            int width() { return w.getWidth();}
    };
}


#endif //LEXI_LINEWIDTHSOURCE_H
