# Open System Intercommunincation [OSI]
I will first start with why? Why do we need this, if we won't have it what will we need to do??

### WHY DO WE NEED STANDARD MODEL LIKE OSI?
Without a standard model (like OSI model), application we build will have **no knowledge of the underlying network medium.** If there will be no standard communication model, we will have to code different versions of application. One for WIFI, one for ethernet one for fiber.

The OSI model provides layers of abstraction. As an application developer, you code against the Application Layer (Layer 7). You don't care if the underlying physical connection (Layer 1) is Wi-Fi, Ethernet, or fiber optic cable. The layers in between handle the complex details of translating your application's request into the right format for the physical medium. 

## THERE ARE JUST 2-3 MAINS PROTOCOLS!

### What is a Protocol?
-> Set of rules and guidelines that govern the communication betweem difference entiries in a system.

-> Defines how data is transmitted, received and interpreted between devices.

-> The aim of network protocol is to facilitate the exchange of data between devices connected in a network.

Protocol operates at different layer of the network stack, with **each layer responsible for specific aspect of communication.**

**IP (Internet Protocol) - LAYER 3 [NETWORK LAYER]**
-> Defines the addressing(assigning unique logical address - IP address) and 
-> routing mechanisms(determines the most effective path for data packets to travel across) multiple networks to reach final destination)
-> Data unit = packets

**TCP/UDP (tranmission control protocol/user datagram protocol) - LAYER 4 [TRANSPORT LAYER]**
-> Transportt layer protocol manages the connection between devices.
-> Provides reliable connection-oriented data delivery. [TCP]


[7 layers of OSI MODEL](https://www.linkedin.com/feed/update/urn:li:activity:7363433963266166786/)

NOTE ->
- Port information is with  Transport Layer
- IP information is with Network Layer



- Application Layer
  -  Provides network services to application.
  -  HTTP, FTP, SMTP, DNS, SNMP, Telnet, SSH
  -  Interacts directly with the software application.
  -  Application receives structured data (e.g., Python dict, JavaScript object). They are serialized into a text or binary format like JSON, XML, or Protobuf. Sending that serialized text as part of an HTTP request or response body
  -  ```js
     const data = { username: "alice", password: "wonderland123" }; // js object
     const jsonString = JSON.stringify(data); // <-- Serialization happens here
     ```
- Presentation Layer  / Syntax Layer
  -  Translates data between the application and the network [ DATA TRANSLATOR FOR NETWORK]
  -  Conceptually handles how data is represented, encrypted, and encoded during transmission.
  -  Ensures that data from one system can be properly understood by another system.
  -  TLS encrypts the serialized JSON data
  -  For HTTPS: Turning plaintext HTTP data (which may include JSON) into encrypted bytes.
 
- Session Layer
- Transport Layer
