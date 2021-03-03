#pragma once

#include <sstream>

class NonCopyable {
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable& other) = delete;
    virtual ~NonCopyable() = default;

    NonCopyable& operator =(const NonCopyable& other) = delete;

};

class NonMoveable {
public:
    NonMoveable() = default;
    NonMoveable(NonMoveable&& other) = delete;
    virtual ~NonMoveable() = default;

    NonMoveable& operator =(NonMoveable&& other) = delete;

};

template <typename T>
class Singleton : public NonCopyable, public NonMoveable {
public:
    template <typename... Args>
    static T* Create(Args&... args) {
        if (s_Instance) {
            std::stringstream ss;
            ss << "Engine::Singleton<" << typeid(T).name() << ">::Create: s_Instance is not nullptr!";
            throw std::runtime_error(ss.str());
        }

        return s_Instance = new T(args...);
    }

    static void Destroy() {
        delete s_Instance;
        s_Instance = nullptr;
    }

    static inline T& Get() {
        if (!s_Instance) {
            std::stringstream ss;
            ss << "Engine::Singleton::Get: s_Instance(";
            ss << typeid(T).name();
            ss << ") is nullptr!";

            throw std::runtime_error(ss.str());
        }

        return *s_Instance;
    }

    static inline T* GetPointer() {
        return s_Instance;
    }

protected:
    Singleton() = default;

    static inline T* s_Instance = nullptr;

};