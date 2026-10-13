//
// Created by Igor on 13.10.26..
//

#ifndef LEXI_COMPOSITOR_H
#define LEXI_COMPOSITOR_H



namespace formatting {

    class Composition;

    class Compositor {
        private:
           Composition* composition;
        public:
            Compositor(Composition* composition):composition(composition){}
            virtual void compose()=0;
    };

} // formatting

#endif //LEXI_COMPOSITOR_H
