#ifndef BRIDGE_DISPLAY_IMPL_HPP
#define BRIDGE_DISPLAY_IMPL_HPP

namespace Is
{
    class DisplayImpl
    {
    public:
        virtual void rawOpen() = 0;
        virtual void rawPrint() = 0;
        virtual void rawClose() = 0;

        DisplayImpl() {}
        virtual ~DisplayImpl() {}
    };
}
#endif