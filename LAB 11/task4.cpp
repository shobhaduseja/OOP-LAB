#include <iostream>
#include <exception>
#include <string>

class DatabaseException : public std::exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException {};

template <typename T>
class DatabaseConnector {
public:
    void connect(T db) {
        if (db == "invalid_db")
            throw ConnectionFailedException();
        else if (db == "slow_db")
            throw QueryTimeoutException();
        else
            std::cout << "Connected to " << db << " successfully.\n";
    }
};

int main() {
    DatabaseConnector<std::string> connector;

    try {
        std::cout << "Attempting to connect to invalid_db...\n";
        connector.connect("invalid_db");
    } catch (const ConnectionFailedException& e) {
        std::cout << "Caught ConnectionFailedException - what(): " << e.what() << std::endl;
    } catch (const DatabaseException& e) {
        std::cout << "Caught a general DatabaseException - what(): " << e.what() << std::endl;
    }

    try {
        std::cout << "Attempting to connect to slow_db...\n";
        connector.connect("slow_db");
    } catch (const QueryTimeoutException& e) {
        std::cout << "Caught QueryTimeoutException - what(): " << e.what() << std::endl;
    } catch (const DatabaseException& e) {
        std::cout << "Caught a general DatabaseException - what(): " << e.what() << std::endl;
    }

    return 0;
}
