#include "Reference/Top/ReferenceTopologyDefs.hpp"

namespace Reference {

  namespace Allocation {

    Fw::MallocAllocator mallocator;

  }

  Drv::BlockDriver blockDrv(FW_OPTIONAL_NAME("blockDrv"));

}
