#include <iostream>
#include <cstdio>
#include <cstring>

std::string generatePasswordHash(const std::string& password, const std::string& salt) {
    std::string command = "openssl passwd -1 -salt " + salt + " " + password;
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        std::cerr << "Error: popen failed!" << std::endl;
        return "";
    }
    char buffer[128];
    std::string result = "";
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != nullptr)
            result += buffer;
    }
    pclose(pipe);
    // Remove trailing newline character from the result
    if (!result.empty() && result[result.length() - 1] == '\n') {
        result.erase(result.length() - 1);
    }
    return result;
}

int main () {
    std::string hashed_password = "$1$hfT7jp2q$wPwz7GC6xLt9eQZ9eJkaq."; //compare with
    //alg goes here
    //while (hash != hashed_password) 

        std::string pass = "zhgnnd"; //brute force pass
        std::string salt = "hfT7jp2q";
        std::string input = salt+pass;

        std::string hash = generatePasswordHash(pass, salt);
        for(int i = 0; i < hashed_password.length(); ++i)
        {
            if(hashed_password[i] != hash[i])
            {
                std::cout << "NOT IT" << std::endl;
                break;
            }
            else if (i == hashed_password.length()-1)
            {
                std::cout << "MATCH" << std::endl;
            }
        }
        std::cout << "Generated: \n" << hash << std::endl;
        std::cout << "Expected: \n" << hashed_password << std::endl;

}