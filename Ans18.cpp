#include <iostream>
using namespace std;

// Singleton class
class ConfigurationManager {
private:
    static ConfigurationManager* instance;  // Static instance pointer
    string configData;  // Example configuration data

    // Private constructor to prevent instantiation
    ConfigurationManager() {
        configData = "Default Configuration";
    }

public:
    // Delete copy constructor and assignment operator
    ConfigurationManager(const ConfigurationManager&) = delete;
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;

    // Static method to get the instance of the class
    static ConfigurationManager* getInstance() {
        if (!instance) {  // If instance doesn't exist, create one
            instance = new ConfigurationManager();
        }
        return instance;
    }

    void displayConfig() {
        cout << "Configuration: " << configData << endl;
    }

    void setConfigData(const string& data) {
        configData = data;
    }
};

// Initialize static member
ConfigurationManager* ConfigurationManager::instance = nullptr;

int main() {
    // Accessing the singleton instance
    ConfigurationManager* configManager = ConfigurationManager::getInstance();
    configManager->displayConfig();  // Display default configuration

    // Changing configuration data
    configManager->setConfigData("Updated Configuration");
    configManager->displayConfig();  // Display updated configuration

    // Trying to create another instance
    ConfigurationManager* anotherConfigManager = ConfigurationManager::getInstance();
    anotherConfigManager->displayConfig();  // Should display the same updated configuration

    return 0;
}
