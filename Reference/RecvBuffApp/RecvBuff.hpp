#ifndef REFERENCE_LPR_ATM_IMPL_HPP
#define REFERENCE_LPR_ATM_IMPL_HPP

#include <Reference/RecvBuffApp/RecvBuffComponentAc.hpp>

namespace Reference {

    class RecvBuff : public RecvBuffComponentBase {
        public:

            // Only called by derived class
            RecvBuff(const char* compName);

            void init(NATIVE_INT_TYPE instanceId = 0);
            ~RecvBuff();

        private:

            // downcall for input port
            void Data_handler(NATIVE_INT_TYPE portNum, Drv::DataBuffer &buff);
            Reference::PacketStat m_stats;
            U32 m_buffsReceived; // !< number of buffers received
            bool m_firstBuffReceived; // !< first buffer received or not
            U32 m_errBuffs; // !< number of buffers with errors received
            F32 m_sensor1;
            F32 m_sensor2;
            void toString(char* str, I32 buffer_size);

            // parameter update notification
            void parameterUpdated(FwPrmIdType id);

    };

}

#endif
