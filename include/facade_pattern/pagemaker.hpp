#ifndef FACARD_PAGEMAKER_HPP
#define FACARD_PAGEMAKER_HPP

#include "../common.hpp"
#include "database.hpp"
#include "html_writer.hpp"

#include <string>
#include <iostream>

namespace Is
{
    using std::string;

    class DP_API PageMaker
    {
        // インスタンスは作らないのでコンストラクタはprivate
        PageMaker() {}
    public:
        ~PageMaker() {}

        static void makeWelcomPage(const string& mail_addr, const string& filename)
        {
            try
            {
                auto json_mail_prop = Database::getProperties("maildata");
                if (json_mail_prop)
                {
                    if (json_mail_prop->contains(mail_addr))
                    {
                        string username = (*json_mail_prop)[mail_addr]; // string
                        HtmlWriter writer(filename);
                        writer.title("Welcome to " + username + "'s page!");
                        writer.paragraph(username + "のページへようこそ。");
                        writer.paragraph("メールまっていますね。");
                        writer.mailto(mail_addr, username);
                        writer.close();
                        std::cout << filename << " is created for " 
                            << mail_addr << " (" << username + ")" << std::endl;
                    }
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
        }
    };
}

#endif