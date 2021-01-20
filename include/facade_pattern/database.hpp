#ifndef FACARD_DATABASE_HPP
#define FACARD_DATABASE_HPP

#include <nlohmann/json.hpp>

#include "../common.hpp"


#include <string>
#include <sstream>
#include <memory>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>

namespace Is
{
    using std::string;
    using std::shared_ptr;
    using std::ifstream;

    class DP_API Database
    {
        Database() {}

    public:
        ~Database() {}

        static shared_ptr<nlohmann::json> getProperties(const string& db_name)
        {
            string filename = db_name + ".json";

            using json = nlohmann::json;
            shared_ptr<json> json_sptr(nullptr);

            try
            {
                ifstream ifs(filename);
                if (ifs.fail())
                {
                    std::stringstream ss;
                    ss << "Error: " << filename << " can NOT be open." << std::endl;
                    throw std::runtime_error(ss.str()); // 例外スロー: すぐにcatch文に飛ぶ. 自動変数ifsはデストラクタでclose()が呼ばれるので例外安全.
                }

                json_sptr.reset(new json());
                ifs >> *json_sptr; // Parse
            }
            catch (const std::runtime_error& e)
            {
                std::cerr << e.what() << std::endl;   
            }
            catch (const std::exception& e)
            {
                // std::bad_alloc例外とかを補足
                std::cerr << e.what() << std::endl;
            }
            catch (...)
            {
                std::cerr << "Unkonwn error." << std::endl;
            }

            return json_sptr;
        }
    };
}
#endif