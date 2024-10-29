#include "calc.hpp"

#include <assert.h>
#include <string.h>

void RandomMacAddrs::Get(uint8_t mac_address[kAddressSize]) {
  assert((mac_address != nullptr) && "Parameter must be not null.");
  memcpy(mac_address, mac_address_, kAddressSize);
  return;
}
