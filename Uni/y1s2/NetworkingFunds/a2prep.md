# Config basic router settings with IOS CLI

## Topology

PCa - Switch - Router - PCb

## OBjectives

- Assign static IPv4 info to the PC interfaces
- Configure basic router settings
- Verify network connectivity
- Show router info

## Step 1: Configure the PC interfaces.

- a. Configure the IP address, subnet mask, and default gateway settings on PC-A.
- b. Configure the IP address, subnet mask, and default gateway settings on PC-B.
- c. Ping PC-B from a command prompt window on PC-A.
Why were the pings not successful?
  - `router interface/gateways not configured yet so Layer 3 traffic not being routed between subnets