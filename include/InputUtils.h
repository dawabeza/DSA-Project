#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <iostream>
#include <limits>
#include <string>

namespace InputUtils {

    bool readInt(const std::string& prompt, int& value);
    bool readPositiveInt(const std::string& prompt, int& value);
    bool readNonNegativeInt(const std::string& prompt, int& value);
    bool readIntInRange(const std::string& prompt, int& value, int min, int max);

    bool readDouble(const std::string& prompt, double& value);
    bool readNonNegativeDouble(const std::string& prompt, double& value);

    bool readChar(const std::string& prompt, char& value);
    bool readYesNo(const std::string& prompt);

}

#endif
