# TCP/IP (Transmission Control Protocol/Internet Protocol)

## Why do we need protocol and why its layed?
- Having different layers allows for greater flexibility and scalabilily, sepration of concern, allows each layer to evolve indepedently.
- Without such standard network would be fragmented and incopatible. These protocols provides a stadardized communication, no matter the software or handware. Interoperatability.
## Indtroduction
- It is a layered set of communication protocols.
- TCP/IP dictates how data in gragmented into packets, how each packet is addressed and routed. How to verify packet integrity and how to detect/fix missing packet.
- Its not a single protocol but a suite of it/collection of it.

- THE TOP LAYER IS APPLICATION LAYER, contains user facing protocol which are build on top of TCP(mostly). Contains protocol on which application depends on daily basis. eg- HTTP, HTTPS,

## EACH LAYER

1. **APPLICATION LAYER**
  - Contains the (user facing/applciation facing protocol) eg-> HTTP
  - It simply produces the data and passes it to lower layers.
  - When machines communicates they need to establish TCP connection which is handled by TRANSPORT LAYER, but how will they communicate then? They need a common language(here protocol) that they both can understand.
  - eg- GET /foo HTTP1.1\r\n
2. **TRANSPORT LAYER**
  - Handles the mechanics of reliable delivery. Generating actually delivary payloads(packets).
  - Deals with how to deliver data fully in order, without error and duplicatation on an unreliable medium.
  - Breaking data into segments and adding sequence number to it, using ACK gets to know about missing packets.
