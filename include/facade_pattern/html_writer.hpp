#ifndef FACARD_HTMLWRITER_HPP
#define FACARD_HTMLWRITER_HPP

#include "../common.hpp"

#include <string>
#include <sstream>
#include <fstream>

namespace Is
{
    using std::string;

    class DP_API HtmlWriter
    {
        string filename_;
        std::ostringstream oss_;

    public:
        HtmlWriter(const string& filename) : filename_(filename) {}
        ~HtmlWriter() {}

        void title(const string& title)
        {
            using namespace std::literals::string_literals;
            oss_ << "<html>"s;
            oss_ << "<head>"s;
            oss_ << "<title>"s << title << "</title>"s;
            oss_ << "</head>"s;
            oss_ << "<body>"s << std::endl;
            oss_ << "<h1>" << title << "</h1>"s << std::endl;
        }

        void paragraph(const string& msg)
        {
            using namespace std::literals::string_literals;
            oss_ << "<p>"s << msg << "</p>"s << std::endl;
        }

        void link(const string& href, const string& caption)
        {
            using namespace std::literals::string_literals;
            string msg = "<a href=\""s + href + "\">" + caption + "</a>";
            paragraph(msg);
        }

        void mailto(const string& mail_addr, const string& user_name)
        {
            using namespace std::literals::string_literals;
            string href = "mailto:"s + mail_addr;
            link(href, user_name);
        }

        void close() noexcept(false) // 任意の例外を送出することを明示
        {
            using namespace std::literals::string_literals;
            oss_ << "</body>"s;
            oss_ << "</html>"s << std::endl;

            std::ofstream ofs(filename_);
            ofs.exceptions(std::ofstream::failbit | std::ofstream::badbit);
            ofs << oss_.str();
        }
    };
}
#endif