I will first start with why? Why do we need this, if we won't have it what will we need to do??

### WHY DO WE NEED STANDARD MODEL LIKE OSI?
Without a standard model (like OSI model), application we build will have **no knowledge of the underlying network medium.** If there will be no standard communication model, we will have to code different versions of application. One for WIFI, one for ethernet one for fiber.

The OSI model provides layers of abstraction. As an application developer, you code against the Application Layer (Layer 7). You don't care if the underlying physical connection (Layer 1) is Wi-Fi, Ethernet, or fiber optic cable. The layers in between handle the complex details of translating your application's request into the right format for the physical medium. 
