#include <iostream>

#ifndef _TEMPLATE_ENGINE_HH
#define _TEMPLATE_ENGINE_HH                         "templateEngine.hh"

class templateEngine {
    private:
        void generateTopHTML();
        void generateBottomHTML();
        void generatePreviewImgForm();
        void generateReadDbForm();
        void generateWriteDbForm();
        void generateAllForms();
        void generateInnerImgPreviewPage();

    public:
        void generateMainPage();
        void generateImgPreviewPage();
};

#endif