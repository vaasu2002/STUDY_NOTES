# Chain of Responsibility

When we have a event that needs to be passed thought multiple handlers(situations). This can be done by a series of 'if' statements. It works but it's not ideal. The main problem here is resubility, if we want to use the same condition way of dealing somewhere else we can't.

Instead of having a big cluster of ```if``` statements, we can express it as a chain of objects. Each of these objects will worry about only one particular situation. There can be like if object can handle the situtation if will process and can either stop the chain forwarding or just send forward to let other also processing things on event.

e.g. Validating password
```cpp
if(password.size()<5){
  // password is too short
}
for(char ch: password){
  if(ch.isupper()){
    cnt_u++;
  }
  if(ch.islower(){
    cnt_l++;
  }
}
if(cnt_u==0){
  //  password does not contain any upper case
}
if(cnt_l==0){
  // password does not contain any lower case
}
```
The sequence of handlers processes an event one after another. Even is passed along a chain of handlers.

A chain of components/handlers that all get a chance to process a command/query/event, optionally. Having an ability to terminate the processing chain as well.

E.g. -> We have a computer game where each fighter has an attack and defense value. Based on the spell we use, these values can increase or decrease. Using the Chain of Responsibility (CoR) pattern, we can register each shot as it happens, apply the effects of the spell in sequence, and then calculate the defender’s final health.

## Types:-
1. Pointer Chain
2. Broker Chain
