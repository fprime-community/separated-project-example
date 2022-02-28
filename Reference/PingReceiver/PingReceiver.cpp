// ======================================================================
// \title  PingReceiver.cpp
// \author tim
// \brief  cpp file for PingReceiver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Reference/PingReceiver/PingReceiver.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Reference {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  PingReceiver ::
    PingReceiver(
        const char *const compName
    ) : PingReceiverComponentBase(compName), m_inhibitPings(false), m_pingsRecvd(0)
  {

  }

  void PingReceiver ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    PingReceiverComponentBase::init(queueDepth, instance);
  }

  PingReceiver ::
    ~PingReceiver()
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void PingReceiver ::
    PingIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 key
    )
  {
    //this->log_DIAGNOSTIC_PR_PingReceived(key);
    this->tlmWrite_PR_NumPings(this->m_pingsRecvd++);
    if (not this->m_inhibitPings) {
        PingOut_out(0,key);
    }
  }

  void PingReceiver::PR_StopPings_cmdHandler(
          FwOpcodeType opCode, /*!< The opcode*/
          U32 cmdSeq /*!< The command sequence number*/
      ) {
      this->m_inhibitPings = true;
      this->cmdResponse_out(opCode,cmdSeq,Fw::CmdResponse::OK);
  }

} // end namespace Reference
