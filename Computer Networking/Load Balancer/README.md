# Load Balancer
A server/service that distributes client requests across multiple backend servers. Ensures reliability, scalability, and availability by preventing any single backend from being overloaded.

NOTE:- OSI model is a conceptual framework; each layer serves a specific purpose and communicates with the layer directly above and below it. 

L4
- Operates at Layer 4 (Transport Layer) of the OSI model.
- Makes routing decisions based on IP address and port numbers (source/destination).
- Protocol-agnostic → Works with both TCP and UDP traffic.
- Uses network-level information only (does not inspect the packet payload like L7 load balancers).
- Very fast and efficient, since it doesn’t parse application data.

L7
- Operates at Layer 7 (Application Layer) of the OSI model.
- Can inspect and understand application data (e.g., HTTP headers, URL paths, cookies, query params).
- Makes content-based routing decisions (smarter than just IP/Port).
- Supports advanced traffic management features:
  - URL rewrites
  - Adding/removing headers
  - Redirects (e.g., HTTP → HTTPS)
  - SSL termination/offloading

L4 LB: only knows IP + Port, blind to application data.

L7 LB: understands the content of the request, so it can do smart routing and modifications.
