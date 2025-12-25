#include "../include/InputUtils.h"

namespace InputUtils {

    // ---------- Core helpers ----------

    static void clearInput()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // ---------- Integer input ----------
  bool readIntInRange(const std::string& prompt, int& value, int min, int max) {
        while (true) {
            std::cout << prompt;
            if (!(std::cin >> value)) {
                std::cin.clear(); // clear error flags
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a numeric value.\n";
                continue;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush remaining input

            if (value < min || value > max) {
                std::cout << "Value must be between " << min << " and " << max << ".\n";
                continue;
            }

            return true; // valid input
        }
}

    bool readInt(const std::string& prompt, int& value)
    {
        std::cout << prompt;
        if (!(std::cin >> value)) {
            clearInput();
            return false;
        }
        clearInput();
        return true;
    }

    bool readPositiveInt(const std::string& prompt, int& value)
    {
        if (!readInt(prompt, value))
            return false;
        return value > 0;
    }

    bool readNonNegativeInt(const std::string& prompt, int& value)
    {
        if (!readInt(prompt, value))
            return false;
        return value >= 0;
    }

    // ---------- Double input ----------

    bool readDouble(const std::string& prompt, double& value)
    {
        std::cout << prompt;
        if (!(std::cin >> value)) {
            clearInput();
            return false;
        }
        clearInput();
        return true;
    }

    bool readNonNegativeDouble(const std::string& prompt, double& value)
    {
        if (!readDouble(prompt, value))
            return false;
        return value >= 0.0;
    }

    // ---------- Char / Yes-No ----------

    bool readChar(const std::string& prompt, char& value)
    {
        std::cout << prompt;
        if (!(std::cin >> value)) {
            clearInput();
            return false;
        }
        clearInput();
        return true;
    }

    bool readYesNo(const std::string& prompt)
    {
        char c;
        if (!readChar(prompt, c))
            return false;

        return c == 'y' || c == 'Y';
    }

}
