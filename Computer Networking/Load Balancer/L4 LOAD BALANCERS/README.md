#

#### How L4 LB works
Operates on two modes:
1. Pass-through Mode
2. Proxy Mode


### Pass-through Mode
There is no machine on which a connection is made, and then it routes it. The connection is not broken. The connection is  literally just passed through it.

What do we think a load balancer is? The client connects to the load balancer, and the load balancer connects to the backend server. The load balancer manager manages two TCP servers. 

But in pass-through mode, the same connection is pass thought the cleint from the backend thoughb laod balancer.

literally forwards the packet to the appropriate nod,e
does not break TCP connection, and makes another tcp connection. Only one TCP connection passes through client to the 

- One single TCP connection exists, directly between client ↔ backend.
- The load balancer only acts as a traffic router, deciding which backend server receives the packets.
- LB does not terminate the connection
- Selection of nodes is based on connection-level metadata  
  - Source IP and port
  - Destination IP and port
  - Protocol (TCP/UDP) or some metadata
- Random, Hash-based, Source IP Hash - configurability depends on LB.

### Proxy Mode
Proxy → The LB acts as a middleman, creating two separate TCP connections.
Load balancer is fuly handling the handshake from clinet to LB, load balancer has a lot more control on which of backen server it will connect with. each check number of connection, latency healthstatis of backen server. So this way using L4, in proxy mode it can do more dynamic routing. It can do Round Robin, Least Connection , Weighted RR, IP Hash, Random etc etc
