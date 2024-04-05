#include <unistd.h>
#include <cstring>
#include <iostream>

int main () {
    //team0:$1$ZvtfRmCz$M5j8uQCHnt9twgU./nyRJ0:16653:0:99999:7:::
    std::string hashed_password = "wPwz7GC6xLt9eQZ9eJkaq."; //compare with
    //alg goes here
    //while (hash != hashed_password) 

        std::string pass = "zhgnnd"; //brute force pass
        std::string salt = "$1$hfT7jp2q$";
        for(int i =0; i < 10000; i++) {
            char* hash = crypt(pass.c_str(), salt.c_str());
            if (std::string(hash) == hashed_password) {
                std::cout << "Password found: " << pass << std::endl;
                break;
            }
            else {
                std::cout << hash << std::endl;
            }
        }
        //comparrison hash with hashed_password

    //std::cout << hash;
}