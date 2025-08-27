# Chain of Responsibility

The sequence of handlers processes an event one after another. Even is passed along a chain of handlers.

A chain of components/handlers that all get a chance to process a command/query/event, optionally. Having an ability to terminate the processing chain as well.

E.g. -> We have a computer game where each fighter has an attack and defense value. Based on the spell we use, these values can increase or decrease. Using the Chain of Responsibility (CoR) pattern, we can register each shot as it happens, apply the effects of the spell in sequence, and then calculate the defender’s final health.

## Types:-
1. Pointer Chain
2. Broker Chain
