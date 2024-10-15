#include <iostream>
using namespace std;

class ConfigManager {
    static ConfigManager* instance;

    ConfigManager() {}  // Private constructor

public:
    static ConfigManager* getInstance() {
        if (!instance) instance = new ConfigManager();
        return instance;
    }

    void showConfig() { cout << "Configuration settings\n"; }
};

ConfigManager* ConfigManager::instance = nullptr;

int main() {
    ConfigManager::getInstance()->showConfig();
    return 0;
}
