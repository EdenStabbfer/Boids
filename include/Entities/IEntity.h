//
// Created by kufuk on 27.08.2023.
//

#ifndef IENTITY_H
#define IENTITY_H


#include <cstdint>
#include <concepts>

class IEntity;

template<class T>
concept IsEntity = std::derived_from<T, IEntity>;

class IEntity {
    template<IsEntity T>
    friend
    class IContainer;

public:
    IEntity();

    ~IEntity() = default;

    bool operator==(const IEntity &other) const;

    bool operator!=(const IEntity &other) const;

    [[nodiscard]]
    uint32_t getId() const;

private:
    uint32_t _id;

    static uint32_t generateId();
};


#endif //IENTITY_H
