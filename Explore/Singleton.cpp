//IMplement a singleton.
//IN software engineering, oftentimes loggers,
// settings managera, database connections  and other objects are implemented  as singleton . A singleton is a design
// pattern  that restricts the user from creating more than one instance of said object. THis means that it cannot be copied or moved.

class Singleton {
    public:
    static Singleton* Getinstance() {
        static Singleton instance;
        return &instance;
    }

    Singleton(const Singleton&) = delete;

    void operator=(const Singleton&) = delete;

    Singleton (Singleton&&)= delete;

    void operator=(const Singleton&&) = delete;
    private:
    Singleton() = default;
};