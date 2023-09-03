//
// Created by kufuk on 05.08.2023.
//

#ifndef ICONTAINER_H
#define ICONTAINER_H

#include "../Entities/IEntity.h"

#include <vector>

template<IsEntity T>
class IContainer
{
    template<IsEntity U>
    friend class IContainer;

protected:
    using DataType = std::vector<T>;
    using ForEachFunction = void(T&);

public:
    IContainer() = default;
    ~IContainer() = default;

    virtual void forEach(ForEachFunction* function) = 0;
    virtual void forEachPair(const T& outer_obj, ForEachFunction* function) = 0;

    const T& get(int idx) { return m_data[idx]; }
    T& get(int idx) const { return m_data[idx]; }

    int size() { return m_data.size(); }

    typename DataType::iterator begin() { return m_data.begin(); }
    typename DataType::iterator end() { return m_data.end(); }

    template<class... Args>
    auto& add(Args... args)
    {
        return m_data.emplace_back(std::forward<Args>(args)...);
    }

protected:
    DataType m_data;
};


#endif //ICONTAINER_H
