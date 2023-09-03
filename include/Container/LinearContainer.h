//
// Created by kufuk on 02.09.2023.
//

#ifndef LINEARCONTAINER_H
#define LINEARCONTAINER_H

#include "IContainer.h"

template<IsEntity T>
class LinearContainer: public IContainer<T>
{
public:
    LinearContainer() = default;
    ~LinearContainer() = default;

    void forEach(typename IContainer<T>::ForEachFunction* function) override
    {
        for (auto& outer_obj: this->m_data)
        {
            function(outer_obj);
        }
    }

    void forEachPair(const T& outer_obj, typename IContainer<T>::ForEachFunction* function) override
    {
        for (auto& inner_obj: this->m_data)
        {
            if(outer_obj != inner_obj)
            {
                function(inner_obj);
            }
        }
    }
};

#endif //LINEARCONTAINER_H
