#include "abstract_factory_pattern/abstract_factory.hpp"

#include <exception>
#include <stdexcept> // runtime_error

namespace Is
{
    shared_ptr<AbstractFactory> AbstractFactory::getFactory(const string& classname)
    {
        Registry_t& registry = getRegistry();

        try
        {
            auto iter = registry.find(classname);
            if (iter == registry.end())
            {
                string status = "クラス " + classname + " が見つかりません.";
                throw std::runtime_error(status);
            }

            return registry[classname];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::abort();
        }
    }
}