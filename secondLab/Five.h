#include <cstddef>
#include <string>

class Five {
    private:
        unsigned char * data;
        std:: size_t n;
        
    public:
        Five();
        Five(const std::string &num);
        Five(const Five &o);
        ~Five();

        Five sum(const Five &o) const;
        Five sub(const Five &o) const;

        void sumAs(const Five &o);
        void subAs(const Five &o);


        bool lt(const Five &o) const;
        bool eq(const Five &o) const;
        bool mt(const Five &o) const;


};