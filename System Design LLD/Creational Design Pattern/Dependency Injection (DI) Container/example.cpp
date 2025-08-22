#include <iostream>
#include <memory>
#include <functional>
#include <unordered_map>
#include <typeindex>
#include <stdexcept>
#include <tuple>
#include <utility>

/**
 * @class DIContainer
 * @brief A Dependency Injection (DI) container.
 *
 * Manages the lifecycle of objects based on the principle of
 * Inversion of Control (IoC). It allows for registering types and resolving them
 * on demand.
 */
class DIContainer {
    // unordered map
    // key-> std::type_index (This allows us to use types as keys in our map)
    // value-> callable that,when executed creates and returns a generic shared pointer.
    // std::function<>: A wrapper that can hold any callable (like a lambda).
    // (): The function takes no arguments.
    // std::shared_ptr<void>: It returns a smart pointer to a generic, untyped block of memory.
    std::unordered_map<std::type_index, 
    std::function<std::shared_ptr<void>()>> factories;
public:
    /**
     * @enum Lifetime
     * @brief Defines the lifetime scope for a registered type.
     */
    enum class Lifetime { Singleton, Transient }; 
    
    /**
     * @brief Registers a mapping from an interface (or base class) to a concrete implementation.
     * @tparam TInterface The interface or base type to use as the key for resolution.
     * @tparam TImpl The concrete implementation type to be created.
     * @param lifetime(Lifetime): default is Transient.
    */
    template<typename TInterface, typename TImpl>
    void registerType(Lifetime lifetime = Lifetime::Transient) {
        // The interface type is used as the unique key for the factory map.
        auto typeId = std::type_index(typeid(TInterface));

        if (lifetime == Lifetime::Singleton) {
            // For Singletons, store a lambda that creates the instance only once
            factories[typeId] = []() { 
                static std::shared_ptr<TInterface> instance = std::make_shared<TImpl>(); // Magic Static 
                return instance;
            };
        }
        else { // Transient
            // For Transients, store a lambda that creates a new instance every time it's called.
            factories[typeId] = []() {
                return std::make_shared<TImpl>();
            };
        }
    }
    
    /**
     * @brief Resolves (creates or retrieves) an instance(object) of the requested type.
     * @tparam T The type of the object to resolve.
     * @return A std::shared_ptr to the resolved object.
     * @throws std::runtime_error if the type has not been registered.
     */
    template<typename T>
    std::shared_ptr<T> resolve() {
        // Get the type index for the requested type to use as a lookup key.
        auto typeId = std::type_index(typeid(T));
        auto it = factories.find(typeId);
        
        // Ensure that a factory for this type was previously registered.
        if (it == factories.end()) {
            throw std::runtime_error("Type not registered in container");
        }
        
        
        // 'it->second' is the std::function.
        // Invoking it 'it->second()' creates an object and returns std::shared_ptr<void>;
        // Then casting the genetic std::shared_ptr to specific typed std::shared_ptr.
        return std::static_pointer_cast<T>(it->second());
    }
};
