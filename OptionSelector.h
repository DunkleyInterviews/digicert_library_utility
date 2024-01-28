#ifndef DIGICERTLIBRARY_OPTIONSELECTOR_H
#define DIGICERTLIBRARY_OPTIONSELECTOR_H
#include <string>
using std::string;

class OptionSelector {
public:
    static const std::string LIST;
    static const std::string GET;
    static const std::string CREATE;
    static const std::string UPDATE;
    static const std::string DELETE;
    static const std::string EXIT;

    void optionSelector();
};

#endif //DIGICERTLIBRARY_OPTIONSELECTOR_H
